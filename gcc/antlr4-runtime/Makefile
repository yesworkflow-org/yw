ANTLR4_LIB = libantlr4.a

SRC = $(ANTLR4_RUNTIME_SRC)

ANTLR4_SRCS = \
	$(wildcard $(SRC)/*.cpp)              \
	$(wildcard $(SRC)/atn/*.cpp)          \
	$(wildcard $(SRC)/dfa/*.cpp)          \
	$(wildcard $(SRC)/misc/*.cpp)         \
	$(wildcard $(SRC)/support/*.cpp)      \
	$(wildcard $(SRC)/tree/*.cpp)         \
	$(wildcard $(SRC)/tree/pattern/*.cpp) \
	$(wildcard $(SRC)/tree/xpath/*.cpp)

CPPFLAGS =  -std=c++14 -g3 -W -Wall -pedantic
CPPFLAGS += -I$(ANTLR4_RUNTIME_SRC) -DANTLR4CPP_EXPORTS -Wno-attributes

all: $(ANTLR4_LIB)

$(ANTLR4_LIB): $(ANTLR4_SRCS)
	$(CXX) -c $(CPPFLAGS) ${ANTLR4_SRCS} 
	rm -f $(ANTLR4_LIB)
	ar vq $(ANTLR4_LIB) *.o

tidy : $(ANTLR4_LIB)
	rm -f *.o

clean:
	rm -f *.o $(ANTLR4_LIB)