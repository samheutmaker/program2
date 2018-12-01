run: build link
	./Jesse_Dahl_Sam_Heutmaker_Program2

build: filter types print sort
	gcc -c Jesse_Dahl_Sam_Heutmaker_Program2.c
	
link: 
	gcc types.o sort.o filter.o print.o Jesse_Dahl_Sam_Heutmaker_Program2.o -o Jesse_Dahl_Sam_Heutmaker_Program2

filter:
	gcc -c filter.c

types:
	gcc -c types.c

print:
	gcc -c print.c

sort:
	gcc -c sort.c


