.PHONY:	norme-public norme-private norme-srcs

STYLE=$(BOLD)

NORME_PUBLIC	:=	$(addprefix norme-public-, $(notdir $(wildcard $(INCLUDES_DIR)/*.h)))
norme-public-%:		$(INCLUDES_DIR)/%
					@printf "%-35s" "		$<:"
					$(ROOT_DIR)/scripts/color_norminette.sh $<
norme-public:
					@echo "\t$(STYLE)Public headers:$(NO_COLOR)"
					@$(MAKE) -s $(NORME_PUBLIC)


NORME_PRIVATE	:=	$(addprefix norme-private-, $(notdir $(wildcard $(SRCS_DIR)/*.h)))
norme-private-%:	$(SRCS_DIR)/%
					@printf "%-35s" "		$<:"
					$(ROOT_DIR)/scripts/color_norminette.sh $<

norme-private:
					@echo "\t$(STYLE)Private headers:$(NO_COLOR)"
ifeq ($(NORME_PRIVATE),)
					@printf "%-35s" "		No private header"
					@echo ""
else
					@$(MAKE) -s $(NORME_PRIVATE)
endif


NORME_SRCS		:=	$(addprefix norme-srcs-, $(SRCS))
norme-srcs-%:		$(SRCS_DIR)/%
					@printf "%-35s" "		$<:"
					$(ROOT_DIR)/scripts/color_norminette.sh $<
norme-srcs:
					@echo "\t$(STYLE)Source files:$(NO_COLOR)"
					@$(MAKE) -s $(NORME_SRCS)


norme-module:		norme-public norme-private norme-srcs
