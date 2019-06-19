/*
  Mano: arreglo de 5 enteros usados para informar los dados tirados/elegidos.
  puntajes: Envia el puntaje actual de los jugadores y el turno del jugador actual.
  mipuntaje: Valores de cada categoria de un jugador (se envia un -1 si la categoria esta tachada).
  inicio: El programa jugador recibe la cantidad de jugadores y muestra al usuario un mensaje de bienvenida.
*/
const MAXJUGADORES = 6;
struct manostruct {
  int dados[5];
};
struct puntajesstruct {
  int puntos[MAXJUGADORES];
  int turnojugador;
};
struct mipuntajestruct {
  int categorias[11];
};
struct datosinicialesstruct {
  int cantidadJugadores;
  int nroJugador;
};
typedef struct manostruct mano;
typedef struct puntajesstruct puntajes;
typedef struct mipuntajestruct mipuntaje;
typedef struct datosinicialesstruct datosiniciales;
program GENERALA {
  version VER1 {
    int mostrardados(mano) = 1;
    mano elegirdados(mano) = 2;
    int mostrarpuntajes(puntajes) = 3;
    int mostrarmipuntaje(mipuntaje) = 4;
    int elegirmano(mipuntaje) = 5;
    int fin(puntajes) = 6;
    int inicio(datosiniciales) = 7;
  } = 1;
} = 0x200F0B01;
