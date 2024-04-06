/*
Assignment name  : ft_list_size
Expected files   : ft_list_size.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/
//ft_list.h
// #ifndef FT_LIST_H
// # define FT_LIST_H

// typedef struct s_list
// {
// struct s_list *next;
// void *data;
// } t_list;

// #endif

#include "ft_list.h"
int ft_list_size(t_list *begin_list)
{
	int i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return i;
}


#include <stdio.h>
int main()
{
	t_list a, b, c;
	a.next = &b;
	b.next = &c;
	c.next = NULL;

	int data1 = 1, data2 = 2, data3 = 3;
	a.data = &data1;
	b.data = &data2;
	c.data = &data3;

	t_list *ptr = &a;
	printf("%d\n", ft_list_size(ptr));
}

