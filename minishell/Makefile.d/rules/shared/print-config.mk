.PHONY:	print-config

print-config:
	@printf "%b" "$(OBJ_COLOR)"	"Author:		$(WARN_COLOR)$(AUTHOR)\n$(NO_COLOR)"
	@printf "%b" "$(OBJ_COLOR)"	"Date: 		$(WARN_COLOR)$(DATE)\n$(NO_COLOR)"
	@printf "%b" "$(OBJ_COLOR)"	"Kernel: 	$(WARN_COLOR)$(KERNEL)\n$(NO_COLOR)"
	@printf "%b" "$(OBJ_COLOR)"	"Compiler:	$(WARN_COLOR)$(CC)\n$(NO_COLOR)"
	@printf "%b" "$(OBJ_COLOR)"	"Flags: 		$(WARN_COLOR)$(CFLAGS)\n$(NO_COLOR)"
	@printf "%b" "$(OBJ_COLOR)"	"Options:	$(WARN_COLOR)$(COPTS)\n$(NO_COLOR)"
	@printf "%b" "$(OBJ_COLOR)"	"Output:		$(WARN_COLOR)$(NAME)\n$(NO_COLOR)"
	@printf "%b" "$(OBJ_COLOR)"	"Includes:	$(WARN_COLOR)" \
		"$(subst -I,,$(subst $(ROOT_DIR)/,,$(INCLUDES)))\n" \
		"$(NO_COLOR)"
	@printf "%b" "$(OBJ_COLOR)"	"Include libs:	$(WARN_COLOR)$(INCLUDE_LIBS)\n$(NO_COLOR)"
	@printf "%b" "$(OBJ_COLOR)"	"Modules:	$(WARN_COLOR)$(MODULES)\n$(NO_COLOR)"
	@printf "%b" "$(OBJ_COLOR)"	"Dependencies:	$(WARN_COLOR)" \
		"$(subst $(ROOT_DIR)/,,$(STATIC_MODS))\n" \
		"$(NO_COLOR)"
	@printf "%b" "$(OBJ_COLOR)"	"Parent:		$(WARN_COLOR)$(PARENT)\n$(NO_COLOR)"
	@printf "%b" "$(OBJ_COLOR)"	"Root dir:	$(WARN_COLOR)$(ROOT_DIR)\n$(NO_COLOR)"
	@printf "%b" "$(OBJ_COLOR)"	"Default rule:	$(WARN_COLOR)$(.DEFAULT_GOAL)\n$(NO_COLOR)"
