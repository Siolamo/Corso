CC = gcc
CFLAGS = -g

OBJ = util.o net.o math.o

all: main

main: main.o $(OBJ)
	$(CC) main.o $(OBJ) -o main

#amen
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clno:
	rm -f *.o

cln: 
	rm -f *o main