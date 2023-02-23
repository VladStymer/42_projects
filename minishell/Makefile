# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 17:48:26 by lhumbert          #+#    #+#              #
#    Updated: 2023/01/12 16:33:53 by loichu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE_PATH   	:=  $(abspath $(lastword $(MAKEFILE_LIST)))
export ROOT_DIR	:=	$(realpath $(dir $(FILE_PATH)))

include Makefile.d/config/reset-implicit-vars.mk
include global.config.mk
include project.config.mk
include Makefile.d/config/project-defaults.mk
include Makefile.d/config/shared-defaults.mk
include Makefile.d/config/colors.mk
export CFLAGS
export PARENT?=$(NAME)
ifeq ($(KERNEL), Darwin)
 INCLUDE_LIBS	+=	-L$(HOME)/.brew/Cellar/readline/8.2.1/lib
 CFLAGS			 =	-g3 $(BASE_FLAGS) $(ASAN_FLAG)
endif
INCLUDE_LIBS	+= -lreadline

include	Makefile.d/rules/shared/print-config.mk
include	Makefile.d/rules/project/print-module-config.mk
include	Makefile.d/rules/shared/all.mk
include	Makefile.d/rules/project/header.mk
include	Makefile.d/rules/project/name.mk
include	Makefile.d/rules/project/valgrind.mk
include	Makefile.d/rules/shared/objs.mk
include	Makefile.d/rules/project/clean.mk
include	Makefile.d/rules/project/fclean.mk
include	Makefile.d/rules/shared/build-static.mk
include	Makefile.d/rules/shared/re.mk
include	Makefile.d/rules/shared/test-objs.mk
include	Makefile.d/rules/shared/test-bin.mk
include	Makefile.d/rules/project/test.mk
include	Makefile.d/rules/shared/norme.mk
include Makefile.d/macros/build-modules.mk
include Makefile.d/macros/norme-all.mk

#macair M1 = -L /opt/homebrew/Cellar/readline/8.2.1/lib
#42 lausanne = -L$(HOME)/.brew/Cellar/readline/8.2.1/lib
