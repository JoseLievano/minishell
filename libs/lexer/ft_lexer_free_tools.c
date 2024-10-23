#include "ft_lexer.h"

void	free_token(t_dll *list)
{
	t_dll	*tmp;

	tmp = list;
    if (((t_token *)tmp->content)->value != NULL)
    {
        free(((t_token *)tmp->content)->value);
    }
    free(tmp->content);
}
void free_nodes(t_dll *list)
{
    t_dll_clear(list, &free_token);
}