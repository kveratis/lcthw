#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "engine.h"

int Monster_init(void* self)
{
	assert(self != NULL);

	Monster* monster = self;
	monster->hit_points = 10;
	return 1;
}

int Monster_attack(void* self, int damage)
{
	assert(self != NULL);
	assert(damage >= 0);

	Monster* monster = self;

	printf("You attack %s!\n", monster->_(description));

	monster->hit_points -= damage;

	if(monster->hit_points > 0)
	{
		printf("It is still alive.\n");
		return 1;
	}
	else
	{
		printf("It is dead!\n");
		return 0;
	}
}

Object MonsterProto = {
	.init = Monster_init,
	.attack = Monster_attack
};

void* Room_move(void* self, Direction direction)
{
	assert(self != NULL);

	Room* room = self;
	Room* next = NULL;

	if(direction == NORTH && room->north)
	{
		printf("You go north, into:\n");
		next = room->north;
	}
	else if(direction == SOUTH && room->south)
	{
		printf("You go south, into:\n");
		next = room->south;
	}
	else if(direction == EAST && room->east)
	{
		printf("You go east, into:\n");
		next = room->east;
	}
	else if(direction == WEST && room->west)
	{
		printf("You go west, into:\n");
		next = room->west;
	}
	else
	{
		printf("You can't go that dirction.");
		next = NULL;
	}

	if(next)
	{
		next->_(describe)(next);
	}

	return next;
}

int Room_attack(void* self, int damage)
{
	assert(self != NULL);

	Room* room = self;
	Monster* monster = room->bad_guy;

	if(monster)
	{
		return monster->_(attack)(monster, damage);
	}
	else
	{
		printf("You flail in the air at nothing. Idiot.\n");
		return 1;
	}
}

Object RoomProto = {
	.move = Room_move,
	.attack = Room_attack
};

void* Map_move(void* self, Direction direction)
{
	assert(self != NULL);
	Map* map = self;
	Room* location = map->location;
	Room* next = NULL;

	assert(location != NULL);
	next = location->_(move)(location, direction);

	if(next)
	{
		map->location = next;
	}

	return next;
}

int Map_attack(void* self, int damage)
{
	assert(self != NULL);

	Map* map = self;
	Room* location = map->location;

	assert(location != NULL);
	return location->_(attack)(location, damage);
}

Object MapProto = {
	.init = Map_init,
	.move = Map_move,
	.attack = Map_attack
};

int process_input(Map* game)
{
	assert(game != NULL);

	printf("\n> ");

	char ch = getchar();
	getchar(); // eat ENTER

	int damage = rand() % 4;
	int running = 1;

	switch(ch)
	{
		case 'q':
		case 'Q':
			printf("Giving up? You suck.\n");
			running = 0;
			break;
		case 'n':
		case 'N':
			game->_(move)(game, NORTH);
			break;
		case 's':
		case 'S':
			game->_(move)(game, SOUTH);
			break;
		case 'e':
		case 'E':
			game->_(move)(game, EAST);
			break;
		case 'w':
		case 'W':
			game->_(move)(game, WEST);
			break;
		case 'a':
		case 'A':
			// check for win condition (0 - no longer running)
			running = game->_(attack)(game, damage);

			if(!running)
			{
				printf("You won! You killed the minotaur\n");
			}
			break;
		case 'l':
		case 'L':
			printf("You can go:\n");
			if(game->location->north) printf("NORTH\n");
			if(game->location->south) printf("SOUTH\n");
			if(game->location->east) printf("EAST\n");
			if(game->location->west) printf("WEST\n");
			break;
		default:
			printf("What?: %d\n", ch);
	}

	return running;
}