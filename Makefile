all: libchtroll.so demo fdemo libfchtroll.so 

libchtroll.so: chtroll.o
	gcc -shared -o libchtroll.so chtroll.o

chtroll.o: chtroll.c
	gcc -Wall -fPIC -c chtroll.c

libfchtroll.so: fchtroll.o
	gcc -shared -o libfchtroll.so fchtroll.o

fchtroll.o: fchtroll.c
	gcc -Wall -fPIC -c fchtroll.c

clean:
	rm -fr libchtroll.so chtroll.o demo.o demo testing fdemo.o fdemo libfchtroll.so fchtroll.o

demo.o: demo.c
	gcc -Wall -c demo.c

demo: demo.o
	gcc -o demo demo.o

fdemo.o: fdemo.c
	gcc -Wall -c fdemo.c

fdemo: fdemo.o
	gcc -o fdemo fdemo.o

