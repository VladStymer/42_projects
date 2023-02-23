%.a:
		echo Build static lib $@
		@$(MAKE) --no-print-directory -C $(dir $@) all
