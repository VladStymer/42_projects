ROOT_DIR	?=	../..

include	$(ROOT_DIR)/Makefile.d/config/reset-implicit-vars.mk
include	$(ROOT_DIR)/Makefile.d/config/module-defaults.mk
include	$(ROOT_DIR)/Makefile.d/config/shared-defaults.mk
include $(ROOT_DIR)/global.config.mk
include $(ROOT_DIR)/Makefile.d/config/colors.mk
export CFLAGS
export PARENT?=$(NAME)

include	$(ROOT_DIR)/Makefile.d/rules/shared/print-config.mk
include	$(ROOT_DIR)/Makefile.d/rules/shared/all.mk
include	$(ROOT_DIR)/Makefile.d/rules/modules/header.mk
include	$(ROOT_DIR)/Makefile.d/rules/modules/name.mk
include	$(ROOT_DIR)/Makefile.d/rules/shared/objs.mk
include	$(ROOT_DIR)/Makefile.d/rules/shared/build-static.mk
include	$(ROOT_DIR)/Makefile.d/rules/modules/clean.mk
include	$(ROOT_DIR)/Makefile.d/rules/modules/fclean.mk
include	$(ROOT_DIR)/Makefile.d/rules/shared/re.mk
include	$(ROOT_DIR)/Makefile.d/rules/shared/test-objs.mk
include	$(ROOT_DIR)/Makefile.d/rules/shared/test-bin.mk
include	$(ROOT_DIR)/Makefile.d/rules/shared/test.mk
include	$(ROOT_DIR)/Makefile.d/rules/shared/norme.mk
