include ./build/Makefile_var.mk

include ./build/ft_nm/Makefile_var_nm.mk
include ./build/ft_otool/Makefile_var_otool.mk

all: $(FT_NM) $(FT_OTOOL)

include ./build/ft_nm/Makefile_nm.mk
include ./build/ft_otool/Makefile_otool.mk

$(PRINTFDIR)/$(LIB):
	@make -C $(PRINTFDIR)

$(OBJSDIR):
	@mkdir -p $(OBJSDIR)/{$(FT_NM),$(FT_OTOOL)}

clean:
	@echo "${RED}Cleaning $(FT_NM)${RESET} [${GREEN}✔${RESET}]"
	@echo "${RED}Cleaning $(FT_OTOOL)${RESET} [${GREEN}✔${RESET}]"
	@/bin/rm -rf $(OBJSDIR);
	@make clean -C $(PRINTFDIR)

fclean: clean
	@echo "${RED}Purge $(NAME)${RESET} [${GREEN}✔${RESET}]"
	@/bin/rm -f $(FT_NM) $(FT_OTOOL)
	@make fclean -C $(PRINTFDIR)
	@rm -rf $(NAME).dSYM

re: fclean all

.PHONY: all, clean, fclean, re, $(LIBD)

.SUFFIXES: .c .o
