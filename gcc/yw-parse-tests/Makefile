TEST_RUNNER = test_runner

CPPUTEST_INCLUDE_DIR = $(CPPUTEST_HOME)/include
CPPUTEST_LIB_DIR     = $(CPPUTEST_HOME)/cpputest_build/lib

YW_REPO_ROOT = ../..
YW_SRC_DIRS  = $(YW_REPO_ROOT)/src
YW_TEST_DIRS = $(YW_REPO_ROOT)/test
YW_GCC_DIRS  = $(YW_REPO_ROOT)/gcc

SRC = $(wildcard $(YW_TEST_DIRS)/yw-parse-tests/*.cpp) test_runner.c

CPPFLAGS =  -std=c++14 -g3 -MMD -MP -D_THREAD_SAFE -DCPPUTEST -Wno-unused-parameter -Wno-unused-variable
CPPFLAGS += -W -Wall -Wno-deprecated -pedantic -O3 -Wno-unused-but-set-variable -Wno-attributes
CPPFLAGS += -I$(CPPUTEST_INCLUDE_DIR)
CPPFLAGS += -I$(YW_SRC_DIRS)/yw-parse
CPPFLAGS += -I$(ANTLR4_RUNTIME_SRC)
CPPFLAGS += -I$(YW_TEST_DIRS)/yw-test
CPPFLAGS += -DANTLR4CPP_STATIC 

GCC_LIBS   = -lm -lpthread -lstdc++
UTEST_LIBS = -lCppUTestExt -lCppUTest -L$(CPPUTEST_LIB_DIR)       
YW_LIBS    = -lywparse                -L$(YW_GCC_DIRS)/yw-parse
ANTLRLIB   = -lantlr4                 -L$(YW_GCC_DIRS)/antlr4-runtime
test: $(TEST_RUNNER)
	./$(TEST_RUNNER) -v

runner: $(TEST_RUNNER)

$(TEST_RUNNER): $(SRC)  
	$(CXX) $(CPPFLAGS) $(SRC) $(UTEST_LIBS) $(YW_LIBS) $(GCC_LIBS) $(ANTLRLIB) -o $(TEST_RUNNER)

clean:
	rm -f $(TEST_RUNNER) *.d