help:
	@echo "Formato de uso:"
	@echo "# make debian : Compilar para sistemas operativos Debian"
	@echo "# make fedora : Compilar para sistemas operativos Fedora"
	@echo "# make clean : Eliminar archivos compilados, dejando los fuentes"
.PHONY: help

fedora:
	make all PARAM="-ltirpc -I/usr/include/tirpc"

debian:
	make all PARAM=""

.PHONY: all

all: jugador coordinador
.PHONY: clean
clean:
	rm jugador coordinador generala.h generala_clnt.c generala_svc.c generala_xdr.c
jugador: jugador.c generala_svc.c generala.h generala_xdr.c
	gcc ${PARAM} -lnsl -o jugador jugador.c generala_svc.c generala_xdr.c
coordinador: coordinador.c generala_clnt.c generala_xdr.c generala.h
	gcc ${PARAM} -lnsl -o coordinador coordinador.c generala_clnt.c generala_xdr.c
generala.h generala_clnt.c generala_svc.c generala_xdr.c: generala.x
	rpcgen generala.x
