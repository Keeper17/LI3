SGV: src/control/control.c produtos.o clientes.o faturacao.o filial.o view.o listas.o
	gcc -ansi -o SGV src/control/control.c produtos.o clientes.o faturacao.o filial.o view.o listas.o

view.o : src/view/view.c include/view/view.h
	gcc -ansi -c src/view/view.c

produtos.o: src/model/produtos.c include/model/produtos.h
	gcc -ansi -c src/model/produtos.c

clientes.o: src/model/clientes.c include/model/clientes.h
	gcc -ansi -c src/model/clientes.c

faturacao.o: src/model/faturacao.c include/model/faturacao.h
	gcc -ansi -c src/model/faturacao.c

filial.o: src/model/filial.c include/model/filial.h
	gcc -ansi -c src/model/filial.c

bool.o: src/model/bool.c include/model/bool.h
	gcc -ansi -c src/model/bool.c

listas.o : src/model/listas.c include/model/listas.h
	gcc -ansi -c src/model/listas.c

clean:
	rm *.o
	rm SGV
