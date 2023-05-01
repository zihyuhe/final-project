#ifndef SORT_H
#define SORT_H

// Define a drink struct
struct Drink {
    char name[50];
    int calories;
    int price;
    struct Drink* next;
};

// Define a food struct
struct Food {
    char name[50];
    int calories;
    int price;
    struct Food* next;
};

int getPrice(struct Drink* drink_head, char name[]);
int getCalories(struct Drink* drink_head, char name[]);
int getFoodPrice(struct Food* food_head, char name[]);
int getFoodCalories(struct Food* food_head, char name[]);
void findBestCombo(struct Drink* drink_head, struct Food* food_head, int budget, int max_calories);

#endif

