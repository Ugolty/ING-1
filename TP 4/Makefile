#Création de l'exécutable
exe: main.o approxPi.o approxRacineDe2.o
	gcc main.o approxPi.o approxRacineDe2.o -o exe -lm

#Compilation du fichier main.c
main.o: main.c
	gcc -c main.c -o main.o -Wall

#Compilaton du fichier approxPi.c
approxPi.o: approxPi.c
	gcc -c approxPi.c -o approxPi.o -Wall

#Compilation du fichier approxRacineDe2.c
approxRacineDe2.o: approxRacineDe2.c
	gcc -c approxRacineDe2.c -o approxRacineDe2.o -Wall

#Suppression des fichiers .o et de l'exécutable
clean:
	rm -f *.o exe

#Création et mise à jour de la documentation Doxygen, et son ouverture sur Firefox
doxy:
	doxygen Doxyfile
	firefox html/index.html