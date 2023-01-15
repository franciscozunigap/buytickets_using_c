#include "head.h"

// funciones para la cola

void push(fans **cabeza, fans *datos_cliente){
	fans *nuevo = malloc(sizeof(fans));
	nuevo->id = datos_cliente->id;
	nuevo->presupuesto = datos_cliente->presupuesto;
	nuevo->sgte = *cabeza;
	*cabeza = nuevo;

}

void pop(fans **fin){

	fans *objetivo = *fin;

	*fin = objetivo->sgte;

	free(objetivo);

}
