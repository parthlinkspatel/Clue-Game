#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "rooms.h"
#include "items.h"



//Frees all the allocated space when called maloc
void malocFree() {
    free(rooms[0]->ItemList);
    free(rooms[1]->ItemList);
    free(rooms[2]->ItemList);
    free(rooms[3]->ItemList);
    free(rooms[4]->ItemList);
    free(rooms[5]->ItemList);
    free(rooms[0]);
    free(rooms[1]);
    free(rooms[2]);
    free(rooms[3]);
    free(rooms[4]);
    free(rooms[5]);
    free(rooms[6]);
    free(rooms[7]);
    free(rooms[8]);
}

//Array of 5 characters
char *charList[] = {
    "James",
    "John",
    "Ava",
    "Thomas",
    "Calvin"
};

//Avatar starts at room 0
int roomNumber = 0;
//Current Room of type Room
struct Room *current;
//To keep track of guesses
int guessCnt = 0;
//inventory of type Item 
struct Item *inventoryList = NULL;


//This function prints out the list of commands when help command is called.
void helpCmdPrint() {
    printf("Commands: (type in lowercase)\nhelp\nlist\nlook\ngo\ntake\ndrop\ninventory\nclue\n");
}

//Prints list of all 5 characters, 6 items, and 9 rooms/restaraunts 
void list(){
    printf("\nCharacters: James, John, Ava, Thomas, Calvin");
    printf("\nItems: Burger, Taco, Fries, Chicken, Soda, Fish");
    printf("\nRooms/Restaraunts: McDonalds, Applebee's, Chili's, Wendy's, Berkshire, Hampshire, Worcester, Franklin, Wendy's\n");
}

//prints the characters in the room
void lookHelperCharacters(int num){
    //If there is no character in the room
    if (rooms[num]->Character[0] == NULL){
        printf("\nThere are no characters here");
    } 
    //Loops through to find the element that isn't null
    else{ 
        printf("The people/characters in this restaraunt/room are:");
        int i=0;
        while (i<5){
            if(rooms[num]->Character[i] != NULL){
                printf("\n%s", rooms[num]->Character[i]);
            }
            i++;
        }
    }
}

//prints the surround rooms' names
void lookHelperDirections(int num){
    if(num < 5){
        printf("\n%s is South of your current room", rooms[num+3]->name);
    }
    if (num > 3){
        printf("\n%s is North of your current room", rooms[num-3]->name);
    }
    if ( num == 1 || num == 2 || num == 4 || num==5 || num==7 || num==8){
        printf("\n%s is West of your current room", rooms[num-1]->name);
    }
    if ( num == 1 || num == 0 || num == 4 || num==3 || num==7 || num==6){
        printf("\n%s is East of your current room", rooms[num+1]->name);
    }    
}

//prints the item/s in the room
void lookHelperItems(int num){
    struct Item* items = rooms[num]->ItemList;
    if( items == NULL ){
        printf("There are no items/food here");
    } else{
        while(items != NULL){
            printf("\n%s", items->itemName);
            items = items->next;
        }
    }
}

//prints which characters, items, and which rooms around around 
void look(int num){
    printf("\nThis is room number %d, the name of the Restaraunt is %s", num, rooms[num]->name);
    
    lookHelperCharacters(num);
    lookHelperDirections(num);
    lookHelperItems(num);
}

//did not get to this yet
void go(){

}

