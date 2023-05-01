#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Get the price of a drink by its name
int getPrice(struct Drink* drink_head, char name[]) {
    struct Drink* current = drink_head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->price;
        }
        current = current->next;
    }
    return -1;
}

// Get the calories of a drink by its name
int getCalories(struct Drink* drink_head, char name[]) {
    struct Drink* current = drink_head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->calories;
        }
        current = current->next;
    }
    return -1;
}

// Get the price of a food by its name
int getFoodPrice(struct Food* food_head, char name[]) {
    struct Food* current = food_head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->price;
        }
        current = current->next;
    }
    return -1;
}

// Get the calories of a food by its name
int getFoodCalories(struct Food* food_head, char name[]) {
    struct Food* current = food_head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->calories;
        }
        current = current->next;
    }
    return -1;
}

// Find the best combination of food and drink based on price and calories
void findBestCombo(struct Drink* drink_head, struct Food* food_head, int budget, int max_calories) {
    struct Drink* current_drink = drink_head;
    struct Food* current_food = food_head;
    int best_price = -1;
    int best_calories = -1;
    char best_drink_name[50];
    char best_food_name[50];

    // Loop through all possible combinations of drinks and foods
    while (current_drink != NULL) {
        while (current_food != NULL) {
            int total_price = current_drink->price + current_food->price;
            int total_calories = current_drink->calories + current_food->calories;

            // Check if the combination is within budget and has the highest calories so far
            if (total_price <= budget && total_calories <= max_calories && total_calories > best_calories) {
                best_price = total_price;
                best_calories = total_calories;
                strcpy(best_drink_name, current_drink->name);
                strcpy(best_food_name, current_food->name);
            }

            current_food = current_food->next;
        }

        current_drink = current_drink->next;
        current_food = food_head;
    }

    // Print the best combination
    if (best_price != -1 && best_calories != -1) {
        printf("The best combination is %s and %s.\n", best_drink_name, best_food_name);
        printf("Price: %d\n", best_price);
        printf("Calories: %d\n", best_calories);
    } else {
        printf("Not found.\n");
    }
}
