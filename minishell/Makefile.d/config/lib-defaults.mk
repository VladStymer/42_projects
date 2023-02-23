NAME		?=	$(notdir $(shell pwd)).a
MOD_NAME	?=	$(basename $(NAME))
#STATIC_MODS	?=	$(foreach dep,$(DEPS),$(MODULES_DIR)/$(dep)/$(dep).a)
