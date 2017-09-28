include ../graphviz.setup.makefile

CFLAGS += -g3 
CLAGS += -Wall 
CFLAGS += -pedantic 
CFLAGS += -Wno-attributes
CFLAGS += -Wno-deprecated 
CFLAGS += -Wno-unused-parameter 
CFLAGS += -Wno-unused-but-set-variable 
CFLAGS += -Wno-unused-variable 
CFLAGS += -Wno-int-conversion
CFLAGS += -Wno-implicit-int
CFLAGS += -Wno-incompatible-pointer-types
CLFAGS += -Wno-pointer-to-int-cast

LIB_TARGET = libgraphviz.a

GV_INCLUDES += -Imsys2

GV_SRC   += $(wildcard $(GRAPHVIZ_SRC)/lib/cdt/*.c)
GV_SRC   += $(wildcard $(GRAPHVIZ_SRC)/lib/dotgen/*.c)
GV_SRC   += $(wildcard $(GRAPHVIZ_SRC)/lib/gvc/*.c)
GV_SRC   += $(wildcard $(GRAPHVIZ_SRC)/lib/pathplan/*.c)
GV_SRC   += $(wildcard $(GRAPHVIZ_SRC)/lib/xdot/*.c)
GV_SRC   += $(wildcard $(GRAPHVIZ_SRC)/plugin/dot_layout/*.c)


GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/agerror.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/agxbuf.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/apply.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/attr.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/edge.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/flatten.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/grammar.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/graph.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/id.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/imap.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/io.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/mem.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/node.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/obj.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/pend.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/rec.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/refstr.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/scan.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/subg.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/utils.c
GV_SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/write.c

GV_SRC += $(GRAPHVIZ_SRC)/plugin/core/gvplugin_core.c
GV_SRC += $(GRAPHVIZ_SRC)/plugin/core/gvrender_core_dot.c
GV_SRC += $(GRAPHVIZ_SRC)/plugin/core/gvrender_core_svg.c

CONSTANTS += -DYY_NO_UNISTD_H

INCLUDES = $(GV_INCLUDES)
SRC = $(GV_SRC)
CGRAPHDIR = $(GRAPHVIZ_SRC)/lib/cgraph

all: $(LIB_TARGET)

GENERATED_SRC =  $(CGRAPHDIR)/grammar.c $(CGRAPHDIR)/scan.c
grammar: $(GENERATED_SRC)

$(GENERATED_SRC): $(CGRAPHDIR)/grammar.y $(CGRAPHDIR)/scan.l
	bison -dy $(CGRAPHDIR)/grammar.y -o $(CGRAPHDIR)/grammar.c
	flex -o$(CGRAPHDIR)/scan.c $(CGRAPHDIR)/scan.l

$(LIB_TARGET): $(LIB_SRC)
	$(CC) -c $(CFLAGS) $(CONSTANTS) $(INCLUDES) $(SRC)
	rm -f $(LIB_TARGET)
	ar vq $(LIB_TARGET) *.o

lib : $(LIB_TARGET)
	rm -f *.o

clean:
	rm -f $(GENERATED_SRC) $(LIB_TARGET) *.o