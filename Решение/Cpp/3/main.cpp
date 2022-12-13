#include <iostream>

struct list
{
	int num;
	struct list* next;
};

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

void printList(list* beg)
{
	while (beg != NULL)
	{
		printf("%d  ", beg->num);
		beg = beg->next;
	}
	printf("\n");
}

list* firstElementToEnd(list* beg) // возвращает указатель на новое начало списка
{
	list* newbeg = beg->next;

	list* end = beg;
	for (; end->next != NULL; end = end->next);
	end->next = beg;
	beg->next = NULL;

	return newbeg;
}

int main()
{
	list* my_list = NULL;
	my_list = addLast(my_list, 1);
	my_list = addLast(my_list, 2);
	my_list = addLast(my_list, 3);
	my_list = addLast(my_list, 4);
	my_list = addLast(my_list, 5);
	my_list = addLast(my_list, 6);

	printList(my_list);
	my_list = firstElementToEnd(my_list);
	printList(my_list);

	return 0;
}