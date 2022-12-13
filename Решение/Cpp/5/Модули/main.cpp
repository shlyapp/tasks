#include "listadd.h"
#include "listprinter.h"
#include "list_first_last_elements_flip.h"

#include "treeprinter.h"
#include "treeadding.h"

int main()
{
	// запуск модуля со списком
	list_work();

	printf("\n\n");

	// запуск модуля с бинарным деревом
	tree_work();

	return 0;
}