CC=gcc
CFLAGS=-m32 -fno-stack-protector -no-pie -D_FORTIFY_SOURCE=0
LDFLAGS=-m32
EXEC=textadventure

all: $(EXEC)

$(EXEC): textadventure.o
	$(CC) $(LDFLAGS) -o $@ $^

main.o: textadventure.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(EXEC)

.PHONY: clean
