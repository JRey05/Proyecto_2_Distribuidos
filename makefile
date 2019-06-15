.PHONY: all
all: jugador coordinador
.PHONY: clean
clean:
	rm jugador coordinador generala.h generala_clnt.c generala_svc.c generala_xdr.c
jugador: jugador.c generala_svc.c generala.h generala_xdr.c
	gcc -lnsl -o jugador jugador.c generala_svc.c generala_xdr.c
coordinador: coordinador.c generala_clnt.c generala_xdr.c generala.h
	gcc -lnsl -o coordinador coordinador.c generala_clnt.c generala_xdr.c
generala.h generala_clnt.c generala_svc.c generala_xdr.c: generala.x
	rpcgen generala.x
