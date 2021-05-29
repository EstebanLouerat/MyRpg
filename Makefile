##
## EPITECH PROJECT, 2021
## makefile
## File description:
## .
##

PROJECT	=	MY_RPG

NAME	=	my_rpg

SRC		=	$(wildcard source/*.c) $(wildcard source/lib/*.c) $(wildcard source/init/*.c)

OBJ		=	$(SRC:.c=.o)

CFLAG 	=	-I./include

CSFML	=	-lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio

REDDARK	=	\e[31;1m
RED		=	\e[31;1m
GREEN	=	\e[32;1m
YEL		=	\e[33;1m
BLUE	=	\e[34;1m
PINK	=	\e[35;1m
CYAN	=	\e[36;1m
WHITE	=	\e[0m

all:	$(NAME)
	
debug:
	$(eval CFLAGS += -g3)
	@echo -ne "$(PINK)[DEBUG]$(WHITE)\n"
	@make BLUE='\033[35;1m' DEBUG='-g3' -s fclean $(NAME)

start_compil:
	@echo -ne "\n$(GREEN)[$(WHITE)$(PROJECT)$(GREEN)] — START BUILD\n\n"

$(NAME):	start_compil $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAG) $(CSFML)
	@echo -ne "\n$(GREEN) → $(RED) Compilation Done!\n\n$(WHITE)"

%.o:%.c
	@printf "$(GREEN)[$(WHITE)$(PROJECT)$(GREEN)] — $(BLUE)%-30s" $@
	@echo -ne "$(WHITE)[$(GREEN)√$(WHITE)]\n"
	@gcc -o $@ -c $< $(CFLAG)

clean:
	@echo -ne "$(REDDARK)\nCleaning build files of \
	$(GREEN)[$(WHITE)$(PROJECT)$(GREEN)]\n\n"
	@printf "$(GREEN)[$(WHITE)$(PROJECT)$(GREEN)] — $(RED) %-30s\n" $(OBJ)
	@echo -ne "\n$(GREEN) → $(RED) Build clean.\n\n$(WHITE)"
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re