include ../yw.setup.makefile
include ../cpp.setup.makefile

LIB_TARGET = libantlr4.a

LIB_SRC   += $(wildcard $(ANTLR4_RUNTIME_SRC)/*.cpp)
LIB_SRC   += $(wildcard $(ANTLR4_RUNTIME_SRC)/atn/*.cpp)
LIB_SRC   += $(wildcard $(ANTLR4_RUNTIME_SRC)/dfa/*.cpp)
LIB_SRC   += $(wildcard $(ANTLR4_RUNTIME_SRC)/misc/*.cpp)
LIB_SRC   += $(wildcard $(ANTLR4_RUNTIME_SRC)/support/*.cpp)
LIB_SRC   += $(wildcard $(ANTLR4_RUNTIME_SRC)/tree/*.cpp)
LIB_SRC   += $(wildcard $(ANTLR4_RUNTIME_SRC)/tree/pattern/*.cpp)
LIB_SRC   += $(wildcard $(ANTLR4_RUNTIME_SRC)/tree/xpath/*.cpp)

include ../lib.targets.makefile
