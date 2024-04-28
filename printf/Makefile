CC = cc
CFLAGS = -Wall -Wextra -Werror
INCDIR = .
SRC = ft_printf.c\
		pf_set.c\
		putnbr_fd.c\
		set_c.c\
		set_d.c\
		set_d2.c\
		set_p.c\
		set_per.c\
		set_s.c\
		set_x.c\
		set_xx.c
LIBSRC = libft/ft_memset.c\
		libft/ft_bzero.c\
		libft/ft_memcpy.c\
		libft/ft_memmove.c\
		libft/ft_memchr.c\
		libft/ft_memcmp.c\
		libft/ft_strlen.c\
		libft/ft_strlcpy.c\
		libft/ft_strlcat.c\
		libft/ft_strchr.c\
		libft/ft_strrchr.c\
		libft/ft_strnstr.c\
		libft/ft_strncmp.c\
		libft/ft_atoi.c\
		libft/ft_isalpha.c\
		libft/ft_isdigit.c\
		libft/ft_isalnum.c\
		libft/ft_isascii.c\
		libft/ft_isprint.c\
		libft/ft_toupper.c\
		libft/ft_tolower.c\
		libft/ft_calloc.c\
		libft/ft_strdup.c\
		libft/ft_substr.c\
		libft/ft_strjoin.c\
		libft/ft_strtrim.c\
		libft/ft_split.c\
		libft/ft_itoa.c\
		libft/ft_strmapi.c\
		libft/ft_putchar_fd.c\
		libft/ft_putstr_fd.c\
		libft/ft_putendl_fd.c\
		libft/ft_putnbr_fd.c\
		libft/ft_striteri.c
OBJ = $(SRC:%.c=%.o)
LIBFTDIR = libft
LIBFTOBJ = $(LIBSRC:%.c=%.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(LIBFTOBJ) $(OBJ)
	ar rcs $(NAME) $(OBJ) $(LIBFTOBJ)

$(LIBFTOBJ):$(LIBSRC)
	make -C $(LIBFTDIR)
	make -C $(LIBFTDIR) bonus

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
