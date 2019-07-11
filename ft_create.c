#include "libft/libft.h"

void	ft_create(char *nums)
{
	t_list *a;
	t_list *b;
	char **data;
	t_list *head;
	char *line;
	int	i, j;

	head = NULL;
	a = NULL;
	b = NULL;
	data = ft_strsplit(nums, ' ');
	i = -1;
	while (data[++i] != NULL)
		ft_lstadd(&a, ft_lstnew(data[i], ft_strlen(data[i]) + 1));
	j = 0;
	while (get_next_line(0, &line) == 1)
	{
		ft_lstadd(&head, ft_lstnew(line, ft_strlen(line) + 1));
	}

	t_list *link;

	link = a;
	a = a->next;
	a->prev = NULL;
	link->prev = NULL;
	link->next = NULL;

	ft_lstadd(&b, link);

	link = a;
	a = a->next;
	a->prev = NULL;
	link->prev = NULL;
	link->next = NULL;

	ft_lstadd(&b, link);

	link = a->next;
	a->next = link->next;
	link->next->prev = a;
	link->prev = NULL;
	link->next = NULL;

	ft_lstadd(&a, link);
	link = a;
	while (link->next)
		link = link->next;
	link->prev->next = NULL;
	link->prev = NULL;
	link->next = NULL;
	ft_lstadd(&a, link);
	t_list *iter;
	iter = a;
	ft_putendl("A           ");
	while(iter)
	{
		ft_putendl(iter->content);
		iter = iter->next;
	}
	iter = b;
	ft_putendl("B");
	while(iter)
	{
		ft_putendl(iter->content);
		iter = iter->next;
	}
}

int		main(int ac, char **av)
{
	ft_create(av[1]);
}


