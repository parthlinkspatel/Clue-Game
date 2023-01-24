#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>



extern struct Room *rooms[];
struct Room {
      char* name;
      struct Room * North;
      struct Room * South;
      struct Room * East;
      struct Room * West;
      struct Item * ItemList;
      char * Character[5];
};


//initializes 9 Rooms and assigns its directions (North east south west), name, and character if applicable.
void initRooms();

//Ramdomize Rooms
void randomizeRooms();

