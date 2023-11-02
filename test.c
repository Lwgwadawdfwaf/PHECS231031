#include "Phecs.h"

struct x
{
	int x;
	struct x* son;
};

void csh(struct x**ps)
{
	*ps = NULL;
}
void cccc(struct x** ps,int x)
{
	if (*ps == NULL)
	{
		*ps = (struct x*)malloc(sizeof(struct x));
		(*ps)->son = NULL;
		(*ps)->x = x;
	}
	else
	{
		struct x* cmp = *ps;
		while (cmp->son)
		{
			cmp = cmp->son;
		}
		cmp->son = (struct x*)malloc(sizeof(struct x));
		cmp->son->x = x;
		cmp->son->son = NULL;
	}
	if ((*ps)->x == 3)
	{
		*ps = NULL;
	}
}

void printX(struct x* ps)
{
	while (ps)
	{
		printf("%d ", ps->x);
		ps = ps->son;
	}
}

void test()
{
	struct x* x1;
	csh(&x1);
	cccc(&x1, 1);
	cccc(&x1->son,2);
	cccc(&x1->son,3);
	cccc(&x1->son->son, 4);
	cccc(&x1->son, 5);
	cccc(&x1->son,6);
	printX(x1);
}

void cccop_F(Tree T)
{
	printf("%d ", T->x);
}

void test2()
{
	Tree T1;
	Treecsh(&T1);
	for (int i = 10000; i > 0; i--)
	{
		push_x(&T1, i);
	}
	printf("��������������������������������������\n");
	Tree t1 = find_T(T1, 5000);
	Tree t2 = find_T(T1, 50000);
	printf("%d\n", t1->x);
	if(t2==NULL)
		printf("%d\n", (int)t2);
	int x = traverse_T(T1);
	printf("\n%d", x);
}

void test3()
{
	Stack S;
	Stackcsh(&S);

}
void test4()
{

}

int main()
{
	test2();
	return 0;
}