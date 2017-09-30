
CPPFLAGS += -std=c++14 
CPPFLAGS += -Wall 
CPPFLAGS += -pedantic 
CPPFLAGS += -Wno-attributes
CPPFLAGS += -Wno-deprecated 
CPPFLAGS += -Wno-unused-parameter 
CPPFLAGS += -Wno-unused-but-set-variable 
CPPFLAGS += -Wno-unused-variable 

LDFLAGS +=  -static-libstdc++

ifeq ($(YW_PLATFORM),macos)
CPP_LIBS  += -lstdc++
LIBCPPFLAGS += -mmacosx-version-min=10.6
APPCPPFLAGS += -mmacosx-version-min=10.6
endif

ifeq ($(YW_PLATFORM),ubuntu)
CPP_LIBS  += -lstdc++
CPP_LIBS  += -lm
CPP_LIBS  += -lpthread
endif

ifeq ($(YW_BUILD),release)
CPPFLAGS += -O3
else
CPPFLAGS += -g3
endif

ifdef USE_DL_LIB
CPP_LIBS  += -ldl
endif

ifdef USING_STD_FILESYSTEM
CONSTANTS += -DUSING_STD_FILESYSTEM
CPP_LIBS  += -lstdc++fs
endif
