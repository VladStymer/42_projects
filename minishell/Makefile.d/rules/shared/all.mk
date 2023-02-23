.PHONY: all

ifeq ($(PARENT), $(NAME))
 CHECK_HEADERS=check_headers
endif

check_headers:
	@echo "------------------------------"
	@echo "norminette on header files"
	@echo "------------------------------"
	@$(ROOT_DIR)/scripts/color_norminette.sh $(addsuffix *.h, $(INCLUDE_DIRS)) 2> /dev/null

all:		header $(CHECK_HEADERS) $(NAME)
