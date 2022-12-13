#ifndef LIST_MOD

#define NULL 0
#define LIST_MOD

struct list
{
	int num;
	struct list* next;
};

void list_work();

#endif
