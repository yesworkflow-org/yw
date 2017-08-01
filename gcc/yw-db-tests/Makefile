TEST_RUNNER = test_runner

CPPUTEST_INCLUDE_DIR = $(CPPUTEST_HOME)/include
CPPUTEST_LIB_DIR     = $(CPPUTEST_HOME)/cpputest_build/lib

YW_REPO_ROOT = ../..
YW_SRC_DIRS  = $(YW_REPO_ROOT)/src
YW_TEST_DIRS = $(YW_REPO_ROOT)/test
YW_GCC_DIRS  = $(YW_REPO_ROOT)/gcc

SRC = $(wildcard $(YW_TEST_DIRS)/yw-db-tests/*.cpp) test_runner.c

CPPFLAGS =  -std=c++14 -g3 -MMD -MP -D_THREAD_SAFE -DCPPUTEST -Wno-unused-parameter -Wno-unused-variable
CPPFLAGS += -W -Wall -Wno-deprecated -pedantic -O3 -Wno-unused-but-set-variable
CPPFLAGS += -I$(CPPUTEST_INCLUDE_DIR)
CPPFLAGS += -I$(YW_SRC_DIRS)/yw-types
CPPFLAGS += -I$(YW_SRC_DIRS)/sqlite-db
CPPFLAGS += -I$(YW_SRC_DIRS)/yw-db
CPPFLAGS += -I$(YW_TEST_DIRS)/yw-test

GCC_LIBS   = -lm -lpthread -lstdc++
UTEST_LIBS = -lCppUTestExt -lCppUTest -L$(CPPUTEST_LIB_DIR)       
YW_LIBS    = -lywdb                   -L$(YW_GCC_DIRS)/yw-db
YW_LIBS   += -lsqlitedb               -L$(YW_GCC_DIRS)/sqlite-db
YW_LIBS   += -lsqlite3                -L$(YW_GCC_DIRS)/sqlite3  

test: $(TEST_RUNNER)
	./$(TEST_RUNNER) -v

runner: $(TEST_RUNNER)

$(TEST_RUNNER): $(SRC)  
	$(CXX) $(CPPFLAGS) $(SRC) $(UTEST_LIBS) $(YW_LIBS) $(GCC_LIBS) -o $(TEST_RUNNER)

clean:
	rm -f $(TEST_RUNNER) *.d