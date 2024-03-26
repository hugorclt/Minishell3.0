#include "minishell.h"

int	repl()
{
	char	*str;

	while (42)
	{
		str = readline("$> ");
		if (!str)
			return (FAILURE);
		init_lexer(str);
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

