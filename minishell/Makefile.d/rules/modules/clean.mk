.PHONY: clean

clean:
						@echo
						@echo "------------------------------"
						@echo "CLEAN MODULE $(NAME)"
						@echo "------------------------------"
						$(RM) $(BASE_OBJS) $(TEST_OBJS)
