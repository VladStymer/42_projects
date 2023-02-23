.PHONY: test

ifeq ($(KERNEL), Darwin)
 LEAKS=leaks -atExit --
endif

PREPARE_TEST:	$(MOD_NAME)-test
				chmod +x ./$(MOD_NAME)-test

test:		PREPARE_TEST
			$(LEAKS) ./$(MOD_NAME)-test

pytest:		PREPARE_TEST
			./test.py
		
