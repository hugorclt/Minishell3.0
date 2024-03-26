#ifndef LEXER_H
# define LEXER_H

#include <stdlib.h>

#include "minishell.h"
#include "string.h"

enum e_token_type {
	COMMAND,
	L_PARENTH,
	R_PARENTH,
	AND,
	OR,
	PIPE,
};

typedef struct s_lexer {
	char	*input_prompt;
} t_lexer;

t_lexer	*init_lexer(char *input_prompt);
void	peek_token(t_lexer *lexer);
void	scan_token(t_lexer *lexer);

#endif
