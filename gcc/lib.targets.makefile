
INCLUDES = $(YW_INCLUDES) $(ANTLR_INCLUDES)

all: $(LIB_TARGET)

$(LIB_TARGET): $(LIB_SRC)
	$(CXX) -c $(CPPFLAGS) $(CONSTANTS) $(INCLUDES) $(LIB_SRC)
	rm -f $(LIB_TARGET)
	ar vq $(LIB_TARGET) *.o

lib : $(LIB_TARGET)
	rm -f *.o

clean:
	rm -f $(LIB_TARGET) *.o 