CC = cc
LIB = -lSDL2 -lSDL2_image -lSDL2_ttf

DEBUG = -g
CFLAGS = $(DEBUG) -Wall -ansi -pedantic -std=c99
LDFLAGS = $(LIB)

OBJS = main.o error.o iface.o sprite.o sheet.o map.o player.o \
		tiledata.o

EXE = rpg

%.o: %.c 
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXE): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) 

tags:
	ctags -R *.[ch]

clean:
	rm tags *.o *~ $(EXE)
