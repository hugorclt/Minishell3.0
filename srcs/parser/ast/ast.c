#include "ast.h"

t_node	*new_node(t_token *token, t_node *left, t_node *right, t_node *parent)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->left = left;
	node->right = right;
	node->parent = parent;
	node->token = token;
	return (node);
}

t_node	*parse_redirect(t_lexer **lexer, t_node *parent)
{
	return (new_node(scan_token(lexer), NULL, NULL, parent));	
}

static t_node	*parse_simple_cmd(t_lexer **lexer, t_node *parent)
{
	t_node *left;
	t_node *right;
	int next_token;
	t_token *token;

	next_token = peek_token(*lexer);
	while (next_token == HEREDOC || next_token == APPEND || next_token == INFILE || next_token == OUTFILE)
	{
		if (next_token == HEREDOC || next_token == INFILE)
			left = parse_redirect(lexer, parent);
		else
			right = parse_redirect(lexer, parent);
		next_token = peek_token(*lexer);
	}
	if (next_token == CMD)
		token = scan_token(lexer);
	else
	{
		printf("minishell: syntax error: parse_simple_cmd\n");
		return (NULL);
	}
	while (next_token == HEREDOC || next_token == APPEND || next_token == INFILE || next_token == OUTFILE || next_token == CMD)
	{
		if (next_token == HEREDOC || next_token == INFILE)
			left = parse_redirect(lexer, parent);
		else if (next_token == APPEND || next_token == OUTFILE)
			right = parse_redirect(lexer, parent);
		else if (next_token == CMD)
			token->cmd = ft_tabjoin(token->cmd, scan_token(lexer)->cmd); //--> leak
		next_token = peek_token(*lexer);
	}
	return (new_node(token, left, right, parent));
}

static t_node	*parse_command(t_lexer **lexer, t_node *parent)
{
	t_node	*result;
	int next_token;

	next_token = peek_token(*lexer);
	if (next_token == R_PARENTH)
	{
		scan_token(lexer);// --> to free
		result = parse_and_or(lexer, parent);
		scan_token(lexer); // --> to free
	}
	else if (next_token == CMD)
		result = parse_simple_cmd(lexer, parent);
	else
		printf("minishell: syntax error: parse_command\n");
	return (result);
}

static t_node	*parse_pipeline(t_lexer **lexer, t_node *parent)
{
	t_node *right_cmd;
	t_node *result;
	t_node *left_cmd;
	t_token *token;
	int next_token;

	right_cmd = parse_command(lexer, parent);
	result = NULL;
	while (42)
	{
		next_token = peek_token(*lexer);
		if (next_token == PIPE)
		{
			token = scan_token(lexer);
			left_cmd = parse_command(lexer, parent); // bug ici parce que le parent est cense etre la variable result
			result = new_node(token, left_cmd, right_cmd, parent);
		}
		else if (next_token == END)
		{
			if (!result)
				return (right_cmd);
			return (result);
		}	
		else
		{
			printf("minishell: syntax error: parse_pipeline\n");
			return (NULL);
		}
	}
	return (result);
}

t_node *parse_and_or(t_lexer **lexer, t_node *parent)
{
	t_node *right_pipeline;
	t_node *result;
	t_node *left_pipeline;
	t_token *token;
	int		next_token;

	right_pipeline = parse_pipeline(lexer, parent);
	result = NULL;
	while (42)
	{
		next_token = peek_token(*lexer);
		if (next_token == OR || next_token == AND)
		{
			token = scan_token(lexer);
			left_pipeline = parse_pipeline(lexer, parent); // bug ici parce que le parent est cense etre la variable result
			result = new_node(token, left_pipeline, right_pipeline, parent);
		}
		else if (next_token == END)
		{
			if (!result)
				return (right_pipeline);
			return (result);
		}
		else
		{
			printf("minishell: syntax error: parse_and_or");
			return (NULL);
		}
	}
	return (result);
}

t_node	*get_complete_ast(t_lexer **lexer)
{
	t_node	*tree;

	tree = parse_and_or(lexer, NULL);
	return (tree);
}
