#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Drink {
    char name[50];
    int calories;
    int price;
    struct Drink* next;
};

void data_drinks() {
    FILE* fp;
    char line[100];

    fp = fopen("drinks.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        exit(1);
    }

    struct Drink* drinks = NULL;
    while (fgets(line, 100, fp)) {
        struct Drink* drink = malloc(sizeof(struct Drink));

        // read from strings
        char* token = strtok(line, ",");
        strcpy(drink->name, token);
        token = strtok(NULL, ",");
        drink->calories = atoi(token);
        token = strtok(NULL, ",");
        drink->price = atoi(token);
        drink->next = NULL;

        // add to linked list
        if (drinks == NULL) {
            drinks = drink;
        } else {
            struct Drink* current = drinks;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = drink;
        }
    }



    // free
    struct Drink* current = drinks;
    while (current != NULL) {
        struct Drink* temp = current;
        current = current->next;
        free(temp);
    }

    fclose(fp);
    return 0;
}

