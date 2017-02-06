output:../obj/main.o
	gcc -g ../obj/*.o -o output -lpthread
	mv output ../bin/
	
../obj/main.o:../src/main.c ../include/header.h
	gcc -g -I../include/ -c -Wall ../src/main.c
	mv main.o ../obj/
	
clean:
	rm ../obj/*.o
	rm ../bin/*
