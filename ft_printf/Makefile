NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRC =	ft_printf.c \
		ft_putnbr_i_d.c \
		ft_putnbr_p.c \
		ft_putnbr_u.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(NAME) compiled"

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo $(NAME) deleted

re: fclean all
