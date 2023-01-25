exe: HelloWorld.o
	gcc HelloWorld.o -o exe

HelloWorld.o: HelloWorld.c
	gcc -c HelloWorld.c -o HelloWorld.o -Wall

clean:
	rm -f *.o exe

doxy:
	doxygen Doxyfile
	firefox html/index.html