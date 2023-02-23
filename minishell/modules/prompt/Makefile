# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnicoud <vnicoud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 12:48:09 by vnicoud           #+#    #+#              #
#    Updated: 2023/01/01 11:22:21 by vnicoud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE_PATH	:=	$(abspath $(lastword $(MAKEFILE_LIST)))

include module.config.mk
include ../modules.config.mk
ifeq ($(KERNEL), Darwin)
 INCLUDE_LIBS	+=	-L$(HOME)/.brew/Cellar/readline/8.2.1/lib
 CFLAGS			 =	-g3 $(BASE_FLAGS) $(ASAN_FLAG)
endif
INCLUDE_LIBS	+=	-lreadline