#include "listadd.h"
#include "listprinter.h"
#include "list_first_last_elements_flip.h"

void list_work()
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
}