Programa:

  Este Programa lee un archivo llamado estadioX.txt, luego de leerlo realiza una compra de entradas para este estadio de forma aleatoria, post a esta venta,
  los clientes del Programa reciben una asignacion de asiento y presupuesto sobrante, cada cliente no puede comprar mas de dos entradas



Para compilar:
- Debe estar en el directorio los archivos "codigo.c" "implementaciones.c" "tda_listasimples.c" "tda_cola.c"
- Debe tener instalado el compilador gcc



Intrucciones de complicacion:

# gcc -o codigo.c implementaciones.c tda_listasimples.c tda_cola.c -Wall

Makefile->

  #TEST: codigo.o implementaciones.o tda_listasimple.o tda_cola.o

  #	$(CC) -o $@ codigo.o implementaciones.o tda_listasimple.o tda_cola.o $(FLAGS)


  #codigo.o: codigo.c
  #	$(CC) -c codigo.c $(FLAGS)

  #implementaciones.o: implementaciones.c
  #	$(CC) -c implementaciones.c $(FLAGS)

  #tda_listasimple.o: tda_listasimple.c
  #	$(CC) -c tda_listasimple.c $(FLAGS)

  #tda_cola.o: tda_cola.c
  #	$(CC) -c tda_cola.c $(FLAGS)







Francisco Zuñiga | Paralelo 200| Rol: 202130509-2
