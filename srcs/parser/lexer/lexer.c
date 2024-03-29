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
	if (!ft_strncmp(token, "", 1))
		return (ft_tablen(lexer->token_array) + 1);
	return (ft_tablen(lexer->token_array));
}

// might break if we reach end of line
t_token	*scan_token(t_lexer **lexer)
{
	char	*cmd;
	t_token	*token;

	cmd = get_token(*lexer);
	if (!cmd)
		return (NULL);
	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->cmd = ft_split(cmd, ' ');
	if (!token->cmd)
		return (NULL);

	// Transformation step here (in order): expand, splitting, unquotting

	token->type = peek_token(*lexer);
	(*lexer)->input_prompt += ft_strlen(cmd);
	return (token);
}
