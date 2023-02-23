.PHONY: clean

clean:
						@echo
						@echo "------------------------------"
						@echo "CLEAN PROJECT $(NAME)"
						@echo "------------------------------"
						$(RM) $(BASE_OBJS)
						@$(foreach lib,	$(addprefix $(LIBS_DIR)/, $(LIBS)),				\
							$(MAKE) --no-print-directory -C $(lib) clean;				\
						)
						@$(foreach mod,	$(addprefix $(MODULES_DIR)/, $(MODULES)),		\
							$(MAKE) --no-print-directory -C $(mod) clean;				\
						)
