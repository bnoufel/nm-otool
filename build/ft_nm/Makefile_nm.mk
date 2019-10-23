$(FT_NM): $(PRINTFDIR)/$(LIB) $(OBJSDIR) $(OBJSNM)
	@echo "Compiling $(FT_NM)${RESET} [${GREEN}✔${RESET}]"
	@$(CC) $(LDFLAGS) $(CCINCLUDES) $(OBJSNM) -o $(FT_NM)

$(OBJSDIR)/$(FT_NM)/%.o: $(SRCSDIR)/$(FT_NM)/%.c $(HEADERS)
	@$(CC) -c -o $@ $< $(CCINCLUDES)