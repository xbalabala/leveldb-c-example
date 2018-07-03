INIT=$(shell ./init.sh)
CURRENT_PATH=$(PWD)

FILES = leveldb_example leveldb_compact leveldb_iterate
all:
	$(foreach var, $(FILES), \
		gcc $(var).c -o bin/$(var) -Wall -L$(CURRENT_PATH)/basho.leveldb -I$(CURRENT_PATH)/basho.leveldb/include \
		-lleveldb -lstdc++ -lpthread -lm -std=c99;)
