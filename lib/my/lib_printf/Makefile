##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make des files
##

SRC    =	src/my_printf.c			\
			src/va_bin.c 			\
			src/va_octal.c 			\
			src/va_hexa.c 			\
			src/va_adress.c 		\
			src/va_putchar.c 		\
			src/va_putstr.c 		\
			src/va_nbr.c			\
			src/va_unsinbr.c 		\
			src/va_putpercent.c 	\
			src/va_printable.c 		\
			src/utils.c 			\
			src/utils2.c 			\

OBJ 	=	$(SRC:.c=.o)

LIB	= 	libmy_printf.a

BLUE	=	\e[34m
BOLD	=	\e[1m
CYAN	=	\e[36m
DEFAULT	=	\e[0m
GREEN	= 	\e[32m
MAGEN	=	\e[35m
RED		= 	\e[31m

all:	$(LIB)

$(LIB):	$(OBJ)
	@ar rc $(LIB) $(OBJ)
	@mv $(LIB) ../
	@rm -f $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:		clean
	@rm -f ../$(LIB)

re: fclean all
