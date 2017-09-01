
CPPFLAGS += -std=c++14 
#CPPFLAGS += -O3 
CPPFLAGS += -g3 
CPPFLAGS += -Wall 
CPPFLAGS += -pedantic 
CPPFLAGS += -Wno-attributes
CPPFLAGS += -Wno-deprecated 
CPPFLAGS += -Wno-unused-parameter 
CPPFLAGS += -Wno-unused-but-set-variable 
CPPFLAGS += -Wno-unused-variable 

CPP_LIBS  += -lm -lpthread -lstdc++

ifdef USING_STD_FILESYSTEM
CONSTANTS += -D USING_STD_FILESYSTEM
CPP_LIBS  += -lstdc++fs
endif

