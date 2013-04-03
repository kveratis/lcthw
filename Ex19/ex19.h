#ifndef _ex19_h
#define _ex19_h

#include "object.h"

// Taking a look at object.c:52 you can see a pointer used *el=calloc(1, size).
// Go back and look at the NEW macro in object.h and you can see that it is
// getting the sizeof another struct, say Room, and allocates that much.
// However, because you've pointed an Object pointer at this block of memory,
// and because you've put an Object proto field at the front of Room, you're
// able to treat a Room like it's an Object.
// The way to break this down is:
// * You call NEW(Room, "Hello") which the C Pre-Processor (CPP) expands as a
//   macro into Object_new(sizeof(Room), RoomProto, "Hello")
// * This runs, and insize Object_new it allocates a piece of memory that's
//   Room in size, but point an Object* el at it.
// * Since C puts the Room.proto field first, that means the el pointer is
//   really only pointing at enough of the block of memory to see a full Object
//   struct.  It has no idea that it's even called proto.
// * It then uses this pointer to set the contents of the piece of memory 
//   correctly with *el = proto; Remember that you can copy structs, and that
//   *el means "the value of whatever el points at", so this means "assign the
//   proto struct to whatever el points at".
// * Now that this mystery struct is filled in with the right data from proto,
//   the function can then call init or destroy on the Object, but the cool
//   part is whoever called this function can change these out for whatever 
//   ones they want.
// And with that we have a way to get this one function to construct new types
// and give them new functions to change their behavior.

struct Monster
{
	Object proto;
	int hit_points;
};

typedef struct Monster Monster;

int Monster_attack(void* self, int damage);
int Monster_init(void* self);

struct Room
{
	Object proto;
	
	Monster* bad_guy;

	struct Room* north;
	struct Room* south;
	struct Room* east;
	struct Room* west;
};

typedef struct Room Room;

void* Room_move(void* self, Direction direction);
int Room_attack(void* self, int damage);
int Room_init(void* self);

struct Map
{
	Object proto;
	Room* start;
	Room* location;
};

typedef struct Map Map;

void* Map_move(void* self, Direction direction);
int Map_attack(void* self, int damage);
int Map_init(void* self);

#endif
