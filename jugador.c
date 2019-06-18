#include "generala.h"
#include <rpc/rpc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void dibujar1(){
	printf(" _____\n");
	printf("|- - -|\n");
	printf("|- o -|\n");
	printf("|- - -|\n\n");
};
void dibujar2(){
	printf(" _____\n");
	printf("|- - o|\n");
	printf("|- - -|\n");
	printf("|o - -|\n\n");
};
void dibujar3(){
	printf(" _____\n");
	printf("|o - -|\n");
	printf("|- o -|\n");
	printf("|- - o|\n\n");
};
void dibujar4(){
	printf(" _____\n");
	printf("|o - o|\n");
	printf("|- - -|\n");
	printf("|o - o|\n\n");
};
void dibujar5(){
	printf(" _____\n");
	printf("|o - o|\n");
	printf("|- o -|\n");
	printf("|o - o|\n\n");
};
void dibujar6(){
	printf(" _____\n");
	printf("|o - o|\n");
	printf("|o - o|\n");
	printf("|o - o|\n\n");
};
void * mostrardados_1_svc(mano * m, struct svc_req *cliente){
  printf("------------------------------------------------------\n");
  int i;
  for(i=0;i++;i<6){
  	switch (m->dados[i]){		//dado nro i
  		case 1:
  			dibujar1();
  			break;
  		case 2:
  			dibujar2();
  			break;
  		case 3:
  			dibujar3();
  			break;
  		case 4:
  			dibujar4();
  			break;
  		case 5:
  			dibujar5();
  			break;
  		case 6:
  			dibujar6();
  			break;
  	}
  	printf("\t(%i)\n\n",i);	
  }
  static void* var;
  return(var);
}

mano * elegirdados_1_svc(mano * m, struct svc_req *cliente){
	printf("-------------------------------------------------\n");
	printf("Con que dados te quedas?\t");
	char* s;
	scanf("%s",s);
	int misdados[5];
	int slen = strlen(s);
	int i;
	int j=0;
	for (i=0;i++;i<slen){
		if (isdigit(slen[i])){
			misdados[j] = slen[i] - '0';
			j++;
		}
	}
}
/*
void * mostrarpuntajes_1_svc(puntajes * p,struct svc_req *cliente){
  float valorPeso=0;
  valorPeso=0.023;
  static float dolares=0.0;
  dolares = valorPeso * *pesos;
  return &dolares;
}
void * mostrarmipuntaje_1_svc(mipuntaje * mp, struct svc_req *cliente){
  float valorPeso=0;
  valorPeso=0.021;
  static float euros=0.0;
  euros = valorPeso * *pesos;
  return &euros;
}
int st_hora * elegirmano_1_svc(mipuntaje * mp,struct svc_req *cliente){
  struct tm *ahora;
  time_t t;
  static st_hora resultado;
  t = time(NULL);
  ahora=localtime(&t);
  resultado.hora=ahora->tm_hour;
  resultado.minuto=ahora->tm_min;
  resultado.segundo=ahora->tm_sec;
  return (&resultado);
}
void * fin_1_svc(puntajes * p,struct svc_req *cliente){
  struct tm *ahora;
  time_t t;
  static st_dia resultado;
  t = time(NULL);
  ahora=localtime(&t);
  resultado.dia=ahora->tm_mday;
  resultado.mes=ahora->tm_mon + 1;
  resultado.anho=ahora->tm_year + 1900;
  return (&resultado);
}
float * suma_1_svc(arregloFloats * arr, struct svc_req *cliente){
  int cant = arr->cant;
  static float resultado=0;
  for(int i=0; i<cant;i++) {
    resultado+=arr->arr[i];
  }
  return (&resultado);
}
float * resta_1_svc(arregloFloats * arr, struct svc_req *cliente){
  int cant = arr->cant;
  static float resultado=0;
  resultado = arr->arr[0];
  for(int i=1; i<cant;i++) {
    resultado-=arr->arr[i];
  }
  return (&resultado);
}

float * multiplicacion_1_svc(arregloFloats * arr, struct svc_req *cliente) {
  static float resultado;
  resultado=arr->arr[0] * arr->arr[1];
  return (&resultado);
}

float * division_1_svc(arregloFloats * arr, struct svc_req *cliente) {
  static float resultado;
  resultado=arr->arr[0] / arr->arr[1];
  return (&resultado);
}
*/
