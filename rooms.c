#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rooms.h"
#include "items.h"


//Array of restaraunt/room names
char* roomList[] = {
    "McDonalds", 
    "Applebee's", 
    "Chili's", 
    "Wendy's", 
    "Berkshire", 
    "Hampshire", 
    "Worcester", 
    "Franklin", 
    "Wendy's"
    };

//Rearranges roomList array
void randomizeRooms(){
    for(int i=0 ; i<8 ; i++ ){
        srand ( time(NULL) );
        int j = rand() % 9;
        char* temp = roomList[j];
        roomList[j] = roomList[i];
        roomList[i] = temp;
    }
}


char *tempItemList[] = {
    "Burger",
    "Taco",
    "Fries",
    "Chicken",
    "Soda",
    "Fish"
};

char *tempCharacterList[] = {
    "James",
    "John",
    "Ava",
    "Thomas",
    "Calvin"
};

//can be accessed globally
struct Room *rooms[9];

//9 rooms are created and its directions and names are set and items are placed in. 
void initRooms(){
    int i;
    //initializes all rooms and assign its Room names
    for(int a = 0; a<9; a++){
        rooms[a] = (struct Room*) malloc(sizeof( struct Room));
    }    
    for(i = 0; i<9; i++){
        //rooms[i] = (struct Room*) malloc(sizeof( struct Room));
        rooms[i]-> name = roomList[i];
        // rooms[i]-> North = NULL;
        // rooms[i]-> South = NULL;
        // rooms[i]-> East = NULL;
        // rooms[i]-> West = NULL;
        // rooms[i]-> ItemList = NULL;
        if(i<5){
            rooms[i+1]->Character[0] = tempCharacterList[i];
        }
    }

    //Creates and assigns items to the rooms
    struct Item *item1 = (struct Item *) malloc(sizeof(struct Item));
    struct Item *item2 = (struct Item *) malloc(sizeof(struct Item));
    struct Item *item3 = (struct Item *) malloc(sizeof(struct Item));
    struct Item *item4 = (struct Item *) malloc(sizeof(struct Item));
    struct Item *item5 = (struct Item *) malloc(sizeof(struct Item));
    struct Item *item6 = (struct Item *) malloc(sizeof(struct Item));
    item1->itemName = "Burger";
    item2->itemName = "Taco";
    item3->itemName = "Fries";
    item4->itemName = "Chicken";
    item5->itemName = "Soda";
    item6->itemName = "Fish";

    rooms[0] -> ItemList = item1;
    rooms[1] -> ItemList = item2;
    rooms[2] -> ItemList = item3;
    rooms[3] -> ItemList = item4;
    rooms[4] -> ItemList = item5;
    rooms[5] -> ItemList = item6;

    //Initializes room directions
    rooms[0]->East = rooms[1];
    rooms[0]->South = rooms[3];

    rooms[1]-> West = rooms[0];
    rooms[1]-> South = rooms[4];
    rooms[1]-> East = rooms[2];

    rooms[2]-> East= rooms[1];
    rooms[2]-> South= rooms[5];

    rooms[3]-> North= rooms[0];
    rooms[3]-> South= rooms[6];
    rooms[3]-> East= rooms[4];

    rooms[4]-> North= rooms[1];
    rooms[4]-> South= rooms[7];
    rooms[4]-> East= rooms[5];
    rooms[4]-> West= rooms[3];

    rooms[5]-> North= rooms[2];
    rooms[5]-> South= rooms[8];
    rooms[5]-> West= rooms[4];

    rooms[6]-> North= rooms[3];
    rooms[6]-> East= rooms[7];

    rooms[7]-> North= rooms[4];
    rooms[7]-> East= rooms[8];
    rooms[7]-> West= rooms[6];

    rooms[8]-> North= rooms[5];
    rooms[8]-> West= rooms[7];
}

