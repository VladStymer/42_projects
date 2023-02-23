$(NAME):	$(BASE_OBJS) #$(STATIC_MODS)
		@echo
		@echo "Compilation line for $(OUTPUT)"
		ar rcs $(NAME) $(BASE_OBJS)
		@printf "%b" "$(OK_COLOR)" "$(OUTPUT) done compiling !"
		@printf "%b" "$(NO_COLOR)"
		@echo
