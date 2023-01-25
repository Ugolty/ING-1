#Création de l'exécutable
exe: exo6.o
	gcc exo6.o -o exe

#Compilation du fichier exo6.c
exo6.o: exo6.c
	gcc -c exo6.c -o exo6.o -Wall

#Suppression des fichiers .o et de l'exécutable
clean:
	rm -f *.o exe

#Création et mise à jour de la documentation Doxygen, et son ouverture sur Firefox
doxy:
	doxygen Doxyfile
	firefox html/index.html