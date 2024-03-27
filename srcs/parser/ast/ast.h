#ifndef AST_H
# define AST_H

#include "minishell.h"
#include "lexer.h"

typedef struct s_node {
	struct s_node *left;
	struct s_node *right;
	struct s_node *parent;
	token_type type;
}

#endif
