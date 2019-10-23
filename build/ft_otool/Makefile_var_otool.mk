FT_OTOOL	= ft_otool

SRCSDIROTOOL = $(SRCSDIR)/$(FT_OTOOL)/
OBJSDIROTOOL = $(OBJSDIR)/$(FT_OTOOL)/

SRCOTOOL			= ft_otool.c tools.c args.c core.c handle_64.c handle_32.c\
						handle_fat.c check.c
OBJOTOOL 		= 	$(SRCOTOOL:%.c=%.o)

SRCSOTOOL 		= 	$(addprefix $(SRCSDIROTOOL), $(SRCOTOOL))
OBJSOTOOL 		= 	$(addprefix $(OBJSDIROTOOL), $(OBJOTOOL))