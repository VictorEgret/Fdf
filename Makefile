# Variables

NAME		= fdf
INCLUDE		= includes
LIBFT		= libft
MINILIBX	= minilibx-linux
SRC_DIR		= sources/
OBJ_DIR		= objects/
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
SMAKE		= make --no-print-directory

# Colors

END			=	\033[0m
BOLD		=	\033[1m
UNDER		=	\033[4m
REV			=	\033[7m
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

# Sources

SRC_FILES	=	fdf parser initializer listeners display projections display_utils utils


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF		=	.cache_exists

all:		$(NAME)

bonus:		all

$(NAME):	$(OBJ)
			@$(SMAKE) -C $(LIBFT)
			@$(SMAKE) -C ${MINILIBX}
			@$(CC) $(OBJ) -L $(LIBFT) -L $(MINILIBX) -lX11 -lXext  -lmlx -lft -lm -o $@
			@echo "$(GREEN)$(BOLD)Fdf compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "\033[1A                                                     "
			@echo -n "\033[1A"
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -I $(INCLUDE) -I $(LIBFT)/includes -I $(MINILIBX) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -r $(OBJ_DIR)
			@echo "$(BLUE)Fdf object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(MINILIBX)/minilibx.a
			@$(SMAKE) -C $(LIBFT) fclean
			@echo "$(CYAN)minilibx executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)Fdf executable files cleaned!$(DEF_COLOR)"

re:			fclean all

norm:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme > tmp
			@while read -r line; do \
				if [ -z "$${line##*OK*}" ]; then \
					printf "$(GREEN)"; \
					printf "$$line"; \
					printf "$(END)\n"; \
				else \
					if [ -z "$${line##*Error*}" ]; then \
						printf "$(RED)"; \
						printf "$$line"; \
						printf "$(END)\n"; \
					else \
						printf "$$line"; \
					fi \
				fi \
			done < tmp
			@$(RM) tmp

.PHONY:		all clean fclean re norm