#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(time_t timestamp) {
    srand(timestamp);
    return (rand() % 100) + 1;
}

int main() {
    time_t start = time(0);
    for (int i = 0; i < 10000; i++) {
        if (generateRandomNumber(start + i) == 69) {
            printf("%d\n", start + i);
            break;
        }
    }

    return 0;
}