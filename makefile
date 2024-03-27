NAME 		= 	minishell

FILES 		=	srcs/main.c \
			srcs/parser/lexer/lexer.c \
			srcs/parser/lexer/lexer_utils.c \
			srcs/utils/string/ft_strlen.c \
			srcs/utils/string/ft_strdup.c \
			srcs/utils/string/ft_strjoin.c \
			srcs/utils/string/ft_split.c \
			srcs/utils/string/ft_strncmp.c \
			srcs/utils/string/ft_substr.c \
			srcs/utils/string/ft_substring.c

INCL_DIR  = $(addprefix -I,$(shell find $(SRC_DIR) -type d))
CC 			= 	cc
CFLAGS 		= 	-Wall -Wextra -Werror -g3

OBJS_DIR	=	.objs
OBJS 		= 	$(addprefix $(OBJS_DIR)/, $(notdir $(FILES:%.c=%.o)))

DEP			=	$(addprefix $(OBJS_DIR)/, $(notdir $(FILES:%.c=%.d)))

$(OBJS_DIR)		:
	@mkdir -p $(OBJS_DIR)


# For Multiple Directory
$(OBJS_DIR)/%.o	: 	srcs/%.c
	@printf "\033[0;33mGenerating minsihell object... %-38.38s \r" $@
	@$(CC) $(CFLAGS) -c $< -o $@ -MMD $(INCL_DIR)


$(OBJS_DIR)/%.o	: 	srcs/parser/%.c
	@printf "\033[0;33mGenerating minsihell object... %-38.38s \r" $@
	@$(CC) $(CFLAGS) -c $< -o $@ -MMD $(INCL_DIR)

$(OBJS_DIR)/%.o	: 	srcs/utils/string/%.c
	@printf "\033[0;33mGenerating minsihell object... %-38.38s \r" $@
	@$(CC) $(CFLAGS) -c $< -o $@ -MMD $(INCL_DIR)

$(OBJS_DIR)/%.o	: 	srcs/parser/lexer/%.c
	@printf "\033[0;33mGenerating minsihell object... %-38.38s \r" $@
	@$(CC) $(CFLAGS) -c $< -o $@ -MMD $(INCL_DIR)



# End Multiple Directory

all 			: 	$(NAME)

leaks			:	all
	valgrind --suppressions=ignore_readline	\
		--leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes	\
		./minishell

$(NAME)			: 	$(OBJS_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lreadline
	@echo "\033[1;32mMinishell: Done!\033[0m"

clean			:
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)
	@echo "\033[1;31mObject cleaned!\033[0m"

fclean			:	
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)
	@rm -f $(NAME)
	@echo "\033[1;31mProgram and object cleaned!\033[0m"

re				:	fclean all

.PHONY			:
	all test clean fclean re

.SECONDEXPANSION:


-include $(DEP)
