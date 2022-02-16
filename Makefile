##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##


SRC		=	src/check_map.c			\
			src/read_map.c 			\
			src/sokoban.c			\

UTILS	=	lib/my/lib_printf/src/utils.c 	\
			utils/for_read.c 				\
			utils/for_check.c 				\

OBJ     =   $(SRC:.c=.o)$(UTILS:.c=.o)

LIB		=	-L./lib/my -lmy -L./lib/my -lmy_printf

NAME    =   sokoban

BLUE    =   \e[34m
BOLD    =   \e[1m
CYAN    =   \e[36m
DEFAULT =	\e[0m
GREEN   =	\e[32m
MAGEN   =   \e[35m
RED		=	\e[31m

all:    $(NAME)

$(NAME):
	@echo -e "$(BOLD)$(CYAN)Construction de la librairie..."
	@echo -e "$(BOLD)$(GREEN)Construction terminée avec succès !"
	@make -C lib/my --quiet
	@echo -e "$(BOLD)$(CYAN)Compilation des fichiers sources..."
	@gcc -o $(NAME) $(SRC) $(UTILS) $(LIB) -lncurses -Wall -g3
	@echo -e "$(BOLD)$(GREEN)Compilation terminée avec succès !$(DEFAULT)"

clean:
	@echo -e "$(DEFAULT)$(BLUE)Suppression des fichiers de la librairie..."
	@make clean -C lib/my --quiet
	@rm -f $(OBJ)
	@echo -e "$(DEFAULT)$(GREEN)Suppression terminée avec succès.$(DEFAULT)"

fclean:         clean
	@echo -e "$(DEFAULT)$(BLUE)Suppression du binaire..."
	@rm -f $(NAME)
	@make fclean -C lib/my --quiet
	@echo -e "$(DEFAULT)$(GREEN)Suppression terminée avec succès.$(DEFAULT)"

re: fclean all
