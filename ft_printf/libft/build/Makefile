NAME = libft.a

###############################
####### GLOBAL VARIABLE #######
###############################
include Makefile_cfg_var

###############################
######## CREATE FOLDER ########
####### C FILE BY FOLDER ######
###############################
include Makefile_cfg_folder

###############################
######### ADD PREFIX ##########
###### ALL SRC/OBJ FILE #######
###############################
include Makefile_cfg_prefix

all: $(NAME)

$(NAME): $(OBJSDIR) $(OBJS)
	@ar rcs ../$(NAME) $(OBJS)

$(OBJSDIR)/$(DIRLST)/%.o: $(SRCSDIR)/$(DIRLST)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES)
	@echo "${RED}█${RESET}\c"

$(OBJSDIR)/$(DIROTH)/%.o: $(SRCSDIR)/$(DIROTH)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES)
	@echo "${RED}█${RESET}\c"

$(OBJSDIR)/$(DIRCHECK)/%.o: $(SRCSDIR)/$(DIRCHECK)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES)
	@echo "${RED}█${RESET}\c"

$(OBJSDIR)/$(DIRGNL)/%.o: $(SRCSDIR)/$(DIRGNL)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES)
	@echo "${RED}█${RESET}\c"

$(OBJSDIR)/$(DIRMEM)/%.o: $(SRCSDIR)/$(DIRMEM)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES)
	@echo "${YELLOW}█${RESET}\c"

$(OBJSDIR)/$(DIRPUT)/%.o: $(SRCSDIR)/$(DIRPUT)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES)
	@echo "${YELLOW}█${RESET}\c"

$(OBJSDIR)/$(DIRSTD)/%.o: $(SRCSDIR)/$(DIRSTD)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES)
	@echo "${YELLOW}█${RESET}\c"

$(OBJSDIR)/$(DIRSTR)/%.o: $(SRCSDIR)/$(DIRSTR)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES)
	@echo "${GREEN}█${RESET}\c"

$(OBJSDIR)/$(DIRTAB)/%.o: $(SRCSDIR)/$(DIRTAB)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES)
	@echo "${RED}█${RESET}\c"

$(OBJSDIR)/$(DIROTH)/%.o: $(SRCSDIR)/$(DIROTH)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< -I$(INCLUDES)
	@echo "${RED}█${RESET}\c"

$(OBJSDIR):
	@mkdir -p $(OBJSDIR)/$(DIRLST);
	@mkdir -p $(OBJSDIR)/$(DIRCHECK);
	@mkdir -p $(OBJSDIR)/$(DIRGNL);
	@mkdir -p $(OBJSDIR)/$(DIRMEM);
	@mkdir -p $(OBJSDIR)/$(DIRPUT);
	@mkdir -p $(OBJSDIR)/$(DIRSTD);
	@mkdir -p $(OBJSDIR)/$(DIRSTR);
	@mkdir -p $(OBJSDIR)/$(DIRTAB);
	@mkdir -p $(OBJSDIR)/$(DIROTH);
	@echo "\nCompiling $(NAME)${RESET} [${GREEN}✔${RESET}]"


clean:
	@echo "${RED}Cleaning $(NAME)${RESET} [${GREEN}✔${RESET}]"
	@/bin/rm -rf $(OBJSDIR);

fclean: clean
	@echo "${RED}Purge $(NAME)${RESET} [${GREEN}✔${RESET}]"
	@/bin/rm -f ../$(NAME)
	@rm -rf ../$(NAME).dSYM

re: fclean all

.PHONY: all, clean, fclean, re, $(LIBD), $(OBJSDIR)/$(DIRLST), $(OBJSDIR)/$(DIRCHECK), $(OBJSDIR)/$(DIRGNL), $(OBJSDIR)/$(DIRMEM), $(OBJSDIR)/$(DIRPUT), $(OBJSDIR)/$(DIRSTD), $(OBJSDIR)/$(DIRSTR), $(OBJSDIR)/$(DIRTAB)

.SUFFIXES: .c .o
