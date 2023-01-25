#Création de l'exécutable
exe: exo4.o
	gcc exo4.o -o exe

#Compilation du fichier exo4.c
exo4.o: exo4.c
	gcc -c exo4.c -o exo4.o -Wall

#Suppression des fichiers .o et de l'exécutable
clean:
	rm -f *.o exe

#Création et mise à jour de la documentation Doxygen, et son ouverture sur Firefox
doxy:
	doxygen Doxyfile
	firefox html/index.html