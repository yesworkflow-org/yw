include ../yw.setup.makefile
include ../graphviz.setup.makefile
include ../cpp.setup.makefile

CONSTANTS += -DUSE_GRAPHVIZ_LIB

LIB_TARGET = libywgraph.a
LIB_SRC    = $(wildcard $(YW_SRC_DIR)/yw-graph/*.cpp)

include ../lib.targets.makefile
