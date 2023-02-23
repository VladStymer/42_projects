.PHONY: header

header:
			@printf "\n"
			@printf "%b" "$(OK_COLOR)"
			@printf "%b" "$(OK_COLOR)"
			@echo "============================================================"
			@echo "                 Compiling $(MOD_NAME)"
			@echo "============================================================"
			@printf "%b" "$(NO_COLOR)"
			@echo
			@$(MAKE) -s print-config
			@echo
