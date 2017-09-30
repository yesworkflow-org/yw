

SRC      = $(APP_SRC)
INCLUDES = $(YW_INCLUDES) $(ANTLR_INCLUDES)
LIBS     = $(YW_LIBS) $(ANTLR_LIB) $(GV_LIBS) $(CPP_LIBS)

all: app

app: $(APP)

$(APP): $(APP_SRC)  
	$(CXX) $(CPPFLAGS) $(APPCPPFLAGS) $(CONSTANTS) $(INCLUDES) $(SRC) $(LIBS) $(LDFLAGS) -o $(APP)

clean:
	rm -f $(APP)