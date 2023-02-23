$(TEST_DIR)/$(OBJS_DIR)/%.o:	$(TEST_DIR)/%.c
								@mkdir -p $(dir $@)
								$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
								@echo
