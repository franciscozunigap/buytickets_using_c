CC=gcc
FLAGS= -Wall 
FLAGS1= -lm -lrt 

TEST: codigo.o implementaciones.o tda_listasimple.o tda_cola.o

	$(CC) -o $@ codigo.o implementaciones.o tda_listasimple.o tda_cola.o $(FLAGS)
	
	
codigo.o: codigo.c
	$(CC) -c codigo.c $(FLAGS)

implementaciones.o: implementaciones.c
	$(CC) -c implementaciones.c $(FLAGS)

tda_listasimple.o: tda_listasimple.c
	$(CC) -c tda_listasimple.c $(FLAGS)
	
tda_cola.o: tda_cola.c
	$(CC) -c tda_cola.c $(FLAGS)
	
codigo.c: head.h
implementacionesc: head.h
tda_listasimple: head.h
tda_cola: head.h
