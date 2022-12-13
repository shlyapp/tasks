#include "list_first_last_elements_flip.h"

list* firstElementToEnd(list* beg)
{
	list* newbeg = beg->next;

	list* end = beg;
	for (; end->next != NULL; end = end->next);
	end->next = beg;
	beg->next = NULL;

	return newbeg;
}