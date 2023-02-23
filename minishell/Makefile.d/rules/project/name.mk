CLEAN_MOD_OBJS:
	-rm $(STATIC_MODS) $(STATIC_LIBS)

$(NAME):	CLEAN_MOD_OBJS $(BASE_OBJS) $(STATIC_MODS) $(STATIC_LIBS)
	@echo
	@echo "Compilation line for $(OUTPUT)"
	$(CC) $(CFLAGS) $(INCLUDES) $(BASE_OBJS) $(STATIC_MODS) $(COPTS) $(INCLUDE_LIBS)
	@printf "%b" "$(OK_COLOR)" "$(OUTPUT) done compiling !"
	@printf "%b" "$(NO_COLOR)"
	@echo
