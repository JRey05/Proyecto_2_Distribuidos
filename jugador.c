#include "generala.h"
#include <rpc/rpc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int cantJugadores;
void dibujarLinea1(mano *dados){
  int i=0;
  for(i=0;i<5;i++){
    printf(" _____\t");
  }
  printf("\n");
}
void dibujarLinea2(mano *dados){
  int i=0;
  for(i=0;i<5;i++){
    switch(dados->dados[i]){
      case 1:{
        printf("|- - -|\t");
      }break;
      case 2:{
        printf("|o - -|\t");
      }break;
      case 3:{
        printf("|o - -|\t");
      }break;
      case 4:{
        printf("|o - o|\t");
      }break;
      case 5:{
        printf("|o - o|\t");
      }break;
      case 6:{
        printf("|o - o|\t");
      }break;
    }
  }
  printf("\n");
}
void dibujarLinea3(mano *dados){
  int i=0;
  for(i=0;i<5;i++){
    switch(dados->dados[i]){
      case 1:{
        printf("|- o -|\t");
      }break;
      case 2:{
        printf("|- - -|\t");
      }break;
      case 3:{
        printf("|- o -|\t");
      }break;
      case 4:{
        printf("|- - -|\t");
      }break;
      case 5:{
        printf("|- o -|\t");
      }break;
      case 6:{
        printf("|o - o|\t");
      }break;
    }
  }
  printf("\n");
}
void dibujarLinea4(mano *dados){
  int i=0;
  for(i=0;i<5;i++){
    switch(dados->dados[i]){
      case 1:{
        printf("|- - -|\t");
      }break;
      case 2:{
        printf("|- - o|\t");
      }break;
      case 3:{
        printf("|- - o|\t");
      }break;
      case 4:{
        printf("|o - o|\t");
      }break;
      case 5:{
        printf("|o - o|\t");
      }break;
      case 6:{
        printf("|o - o|\t");
      }break;
    }
  }
  printf("\n");
}
void dibujarLinea5(){
  printf("(1)\t(2)\t(3)\t(4)\t(5)\n");
}

int * mostrardados_1_svc(mano * m, struct svc_req *cliente){
	dibujarLinea1(m);
	dibujarLinea2(m);
	dibujarLinea3(m);
	dibujarLinea4(m);
	dibujarLinea5();
	static int var;
  var = 1;
	return(&var);
}

mano * elegirdados_1_svc(mano * m, struct svc_req *cliente){
	printf("-------------------------------------------------\n");
	printf("Con que dados te quedas?\t");
	char* s;
	scanf("%s",s);
	static mano misdados;
	int slen = strlen(s);
	int i,num;
  for(i=0;i<5;i++){
    misdados.dados[i]=0;
  }
	int j=0;
	for (i=0;i<slen;i++){		//recorro el string ingresado y capturo los primeros 5 digitos entre 1 y 5

    if (isdigit(s[i])){
			num = s[i] - '0';			//conversion digito a int
			if ((num<6)&&(num>0)){
				misdados.dados[j]=m->dados[num-1];
				j++;
			}
		}
		if (j==5) {		//ya encontre 5 digitos en el mensaje, estos seran los dados, salgo del bucle for
      break;
		}
	}
	int k;
	for (k=5;k<j;k--){
		misdados.dados[k]==0;	//un 0 representa un dado que no fue elegido
	}
  
	return &misdados;
}

int * mostrarpuntajes_1_svc(puntajes * p,struct svc_req *cliente){
  int i;
  int pts,turn;
  printf("------------------Puntajes------------------\n");
  printf(" ____________________________________________\n");
  printf("|------Jugador-------|--------Puntaje--------|\n");
  printf(" ____________________|_______________________\n");
  turn=p->turnojugador;
  for(i=0;i<cantJugadores;i++){
  	pts=p->puntos[i];
  	printf(" ____________________|________________________\n");
  	if (turn==i){
  		printf("|---->Jugador %i<----|----------%i----------|\n",i+1,pts);	//es el turno de este jugador
  	}
  	else{
  		printf("|-----Jugador %i-----|----------%i----------|\n",i+1,pts);
  	}
  }
  static int var;
  var = 1;
  return(&var);
}

int * mostrarmipuntaje_1_svc(mipuntaje * mp, struct svc_req *cliente){
	//orden: 1, 2, 3, 4, 5, 6, escalera, full, poker, generala, generala doble
	int total=0;
	int i;
  //Creo que esto es la falla! Solucionado!!! (con malloc :|)
	char* c[11];
  for(i=0;i<11;i++){
    c[i]=malloc(4);
  }
	for(i=0;i<11;i++){
		if(mp->categorias[i]>=0){
			total=total+mp->categorias[i];
			sprintf(c[i],"%d",mp->categorias[i]);
		}
		else{
			strcpy(c[i],"x");	//representa una categoria tachada
		}
	}
	printf("------------------Mi puntaje-------------------\n");
	printf(" ______________________________________________\n");
  	printf("|------Categoria-------|--------Puntaje--------|\n");
	printf("|______________________|_______________________|\n");
  	printf("|----------1-----------|----------%s-----------|\n",c[0]);
  	printf("|----------2-----------|----------%s-----------|\n",c[1]);
  	printf("|----------3-----------|----------%s-----------|\n",c[2]);
  	printf("|----------4-----------|----------%s-----------|\n",c[3]);
  	printf("|----------5-----------|----------%s-----------|\n",c[4]);
  	printf("|----------6-----------|----------%s-----------|\n",c[5]);
  	printf("|-------Escalera-------|----------%s-----------|\n",c[6]);
  	printf("|--------Full----------|----------%s-----------|\n",c[7]);
  	printf("|--------Poker---------|----------%s-----------|\n",c[8]);
  	printf("|-------Generala-------|----------%s-----------|\n",c[9]);
  	printf("|----Generala Doble----|----------%s-----------|\n",c[10]);
	printf("|______________________|_______________________|\n");
  	printf("|--------Total---------|----------%i-----------|\n",total);
	printf("|______________________|_______________________|\n");
  	static int var;
    var = 1;
  	return(&var);

}

