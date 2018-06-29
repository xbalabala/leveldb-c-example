#include <leveldb/c.h>
#include <stdio.h>
#include <unistd.h>

int
main(int argc, char* argv[]){
  leveldb_t *db;
  leveldb_options_t *options;
  char *err = NULL;

  char* db_path = argv[1];
  if (db_path == NULL) {
    printf("usage: %s [db-path]\n", argv[0]);
    return 1;
  }

  // open
  options = leveldb_options_create();
  leveldb_options_set_create_if_missing(options, 1);
  db = leveldb_open(options, db_path, &err);
  if (err != NULL) {
    fprintf(stderr, "Open fail.\n");
    return 1;
  }

  leveldb_compact_range(db, NULL, 0, NULL, 0);

  return 0;
}
