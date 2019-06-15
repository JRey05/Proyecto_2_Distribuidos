#include <stdio.h>
#include <stdlib.h>
#include "generala.h"
#include <rpc/rpc.h>

int main(int argc,char *argv[]) {
  char *server;
  int cantJugadores = argc - 1;
  CLIENT *jugadores[cantJugadores];
  int i;
  if (cantJugadores <= 1) {
    printf("Error en el llamado: \n \t coordinador ip1 ip2 ... Maximo 6 jugadores.\n");
  }
  for (i=0; i<cantJugadores; i++){
    server = argv[i+1];
    jugadores[i] = clnt_create(server,GENERALA, VER1, "TCP");
    if(jugadores[i] == (CLIENT *) NULL) {
      printf("Error al conectarse al jugador \"%s\"\n",server);
      exit(1);
    }
  }

}
