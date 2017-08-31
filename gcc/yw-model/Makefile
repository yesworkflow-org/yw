
YW_MODEL_LIB=libywmodel.a

YW_REPO_ROOT = ../..
YW_SRC_DIRS  = $(YW_REPO_ROOT)/src
YW_MODEL_SRCS=$(wildcard $(YW_SRC_DIRS)/yw-model/*.cpp)

CPPFLAGS  = -I$(ANTLR4_RUNTIME_SRC) -Wno-attributes -DANTLR4CPP_STATIC
CPPFLAGS += -I$(YW_SRC_DIRS)/yw-types
CPPFLAGS += -I$(YW_SRC_DIRS)/sqlite-db
CPPFLAGS += -I$(YW_SRC_DIRS)/yw-db
CPPFLAGS += -I$(YW_SRC_DIRS)/yw-parse
CPPFLAGS += -I$(YW_SRC_DIRS)/yw-extract
CPPFLAGS += -I$(YW_SRC_DIRS)/yw-model

all: $(YW_MODEL_LIB)

$(YW_MODEL_LIB): $(YW_MODEL_SRCS) 
	$(CXX) -c -g3 -std=c++14 -c ${YW_MODEL_SRCS} $(CPPFLAGS)
	rm -f $(YW_MODEL_LIB)
	ar vq $(YW_MODEL_LIB) *.o

tidy : $(YW_MODEL_LIB)
	rm -f *.o

clean:
	rm -f *.o *.a