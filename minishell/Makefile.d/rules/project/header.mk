.PHONY: header

header:
			@printf "%b" "$(OK_COLOR)"
			@echo "$$(cat logo.ascii)"
			@printf "%b" "$(NO_COLOR)"
			@echo
			@$(MAKE) -s print-config
			@echo
