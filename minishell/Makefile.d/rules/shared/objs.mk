$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
	@echo "\n" "==>" norminette $< "<=="
	$(ROOT_DIR)/scripts/color_norminette.sh $<
	@echo 
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
