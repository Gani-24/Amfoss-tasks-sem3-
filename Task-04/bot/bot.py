import os
import telebot
import requests
import csv
from dotenv import load_dotenv

load_dotenv()

mykey = os.getenv('keyy')
botid = os.getenv('botkey')

bot = telebot.TeleBot(botid)

movie_data = []

@bot.message_handler(commands=['start'])
def start(message):
    global bot_running
    bot_running = True
    bot.reply_to(message, 'Hello there! I am a bot that will show movie information for you and export it in a CSV file.')

@bot.message_handler(commands=['stop'])
def stop(message):
    global bot_running
    bot_running = False
    movie_data.clear()
    bot.reply_to(message, 'Bye! Have a good time')


@bot.message_handler(commands=['help'])
def help(message):
    help_text = '''You can use the following commands:\n\n
                    1. /movie MOVIE_NAME - Get the details of a particular movie\n\n
                    2. /export - Export all the movie data in CSV format\n\n
                    3. /stop or /bye - Stop the bot'''
    bot.reply_to(message, help_text)


@bot.message_handler(func=lambda message: bot_running, commands=['movie'])
def movie_info(message):
    movieid = message.text.split()
    movie_title = " ".join(movieid[1:])
    response = requests.get(f"http://www.omdbapi.com/?apikey={mykey}&t={movie_title}")
    movie_info = response.json()
    movie_data.append([movie_info['Title'], movie_info['Year'], movie_info['Released'], movie_info['imdbRating']])
    bot.reply_to(message, 'Getting movie info...')
    bot.send_photo(message.chat.id, movie_info['Poster'], caption=f"Movie Name: {movie_info['Title']}\nYear: {movie_info['Year']}\nReleased: {movie_info['Released']}\nimdbRating: {movie_info['imdbRating']}")
    csvwriter(movie_data)

@bot.message_handler(func=lambda message: bot_running, commands=['export'])
def export_data(message):
    bot.reply_to(message, 'Generating file...')
    with open('movies.csv', 'rb') as file:
        bot.send_document(message.chat.id, file)

def csvwriter(data):
    header = ['Title', 'Year', 'Released', 'IMDB Rating']
    with open('movies.csv', 'w', encoding='UTF8', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(header)
        writer.writerows(data)

@bot.message_handler(func=lambda message: bot_running)
def default(message):
    bot.reply_to(message, 'Sorry, I did not understand.')


bot_running = False
bot.infinity_polling()
