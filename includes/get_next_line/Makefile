# Nome della libreria
NAME = libgnl.a

# File sorgenti
SRCS = get_next_line.c get_next_line_utils.c

# File oggetto
OBJS = $(SRCS:.c=.o)

# Compilatore e flag
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Regola predefinita
all: $(NAME)

# Creazione della libreria
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compilazione dei file oggetto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Pulizia dei file oggetto
clean:
	rm -f $(OBJS)

# Pulizia completa (file oggetto e libreria)
fclean: clean
	rm -f $(NAME)

# Ricompilazione completa
re: fclean all

# Indica che le regole non sono file
.PHONY: all clean fclean re