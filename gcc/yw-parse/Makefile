include ../yw.setup.makefile
include ../cpp.setup.makefile

LIB_TARGET = libywparse.a
SRC_DIR    = $(YW_SRC_DIR)/yw-parse

GENERATED_H   = ${SRC_DIR}/YWLexer.h          \
                ${SRC_DIR}/YWParser.h         \
                ${SRC_DIR}/YWListener.h       \
                ${SRC_DIR}/YWBaseListener.h

GENERATED_CPP = ${SRC_DIR}/YWLexer.cpp        \
                ${SRC_DIR}/YWParser.cpp       \
                ${SRC_DIR}/YWListener.cpp     \
                ${SRC_DIR}/YWBaseListener.cpp \

GENERATED_TXT = ${SRC_DIR}/YWLexer.tokens     \
                ${SRC_DIR}/YW.tokens

GENERATED_SRC = $(GENERATED_H) $(GENERATED_CPP) $(GENERATED_TXT)

LIB_SRC = $(wildcard $(YW_SRC_DIR)/yw-parse/*.cpp) $(GENERATED_CPP)

all: grammar lib

grammar: ${GENERATED_H} ${GENERATED_CPP}

${GENERATED_SRC}:
	 $(YW_SRC_DIR)/yw-parse/build.ps1

include ../lib.targets.makefile
