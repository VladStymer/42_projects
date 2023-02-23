.PHONY: fclean

fclean:					clean
						@echo
						@echo "------------------------------"
						@echo "FCLEAN PROJECT $(NAME)"
						@echo "------------------------------"
						rm -rf $(NAME)
						@$(foreach lib,	$(addprefix $(LIBS_DIR)/, $(LIBS)),				\
							$(MAKE) --no-print-directory -C $(lib) fclean;				\
						)
						@$(foreach mod,	$(addprefix $(MODULES_DIR)/, $(MODULES)),		\
							$(MAKE) --no-print-directory -C $(mod) fclean;				\
						)
