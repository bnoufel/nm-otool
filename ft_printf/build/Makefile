NAME 		= 	libftprintf.a
##############################
####### GLOBAL VARIABLE ######
##############################
include Makefile_cfg_var.mk

##############################
######## CREATE FOLDER #######
###### C FILE BY FOLDER ######
##############################
include Makefile_cfg_folder.mk

##############################
######### ADD PREFIX #########
###### ALL SRC/OBJ FILE ######
##### ALL SRCS/OBJS FILE #####
####### IN SRCS FOLDER #######
##############################
include Makefile_cfg_prefix.mk


all: $(NAME)

$(NAME): $(LIBD) $(OBJSDIR) $(OBJS)
	@cp $(LIBD) ../$(NAME)
	@ar rcs ../$(NAME) $(OBJS)
	@echo ""

$(LIBD):
	@make -C $(LIBFTDIR)/

$(OBJSDIR)/$(DIRLST)/%.o: $(SRCSDIR)/$(DIRLST)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES) -I$(HEADERLIB)
	@echo "${RED}█${RESET}\c"

$(OBJSDIR)/$(DIRPP)/%.o: $(SRCSDIR)/$(DIRPP)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES) -I$(HEADERLIB)
	@echo "${YELLOW}█${RESET}\c"

$(OBJSDIR)/$(DIRBUFF)/%.o: $(SRCSDIR)/$(DIRBUFF)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES) -I$(HEADERLIB)
	@echo "${YELLOW}█${RESET}\c"
	
$(OBJSDIR)/$(DIRCORE)/%.o: $(SRCSDIR)/$(DIRCORE)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES) -I$(HEADERLIB)
	@echo "${GREEN}█${RESET}\c"
	
$(OBJSDIR)/$(DIRCONVERT)/%.o: $(SRCSDIR)/$(DIRCONVERT)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES) -I$(HEADERLIB)
	@echo "${GREEN}█${RESET}\c"


$(OBJSDIR):
	@mkdir -p $(OBJSDIR)/$(DIRLST);
	@mkdir -p $(OBJSDIR)/$(DIRCORE);
	@mkdir -p $(OBJSDIR)/$(DIRCONVERT);
	@mkdir -p $(OBJSDIR)/$(DIRPP);
	@mkdir -p $(OBJSDIR)/$(DIRBUFF);
	@echo "\nCompiling $(NAME)${RESET} [${GREEN}✔${RESET}]"

clean:
	@echo "${RED}Cleaning $(NAME)${RESET} [${GREEN}✔${RESET}]"
	@/bin/rm -rf $(OBJSDIR);
	@make clean -C $(LIBFTDIR)

fclean: clean
	@echo "${RED}Purge $(NAME)${RESET} [${GREEN}✔${RESET}]"
	@/bin/rm -f ../$(NAME)
	@make fclean -C $(LIBFTDIR)
	@rm -rf ../$(NAME).dSYM
	@rm -rf ../ft_printf.dSYM

re: fclean all

.PHONY: all, clean, fclean, re, $(LIBD), $(OBJSDIR)/$(DIRCONVERT), $(OBJSDIR)/$(DIRLST), $(OBJSDIR)/$(DIRPP), $(OBJSDIR)/$(DIRBUFF), $(OBJSDIR)/$(DIRCORE)

.SUFFIXES: .c .o
