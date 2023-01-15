#include "head.h"

const double pct_interno = 0.25;
const int cant_externo = 5000;




int main(int argc, char *argv[]) {
  stadium st;

  srand(time(NULL));

  leer_estadio(argv[1],&st); // LEE UN ESTADIO Y ALMACENA VARIABLES

  int capacidad_estadio=0;
  int i;
  for(i = 0; i<st.cant_sec;i++){

    capacidad_estadio+= st.secc[i].asientos;
  }


  int n_clientes = numero_clientes(capacidad_estadio);


  //asigno el precio barato y el caro de forma abitraria
  float barato = 20;
  float caro = 0;
  int count;
  for(count=0; count<st.cant_sec; count++){
    if(st.secc[count].factor > caro){
      caro = st.secc[count].factor;
    }
  }
  int t;
  for(t =0; t<st.cant_sec; t++){
    if(st.secc[t].factor < barato){
      barato = st.secc[t].factor;
    }
  }


  int total_caro = caro * st.pbase;
  int total_barato = barato * st.pbase;


  //Crear lista aleatoria de n_clientes, esto con un for que en cada ciclo genera un cliente
  // ¿POR QUE LISTA SIMPLE ENAZADA? ocupé esta tda porque me parece sencilla para ir agregando los clientes a esta
  //    de forma aleatoria

  int largo_clientes=0;
  int posicion = 0;
  fans *head = NULL;


  while (largo_clientes < n_clientes) {
    int presupuesto = genera_presupuesto(total_barato,total_caro);
    //posicion es un rand en funcion del largo de los clientess
    largo_clientes++;
    posicion = rand() % (largo_clientes + 0);
    cliente(&head, presupuesto, posicion);


  }


  //write_tda(head,n_sec,p_base); // crea el archivo con las tda llamado "tda.c"

  // vender desde el inicio al final, para esto genero una cola
  // ¿ POR QUE UNA COLA? Ocupé una cola porque consideré sencillo agregar una a una, para luego ocupa la utilidad
  //    LIFO para la venta, accediendo asi a caada cliente y modificando sus datos en la cola

  fans *cabeza_cola = NULL;
  if(head == NULL){
	  exit(-1);
	}else{
		fans *rec = head;
		while(rec!=NULL){
			push(&cabeza_cola, rec);
      rec = rec->sgte;
		}
	}

  //por cada nodo de la pila tengo un id y un presupuesto
  //ahora recorro la pila y asigno las variables con condiciones presupuestarias
  //antes ordeno arreglo en funcion de los factores, esto de mayor a menor

  ordenar_mayor_menor(st.secc, st.cant_sec);


  venta(cabeza_cola,st,n_clientes); //en la venta hago los reportes


  free_nodos(&head);
  int m;
  for (m=0; m < n_clientes; m++) {
    pop(&cabeza_cola);
  }


  return 0;
}
