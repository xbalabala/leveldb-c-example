LevelDB C example
===========================

This is a simple example to demonstrate how you use [LevelDB](http://code.google.com/p/leveldb) with C.


Install
---------------------------

Install LevelDB either by yourself or with a package manager. I recommend [Homebrew](http://mxcl.github.com/homebrew/) for OS X. Please note that LevelDB requires [Snappy](http://code.google.com/p/snappy/).


build from source:

    # git clone https://github.com/google/leveldb, follow readme build
    cp --preserve=links libleveldb.a /usr/local/lib
    cp -r include/leveldb /usr/local/include/

Compile
---------------------------
Compile with GCC:

    gcc leveldb_example.c -Wall -lleveldb -lstdc++ -lpthread


License
---------------------------
[MIT](http://en.wikipedia.org/wiki/MIT_License)
