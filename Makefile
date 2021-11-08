.PHONY: all loops loopd recursives recursived clean
CC = gcc
AR = ar
loopFiles = basicClassification.o advancedClassificationLoop.o
recFiles = basicClassification.o advancedClassificationRecursion.o
FLAGS= -Wall -g

all: libclassloops.a libclassrec.a libclassloops.so libclassrec.so mains maindloop maindrec
loops: libclassloops.a
loopd: libclassloops.so
recursives:libclassrec.a
recursived:libclassrec.so

mains: main.o libclassrec.a
	$(CC) $(FLAGS)  -o mains main.o libclassrec.a -lm
maindloop: main.o libclassloops.so
	$(CC) $(FLAGS)  -o maindloop main.o ./libclassloops.so -lm
maindrec: main.o libclassrec.so 
	$(CC) $(FLAGS)  -o maindrec main.o ./libclassrec.so -lm
libclassloops.a: $(loopFiles)
	$(AR) -rcs libclassloops.a $(loopFiles)
libclassrec.a: $(recFiles)
	$(AR) -rcs libclassrec.a $(recFiles)
libclassloops.so: $(loopFiles)
	$(CC) -shared -o libclassloops.so $(loopFiles) -lm 
libclassrec.so: $(recFiles)
	$(CC) -shared -o libclassrec.so $(recFiles) -lm
basicClassification.o: basicClassification.c NumClass.h 
	$(CC) $(FLAGS) -c basicClassification.c -lm
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c -lm
main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c
clean:
	rm -f *.o *.a *.so maindloop maindrec mains