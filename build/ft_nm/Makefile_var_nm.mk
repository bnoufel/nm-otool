FT_NM		= ft_nm

SRCSDIRNM	= $(SRCSDIR)/$(FT_NM)/
OBJSDIRNM	= $(OBJSDIR)/$(FT_NM)/

SRCNM			= ft_nm.c handle_32.c handle_64.c tools64.c tools32.c utils.c merge.c rmerge.c\
				list.c handle_fat.c args.c args2.c core_nm.c tools.c puthandle_32.c puthandle_64.c\
				clean.c

SRCSNM 		= 	$(addprefix $(SRCSDIRNM), $(SRCNM))
OBJNM 		= 	$(SRCNM:%.c=%.o)

OBJSNM 		= 	$(addprefix $(OBJSDIRNM), $(OBJNM))