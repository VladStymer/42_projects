.PHONY: clean

clean:
						@echo
						@echo "------------------------------"
						@echo "CLEAN LIB $(NAME)"
						@echo "------------------------------"
						$(RM) $(BASE_OBJS) $(TEST_OBJS)
