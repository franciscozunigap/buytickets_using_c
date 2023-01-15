#include "head.h"
int id = 0;

void cliente(fans **cabeza, int presupuesto, int pos){
	fans *lista = malloc(sizeof(fans));
	fans *recorredor = (*cabeza);
  int cont;


  if (lista == NULL){
		printf("Error en creación de nodo\n");
		exit(-1);
	}

  id += 1;

  lista->id = malloc(sizeof(char)*20);
  sprintf(lista->id, "%d", id);

  lista->presupuesto = presupuesto;


  lista->n_seccion = 0;
  lista->n_entradas = 0;

	if(recorredor==NULL){ //casos primer nodo
		lista->sgte=NULL;
		*cabeza = lista;
	}else{ //caso entre nodos y final
		for(cont=0; cont<(pos-1); cont++){ //crear nodos en desorden hasta pos
			if(recorredor->sgte == NULL) //para nodo final
				break;
  		else {
        recorredor = recorredor->sgte;
      }
		}
		lista->sgte = recorredor->sgte;
		recorredor->sgte = lista;
	}
};

void free_nodos(fans **del){
	fans *sicario = *del;
  while(*del != NULL){
		*del = sicario->sgte;

		free(sicario);
		sicario = *del;
	}
};

void write_tda(fans *cabeza, int n_seccion, int p_base){
  FILE *tda;
  char *nom = "tda.txt";
  char *modo = "a";

  tda = fopen(nom, modo);

  if (tda == NULL) {
    printf("Error abriendo archivo %s", nom);
    exit(-1);
  }

  fprintf(tda, "cantidad de secciones: %d    precio base: %d\n \n", n_seccion, p_base);

  if(cabeza == NULL){
    //printf("[]\n");
    fprintf(tda, "[]");


  }else{
    fans *rec = cabeza;
    while(rec!=NULL){
      fprintf(tda,"[id: %s | ",rec->id);
      fprintf(tda,"presupuesto: %d  | ", rec-> presupuesto);
      fprintf(tda,"n_seccion: %d | ", rec-> n_seccion);
      fprintf(tda,"n_entradas: %d]\n", rec-> n_entradas);

      rec=rec->sgte;
    }
  }
  fclose(tda);
}
