use scraper::{Html, Selector};
use std::error::Error;
use csv::Writer;

fn main() -> Result<(), Box<dyn Error>> {
    let url = "https://crypto.com/price";
    let response = reqwest::blocking::get(url)?;
    let body = response.text()?;
    let document = Html::parse_document(&body);

    let mut wtr = Writer::from_path("crypto.csv")?;
    wtr.write_record(&["Name", "Price", "24H change", "24H volume", "Market Cap"])?;

    let data = extract_data(&document)?;
    for row in data {
        wtr.write_record(&row)?;
    }

    wtr.flush()?;
    println!("Done");

    Ok(())
}

fn extract_data(document: &Html) -> Result<Vec<Vec<String>>, Box<dyn Error>> {
    let crypto = Selector::parse("tr.css-1cxc880")?;
    let namecrypto = Selector::parse("div.css-ttxvk0  p")?;
    let pricecrypto = Selector::parse("div.css-b1ilzc")?;
    let h24crypto = Selector::parse("div.css-16q9pr7 p")?;
    let h24volcrypto = Selector::parse("td.css-1nh9lk8")?;
    let marketcapcrypto = Selector::parse("td.css-1nh9lk8+td")?;

    let mut data = Vec::new();
    for element in document.select(&crypto) {
        let name = element.select(&namecrypto)
                          .next()
                          .map(|e| e.text().collect())
                          .unwrap_or("".to_string());
        let price = element.select(&pricecrypto)
                           .next()
                           .map(|e| e.text().collect())
                           .unwrap_or("".to_string());
        let h24 = element.select(&h24crypto)
                         .next()
                         .map(|e| e.text().collect())
                         .unwrap_or("".to_string());
        let h24v = element.select(&h24volcrypto)
                          .next()
                          .map(|e| e.text().collect())
                          .unwrap_or("".to_string());
        let mark = element.select(&marketcapcrypto)
                          .next()
                          .map(|e| e.text().collect())
                          .unwrap_or("".to_string());

        data.push(vec![name, price, h24, h24v, mark]);
    }

    Ok(data)
}
