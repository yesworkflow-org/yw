
YW_PARSE_LIB=libywparse.a

YW_REPO_ROOT = ../..
YW_SRC_DIRS  = $(YW_REPO_ROOT)/src
YW_PARSE_SRCS=$(wildcard $(YW_SRC_DIRS)/yw-parse/*.cpp)

CPPFLAGS = -I$(ANTLR4_RUNTIME_SRC) -Wno-attributes -DANTLR4CPP_STATIC

all: $(YW_PARSE_LIB)

$(YW_PARSE_LIB): $(YW_PARSE_SRCS) 
	$(CXX) -c -g3 -std=c++14 -c ${YW_PARSE_SRCS} $(CPPFLAGS)
	rm -f $(YW_PARSE_LIB)
	ar vq $(YW_PARSE_LIB) *.o

tidy : $(YW_PARSE_LIB)
	rm -f *.o

clean:
	rm -f *.o *.a