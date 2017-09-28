
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

INCLUDES += -I$(GRAPHVIZ_SRC)/
INCLUDES += -I$(GRAPHVIZ_SRC)/lib/common
INCLUDES += -I$(GRAPHVIZ_SRC)/lib/cdt
INCLUDES += -I$(GRAPHVIZ_SRC)/lib/cgraph
INCLUDES += -I$(GRAPHVIZ_SRC)/lib/dotgen
INCLUDES += -I$(GRAPHVIZ_SRC)/lib/gvc
INCLUDES += -I$(GRAPHVIZ_SRC)/lib/pack
INCLUDES += -I$(GRAPHVIZ_SRC)/lib/pathplan
INCLUDES += -I$(GRAPHVIZ_SRC)/lib/xdot
INCLUDES += -I$(GRAPHVIZ_SRC)/plugin/core
INCLUDES += -I$(GRAPHVIZ_SRC)/plugin/dot_layout
INCLUDES += -Imsys2

SRC   += $(wildcard $(GRAPHVIZ_SRC)/lib/cdt/*.c)
SRC   += $(wildcard $(GRAPHVIZ_SRC)/lib/dotgen/*.c)
SRC   += $(wildcard $(GRAPHVIZ_SRC)/lib/gvc/*.c)
SRC   += $(wildcard $(GRAPHVIZ_SRC)/lib/pathplan/*.c)
SRC   += $(wildcard $(GRAPHVIZ_SRC)/lib/xdot/*.c)
SRC   += $(wildcard $(GRAPHVIZ_SRC)/plugin/dot_layout/*.c)



SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/agerror.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/agxbuf.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/apply.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/attr.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/edge.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/flatten.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/grammar.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/graph.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/id.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/imap.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/io.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/mem.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/node.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/obj.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/pend.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/rec.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/refstr.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/scan.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/subg.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/utils.c
SRC   += $(GRAPHVIZ_SRC)/lib/cgraph/write.c


SRC += $(GRAPHVIZ_SRC)/plugin/core/gvplugin_core.c
SRC += $(GRAPHVIZ_SRC)/plugin/core/gvrender_core_dot.c
SRC += $(GRAPHVIZ_SRC)/plugin/core/gvrender_core_svg.c

CONSTANTS += -DYY_NO_UNISTD_H

CGRAPHDIR = $(GRAPHVIZ_SRC)/lib/cgraph

all: $(LIB_TARGET)

GENERATED_SRC =  $(CGRAPHDIR)/grammar.c $(CGRAPHDIR)/scan.c
grammar: $(GENERATED_SRC)

$(GENERATED_SRC): $(CGRAPHDIR)/grammar.y $(CGRAPHDIR)/scan.l
	bison -dy $(CGRAPHDIR)/grammar.y -o $(CGRAPHDIR)/grammar.c
	flex -o$(CGRAPHDIR)/scan.c $(CGRAPHDIR)/scan.l

$(LIB_TARGET): grammar $(LIB_SRC)
	$(CC) -c $(CFLAGS) $(CONSTANTS) $(INCLUDES) $(SRC)
	rm -f $(LIB_TARGET)
	ar vq $(LIB_TARGET) *.o

lib : $(LIB_TARGET)
	rm -f *.o

clean:
	rm -f $(GENERATED_SRC) $(LIB_TARGET) *.o