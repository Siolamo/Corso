media: main.o listaStudenti.o
	gcc main.o listaStudenti.o -o media

listaStudenti.o: listaStudenti.c listaStudenti.h
	gcc -g -c listaStudenti.c

main.o: main.c listaStudenti.h
	gcc -g -c main.c