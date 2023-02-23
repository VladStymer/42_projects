define BUILD_MODULE
$(MODULES_DIR)/$(1)/$(1).o:
	@$(MAKE) -C $(MODULES_DIR)/$(1) all
endef

$(foreach mod,$(MODULES),$(eval $(call BUILD_MODULE,$(mod))))
