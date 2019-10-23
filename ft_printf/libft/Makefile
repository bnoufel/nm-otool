NAME 		= 	libft.a
##############################
####### GLOBAL VARIABLE ######
##############################
RED 		= 	\x1b[31m
YELLOW	 	= 	\x1b[33m
GREEN 		= 	\x1b[32m
RESET		= 	\x1b[0m

SRCSDIR 	= 	srcs
SRCSDIR1 	= 	mem
SRCSDIR2 	= 	str
SRCSDIR3 	= 	put
SRCSDIR4 	= 	stdlib
SRCSDIR5 	= 	check

OBJSDIR 	= 	objects

INCLUDES 	= 	includes

CFLAGS 		= 	-Wall -Werror -Wextra -g3
CC 			= 	gcc $(CFLAGS)
HEADER		=	libft.h
HEADERS		=	$(addprefix $(INCLUDES)/, $(HEADER))
SRCMEM		=	ft_bzero.c ft_memmalloc.c
SRCCHECK	=	ft_isspace.c ft_isnegative.c ft_isupper.c ft_islower.c
SRCSTR		=	ft_strlen.c ft_strcat.c ft_strncmp.c ft_strcmp.c ft_strdup.c ft_charcat.c \
				ft_strlowcase.c ft_strnew.c ft_strjoinfree.c ft_strjoin.c  ft_strdel.c ft_strclr.c ft_strndup.c ft_toupper.c
SRCPUT		=	ft_putchar_fd.c ft_putstr_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putchar.c \
				ft_putendl.c ft_putendl_fd.c ft_putstr.c
SRCSTDLIB	=	ft_atoi.c ft_atol.c ft_atoll.c ft_stoa.c ft_itoa.c ft_ltoa.c ft_lltoa.c \
				ft_itoa_base.c ft_ltoa_base.c ft_lltoa_base.c ft_ulltoa_base.c \
				ft_atoul.c

SRCSMEM		= 	$(addprefix $(SRCSDIR1)/, $(SRCMEM))
SRCSSTR		= 	$(addprefix $(SRCSDIR2)/, $(SRCSTR))
SRCSPUT		= 	$(addprefix $(SRCSDIR3)/, $(SRCPUT))
SRCSSTDLIB	= 	$(addprefix $(SRCSDIR4)/, $(SRCSTDLIB))
SRCSCHECK	= 	$(addprefix $(SRCSDIR5)/, $(SRCCHECK))

SRC 		=	$(SRCSMEM) $(SRCSSTR) $(SRCSPUT) $(SRCSSTDLIB) $(SRCSCHECK)
OBJ 		= 	$(SRC:%.c=%.o)

SRCS 		= 	$(addprefix $(SRCSDIR)/, $(SRC))
OBJS 		= 	$(addprefix $(OBJSDIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(OBJSDIR) $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJSDIR)/$(SRCSDIR1)/%.o: $(SRCSDIR)/$(SRCSDIR1)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES)
	@echo "${RED}█${RESET}\c"

$(OBJSDIR)/$(SRCSDIR2)/%.o: $(SRCSDIR)/$(SRCSDIR2)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES)
	@echo "${YELLOW}█${RESET}\c"

$(OBJSDIR)/$(SRCSDIR3)/%.o: $(SRCSDIR)/$(SRCSDIR3)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES)
	@echo "${YELLOW}█${RESET}\c"

$(OBJSDIR)/$(SRCSDIR4)/%.o: $(SRCSDIR)/$(SRCSDIR4)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES)
	@echo "${GREEN}█${RESET}\c"

$(OBJSDIR)/$(SRCSDIR5)/%.o: $(SRCSDIR)/$(SRCSDIR5)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES)
	@echo "${GREEN}█${RESET}\c"


$(OBJSDIR):
	@if [ ! -d "$(OBJSDIR)/" ]; then \
		mkdir -p $(OBJSDIR)/$(SRCSDIR1); \
		mkdir -p $(OBJSDIR)/$(SRCSDIR2); \
		mkdir -p $(OBJSDIR)/$(SRCSDIR3); \
		mkdir -p $(OBJSDIR)/$(SRCSDIR4); \
		mkdir -p $(OBJSDIR)/$(SRCSDIR5); \
	fi
	@echo "Compiling $(NAME)${RESET} [${GREEN}✔${RESET}]"

clean:
	@echo "${RED}Cleaning $(NAME)${RESET} [${GREEN}✔${RESET}]"
	@/bin/rm -rf $(OBJSDIR);

fclean: clean
	@echo "${RED}Purge $(NAME)${RESET} [${GREEN}✔${RESET}]"
	@/bin/rm -f $(NAME)
	@if [ -d $(LIBDIR) ]; then \
		/bin/rm -rf $(LIBDIR); \
	fi

re: fclean all

.PHONY: all, clean, fclean, re, $(OBJSDIR)/$(SRCSDIR1), $(OBJSDIR)/$(SRCSDIR2), $(OBJSDIR)/$(SRCSDIR3), $(OBJSDIR)/$(SRCSDIR4), $(OBJSDIR)/$(SRCSDIR5)

.SUFFIXES: .c .o
