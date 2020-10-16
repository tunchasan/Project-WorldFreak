Objects :=  ./lib/BST.o ./lib/HashTable.o ./lib/Node.o
compile:
	gcc -I ./include/ -o ./lib/BST.o -c ./src/BST.c
	gcc -I ./include/ -o ./lib/HashTable.o -c ./src/HashTable.c
	gcc -I ./include/ -o ./lib/Node.o -c ./src/Node.c

	gcc -I ./include/ -o ./bin/wordfreak $(Objects) ./src/wordfreak.c