#include "treeadding.h"
#include "treeprinter.h"

void tree_work()
{
	setlocale(NULL, "ru");
	tree* my_tree = NULL;

	// вставл€ю узлы в дерево:
	NOTE note;
	note = { 1, "Alexey", "Nekrasov", "74948486204", {1, 6, 2005} };
	my_tree = addtree(my_tree, note);
	note = { 2, "Maxim", "Pechenkin", "76766783436", {2, 10, 2007} };
	addtree(my_tree, note);
	note = { 3, "Sasha", "Serb", "77192030526", {1, 4, 2002} };
	addtree(my_tree, note);
	note = { 4, "Danil", "Lekomtsev", "76613381725", {17, 2, 2005} };
	addtree(my_tree, note);
	note = { 5, "Vladimir", "Lomaev", "75727767284", {4, 1, 2005} };
	addtree(my_tree, note);
	note = { 6, "Slava", "Annenko", "72959093810", {5, 6, 1990} };
	addtree(my_tree, note);
	note = { 7, "Oleg", "Potemkin", "74189817674", {7, 9, 2003} };
	addtree(my_tree, note);
	note = { 8, "Zhitomir", "Kalachov", "79034943224", {5, 7, 2010} };
	addtree(my_tree, note);
	note = { 9, "Petr", "Karlovich", "72959093850", {2, 6, 1992} };
	addtree(my_tree, note);
	note = { 10, "Arkadiy", "Petrovich", "74189897674", {10, 4, 2009} };
	addtree(my_tree, note);
	note = { 11, "Mistofel", "Pavlovich", "79734943224", {9, 12, 2000} };
	addtree(my_tree, note);


	// отобразить дерево
	printf("ќтображение всего дерева:\n");
	printTree(my_tree, 0);

	printf("\n\n");

	// отобразить листь€
	printf("ќтображение листьев дерева:\n");
	printLeafes(my_tree);

	// ищем по существующему номеру
	printf("\n»щем по существующему номеру:\n");
	char phone1[] = "76613381725";
	findNote(my_tree, phone1);

	// ищем по несуществующему номеру
	printf("»щем по несуществующему номеру:\n");
	char phone2[] = "76613381726";
	findNote(my_tree, phone2);
}