#include "treeadding.h"

tree* addtree(tree* top, const NOTE& newtree) 
{
	if (top == NULL) { //���� ��������� �� ������ �����,
	//�� �������� ������ ��� ����

		top = (tree*)malloc(sizeof(tree));
		if (!top) { //����� ���� ������ �� ��������
			printf("�� ������� ������\n");
			return NULL;
		}
		top->data = newtree; //������ ������ � ����
		top->left = NULL; //��������� ����������
		top->right = NULL;
	}
	else // ����� ���������� �������� � ���� � �����������
		if (strcmp(top->data.phone, newtree.phone) > 0)
			// ��������� � ����� ���������
			top->left = addtree(top->left, newtree);
		else //��� � ������ ���������
			top->right = addtree(top->right, newtree);

	return top; //���������� ��������� �� ������ ������
}