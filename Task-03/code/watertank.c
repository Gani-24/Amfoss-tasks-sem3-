#include <stdio.h>

int main() {
    int n, s, ini, fin, z, i, j;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &s);
        int array[s];
        for (j = 0; j < s; j++) {
            scanf("%d", &array[j]);
        }

        ini = 0;
        fin = s-1;
        for (j = 0; j < s-1; j++) {
            if (array[j] > 0) {
                ini = j;
                break;
            }
        }
        int s1 = fin - ini;
        int array1[s1];
        for (j = ini; j < fin; j++) {
            array1[j - ini] = array[j];
        }

        z = 0;
        for (j = 0; j < s1; j++) {
            if (array1[j] == 0) {
                z++;
            }
        }

        if (z == s1) {
            printf("0\n");
        } else {
            int sum = 0;
            for (j = 0; j < s1; j++) {
                sum += array1[j];
            }
            printf("%d\n", sum + z);
        }
    }

    return 0;
}
