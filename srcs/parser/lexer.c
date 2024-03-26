#include "lexer.h"

static char	*get_token(t_lexer *lexer)
{
	(void)lexer;
	return (NULL);
}

t_lexer	*init_lexer(char *input_prompt)
{
	t_lexer	*lexer;

	lexer = (t_lexer *)malloc(sizeof(lexer));
	if (!lexer)
		return (NULL);
	lexer->input_prompt = input_prompt;
	return (lexer);
}

void	peek_token(t_lexer *lexer)
{
	(void)lexer;
}

void	scan_token(t_lexer *lexer)
{
	char	*token;

	token = get_token(lexer);
	lexer->input_prompt += ft_strlen(token);
	// return (init_token(token));
}
