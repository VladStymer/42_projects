$(MOD_NAME)-test:				all $(TEST_OBJS) $(STATIC_MODS) $(STATIC_LIBS)
								$(eval OUTPUT := $@)
								@echo
								@echo "Compilation line for $(OUTPUT)"
								$(CC) $(INCLUDES) $(TEST_OBJS) $(NAME) $(COPTS) $(INCLUDE_LIBS)
								@printf "%b" "$(OK_COLOR)" "$(OUTPUT) done compiling !"
								@printf "%b" "$(NO_COLOR)"
								@echo
