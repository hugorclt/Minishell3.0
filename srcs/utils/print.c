#include "utils.h"

static void	print_tree_utils(t_node *root, int space)
{
	int	i;

	i = STEP_PRINT_TREE;
	if (!root)
		return ;
	space += STEP_PRINT_TREE;
	print_tree_utils(root->left, space);
	printf("\n");
	while (i < space)
	{
		printf(" ");
		i++;
	}
	if (root->token && root->token->cmd)
		printf("%s\n", root->token->cmd[0]);
	print_tree_utils(root->right, space);
}

void	print_tree(t_node *tree)
{
	print_tree_utils(tree, 0);
}
