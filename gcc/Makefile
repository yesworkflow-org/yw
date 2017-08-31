

YW_BUILDS =	sqlite-db \
			yw-db  \
		 	yw-parse \
			yw-extract \
			yw-model

YW_TESTS = 	sqlite-db-tests \
			yw-db-tests \
			yw-parse-tests \
			yw-extract-tests \
			yw-model-tests

ALL_BUILDS = ${YW_BUILDS} ${YW_TESTS}

lib:
	for BUILD in $(YW_BUILDS); do \
		echo; \
		echo "---------- Building $$BUILD --------------------" ;	\
		$(MAKE) -C $$BUILD all; \
	done

test: lib
	for BUILD in $(YW_TESTS); do \
		echo; \
		echo "---------- Building $$BUILD --------------------" ;	\
		$(MAKE) -C $$BUILD test; \
	done

clean:
	for BUILD in $(ALL_BUILDS); do \
		echo; \
		echo "---------- Cleaning $$BUILD --------------------" ; \
		$(MAKE) -C $$BUILD clean; \
	done
