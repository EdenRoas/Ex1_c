CC = gcc
AR = ar -rcs
FLAGS = -Wall -g
OBJECT_O = basicClassification.o advancedClassificationRecursion.o main.o
MATH = -lm

all: loops loopd recursives recursived mains maindloop maindrec

loops: libclassloops.a 

loopd: libclassloops.so

libclassloops.a: basicClassification.o advancedClassificationLoop.o 
		$(AR) libclassloops.a basicClassification.o advancedClassificationLoop.o

libclassloops.so: basicClassification.o advancedClassificationLoop.o 
		$(CC) -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o

recursives: libclassrec.a

recursived: libclassrec.so

libclassrec.a: $(OBJECT_O) 
		$(AR) libclassrec.a $(OBJECT_O) 

libclassrec.so: $(OBJECT_O) 
		$(CC) -shared -o libclassrec.so $(OBJECT_O) 
		
mains: main.o libclassrec.a
	$(CC) $(FLAGS) -o mains main.o libclassrec.a $(MATH)

maindloop: main.o 
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so $(MATH)

maindrec: main.o 
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so $(MATH)


main.o: main.c NumClass.h
		$(CC) $(FLAGS) -c main.c

basicClassification.o: basicClassification.c NumClass.h
		$(CC) $(FLAGS) -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
		$(CC) $(FLAGS) -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
		$(CC) $(FLAGS) -c advancedClassificationRecursion.c $(MATH)

.PHONY: clean all

Clean:
		rm -f *.o *.a *.so mains maindloop maindrec looped recursive loops recursived