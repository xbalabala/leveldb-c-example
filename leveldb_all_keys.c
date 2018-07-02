#include <leveldb/c.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int
main(int argc, char* argv[]){
  leveldb_t *db;
  leveldb_options_t *options;
  leveldb_readoptions_t *roptions;
  char *err = NULL;

  char* db_path = argv[1];
  if (db_path == NULL) {
    printf("usage: %s [db-path]\n", argv[0]);
    return 1;
  }

  options = leveldb_options_create();
  roptions = leveldb_readoptions_create();

  // open
  db = leveldb_open(options, db_path, &err);
  if (err != NULL) {
    fprintf(stderr, "Open fail.\n");
    return 1;
  }

  // iterate
  leveldb_iterator_t* iter = leveldb_create_iterator(db, roptions);
  leveldb_iter_seek_to_first(iter);

  size_t klen, vlen;
  const char *k, *v;
  for (int i=0; i<100; i++) {
    leveldb_iter_next(iter);
    k = leveldb_iter_key(iter, &klen);
    v = leveldb_iter_value(iter, &vlen);

    printf("key: %.*s, len: %ld, strlen: %ld\n", (int)klen, k, klen, strlen(k));
    printf("val: %.*s, len: %ld, strlen: %ld\n", (int)vlen, v, vlen, strlen(v));
  }

  // close
  leveldb_close(db);

  return 0;
}
