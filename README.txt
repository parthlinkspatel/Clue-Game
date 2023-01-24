# How to compile this program and play this game
To compile and play this game, you have to use the following 
command: 
% gcc rooms.c items.c adventure.c -g -o play
% ./play

#Goal of the game:
The player of the game is to guess which of the characters is 
the food critic, and which restaraunt the person is going to eat, and which 
food he is going to try. restaraunts will be called rooms in this game,
food will be called items, and one of the characters will be a critic.



# Overview/description of the overall structure of the game board
The structure of the game board is a 3 by 3 game board where there are
9 rooms/restaraunts. 
_____________
|_0_|_1_|_2_|
|_3_|_4_|_5_|
|_6_|_7_|_8_|

Each of the rooms are connected to each other by pointers. 
Room 0 is connected to its neighbors, 1 and 3, by east and south. 
Each room/restaraunts can have characters and items/foods in it.
The user will guess which a room, character, and item. 
If all three are guessed correct within 10 tries, the user wins.


# rooms.c and rooms.h
These files are where the room struct is defined. The room struct will 
include pointers to other rooms in which it neighbors. It will also 
include the characters in the rooms and the items. In rooms.c, the rooms are
initialized and set. The direction pointers are set to it neighbors. And the 
characters and items are placed in it. In the method initRooms(), items are 
also initialized because they need to be placed into a room.
Also rooms.c randomly sets the room to which restaraunt it represents. 

# items.c and items.h
In items.h, itemList and characters are defined so they can be accessed 
globally. Then the item struct is defined. In items.c, the two methods, dropItem and addItem
do exactly what the method name is. The dropItem method takes in two parameters, 
the name of what needs to be dropped, and the list from which the item is to be dropped
The method returns the updated list after the item is dropped.
The addItem also takes in two parameters, the name of the item being added and the list of Items that
its being added to. This method returns the updated list after.

#adventure.c
This file is where the main method is. This is where all of the function methods are.
The main method will call helper methods to take input from user. Then it will
call its respective methods based on its input. 