all: libchtroll.so demo

libchtroll.so: chtroll.o
	gcc -shared -o libchtroll.so chtroll.o

chtroll.o: chtroll.c
	gcc -Wall -fPIC -c chtroll.c

clean:
	rm -fr libchtroll.so chtroll.o demo.o demo testing

demo.o: demo.c
	gcc -Wall -c demo.c

demo: demo.o
	gcc -o demo demo.o
