#
#
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I$(INCDIR) -I$(LIBFTDIR)/include

LIBFTDIR = ./include/libft
INCDIR = ./include
OBJDIR = ./obj

LIBFT = $(LIBFTDIR)/libft.a
CLNT_SRC = ./src/client.c
SRVR_SRC = ./src/server.c
CLNTOBJ = $(CLNT_SRC:./src/%.c=$(OBJDIR)/%.o)
SRVROBJ = $(SRVR_SRC:./src/%.c=$(OBJDIR)/%.o)

SRVR = server
CLNT = client

all: $(SRVR) $(CLNT)

$(SRVR): $(LIBFT) $(SRVROBJ)
	$(CC) $(CFLAGS) -o $(SRVR) $(SRVROBJ) -L$(LIBFTDIR) -lft

$(CLNT): $(LIBFT) $(CLNTOBJ)
	$(CC) $(CFLAGS) -o $(CLNT) $(CLNTOBJ) -L$(LIBFTDIR) -lft

$(OBJDIR)/%.o: ./src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	rm -f $(CLNTOBJ) $(SRVROBJ)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(SRVR) $(CLNT)
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -rf $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re
