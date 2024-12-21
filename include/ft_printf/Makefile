#
#
CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCDIR)

INCDIR = ./include
SRCDIR = ./src
OBJDIR = ./obj

SRCS =  $(SRCDIR)/ft_printf.c $(SRCDIR)/ft_putunbr_fd.c $(SRCDIR)/ft_putxxnbr_fd.c\
		$(SRCDIR)/ft_putxnbr_fd.c $(SRCDIR)/ft_putstr_fd.c $(SRCDIR)/ft_putnbr_fd.c\
		$(SRCDIR)/ft_putchar_fd.c $(SRCDIR)/ft_putptr_fd.c $(SRCDIR)/ft_strlen_fd.c

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	@echo "\n\033[33mCreating libftftprintf static library...\033[0m\n"
	ar rcs $(NAME) $(OBJS)
	@echo "\nlibftprintf.a created \033[32msuccessfully!\033[0m\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR) 
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	@echo "\n\033[33mCleaning up libftprintf build files...\033[0m\n"
	rm -f $(OBJS)
	rm -rf $(OBJDIR)
	@echo "\nlibftprintf build files cleaned up \033[32msuccessfully!\033[0m\n"

fclean: clean
	@echo "\n\033[33mCleaning up libftprintf executable...\033[0m\n"
	rm -f $(NAME)
	@echo "\nlibftprintf executable cleaned up \033[32msuccessfully!\033[0m\n"

re: fclean all

.PHONY: all clean fclean re
