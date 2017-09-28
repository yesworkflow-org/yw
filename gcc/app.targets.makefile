

SRC      = $(APP_SRC)
INCLUDES = $(YW_INCLUDES) $(ANTLR_INCLUDES)
LIBS     = $(YW_LIBS) $(CPP_LIBS) $(ANTLR_LIB) $(GV_LIBS)

all: app

app: $(APP)

$(APP): $(APP_SRC)  
	$(CXX) $(CPPFLAGS) $(CONSTANTS) $(INCLUDES) $(SRC) $(LIBS) -o $(APP)

clean:
	rm -f $(APP)