CC = cc
LIB = -lSDL2 -lSDL2_image

# INCLUDE = -I/usr/local/include

CFLAGS = -Wall -std=c99 $(INCLUDE)
LDFLAGS = $(LIB)

OBJS = main.o error.o iface.o

EXE = rpg

%.o: %.c 
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXE): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) 

tags:
	ctags *.[ch]

clean:
	rm tags *.o *~ && rm $(EXE)
