
YW_DIR = ../..

YW_SRC_DIR  = $(YW_DIR)/src
YW_GCC_DIR  = $(YW_DIR)/gcc

YW_INCLUDES += -I$(YW_SRC_DIR)/yw-cli
YW_INCLUDES += -I$(YW_SRC_DIR)/yw-graph
YW_INCLUDES += -I$(YW_SRC_DIR)/yw-model
YW_INCLUDES += -I$(YW_SRC_DIR)/yw-extract
YW_INCLUDES += -I$(YW_SRC_DIR)/yw-parse
YW_INCLUDES += -I$(YW_SRC_DIR)/yw-db
YW_INCLUDES += -I$(YW_SRC_DIR)/sqlite-db
YW_INCLUDES += -I$(YW_SRC_DIR)/yw-config
YW_INCLUDES += -I$(YW_SRC_DIR)/yw-types
YW_INCLUDES += -I$(YW_SRC_DIR)/sqlite-3.19.3

YW_LIBS   += -lywcli     -L$(YW_GCC_DIR)/yw-cli
YW_LIBS   += -lywgraph   -L$(YW_GCC_DIR)/yw-graph
YW_LIBS   += -lywmodel   -L$(YW_GCC_DIR)/yw-model
YW_LIBS   += -lywextract -L$(YW_GCC_DIR)/yw-extract
YW_LIBS   += -lywparse   -L$(YW_GCC_DIR)/yw-parse
YW_LIBS   += -lywdb      -L$(YW_GCC_DIR)/yw-db
YW_LIBS   += -lsqlitedb  -L$(YW_GCC_DIR)/sqlite-db
YW_LIBS   += -lywconfig  -L$(YW_GCC_DIR)/yw-config
YW_LIBS   += -lsqlite3   -L$(YW_GCC_DIR)/sqlite3

ANTLR_LIB  += -lantlr4 -L$(YW_GCC_DIR)/antlr4-runtime
ANTLR_INCLUDES += -I$(ANTLR4_RUNTIME_SRC)
CONSTANTS += -DANTLR4CPP_STATIC 
