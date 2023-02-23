DEBUG		=	0

SRCS		=	errors.c internal_errors.c format.c normal_errors.c
ifeq ($(DEBUG),1)
	SRCS	+=	debug_errors.c
else
	SRCS	+=	nodebug_errors.c
endif

TEST_SRCS	=	test.c
