DEBUG		= -g3
CC			= gcc -Wall -Werror -Wextra $(DEBUG)

LIBFTDIR	= libft
PRINTFDIR	= ft_printf
LIB			= libftprintf.a

HEADPRINTF	= $(PRINTFDIR)/includes
HEADERLIB	= $(PRINTFDIR)/$(LIBFTDIR)/includes
HEADERS		= $(INCLUDES)/$(FT_NM).h $(INCLUDES)/$(FT_OTOOL).h $(INCLUDES)/global.h $(INCLUDES)/struct.h

INCLUDES	= includes
LDFLAGS 	= -L$(PRINTFDIR) -lftprintf
CCINCLUDES	= -I$(HEADERLIB) -I$(HEADPRINTF) -I$(INCLUDES)

SRCSDIR		= srcs
OBJSDIR		= objects

RED 		= 	\x1b[31m
YELLOW	 	= 	\x1b[33m
GREEN 		= 	\x1b[32m
RESET 		= 	\x1b[0m
