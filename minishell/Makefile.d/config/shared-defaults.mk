AUTHOR				?=	$(USER)
DATE				?=	$(shell git log -1 --format=%cd --date=short)

DEBUG				?=	0

MODULES_DIR			?=	$(ROOT_DIR)/modules
MODULES				?=	$(notdir $(patsubst %/,%,$(dir $(wildcard $(MODULES_DIR)/*/.))))
MODULES_DIRS		?=	$(addprefix $(MODULES_DIR)/, $(MODULES))

LIBS_DIR			?=	$(ROOT_DIR)/libs
LIBS				?=	$(notdir $(patsubst %/,%,$(dir $(wildcard $(LIBS_DIR)/*/.))))
LIBS_DIRS			?=	$(addprefix $(LIBS_DIR)/, $(LIBS))
STATIC_LIBS			?=	$(foreach lib, $(LIBS), $(LIBS_DIR)/${lib}/${lib}.a)

SRCS_DIR			?=	src
TEST_DIR			?=	test
OBJS_DIR			?=	obj
INCLUDES_DIR		=	inc

BASE_OBJS			?=	$(addprefix $(OBJS_DIR)/, ${SRCS:.c=.o})
TEST_OBJS			?=	$(addprefix $(TEST_DIR)/$(OBJS_DIR)/, ${TEST_SRCS:.c=.o})

INCLUDE_DIRS		?=	$(ROOT_DIR)/$(INCLUDES_DIR)/ \
							$(SRCS_DIR)/ \
							$(foreach dir,$(MODULES_DIRS),${dir}/inc/) \
							$(foreach dir,$(LIBS_DIRS),${dir}/inc/)
INCLUDES			?=	$(addprefix -I, $(INCLUDE_DIRS))

INCLUDE_LIBS		?=	$(addprefix -L, $(LIBS_DIRS)) $(patsubst lib%,-l%, $(LIBS))
					

KERNEL				?=	$(shell uname)

ifeq ($(KERNEL), Linux)
 CC					=	clang
endif
CC					=	gcc

RM					?=	rm -f

ifeq ($(KERNEL), Linux)
 ASAN_FLAG			=	-g
endif
BASE_FLAGS			?=	-Wall -Wextra -DDEBUG=$(DEBUG)
ifeq ($(DEBUG),1)
 CFLAGS				=	$(BASE_FLAGS) $(ASAN_FLAG)
else
 CFLAGS				=	$(BASE_FLAGS) -Werror
endif

ifeq ($(KERNEL), Linux)
 ASAN_OPT			=	-fsanitize=address
endif
OUTPUT				?=	$(NAME)
ifeq ($(DEBUG),1)
 COPTS				?=	$(ASAN_OPT) -o $(OUTPUT)
else
 COPTS				?=	-o $(OUTPUT)
endif

.DEFAULT_GOAL		:=	all
