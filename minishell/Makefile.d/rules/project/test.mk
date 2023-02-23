.PHONY: test

ifeq ($(KERNEL), Darwin)
 LEAKS=leaks -atExit --
endif

test:		$(NAME)	
			./test.py

check_leaks:	$(NAME)
				$(LEAKS) ./$(NAME)
