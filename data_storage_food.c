#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Food {
    char name[50];
    int calories;
    int price;
    struct Food* next;
};

void data_foods(){
    FILE* fp;
    char line[100];

    fp = fopen("food.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        exit(1);
    }

    struct Food* foods = NULL;
    while (fgets(line, 100, fp)) {
        struct Food* food = malloc(sizeof(struct Food));

        // read from strings
        char* token = strtok(line, ",");
        strcpy(food->name, token);
        token = strtok(NULL, ",");
        food->calories = atoi(token);
        token = strtok(NULL, ",");
        food->price = atoi(token);
        food->next = NULL;

        // add to linked list
        if (foods == NULL) {
            foods = food;
        } else {
            struct Food* current = foods;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = food;
        }
    }



    // free
    struct Food* current = foods;
    while (current != NULL) {
        struct Food* temp = current;
        current = current->next;
        free(temp);
    }

    fclose(fp);
}

