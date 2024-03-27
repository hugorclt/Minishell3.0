#ifndef LEXER_H
# define LEXER_H

#include <stdlib.h>

#include "minishell.h"
#include "string.h"

typedef enum e_token_type {
	L_PARENTH,
	R_PARENTH,
	AND,
	OR,
	PIPE,
	COMMAND,
}	token_type;

typedef struct s_lexer {
	char	*input_prompt;
	char	**token_array;
} t_lexer;

t_lexer	*init_lexer();
void	clean_lexer(t_lexer *lexer);
void	fill_lexer(t_lexer **lexer, char *input_prompt);
token_type peek_token(t_lexer *lexer);
void	scan_token(t_lexer **lexer);
int	skip_quote(t_lexer *lexer, int *index);

#endif
