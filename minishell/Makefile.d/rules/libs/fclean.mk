.PHONY: fclean

ifeq ($(PARENT), $(NAME))
 CLEAN=clean
endif
fclean:					$(CLEAN)
						@echo
						@echo "------------------------------"
						@echo "FCLEAN LIB $(NAME)"
						@echo "------------------------------"
						$(RM) $(NAME)
						$(RM) $(MOD_NAME)-test
