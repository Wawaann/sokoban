##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Make des files
##


SRC		=	src/box.c				\
			src/check_map.c			\
			src/end.c 				\
			src/event.c 			\
			src/init_game.c 		\
			src/map.c	 			\
			src/player.c 			\
			src/sokoban.c			\

UTILS	=	lib/my/lib_printf/src/utils.c 	\
			utils/for_read.c 				\
			utils/for_check.c 				\
			utils/free_mem.c 				\
			utils/utils.c 					\

OBJ     =   $(SRC:.c=.o)$(UTILS:.c=.o)

LIB		=	-L./lib/my -lmy -L./lib/my -lmy_printf

NAME    =   my_sokoban

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
	@gcc -o $(NAME) $(SRC) $(UTILS) $(LIB) -lncurses -g3
	@echo -e "$(BOLD)$(GREEN)Compilation terminée avec succès !$(DEFAULT)"

clean:
	@echo -e "$(DEFAULT)$(BLUE)Suppression des fichiers de la librairie..."
	@make clean -C lib/my --quiet
	@rm -f $(OBJ)
	@echo -e "$(DEFAULT)$(GREEN)Suppression terminée avec succès.$(DEFAULT)"

fclean:         clean
	@echo -e "$(DEFAULT)$(BLUE)Suppression du binaire..."
	@rm -f $(NAME)
	@rm -rf vgcore*
	@make fclean -C lib/my --quiet
	@echo -e "$(DEFAULT)$(GREEN)Suppression terminée avec succès.$(DEFAULT)"

re: fclean all
