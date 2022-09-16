
SRC				= 	ft_printf.c\
					src/ft_count_precision_width.c\
					src/ft_checks.c\
					src/ft_print_percent.c\
					src/ft_minus_width.c\
					src/ft_print_char.c\
					src/ft_print_str.c\
					src/ft_print_pointer.c\
					src/ft_convert_ptr.c\
					src/ft_print_lower_hexa.c\
					src/ft_convert_hex.c\
					src/ft_minus_dot.c\
					src/ft_only_dot.c\
					src/ft_only_flags.c\
					src/ft_print_upper_hexa.c\
					src/ft_print_nbr.c\
					src/ft_print_unbr.c\


OBJS 			= 	ft_printf.o\
					src/ft_count_precision_width.o\
					src/ft_checks.o\
					src/ft_print_percent.o\
					src/ft_minus_width.o\
					src/ft_print_char.o\
					src/ft_print_str.o\
					src/ft_print_pointer.o\
					src/ft_convert_ptr.o\
					src/ft_print_lower_hexa.o\
					src/ft_convert_hex.o\
					src/ft_minus_dot.o\
					src/ft_only_dot.o\
					src/ft_only_flags.o\
					src/ft_print_upper_hexa.o\
					src/ft_print_nbr.o\
					src/ft_print_unbr.o\


DEF_COLOR     = \033[0;39m
GRAY         = \033[0;90m
RED         = \033[0;91m
GREEN         = \033[0;92m
YELLOW         = \033[0;93m
BLUE         = \033[0;94m
MAGENTA     = \033[0;95m
CYAN         = \033[0;96m
WHITE         = \033[0;97m

NAME			= libftprintf.a

CC				= gcc

FLAGS			= -Wall -Wextra -Werror -c -I.

ARRC			= ar rcs

RM				= rm -f 

all		: $(NAME)

bonus	: all

$(NAME)	: ${OBJS}
		@mv libft.a $(NAME)
		@${ARRC} ${NAME} ${OBJS}
		@echo "\n"
		@echo "$(YELLOW)Done Creating libftprintf.a $(DEF_COLOR)"

%.o		: %.c
		@${CC} ${FLAGS} $< -o $@
		@echo "$(GREEN)Compiling $<$(DEF_COLOR)"

clean	:
		@echo "$(MAGENTA) --------------------------CLEANING FT_PRINTF OBJECTS-------------------------- $(CYAN)"
		@echo "\n"
		@${RM} ${OBJS}
		@echo "$(RED)Object Files Deleted$(DEF_COLOR)"
		@echo "\n"
		@echo "$(GREEN) --------------------------DONE--------------------------$(DEF_COLOR)"

fclean	: 
		@echo "$(MAGENTA) --------------------------REMOVING LIBFTPRINTF.A-------------------------- $(CYAN)"
		@echo "\n"
		@${RM} ${NAME}
		@echo "$(RED)Libftprintf.a Deleted$(DEF_COLOR)"
		@echo "\n"
		@echo "$(GREEN) --------------------------DONE--------------------------$(DEF_COLOR)"

re		: fclean all

.PHONY	:all clean fclean re
		
		




