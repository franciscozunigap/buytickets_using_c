#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const double pct_interno;
const int cant_externo;


typedef struct seccion{
 int id;
 int asientos;
 float factor;
} sector;

typedef struct estadio{
 int cant_sec;
 int pbase;
 sector *secc;
} stadium;

typedef struct cliente {
 char *id;
 int presupuesto;
 int n_seccion;
 int n_entradas;
 struct cliente *sgte;
} fans;


void leer_estadio(char *nombre_archivo, stadium *st); //funcion que lee el estadio y asigna variables

int numero_clientes(int capacidad); //genera numero de clientes

int genera_presupuesto(int _barato, int s_caro); //genera un presupuesto aleatorio

void cliente(fans **cabeza, int presupuesto, int c_clientes); //funcion que genera un cliente

void leer_lista(fans *cabeza, fans *arreglo);

void free_nodos(fans **del); //libera nodos

void write_tda(fans *cabeza, int n_seccion, int p_base); //escribe en el tda.txt las tda

void leer_clientes(char *nombre_archivo, fans *datos_cliente); //lee el tda de los clientes

void push(fans **cabeza, fans *datos_cliente); // inserta a la cola

void venta(fans *cola, stadium st,int n_clientes); // realiza la venta a partir de la cola y los datos del estadio

void ordenar_mayor_menor(sector arreglo[], int l); // ordena el arreglo en funcion de los factoes de mayor a menor

void reporte_publico(int n_entradas, int secc_agotado[],int largo); // muestra por pantalla reportes periodicos

void reporte_privado(char *nom, int e_vendidas, int e_restantes, int c_sin_entrada,int c_sectores, int array_sectores[], int c_restantes, int recaudacion_total); // genera los archivos de reportes privados

void pop(fans **fin); // saca de la cola el elemento superior de la lista

void sponsor(); //funcion sponsor
