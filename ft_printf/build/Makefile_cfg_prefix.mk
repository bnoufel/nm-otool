SRCSLST		= 	$(addprefix $(DIRLST)/, $(SRCLST))
SRCSCORE	= 	$(addprefix $(DIRCORE)/, $(SRCCORE))
SRCSCONVERT	= 	$(addprefix $(DIRCONVERT)/, $(SRCCONVERT))
SRCSPP		= 	$(addprefix $(DIRPP)/, $(SRCPP))
SRCSBUFF	= 	$(addprefix $(DIRBUFF)/, $(SRCBUFF))

SRC 		=	 $(SRCSLST) $(SRCSPP) $(SRCSBUFF) $(SRCSCONVERT) $(SRCSCORE)
OBJ 		= 	$(SRC:%.c=%.o)

SRCS 		= 	$(addprefix $(SRCSDIR)/, $(SRC))
OBJS 		= 	$(addprefix $(OBJSDIR)/, $(OBJ))