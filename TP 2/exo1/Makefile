#Création de l'exécutable
exe: exo1.o
	gcc exo1.o -o exe

#Compilation du fichier exo1.c
exo1.o: exo1.c
	gcc -c exo1.c -o exo1.o -Wall

#Suppression des fichiers .o et de l'exécutable
clean:
	rm -f *.o exe

#Création et mise à jour de la documentation Doxygen, et son ouverture sur Firefox
doxy:
	doxygen Doxyfile
	firefox html/index.html