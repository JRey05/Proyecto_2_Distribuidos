#include <stdio.h>
#include <stdlib.h>
#include "generala.h"
#include <rpc/rpc.h>
#include <time.h>

struct jugador {
  mano dados;
  mipuntaje puntaje;
}

int main(int argc,char *argv[]) {
  char *server;
  int cantJugadores = argc - 1;
  CLIENT *jugadores[cantJugadores];
  mano dados;
  int i;
  srandom(time(NULL));
  if (cantJugadores <= 1) {
    printf("Error en el llamado: \n \t coordinador ip1 ip2 ... Maximo 6 jugadores.\n");
    exit(1);
  }
  for (i=0; i<cantJugadores; i++){
    server = argv[i+1];
    jugadores[i] = clnt_create(server,GENERALA, VER1, "TCP");
    if(jugadores[i] == (CLIENT *) NULL) {
      printf("Error al conectarse al jugador \"%s\"\n",server);
      exit(1);
    }
  }
  // Se establecio conexion con todos los jugadores.
  // Se envia la bienvenida y la cantidad de usuarios
  for (i=0;i<cantJugadores;i++){
    inicio_1(&cantJugadores,jugadores[i]);
  }
  // Se inicia el juego, se envian los
  int ronda,jugador,j,tiros,tirada;
  for (ronda=0;ronda<11;ronda++){   // Se juegan 11 rondas.
    for (jugador=0; jugador>cantJugadores; jugador++){  // Se juega el turno de cada jugador.
      tiros = 5;  //la primera vez se tiran los 5 dados, luego depende de lo que decida el jugador.
      for (tirada=0; tirada<3 || tiros==0; tirada++){ // Se hacen 3 tiradas o hasta que el jugador haya bloqueado los 5 dados.
        for(i=0;i<tiros;i++){
          dados.dados[tiros-i]=(random()%6)+1; //se almacenan de atras para adelante para reemplazar los 0 que indican que un jugador no bloqueo
        }
        for(j=0;j<cantJugadores;j++){
          // Se envian los dados obtenidos a todos los jugadores.
          if(j!=jugador)  // Caso especial para el jugador que esta en su turno
            mostrardados_1(&dados,jugadores[j]);
          else
            dados = *elegirdados_1(&dados,jugadores[j]);
        }
        // Ver cuantos dados eligió y cuantos tiene que tirar otra vez;
        tiros = 5;
        for (j=0;j<5;j++) {
          if (dados.dados[j]!=0)
            tiros--;
        }
      }
      // Armar la estructura para enviar las opciones de puntos al jugador.

    }
  }
}
