

SRCS =	ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_isprint.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strlen.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_substr.c\
		ft_split.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c

DEF_COLOR     = \033[0;39m
GRAY         = \033[0;90m
RED         = \033[0;91m
GREEN         = \033[0;92m
YELLOW         = \033[0;93m
BLUE         = \033[0;94m
MAGENTA     = \033[0;95m
CYAN         = \033[0;96m
WHITE         = \033[0;97m

INCLUDES = .

OBJS	= $(SRCS:.c=.o)

BONUS	= ft_lstnew.c\
		  ft_lstadd_front.c\
		  ft_lstsize.c\
		  ft_lstlast.c\
		  ft_lstadd_back.c\
		  ft_lstdelone.c\
		  ft_lstclear.c\
		  ft_lstiter.c\
		  ft_lstmap.c
		  
BONUSOBJS = $(BONUS:.c=.o)

NAME		= libft.a

FLAGS	= -Wall -Wextra -Werror -c

CC = gcc

LIB = ar rcs

CLEAN = rm -f ${OBJS} ${BONUSOBJS}

FCLEAN = rm -f $(NAME)

all :	$(NAME)

$(NAME) : ${OBJS}
		${LIB} $(NAME) ${OBJS}
	
%.o: %.c
		${CC} ${FLAGS} -I ${INCLUDES} $< -o ${<:.c=.o} 

clean : 
		${CLEAN}

fclean : clean 
		${FCLEAN}

bonus : ${BONUSOBJS}
		${LIB} $(NAME) ${BONUSOBJS}

re :	fclean all
