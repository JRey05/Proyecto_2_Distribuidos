/*
  Mano: arreglo de 5 enteros usados para informar los dados tirados/elegidos.
  puntajes: Envia el puntaje actual de los jugadores.
  mipuntaje: Valores de cada categoria de un jugador (se envia un -1 si la categoria esta tachada).
*/
const MAXJUGADORES = 6;
struct mano {
  int dados[5];
};
struct puntajes {
  int puntos[MAXJUGADORES];
};
struct mipuntaje {
  int categorias[11];
};

program GENERALA {
  version VER1 {
    void mostrardados(mano) = 1;
    mano elegirdados(mano) = 2;
    void mostrarpuntajes(puntajes) = 3;
    void mostrarmipuntaje(mipuntaje) = 4;
    int elegirmano(mipuntaje) = 5;
    void fin(puntajes) = 6;
  } = 1;
} = 0x200F0B01;
