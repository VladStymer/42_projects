$(NAME):	$(BASE_OBJS)
		@echo
		@echo "Compilation line for $(OUTPUT)"
		ld -r $(BASE_OBJS) -o $(NAME)
		@printf "%b" "$(OK_COLOR)" "$(OUTPUT) done compiling !"
		@printf "%b" "$(NO_COLOR)"
		@echo