int * elegirmano_1_svc(mipuntaje * mp,struct svc_req *cliente){
  //orden: 1, 2, 3, 4, 5, 6, escalera, full, poker, generala, generala doble
	int i;
	char* c[11];
	char* o[11];
  for(i=0;i<11;i++){
    c[i]=malloc(4);
    o[i]=malloc(4);
  }
	int cantOpciones=0;
	for(i=0;i<11;i++){
		if(mp->categorias[i]>=0){	//opcion disponible
			sprintf(c[i],"%d",mp->categorias[i]);
			sprintf(o[i],"%d",cantOpciones+1);
			cantOpciones++;
		}
		else{	//opcion no disponible
			strcpy(c[i],"x");
			strcpy(o[i],"x");
		}
	}
	printf("------------------------------Mi puntaje-------------------------------\n");
	printf(" ______________________________________________________________________\n");
  	printf("|--------Opcion--------|------Categoria-------|--------Puntaje--------|\n");
	printf("|______________________|______________________|_______________________|\n");
  	printf("|----------%s-----------|----------1-----------|----------%s-----------|\n",o[0],c[0]);
  	printf("|----------%s-----------|----------2-----------|----------%s-----------|\n",o[1],c[1]);
  	printf("|----------%s-----------|----------3-----------|----------%s-----------|\n",o[2],c[2]);
  	printf("|----------%s-----------|----------4-----------|----------%s-----------|\n",o[3],c[3]);
  	printf("|----------%s-----------|----------5-----------|----------%s-----------|\n",o[4],c[4]);
  	printf("|----------%s-----------|----------6-----------|----------%s-----------|\n",o[5],c[5]);
  	printf("|----------%s-----------|-------Escalera-------|----------%s-----------|\n",o[6],c[6]);
  	printf("|----------%s-----------|--------Full----------|----------%s-----------|\n",o[7],c[7]);
  	printf("|----------%s-----------|--------Poker---------|----------%s-----------|\n",o[8],c[8]);
  	printf("|----------%s-----------|-------Generala-------|----------%s-----------|\n",o[9],c[9]);
  	printf("|----------%s-----------|----Generala Doble----|----------%s-----------|\n",o[10],c[10]);
	printf("|______________________|______________________|_______________________|\n");
	static int e;
	while(1){
		printf("\nQue opcion elegis?\n");
		scanf("%i",&e);
		if((e>0)&&(e<=cantOpciones)){
			//es una opcion valida
			break;
		}
		else{
			printf("Por favor, ingresa una opcion valida\n");
		}
	}
	return &e;
}


int * fin_1_svc(puntajes * p,struct svc_req *cliente){
  if(p->turnojugador>=MAXJUGADORES){
    //Se gano por generala servida.
    printf("----------------FIN DEL JUEGO----------------\n");
    printf(" ____________________________________________\n");
    int ganador = p->turnojugador-MAXJUGADORES;
    printf("Ganador Jugador %i!!",ganador+1);
  }
  else {
    int i;
  	int pts,turn,ganador;
  	int max=0;
  	printf("----------------FIN DEL JUEGO----------------\n");
  	printf(" ____________________________________________\n");
  	printf("|------Jugador-------|--------Puntaje--------|\n");
  	printf(" ____________________|_______________________\n");
	  turn=p->turnojugador;
	  for(i=0;i<cantJugadores;i++){
  		pts=p->puntos[i];
  		if(pts>max){
  			ganador=i+1;
            max=pts;
  		}
  		printf(" ____________________|________________________\n");
  		if (turn-1==i){
  			printf("|-----Jugador %i-----|----------%i----------|\n",i+1,pts);	//es el turno de este jugador
  		}
  		else{
  			printf("|-----Jugador %i-----|----------%i----------|\n",i+1,pts);
  		}
  	}
	  printf("Ganador Jugador %i!!\n",ganador);
  }
	static int var;
  var = 1;
	return(&var);
}

int * inicio_1_svc(datosiniciales * n,struct svc_req *cliente){
	printf("--------------COMIENZO DEL JUEGO----------------\n");
	printf("--------Usted es el Jugador %i, suerte!---------\n",(n->nroJugador)+1);
  cantJugadores=n->cantidadJugadores;
	static int var;
  var = 1;
	return(&var);
}
