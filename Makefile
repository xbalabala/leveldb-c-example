all:
	gcc leveldb_example.c -o bin/example -Wall -lleveldb -lstdc++ -lpthread -std=c99
	gcc leveldb_compact.c -o bin/compact -Wall -lleveldb -lstdc++ -lpthread -std=c99
