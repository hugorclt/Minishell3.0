#include "minishell.h"

int	repl()
{
	char	*str;
	t_lexer	*lexer;

	lexer = init_lexer();
	while (42)
	{
		str = readline("$> ");
		if (!str)
			return (FAILURE);
		fill_lexer(&lexer, str);
		scan_token(&lexer);	
		scan_token(&lexer);	
		scan_token(&lexer);	
		scan_token(&lexer);	
		scan_token(&lexer);	
		scan_token(&lexer);	
		scan_token(&lexer);	
		scan_token(&lexer);	
		scan_token(&lexer);	
		free(str);
	}
	return (1);
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;

	int ret;

	ret = repl();
	return (ret);
}

