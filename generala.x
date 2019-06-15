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
typedef struct manostruct mano;
typedef struct puntajesstruct puntajes;
typedef struct mipuntajestruct mipuntaje;
program GENERALA {
  version VER1 {
    void mostrardados(mano) = 1;
    mano elegirdados(mano) = 2;
    void mostrarpuntajes(puntajes) = 3;
    void mostrarmipuntaje(mipuntaje) = 4;
    int elegirmano(mipuntaje) = 5;
    void fin(puntajes) = 6;
    void inicio(int) = 7;
  } = 1;
} = 0x200F0B01;
