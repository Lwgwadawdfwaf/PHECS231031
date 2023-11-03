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
	printf("込込込込込込込込込込込込込込込込込込込\n");
	Tree t1 = find_T(T1, 5000);
	Tree t2 = find_T(T1, 50000);
	printf("%d\n", t1->x);
	if(t2==NULL)
		printf("%d\n", (int)t2);
	int x = traverse_QT(T1, &cccop_F);
	printf("\n%d", x);
}

void test3()
{
	Stack S;
	Stackcsh(&S);

}
void test4()
{
	Tree T;
	Treecsh(&T);
	for (int i = 0; i < 60000; i++)
	{
		push_x(&T, i);
	}
	int x = traverse_ZT(T, &cccop_F);
	/*pop_x(&T, 2069);
	pop_x(&T, 2068);
	pop_x(&T,2070);*/
	/*for (int i = 0; i < 10000; i++)
	{
		pop_x(&T, i);
		
	}*/
	for (int i = 50000; i >= 0; i--)
	{
		pop_x(&T, i);
	}
	printf("\n");
	int size = traverse_QT(T, cccop_F);
	printf("\n%d\n", size);
	pop_min_x(&T); 
	pop_min_x(&T);
	size = traverse_HT(T/*, cccop_F*/);
	printf("\n%d\n", size);
	printf("\n%d\n%d\n%d\n", ChangeTree(&T, 1000000, -1), ChangeTree(&T, 500000, -1), ChangeTree(&T, 50100, 1000000));
	//pop_max_x(&T);
	/*pop_max_x(&T);
	pop_max_x(&T);
	pop_max_x(&T);
	pop_max_x(&T);
	pop_max_x(&T);
	pop_max_x(&T);
	pop_max_x(&T);
	pop_max_x(&T);
	pop_max_x(&T);
	pop_max_x(&T);
	pop_max_x(&T);
	pop_min_x(&T);
	pop_max_x(&T);
	pop_min_x(&T);
	pop_max_x(&T);
	pop_min_x(&T);
	pop_max_x(&T);
	pop_min_x(&T);*/


	/*size = traverse_ZT(T, &cccop_F);
	printf("\n%d\n \\n\\", size);*/
}

int main()
{
	test4();
	return 0;
}