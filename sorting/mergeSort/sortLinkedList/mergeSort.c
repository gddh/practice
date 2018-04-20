#include "linkedlist.h"

t_list	*merge(t_list *h1, t_list *h2)
{
	t_list *head;
	t_list *tmp;
	head = create_elem(0);
	tmp = head;
	while (h1 && h2)
	{
		if(h1->data < h2->data)
		{
			tmp->next = h1;
			h1 = h1->next;
		}
		else
		{
			tmp->next = h2;
			h2 = h2->next;
		}
		tmp = tmp->next;
	}
	while (h1)
	{
		tmp->next = h1;
		tmp = tmp->next;
		h1 = h1->next;
	}
	while (h2)
	{
		tmp->next = h2;
		tmp = tmp->next;
		h2 = h2->next;
	}
	return head->next;
}

t_list	*mergeSortHelper(t_list *head, t_list *tail)
{
	if (head == tail)
		return (head);
	else
	{
		t_list *mid;
		t_list *tmp;
		t_list *h1;
		t_list *h2;

		mid = head;
		tmp = head;
		while(tmp->next != tail && (tmp->next->next) != tail)
		{
			mid = mid->next;
			tmp = tmp->next->next;
		}
		tmp = mid->next;
		mid->next = NULL;
		h1 = mergeSortHelper(head, mid);
		h2 = mergeSortHelper(tmp, tail);
		return merge(h1, h2);
	}
}

t_list	*mergeSort(t_list	*head)
{
	t_list	*tail;

	tail = head;
	if (tail)
	{
		while (tail->next)
			tail = tail->next;
		return (mergeSortHelper(head, tail));
	}
	return (head);
}

int		main(void)
{
	t_list *p1;
	t_list *p2;
	t_list *res;
	int i;
	
	p1 = NULL;
	i = 20;
	while(i > 0)
	{
		push_back(&p1, i);
		i = i - 2;
	}
	print_list(p1);
	p2 = mergeSort(p1);
	print_list(p2);
}
