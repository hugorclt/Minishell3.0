#ifndef LEXER_H
# define LEXER_H

#include <stdlib.h>

#include "minishell.h"
#include "string.h"
#include "array.h"
#include "ast.h"

# define R_PARENTH 0
# define L_PARENTH 1
# define AND 2
# define OR 3
# define PIPE 4
# define HEREDOC 5
# define APPEND 6
# define INFILE 7
# define OUTFILE 8
# define CMD 9
# define END 10

typedef struct s_lexer {
	char	*input_prompt;
	char	**token_array;
} t_lexer;

typedef struct s_token t_token;

t_lexer	*init_lexer();
void	clean_lexer(t_lexer *lexer);
void	fill_lexer(t_lexer **lexer, char *input_prompt);
int	peek_token(t_lexer *lexer);
t_token	*scan_token(t_lexer **lexer);
int	skip_quote(t_lexer *lexer, int *index);

#endif
