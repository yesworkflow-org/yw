
YW_DB_LIB=libywdb.a
YW_DB_SRCS=$(wildcard ../../src/yw-db/*.cpp)

YW_REPO_ROOT = ../..
YW_SRC_DIRS  = $(YW_REPO_ROOT)/src

CPPFLAGS = -I$(YW_SRC_DIRS)/sqlite-db


all: $(YW_DB_LIB)

$(YW_DB_LIB): $(YW_DB_SRCS) 
	$(CXX) -c -g3 -std=c++14 -c ${YW_DB_SRCS} $(CPPFLAGS)
	rm -f $(YW_DB_LIB)
	ar vq $(YW_DB_LIB) *.o

tidy : $(YW_DB_LIB)
	rm -f *.o

clean:
	rm -f *.o *.a