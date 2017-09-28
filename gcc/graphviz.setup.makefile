

YW_INCLUDES += -I$(YW_SRC_DIR)/yw-graphviz

YW_LIBS   += -lywgraphviz -L$(YW_GCC_DIR)/yw-graphviz

GV_INCLUDES += -I$(GRAPHVIZ_SRC)/
GV_INCLUDES += -I$(GRAPHVIZ_SRC)/lib/common
GV_INCLUDES += -I$(GRAPHVIZ_SRC)/lib/cdt
GV_INCLUDES += -I$(GRAPHVIZ_SRC)/lib/cgraph
GV_INCLUDES += -I$(GRAPHVIZ_SRC)/lib/dotgen
GV_INCLUDES += -I$(GRAPHVIZ_SRC)/lib/fdpgen
GV_INCLUDES += -I$(GRAPHVIZ_SRC)/lib/gvc
GV_INCLUDES += -I$(GRAPHVIZ_SRC)/lib/label
GV_INCLUDES += -I$(GRAPHVIZ_SRC)/lib/pack
GV_INCLUDES += -I$(GRAPHVIZ_SRC)/lib/pathplan
GV_INCLUDES += -I$(GRAPHVIZ_SRC)/lib/xdot
GV_INCLUDES += -I$(GRAPHVIZ_SRC)/plugin/core
GV_INCLUDES += -I$(GRAPHVIZ_SRC)/plugin/dot_layout

GV_LIBS += -lgraphviz  -L$(YW_GCC_DIR)/graphviz-lib

CONSTANTS += -DLTDL_H



