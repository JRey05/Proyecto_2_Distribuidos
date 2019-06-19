#include <stdio.h>
#include <stdlib.h>
#include "generala.h"
#include <rpc/rpc.h>
#include <time.h>

struct jugador {
  CLIENT *clnt;
  mipuntaje puntaje;
};

int main(int argc,char *argv[]) {
  char *server;                               // Variable que almacena los ip de entrada
  int cantJugadores = argc - 1;               // Variable que almacena la cantidad de jugadores pasados por parametro
  struct jugador jugadores[cantJugadores];    // Arreglo de todos los jugadores.
  mano dados;                                 //
  mano jugada;
  int i,j;                                      // Variable de control
  int opcion;                                 // Almacenara la eleccion que haga el jugador
  mipuntaje puntajeTurno;                     // Enviara los puntos que puede optar el jugador
  puntajes tablaPuntos;                       // Almacena los puntos de todos los jugadores y de quien es el turno.
  srandom(time(NULL));
  datosiniciales ini;
  if (cantJugadores <= 1) {
    printf("Error en el llamado: \n \t coordinador ip1 ip2 ... Maximo 6 jugadores.\n");
    exit(1);
  }
  for (i=0; i<cantJugadores; i++){
    server = argv[i+1];
    jugadores[i].clnt = clnt_create(server,GENERALA, VER1, "TCP");
    if(jugadores[i].clnt == (CLIENT *) NULL) {
      printf("Error al conectarse al jugador \"%s\"\n",server);
      exit(1);
    }
    tablaPuntos.puntos[i]=0;                // Inicializa la tabla de puntos general.
    for(j=0;j<11;j++){
      jugadores[i].puntaje.categorias[j]=0;   //Inicializa el puntaje de cada categoria de cada jugador.
    }
  }
  // Se establecio conexion con todos los jugadores.
  // Se envia la bienvenida y la cantidad de usuarios
  ini.cantidadJugadores=cantJugadores;
  for (i=0;i<cantJugadores;i++){
    ini.nroJugador=j+1;
    inicio_1(&ini,jugadores[i].clnt);
  }
  // Se inicia el juego, se envian los
  int ronda,jugador,tiros,tirada;
  for (ronda=0;ronda<11;ronda++){   // Se juegan 11 rondas.
    for (jugador=0; jugador<cantJugadores; jugador++){  // Se juega el turno de cada jugador.
      // Se envia la tabla con el puntaje de cada jugador sumado a que jugador le toca jugar.
      tablaPuntos.turnojugador=jugador;
      for(j=0;j<cantJugadores;j++){
        mostrarpuntajes_1(&tablaPuntos,jugadores[j].clnt);
      }
      mostrarmipuntaje_1(&jugadores[jugador].puntaje,jugadores[jugador].clnt);
      tiros = 5;  //la primera vez se tiran los 5 dados, luego depende de lo que decida el jugador.
      for (tirada=0; tirada<3 || tiros==0; tirada++){ // Se hacen 3 tiradas o hasta que el jugador haya bloqueado los 5 dados.
        for(i=0;i<tiros;i++){
          dados.dados[tiros-i]=(random()%6)+1; //se almacenan de atras para adelante para reemplazar los 0 que indican que un jugador no bloqueo
        }
        for(j=0;j<cantJugadores;j++){
          // Se envian los dados obtenidos a todos los jugadores.
          mostrardados_1(&dados,jugadores[j].clnt);
        }
        dados = *elegirdados_1(&dados,jugadores[jugador].clnt);
        // Ver cuantos dados eligió y cuantos tiene que tirar otra vez;
        tiros = 5;
        for (j=0;j<5;j++) {
          if (dados.dados[j]!=0)
            tiros--;
        }
      }
      // Contar la cantidad de datos con cada numero.
      // Inicializamos una estructura mano con 0 en los 6 casilleros.
      for (i=0; i<5; i++){
        jugada.dados[i]=0;
      }
      // Se le asigna a cada posicion del arreglo la cantidad de dados con ese numero.
      for (i=0; i<5; i++){
        jugada.dados[dados.dados[i]-1]++;
      }
      //Contar la cantidad de puntos posibles.
      // 1 - 6
      for (i=0;i<6;i++) {
        if(jugadores[jugador].puntaje.categorias[i]!=0)   //Verificar que la categoria no se haya jugado.
          puntajeTurno.categorias[i]=jugadores[jugador].puntaje.categorias[i];
        else
          puntajeTurno.categorias[i]=(i+1)*jugada.dados[i];
      }
      // Resto de las categorias
      // Primero se calcula si consigue alguno de los valores utiles y despues si la categoria ya se habia jugado.
      // Escalera.
      if(jugada.dados[1] && jugada.dados[2] && jugada.dados[3] && jugada.dados[4] && (jugada.dados[0] || jugada.dados[5])) {
        puntajeTurno.categorias[6] = 20;
      }

      // Full
      if((jugada.dados[0]==3 || jugada.dados[1]==3 || jugada.dados[2]==3 || jugada.dados[3]==3 || jugada.dados[4]==3 || jugada.dados[5]==3) && (jugada.dados[0]==2 || jugada.dados[1]==2 || jugada.dados[2]==2 || jugada.dados[3]==2 || jugada.dados[4]==2 || jugada.dados[5]==2)) {
        puntajeTurno.categorias[7] = 30;
      }

      // Poker
      if(jugada.dados[0]==4 || jugada.dados[1]==4 || jugada.dados[2]==4 || jugada.dados[3]==4 || jugada.dados[4]==4 || jugada.dados[5]==4) {
        puntajeTurno.categorias[8] = 40;
      }

      // Generala
      if(jugada.dados[0]==5 || jugada.dados[1]==5 || jugada.dados[2]==5 || jugada.dados[3]==5 || jugada.dados[4]==5 || jugada.dados[5]==5)
        puntajeTurno.categorias[9] = 50;

      // Generala doble
      if((jugada.dados[0]==5 || jugada.dados[1]==5 || jugada.dados[2]==5 || jugada.dados[3]==5 || jugada.dados[4]==5 || jugada.dados[5]==5) && jugadores[jugador].puntaje.categorias[9]!=0 && jugadores[jugador].puntaje.categorias[9]!=-1)
        puntajeTurno.categorias[10] = 100;

      // Pensar un poco mejor esto, esta enviando -1 si la categoria (1-6) ya fue jugada.
      for (i=6;i<11;i++) {
        if(jugadores[jugador].puntaje.categorias[i]!=0)
          puntajeTurno.categorias[i]=-1;
      }
      opcion = *elegirmano_1(&puntajeTurno,jugadores[jugador].clnt);
      jugadores[jugador].puntaje.categorias[opcion-1]=puntajeTurno.categorias[opcion-1];
      if(puntajeTurno.categorias[opcion-1]!=-1)
        tablaPuntos.puntos[jugador]+=puntajeTurno.categorias[opcion-1];
    }
  }
}
