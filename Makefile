#
#
CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCDIR) -I$(LIBFTDIR)/include -I$(FT_PRINTFDIR)/include

INCDIR = ./include
LIBFTDIR = $(INCDIR)/libft
FT_PRINTFDIR = $(INCDIR)/ft_printf
OBJDIR = ./obj

LIBFT = $(LIBFTDIR)/libft.a
FT_PRINTF = $(FT_PRINTFDIR)/libftprintf.a

CLNT_SRC = ./src/client.c
SRVR_SRC = ./src/server.c
CLNTOBJ = $(CLNT_SRC:./src/%.c=$(OBJDIR)/%.o)
SRVROBJ = $(SRVR_SRC:./src/%.c=$(OBJDIR)/%.o)
CLNT = client
SRVR = server

all: $(SRVR) $(CLNT)

$(SRVR): $(SRVROBJ) $(LIBFT) $(FT_PRINTF)
	@echo "\n\033[33mCompiling server files and dependencies...\033[0m\n"
	$(CC) $(CFLAGS) -o $(SRVR) $(SRVROBJ) -L$(LIBFTDIR) -lft -L$(FT_PRINTFDIR) -lftprintf
	@echo "\n\033[32mCompilation successful\033[0m!\n"

$(CLNT): $(CLNTOBJ) $(LIBFT) $(FT_PRINTF)
	@echo "\n\033[33mCompiling client files and dependencies...\033[0m\n"
	$(CC) $(CFLAGS) -o $(CLNT) $(CLNTOBJ) -L$(LIBFTDIR) -lft -L$(FT_PRINTFDIR) -lftprintf
	@echo "\n\033[32mCompilation successful\033[0m!\n"

$(OBJDIR)/%.o: ./src/%.c | $(OBJDIR)
	@echo "\n\033[33mCompiling all build files and dependencies...\033[0m\n"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "\n\033[32mCompilation successful\033[0m!\n"

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTFDIR)
	
$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	@echo "\n\033[33mCleaning up build and library files...\033[0m\n"
	rm -f $(CLNTOBJ) $(SRVROBJ)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(FT_PRINTFDIR) clean
	@echo "\nAll build files cleaned up \033[32msuccessfully\033[0m!\n"


fclean: clean
	@echo "\n\033[33mCleaning up executables and static libraries...\033[0m\n"
	rm -f $(SRVR) $(CLNT)
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(FT_PRINTFDIR) fclean
	@echo "\nExecutables and static libraries cleaned up \033[32msuccessfully\033[0m!\n"

re: fclean all

.PHONY: all clean fclean re
