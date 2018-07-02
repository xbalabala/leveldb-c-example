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
  db = leveldb_open(options, db_path, &err);
  if (err != NULL) {
    fprintf(stderr, "Open fail.\n");
    return 1;
  }

  // compact all
  leveldb_compact_range(db, NULL, 0, NULL, 0);

  // close
  leveldb_close(db);

  return 0;
}
