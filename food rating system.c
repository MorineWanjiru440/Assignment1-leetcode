#include <stdio.h>
#include <string.h>

#define MAX 1000   // maximum number of foods
#define LEN 50     // max length for food/cuisine names

// Global arrays
char foods[MAX][LEN];
char cuisines[MAX][LEN];
int ratings[MAX];
int n;  // number of foods

// Initialize the system
void initSystem(char f[][LEN], char c[][LEN], int r[], int size) {
    n = size;
    for (int i = 0; i < n; i++) {
        strcpy(foods[i], f[i]);
        strcpy(cuisines[i], c[i]);
        ratings[i] = r[i];
    }
}

// Change rating of a food
void changeRating(char food[], int newRating) {
    for (int i = 0; i < n; i++) {
        if (strcmp(foods[i], food) == 0) {
            ratings[i] = newRating;
            return;
        }
    }
}

// Get highest-rated food for a cuisine
char* highestRated(char cuisine[]) {
    static char bestFood[LEN];
    int bestRating = -1;

    for (int i = 0; i < n; i++) {
        if (strcmp(cuisines[i], cuisine) == 0) {
            if (ratings[i] > bestRating ||
               (ratings[i] == bestRating && strcmp(foods[i], bestFood) < 0)) {
                bestRating = ratings[i];
                strcpy(bestFood, foods[i]);
            }
        }
    }
    return bestFood;
}

// Example usage
int main() {
    char f[][LEN] = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    char c[][LEN] = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    int r[] = {9, 12, 8, 15, 14, 7};

    int size = 6;
    initSystem(f, c, r, size);

    printf("Highest rated Japanese: %s\n", highestRated("japanese")); // miso
    changeRating("sushi", 16);
    printf("Highest rated Japanese: %s\n", highestRated("japanese")); // sushi
    changeRating("ramen", 16);
    printf("Highest rated Japanese: %s\n", highestRated("japanese")); // ramen (tie -> lexicographically smaller)
    
    return 0;
}