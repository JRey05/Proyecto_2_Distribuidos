# Proyecto_2_Distribuidos
Generala:
Cada jugador levanta un proceso servidor y espera su turno.
El coordinador levanta el proceso cliente con las ips de los jugadores leidas como parametro.
Por cada turno (de cada jugador)
1. El coordinador simula los dados.
2. El coordinador envía los valores a todos los jugadores (todos con el mismo metodo salvo el que tiene el turno).
3. El jugador determina que dados volver a jugar o si se planta.
4. Cuando se planta el coordinador envia las opciones a elegir (puede que tambien se envien junto con los dados y no recien ahora)
5. El jugador elige que puntos toma.
6. El coordinador envia la tabla actualizada a todos los jugadores y vuelve a comenzar.
