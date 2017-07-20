
YW_EXTRACT_LIB=libywextract.a

YW_REPO_ROOT = ../..
YW_SRC_DIRS  = $(YW_REPO_ROOT)/src
YW_EXTRACT_SRCS=$(wildcard $(YW_SRC_DIRS)/yw-extract/*.cpp)

CPPFLAGS  = -I$(ANTLR4_RUNTIME_SRC) -Wno-attributes -DANTLR4CPP_STATIC
CPPFLAGS += -I$(YW_SRC_DIRS)/sqlite-db
CPPFLAGS += -I$(YW_SRC_DIRS)/yw-db
CPPFLAGS += -I$(YW_SRC_DIRS)/yw-parse

all: $(YW_EXTRACT_LIB)

$(YW_EXTRACT_LIB): $(YW_EXTRACT_SRCS) 
	$(CXX) -c -g3 -std=c++14 -c ${YW_EXTRACT_SRCS} $(CPPFLAGS)
	rm -f $(YW_EXTRACT_LIB)
	ar vq $(YW_EXTRACT_LIB) *.o

tidy : $(YW_EXTRACT_LIB)
	rm -f *.o

clean:
	rm -f *.o *.a