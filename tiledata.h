#ifndef TILEDATA_H
#define TILEDATA_H

typedef enum {
	ROOF = 1,
	WALL,
	DESK,
	FLOOR,
	CHEST,
	DOOR,
	STAIRDN,
	STAIRUP,
	BARRIER,
	WEAPONS,
	INN,
	BLANK,
	TOOLS,
	CASTLE,
	TOWN,
	GRASS,
	TREE,
	HILL,
	MOUNTAIN,
	CAVE,
	SAND,
	MARSH,
	BRIDGE,
	WATER
} tilename_t;

typedef struct {
	int tile;
	int flags;
} tiledata_ent;

#define PASSABLE 0x01

#endif
