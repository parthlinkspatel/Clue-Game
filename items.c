#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "items.h"
#include "rooms.h"

char *itemList[] = {
    "Burger",
    "Taco",
    "Fries",
    "Chicken",
    "Soda",
    "Fish"
};

char *characters[] = {
    "James",
    "John",
    "Ava",
    "Thomas",
    "Calvin"
};

//Param head: head is the list of items
//Param input: is the item we want to drop from the list (head)
//Returns an updated list of items
//This method drops the input from the list, head. 
struct Item* dropItem(struct Item* head, char* input){
    struct Item *first = head;
    if(strcmp(input, head->itemName) == 0){
        head = head->next;
        return head;
    } else {
        while (first->next != NULL){
            if(strcmp(first->next->itemName, input) == 0){
                first->next = first->next->next;
                break;
            }else{
                first = first->next;
            }
        }
    }
    return head;
}

//Param head: head is the list of items
//Param input: is the item we want to add to the list (head)
//Returns an updated list of items
//this method adds input to the list, head, by adding the new item
//to the front of the list
struct Item* addItem(struct Item* head, char* input){
    struct Item* newItem = (struct Item*) malloc(sizeof(struct Item));
    newItem->itemName = input;
    return newItem;
}