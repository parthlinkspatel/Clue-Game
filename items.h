#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


extern char *itemList[];
extern char *characters[];
struct Item{
    char *itemName;
    struct Item *next;
};


//Param: Input is the item you are removing from the item list, head is the head of the list
struct Item* dropItem(struct Item* head, char* input);


//Param: Input is the item you are adding to the item list, head is the head of the list
struct Item* addItem(struct Item* head, char* input);
