
DEP_LIBS = antlr4-runtime \
           sqlite3

YW_LIBS  = sqlite-db \
           yw-db  \
           yw-parse \
           yw-extract \
           yw-model

YW_TESTS = sqlite-db-tests \
           yw-db-tests \
           yw-parse-tests \
           yw-extract-tests \
           yw-model-tests

YW_BUILDS = $(YW_LIBS) $(YW_TESTS)

ALL_BUILDS = $(DEP_LIBS) $(YW_BUILDS)

all: dep lib test

dep:
	for BUILD in $(DEP_LIBS); do \
		echo; \
		echo "---------- Building $$BUILD --------------------" ;	\
		$(MAKE) -C $$BUILD lib; \
	done

lib: dep
	for BUILD in $(YW_LIBS); do \
		echo; \
		echo "---------- Building $$BUILD --------------------" ;	\
		$(MAKE) -C $$BUILD lib; \
	done

test: lib
	for BUILD in $(YW_TESTS); do \
		echo; \
		echo "---------- Building $$BUILD --------------------" ;	\
		$(MAKE) -C $$BUILD test; \
	done

clean:
	for BUILD in $(YW_BUILDS); do \
		echo; \
		echo "---------- Cleaning $$BUILD --------------------" ; \
		$(MAKE) -C $$BUILD clean; \
	done

clean-dep:
	for BUILD in $(DEP_LIBS); do \
		echo; \
		echo "---------- Cleaning $$BUILD --------------------" ; \
		$(MAKE) -C $$BUILD clean; \
	done

clean-all:
	for BUILD in $(ALL_BUILDS); do \
		echo; \
		echo "---------- Cleaning $$BUILD --------------------" ; \
		$(MAKE) -C $$BUILD clean; \
	done
