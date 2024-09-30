CC=gcc
CFLAGS=-m32 -fno-stack-protector -no-pie -D_FORTIFY_SOURCE=0 -z execstack
LDFLAGS=-m32
EXEC=breakroom_adventure.exe

all: $(EXEC)

$(EXEC): breakroom_adventure.o
	$(CC) $(LDFLAGS) -o $@ $^
	./${EXEC}

main.o: breakroom_adventure.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(EXEC)

.PHONY: clean
