NAME		?=	$(notdir $(shell pwd)).o
MOD_NAME 	?=	$(basename $(NAME))
STATIC_MODS	?=	$(foreach dep,$(DEPS),$(MODULES_DIR)/$(dep)/$(dep).o)
