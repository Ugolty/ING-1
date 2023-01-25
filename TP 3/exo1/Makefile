#Création de l'exécutable
exe: main.o
	gcc main.o -o exe

#Compilation du fichier main.c
main.o: main.c
	gcc -c main.c -o main.o -Wall

#Suppression des fichiers .o et de l'exécutable
clean:
	rm -f *.o exe

#Création et mise à jour de la documentation Doxygen, et son ouverture sur Firefox
doxy:
	doxygen Doxyfile
	firefox html/index.html