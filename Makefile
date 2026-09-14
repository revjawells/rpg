CC = cc
LIB = -lSDL2 -lSDL2_image

CFLAGS = -Wall -ansi -pedantic -std=c99
LDFLAGS = $(LIB)

OBJS = main.o error.o iface.o sprite.o

EXE = rpg

%.o: %.c 
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXE): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) 

tags:
	ctags *.[ch]

clean:
	rm tags *.o *~ && rm $(EXE)
