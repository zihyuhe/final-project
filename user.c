#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "sort.h"

int main() {

    printf("Welcome!\n");

    struct Drink* drink_head = NULL;
    struct Food* food_head = NULL;

    int budget;
    int max_calories;
    printf("Please enter your ideal budget: ");
    scanf(" %d", &budget);
    printf("Please enter your ideal calories: ");
    scanf(" %d", &max_calories);

    findBestCombo(drink_head, food_head, budget, max_calories);

    return 0;
}

