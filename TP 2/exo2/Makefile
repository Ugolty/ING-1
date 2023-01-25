#Création de l'exécutable
exe: exo2.o
	gcc exo2.o -o exe

#Compilation du fichier exo2.c
exo2.o: exo2.c
	gcc -c exo2.c -o exo2.o -Wall

#Suppression des fichiers .o et de l'exécutable
clean:
	rm -f *.o exe

#Création et mise à jour de la documentation Doxygen, et son ouverture sur Firefox
doxy:
	doxygen Doxyfile
	firefox html/index.html