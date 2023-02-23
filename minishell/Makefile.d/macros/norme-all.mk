define NORME_MODULE
norme-$(1):
	@echo ""
	@echo "$(UNDER)MODULE: $(1)$(NO_COLOR)"
	@$(MAKE) -sC $(MODULES_DIR)/$(1) norme-module
endef
$(foreach mod,$(MODULES),$(eval $(call NORME_MODULE,$(mod))))

define NORME_LIB
norme-$(1):
	@echo ""
	@echo "$(UNDER)LIBRARY: $(1)$(NO_COLOR)"
	@$(MAKE) -sC $(LIBS_DIR)/$(1) norme-module
endef
$(foreach lib,$(LIBS),$(eval $(call NORME_LIB,$(lib))))

norme: norme-module $(addprefix norme-, $(LIBS)) $(addprefix norme-, $(MODULES))
