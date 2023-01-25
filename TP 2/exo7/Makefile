#Création de l'exécutable
exe: exo7.o
	gcc exo7.o -o exe

#Compilation du fichier exo7.c
exo7.o: exo7.c
	gcc -c exo7.c -o exo7.o -Wall

#Suppression des fichiers .o et de l'exécutable
clean:
	rm -f *.o exe

#Création et mise à jour de la documentation Doxygen, et son ouverture sur Firefox
doxy:
	doxygen Doxyfile
	firefox html/index.html