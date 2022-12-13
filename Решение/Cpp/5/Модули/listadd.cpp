#include "listadd.h"

list* addLast(list* beg, int num)
{
	list* element = (list*)malloc(sizeof(list));
	element->num = num;
	element->next = NULL;

	if (beg == NULL)
	{
		beg = element;
	}
	else
	{
		list* end = beg;
		for (; end->next != NULL; end = end->next);
		end->next = element;
	}

	return beg;
}