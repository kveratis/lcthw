#ifndef _object_h
#define _object_h

typedef enum
{
	NORTH,
	SOUTH,
	EAST,
	WEST
} Direction;

// Notice that the first field in the struct is a pointer. Since C puts the
// fields in a struct in order, and since a pointer just points to a chunk
// of memory, you can "cast" a pointer to anything you want.
typedef struct
{
	char* description;
	int (*init)(void* self);
	void (*describe)(void* self);
	void (*destroy)(void* self);
	void* (*move)(void* self, Direction direction);
	int (*attack)(void* self, int damage);
} Object;

int Object_init(void* self);
void Object_destroy(void* self);
void Object_describe(void* self);
void* Object_move(void* self, Direction direction);
int Object_attack(void* self, int damage);
void* Object_new(size_t size, Object proto, char* description);

// This makes a macro, and it works like a template function that spits out
// code on the right, whenever you use the macro on the left.  This one is
// simply makeing a short version of the normal way we'll call Object_new and
// avoids potential errors with calling it wrong.  The way the macro works is
// the T and N parameters to NEW are "injected" into the line of code on the
// right.
// The syntax T##Proto says to "concat Proto at the end of T", so if you had
// NEW(Room, "Hello.") then it would make RoomProto there.
#define NEW(T, N) Object_new(sizeof(T), T##Proto, N)

// This macro is a bit of syntactic sugar for the object system and basically
// helps you write obj->proto.blah as simply obj->_(blah).  It's not necessary
// but it's fun little trick that will be used later.
#define _(N) proto.N

#endif
