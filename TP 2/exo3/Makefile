#Création de l'exécutable
exe: exo3.o
	gcc exo3.o -o exe

#Compilation du fichier exo3.c
exo3.o: exo3.c
	gcc -c exo3.c -o exo3.o -Wall

#Suppression des fichiers .o et de l'exécutable
clean:
	rm -f *.o exe

#Création et mise à jour de la documentation Doxygen, et son ouverture sur Firefox
doxy:
	doxygen Doxyfile
	firefox html/index.html