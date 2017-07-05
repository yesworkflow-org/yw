
SQLITE_DB_LIB=libsqlitedb.a
SQLITE_DB_SRCS=$(wildcard ../../src/sqlite-db/*.cpp)

all: $(SQLITE_DB_LIB)

$(SQLITE_DB_LIB): $(SQLITE_DB_SRCS) 
	$(CXX) -c -g3 -std=c++14 -c ${SQLITE_DB_SRCS} 
	rm -f $(SQLITE_DB_LIB)
	ar vq $(SQLITE_DB_LIB) *.o

tidy : $(SQLITE_DB_LIB)
	rm -f *.o

clean:
	rm -f *.o *.a