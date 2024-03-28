/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:32:19 by hrecolet          #+#    #+#             */
/*   Updated: 2024/03/27 15:32:34 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	skip_quote(t_lexer *lexer, int *index)
{
	char first_quote;
	int	quote_pos_save;

	first_quote = lexer->input_prompt[*index];
	quote_pos_save = *index;
	(*index)++;
	while (lexer->input_prompt[*index] && lexer->input_prompt[*index] != first_quote)
		(*index)++;
	if (!lexer->input_prompt[*index])
	{
		printf("minishell: '%c' not closed at index %d\n", first_quote, quote_pos_save);
		return (FAILURE);
	}
	return (SUCCESS);
}


t_lexer	*init_lexer()
{
	t_lexer	*lexer;

	lexer = (t_lexer *)malloc(sizeof(t_lexer));
	if (!lexer)
		return (NULL);
	lexer->input_prompt = NULL;
	lexer->token_array = ft_split("( ) && || | << >> < >", ' ');
	return (lexer);
}

void	clean_lexer(t_lexer *lexer)
{
	free(lexer->token_array[0]);
	free(lexer->token_array[1]);
	free(lexer->token_array[2]);
	free(lexer->token_array[3]);
	free(lexer->token_array[4]);
	free(lexer->input_prompt);
	free(lexer);
}
