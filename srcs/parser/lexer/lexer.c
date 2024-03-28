#include "lexer.h"

int	is_token(t_lexer *lexer, int index)
{
	int	i;

	i = 0;
	while (lexer->token_array[i])
	{
		if (ft_strncmp(lexer->input_prompt + index, lexer->token_array[i], ft_strlen(lexer->token_array[i])) == 0)
			return (ft_strlen(lexer->token_array[i]));
		i++;
	}
	return (FALSE);
}

void	skip_to_next_word(char *input_prompt, int *i)
{
	if (input_prompt[0] == '<' || input_prompt[0] == '>')
	{
		while (input_prompt[(*i)] && ft_iswhitespace(input_prompt[(*i)]))
			(*i)++;
		while (input_prompt[(*i)] && !ft_iswhitespace(input_prompt[(*i)]))
			(*i)++;
	}
	while (input_prompt[(*i)] && ft_iswhitespace(input_prompt[(*i)]))
		(*i)++;
}

static char	*get_token(t_lexer *lexer)
{
	int i;
	int len_token;

	i = 0;
	while (lexer->input_prompt[i])
	{
		if (lexer->input_prompt[i] == '\"' || lexer->input_prompt[i] == '\'')
			if (skip_quote(lexer, &i) == FAILURE)
				return (NULL);
		len_token = is_token(lexer, i);
		if (len_token > 0)
		{
			if (i == 0)
				i += len_token;
//			while (lexer->input_prompt[i] && ft_iswhitespace(lexer->input_prompt[i]))
//					i++;
			skip_to_next_word(lexer->input_prompt, &i);
			return (ft_substring(lexer->input_prompt, 0, i));
		}
		i++;
	}
	return (ft_substring(lexer->input_prompt, 0, i));
}

void	fill_lexer(t_lexer **lexer, char *input_prompt)
{
	(*lexer)->input_prompt = input_prompt;
}

int	peek_token(t_lexer *lexer)
{
	const char *token;
	int	i;

	i = 0;
	token = get_token(lexer);
	if (!token)
		return (-1);
	while (lexer->token_array[i])
	{
		if (ft_strncmp(token, lexer->token_array[i], ft_strlen(lexer->token_array[i])) == 0)
			return (i);
		i++;
	}
	return (ft_tablen(lexer->token_array));
}

// might break if we reach end of line
void	scan_token(t_lexer **lexer)
{
	char	*token;

	token = get_token(*lexer);
	if (!token)
		return ;
	(*lexer)->input_prompt += ft_strlen(token);
	printf("%s\n", token);
	// return (init_token(token));
}
