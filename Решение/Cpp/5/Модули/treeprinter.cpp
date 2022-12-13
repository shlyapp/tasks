#include "treeprinter.h"

void printTree(tree* node, int level)
{
	if (node == NULL)
		return;
	printTree(node->right, level + 1);
	if (level != 0) {
		for (int i = 0;i < level - 1;i++)
			printf("|\t");
		printf("|-------%d\n", node->data.num);
	}
	else
		printf("%d\n", node->data.num);
	printTree(node->left, level + 1);
}

void findNote(tree* top, char value[d_p])
{
	if (top == NULL) return;

	if (strcmp(top->data.phone, value) == 0)
	{
		printf("num = %d  ", top->data.num);
		printf("name = %s  ", top->data.name);
		printf("fam = %s  ", top->data.fam);
		printf("phone = %s ", top->data.phone);
		printf("birhday = %d.%d.%d\n", top->data.birthday[0], top->data.birthday[1], top->data.birthday[2]);
	}
	else if (strcmp(top->data.phone, value) > 0)
	{
		// ���� � ����� ���������
		if (top->left == NULL)
		{
			printf("���������� �� �������!\n");
			return;
		}
		findNote(top->left, value);
	}
	else // ���� � ������ ���������
	{
		if (top->right == NULL)
		{
			printf("���������� �� �������!\n");
			return;
		}
		findNote(top->right, value);
	}
}

void printLeafes(tree* top) { // ���������� ��� ������ ������
	if (top == NULL) return;

	if (top->left == NULL && top->right == NULL) { // �������� ������
		printf("num = %d  ", top->data.num);
		printf("name = %s  ", top->data.name);
		printf("fam = %s  ", top->data.fam);
		printf("phone = %s ", top->data.phone);
		printf("birhday = %d.%d.%d\n", top->data.birthday[0], top->data.birthday[1], top->data.birthday[2]);
	}
	else
	{
		printLeafes(top->left); //����� ������ ���������
		printLeafes(top->right); //����� ������� ���������
	}
}