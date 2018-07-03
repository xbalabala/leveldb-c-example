#include <leveldb/c.h>
#include <stdio.h>
#include <string.h>

int main()
{
  leveldb_t *db;
  leveldb_options_t *options;
  // leveldb_readoptions_t *roptions;
  leveldb_writeoptions_t *woptions;
  char *err = NULL;
  /* char *read; */
  /* size_t read_len; */

  // open
  options = leveldb_options_create();
  leveldb_options_set_create_if_missing(options, 1);
  db = leveldb_open(options, "testdb", &err);
  if (err != NULL) {
    fprintf(stderr, "Open fail.\n");
    return (1);
  }

  woptions = leveldb_writeoptions_create();
  // roptions = leveldb_readoptions_create();

  int v_size = 10000;
  char k[20], v[20];
  for (int i = 0; i < v_size; i++)
  {
    snprintf(k, 20, "key%d", i);
    snprintf(v, 20, "value%d", i);

    // printf("key: %s, len: %ld, value: %s, len: %ld\n", k, strlen(k), v, strlen(v));

    // write
    leveldb_put(db, woptions, k, strlen(k), v, strlen(v), &err);
    if (err != NULL) {
      fprintf(stderr, "Write fail.\n");
      return (1);
    }

    // read
    /*
    read = leveldb_get(db, roptions, "key", 3, &read_len, &err);
    if (err != NULL) {
      fprintf(stderr, "Read fail.\n");
      return(1);
    }
    printf("key: %s\n", read);
    */

    // delete
    /* leveldb_delete(db, woptions, k, strlen(k), &err); */
    /* if (err != NULL) { */
    /*   fprintf(stderr, "Delete fail.\n"); */
    /*   return (1); */
    /* } */
  }

  // close
  leveldb_close(db);

  // destroy
  /*
  leveldb_destroy_db(options, "testdb", &err);
  if (err != NULL) {
    fprintf(stderr, "Destroy fail.\n");
    return(1);
  }
  */

  return (0);
}