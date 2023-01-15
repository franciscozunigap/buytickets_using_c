#include "head.h"



void leer_estadio(char *nombre_archivo, stadium *st){
 FILE *estadio = fopen(nombre_archivo,"r");
 fscanf(estadio, "%*s %d %*s %d", &st->cant_sec, &st->pbase); //guardar variables de tipo stadium en st; tengo la cant de secciones y el precio base

 st->secc = malloc(sizeof(sector)*st->cant_sec);

 //¿POR QUE ARREGLOS?
 //   ocupé arreglos porque son simples y para este caso puedo ordenarlos de forma unidimensional con el struct

 int i=0;
 while (i<st->cant_sec){ //en funcion de la cantidad de secciones asigna las variables al arreglo

   fscanf(estadio, "%d %d %f", &st->secc[i].id , &st->secc[i].asientos, &st->secc[i].factor);
   i++;
 }




 fclose(estadio);
};

int numero_clientes(int capacidad){
  int a;
  a = rand() % capacidad*20 + (capacidad*5);

  return a;
};

int genera_presupuesto(int s_barato, int s_caro){
  int a;

  a = rand() % ((s_barato/2) + (s_caro*3));

  return a;

};

void ordenar_mayor_menor(sector arreglo[], int l){
  int Temp;
  int i;
  for(i=0;i<l;i++){
    int q;
    for(q=0;q<l-1;q++){
      if(arreglo[q].factor<arreglo[q+1].factor){
        Temp=arreglo[q].factor;
        arreglo[q].factor=arreglo[q+1].factor;
        arreglo[q+1].factor=Temp;
      }
    }
  }
};

void venta(fans *r_cola, stadium st, int n_clientes){

  //arreglo de agotados
  int secc_agotado[st.cant_sec]; //sectores agotados
  int r;
  for (r = 0; r < st.cant_sec; r++) {
    secc_agotado[r] = 0;
  }


  //arreglo de sectors
  int array_sectores[st.cant_sec]; //sectores con lo recolectado
  int k;
  for (k = 0; k < st.cant_sec; k++) {
    array_sectores[k] = 0;
  }

  int entradas = 0; //total vendidas
  int c_sin_entrada = 0;
  int clientes_rest = n_clientes;
  int recaudacion_total=0;

  int entradas_totales;

  int y;
  for(y=0;y<st.cant_sec;y++){
    entradas_totales+= st.secc[y].asientos;
  }




  while(r_cola !=NULL){
    //printf("entradas vendidas: %d\n", entradas);
    if (entradas%5000==0){
      reporte_publico(entradas,secc_agotado,st.cant_sec);
    }
    if(((entradas*100)/entradas_totales)==25){
      int e_restantes = entradas_totales - entradas;
      reporte_privado("25%.txt", entradas, e_restantes, c_sin_entrada, st.cant_sec, array_sectores, clientes_rest, recaudacion_total);

    }
    if(((entradas*100)/entradas_totales)==50){
      int e_restantes = entradas_totales - entradas;
      reporte_privado("50%.txt", entradas, e_restantes, c_sin_entrada, st.cant_sec, array_sectores, clientes_rest, recaudacion_total);

    }
    if(((entradas*100)/entradas_totales)==75){

      int e_restantes = entradas_totales - entradas;
      reporte_privado("75%.txt", entradas, e_restantes, c_sin_entrada, st.cant_sec, array_sectores, clientes_rest, recaudacion_total);

    }
    if(((entradas*100)/entradas_totales)==100){
      int e_restantes = entradas_totales - entradas;
      reporte_privado("100%.txt", entradas, e_restantes, c_sin_entrada, st.cant_sec, array_sectores, clientes_rest, recaudacion_total);

    }
    int random = rand() % 7 + 0;
    if(random==5){
      sponsor();
    }
    //printf("\n\n cliente nuevo: \n\n" );
    clientes_rest-=1;

    int pcompra = 0;
    int max_entradas=0;
    r_cola->n_seccion=1;
    r_cola->n_entradas=0;


    int a;
    for(a=0; a<st.cant_sec; a++){
      int precio_sec = st.secc[a].factor * st.pbase;
      //printf("\n");
      //printf("  precio_sec: %d\n",precio_sec);
      //printf("  presupuesto: %d\n", r_cola->presupuesto );

      if (st.secc[a].asientos!=0) {  //va a comprar, antes de que lo haga debemos comprobar si quedan entradas
        if (r_cola->presupuesto >= precio_sec) {// verificamos si tiene presupuesto
          while(r_cola->presupuesto >= precio_sec){ // mientras lo tenga
            if (max_entradas<=1) { //verificamos maximo de entradas
              //printf("\n comprando...\n");
              pcompra = precio_sec;
              recaudacion_total +=pcompra; //aqui no logre arreglar el error de que se vuelve negativo
              //printf("  compra: %d\n", pcompra );
              r_cola->presupuesto -= pcompra;
              r_cola->n_seccion = a+1;
              r_cola->n_entradas += 1;
              entradas++;

              //printf("  seccion: %d\n", r_cola->n_seccion );
              st.secc[a].asientos -= 1;
              max_entradas++;

              //por cada compra al reporte

              array_sectores[a] +=pcompra;


            }else{
              break;
            }

          }
        //printf("  entradas: %d\n", r_cola->n_entradas);
        //printf("  saldo: %d\n", r_cola->presupuesto );
        //int q;
        //for (q = 0; q < st.cant_sec; q++) {
          //printf("seccion: %d \n  llevamos %d\n", r+1,array_sectores[r]);

        //}

        if(st.secc[a].asientos-entradas <=0){
          //printf("total vendidas: %d\n ", entradas);
          //printf(" quedan: %d\n", 0 );
        }
        else{
          //printf("total vendidas: %d en la seccion %d\n ", entradas,a+1);
          //printf("quedan: %d\n ", st.secc[a].asientos );
        }
        //printf("recaudacion total: %d\n",recaudacion_total);
        //printf("clientes en cola: %d\n", clientes_rest);
        //printf("clientes c_sin_entrada: %d\n", c_sin_entrada);

        break;
        }

    }
    if (st.secc[a].asientos==0) {
      secc_agotado[a] = 10;
    }

  }
    if(r_cola->n_entradas==0){
      c_sin_entrada+=1;
    }
    r_cola = r_cola->sgte;
  }

};

