#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int x[n], y[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        int above = 0, below = 0, left = 0, right = 0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (y[i] == y[j]) {
                    if (x[i] < x[j]) {
                        right = 1;
                    } else {
                        left = 1;
                    }
                }
                if (x[i] == x[j]) {
                    if (y[i] > y[j]) {
                        below = 1;
                    } else {
                        above = 1;
                    }
                }
            }
        }
        if (above && below && left && right) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
