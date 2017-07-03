
SQLITE_DB_LIB=sqlite_db.a
SQLITE_DB_SRCS=$(wildcard ../../src/sqlite-db/*.cpp)

all: $(SQLITE_DB_LIB)

$(SQLITE_DB_LIB): $(SQLITE_DB_SRCS) 
	$(CXX) -c -std=c++14 -c ${SQLITE_DB_SRCS} 
	rm -f $(SQLITE_DB_LIB)
	ar vq $(SQLITE_DB_LIB) *.o

clean:
	rm -f *.o sqlite_db.a