void reporte_publico(int n_entradas, int secc_agotado[],int largo){
  printf("\n total de entradas: %d\n", n_entradas);

  int seccion=0;

  int i = rand() % 3 + 0;
  if (i==3) {
    printf("\n\n | Cocacola!! llena de azucar como tus besitos |\n\n");
  }
  if (i==2) {
    printf("\n\n | Bebe aguita |\n\n");
  }
  if (i==1) {
    printf("\n\n | Se viene el 18 de septiembre, recuerda cuidar tu higado! |\n\n");
  }
  if (i==0) {
    printf("\n\n | Good bunny en CHILE |\n\n");
  }
  int agotadas;
  for (agotadas=0; agotadas<= largo ;agotadas++) {
    seccion++;
    int cuenta=0;
    if(secc_agotado[agotadas]==10){
        printf("\n localidad agotada: [");
        printf("sector: %d ]\n",seccion);
        cuenta+=1;

    }
    if(cuenta==0){
      printf("AÚN HAY ENTRADAS EN LA SECCION: %d\n", agotadas+1);
    }

  }


};

void reporte_privado(char *nom, int e_vendidas, int e_restantes, int c_sin_entrada,int c_sectores, int array_sectores[], int c_restantes, int recaudacion_total) {
  FILE *porcentaje;
  char *modo = "a";

  porcentaje = fopen(nom, modo);

  if (porcentaje == NULL) {
    printf("Error abriendo archivo %s", nom);
    exit(-1);
  }
  // aqui no logre arreglar el error de que me repete muchas veces el print en el archivo
  fprintf(porcentaje, " Entradas vendidas %d |  Entradas restantes %d |  Clientes sin entrada: %d  |\n", e_vendidas, e_restantes, c_sin_entrada);
  fprintf(porcentaje," \n | Clientes restantes: %d | Recaudacion total: %d |", c_restantes, recaudacion_total);
  int i;
  for (i = 0; i < c_sectores; i++) {
    fprintf(porcentaje," Recaudacion en sector %d es de %d :   |\n", i +1, array_sectores[i]);
  }

  fclose(porcentaje);

}

void sponsor(){
  int i = rand() % 3 + 0;
  if (i==3) {
    printf("\n\n | A conejo bueno le gusta el cola cao, a ti? |\n\n");
  }
  if (i==2) {
    printf("\n\n | PRODUCE PUNTEROTICKET.COM |\n\n");
  }
  if (i==1) {
    printf("\n\n | YA ESCUCHASTE EL NUEVO ALBUM DE CONEJO BUENO? :0000 |\n\n");
  }
  if (i==0) {
    printf("\n\n | NO OLVIDES, SI REVENDES LA ENTRADA ES DELITO |\n\n");
  }
}
