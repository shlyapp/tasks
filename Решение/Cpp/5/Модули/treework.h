#ifndef TREE_WORK_MOD

#define NULL 0
#define TREE_WORK_MOD

const int d_p = 12; // ����� ������ ������ ��������  ->  11 ���� + \0

struct NOTE
{
	int num;
	char name[30], fam[30];
	char phone[d_p];
	int birthday[3];
};

struct tree // �������������� �� ������ ��������
{
	NOTE data;
	tree* left;
	tree* right;
};

void tree_work();

#endif