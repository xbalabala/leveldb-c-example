INIT=$(shell ./init.sh)
CURRENT_PATH=$(PWD)

FILES = leveldb_example leveldb_compact leveldb_iterate
all:
	$(foreach var, $(FILES), \
		gcc $(var).c -o bin/$(var) -Wall -L$(CURRENT_PATH)/../leveldb -I$(CURRENT_PATH)/../leveldb/include \
		-lleveldb -lsnappy -lstdc++ -lpthread -lm -std=c99;)