//This method checks if the room has any items in it, and adds it
//to the inventory list, and takes it out of the room.
//If input is invalid, take() is called again and user will be prompted to type again
void take(){
    //if current room doesn't have any items in it
    if(current->ItemList == NULL){
        printf("\nThe current room youre in doesnt have any items in it");
    }else{
        printf("\nEnter item you want to add\n");
        //get user's input on what item to drop
        char *userInput = (char*) malloc(sizeof(char)*100);
        struct Item *list = inventoryList;
        while( strcmp(list->itemName,userInput) != 0 ){
            list= list->next;
            //checks if user's input is in the list 
            if(list->itemName == NULL){
                printf("\nCouldn't find item in inventory, maybe check spelling or case");
                take();//player enters item in input if not found
            }
        }
        inventoryList = addItem(list, userInput);
        current->ItemList = dropItem(current->ItemList,userInput);
    }
}
//This method uses the dropItem method in items.c to drop the item
//entered by the user. It checks cases for if the inventory list
//is empty or if the user entered an invalid item
void drop(){
    //if inventroy is empty, dont drop anything
    if(inventoryList == NULL){
        printf("\nInventory is empty");
    }
    else{
        printf("\nEnter item you want to drop\n");
        //get user's input on what item to drop
        char *userInput = (char*) malloc(sizeof(char)*100);
        struct Item *list = inventoryList;
        scanf("%s",userInput);
        while( strcmp(list->itemName,userInput) != 0 ){
            list= list->next;
            //checks if user's input is in the list 
            if(list->itemName == NULL){
                printf("\nCouldn't find item in inventory, maybe check spelling or case");
                drop();//player enters item in input if not found
            }
        }
        inventoryList = dropItem(inventoryList, userInput);
        current->ItemList = addItem(current->ItemList, userInput);
    }

}

//prints the inventory
void inventoryPrint(){
    if(inventoryList==NULL){
        printf("Your inventory is empty");
    } else{
        //need to iterate through the inventory list
        struct Item *list = inventoryList;
        while(list!=NULL){
            printf("\n%s",list->itemName);
            list = list -> next;
        }
    }
}

//Did not get to this yet
void clue(){

}

//this method ask for an input command 
// and then calls another method based on the used input
void inputMenu(){
    printf("\n\nEnter Command\n");
    char *inputCommand = (char *) malloc(sizeof(char) * 12);
    scanf("%s", inputCommand);

    // Calls the necessary function based on command
    if(strcmp(inputCommand, "help")==0){ helpCmdPrint(); }
    else if(strcmp(inputCommand, "list")==0){ list(); }
    else if(strcmp(inputCommand, "look")==0){ look(4); }
    else if(strcmp(inputCommand, "go")==0){ go(); }
    else if(strcmp(inputCommand, "take")==0){ take(); }
    else if(strcmp(inputCommand, "drop")==0){ drop(); }
    else if(strcmp(inputCommand, "inventory")==0){ inventoryPrint(); }
    else if(strcmp(inputCommand, "clue")==0){ 
        guessCnt++;
        clue(); }
    // If command is invalid
    else {
        printf("invalid command");
        printf("\nEnter a Valid Command or 'help'");
        char inputCommand[10];
        inputMenu();
    }
}

//Generating answers key 
struct Room *roomAns;
struct Item *itemAns;
char *charAns;
void createAns(){ 
    srand(time(0));
    roomAns = rooms[rand() % 9];
    srand(time(NULL));
    itemAns -> itemName = itemList[rand()%6];
    charAns = charList[rand() % 5];
}

//set boolean correct to false and set it to true when all 3 match
bool correct = false;
//This method checks is the game is won or not and prints a message
void results(){
    if(correct){
        printf("\nYAY you have won the game. Thank you for playing");
    } else{
        printf("\nDang it, you ran out of guesses. Try again.");
    }
} 

int main()
{
    printf("\nWelcome to Parth's and Ishita's game. You are in room 0 of 3x3 mapped grid. There are 9 restaraunts. There are 5 characters and of those is one food critic. Also, this is 6 food items. You will have to play the game and guess who is the food critic at which restaraunt and what is he/she eating.\n" );
    //menu();
    itemAns = (struct Item *) malloc(sizeof(struct Item));
    inventoryList = (struct Item *) malloc(sizeof(struct Item));
    randomizeRooms();
    initRooms();
    createAns();
    current = rooms[roomNumber];//room #0
    while(guessCnt < 10 && !correct){
        printf("\nYou have %d guesses left", 10-guessCnt);
        inputMenu();
    }
    results();

    malocFree();

    free(itemAns);
    free(inventoryList);
    return 0;
}
