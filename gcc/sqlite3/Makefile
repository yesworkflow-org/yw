
SQLITE3_SRC=../../src/sqlite-3.19.3/

all: sqlite3.a

sqlite3.a: 
	$(CC) -c -g3 ${SQLITE3_SRC}/sqlite3.c 
	ar vq sqlite3.a sqlite3.o

clean:
	rm -f sqlite3.o sqlite3.a