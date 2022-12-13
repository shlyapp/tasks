#include "listprinter.h"

void printList(list* beg)
{
	while (beg != 0)
	{
		printf("%d  ", beg->num);
		beg = beg->next;
	}
	printf("\n");
}