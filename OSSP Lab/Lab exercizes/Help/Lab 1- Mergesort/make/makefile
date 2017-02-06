###########################################################################################################makefile#####################################################################################################
../bin/list: ../obj/mergesort.o ../obj/main.o 
	gcc -g -o ../bin/list   ../obj/main.o ../obj/mergesort.o
	mv list ../bin/
../obj/mergesort.o:../src/mergesort.c
	gcc -g -c -I../include/ -Wall ../src/mergesort.c
	mv mergesort.o ../obj/
../obj/main.o:../src/main.c ../include/header.h
	gcc -g -c -I../include/ -Wall ../src/main.c
	mv main.o ../obj/
clean :
	rm ../obj/*.o
	rm ../bin/list
