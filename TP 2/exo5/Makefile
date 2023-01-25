#Création de l'exécutable
exe: exo5.o
	gcc exo5.o -o exe

#Compilation du fichier exo5.c
exo5.o: exo5.c
	gcc -c exo5.c -o exo5.o -Wall

#Suppression des fichiers .o et de l'exécutable
clean:
	rm -f *.o exe

#Création et mise à jour de la documentation Doxygen, et son ouverture sur Firefox
doxy:
	doxygen Doxyfile
	firefox html/index.html