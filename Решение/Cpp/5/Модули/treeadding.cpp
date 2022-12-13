#include "treeadding.h"

tree* addtree(tree* top, const NOTE& newtree) 
{
	if (top == NULL) { //если находимся на уровне листа,
	//то выделить память под узел

		top = (tree*)malloc(sizeof(tree));
		if (!top) { //выход если память не выделена
			printf("Не хватает памяти\n");
			return NULL;
		}
		top->data = newtree; //запись данных в узел
		top->left = NULL; //обнуление указателей
		top->right = NULL;
	}
	else // иначе сравниваем значение в узле с добавляемым
		if (strcmp(top->data.phone, newtree.phone) > 0)
			// добавляем в левое поддерево
			top->left = addtree(top->left, newtree);
		else //или в правое поддерево
			top->right = addtree(top->right, newtree);

	return top; //возвращаем указатель на корень дерева
}