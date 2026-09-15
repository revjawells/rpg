CC = cc
LIB = -lSDL2 -lSDL2_image

DEBUG = -g
CFLAGS = $(DEBUG) -Wall -ansi -pedantic -std=c99
LDFLAGS = $(LIB)

OBJS = main.o error.o iface.o sprite.o sheet.o 

EXE = rpg

%.o: %.c 
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXE): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) 

tags:
	ctags *.[ch]

clean:
	rm tags *.o *~ && rm $(EXE)
