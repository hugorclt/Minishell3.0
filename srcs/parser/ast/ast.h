#ifndef AST_H
# define AST_H

#include "minishell.h"
#include "array.h"
#include "lexer.h"

typedef struct s_lexer t_lexer;
typedef struct s_token {
	int	type;
	char **cmd;
}	t_token;

typedef struct s_node {
	struct s_node *left;
	struct s_node *right;
	struct s_node *parent;
	t_token	*token;
}	t_node;


t_node	*get_complete_ast(t_lexer **lexer);
t_node *parse_and_or(t_lexer **lexer, t_node *parent);
#endif
