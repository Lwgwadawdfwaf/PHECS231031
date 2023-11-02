#include "Phecs.h"

//初始化队列
void Queuecsh(Queue* Q)
{
	(*Q) = NULL;
}

//入队
void InQueue(Queue* Q, Tree T)
{
	Queue node = (Queue)malloc(sizeof(struct queue));
	node->x = T;
	if (!(*Q))
	{
		*Q= node;
		(*Q)->next = NULL;
		(*Q)->last = node;
	}
	else
	{
		node->next = *Q;
		node->last = (*Q)->last;
		(*Q)->last = node;
		*Q = node;
	}
}

//出队
Tree OutQueue(Queue* Q)
{
	assert((*Q)->last != NULL);
	Queue cmp = (*Q)->last;
	Tree Tcmp = cmp->x;
	if ((*Q)->next == NULL)
	{
		*Q = NULL;
	}
	else
	{
		(*Q)->last = cmp->last;
		cmp->last->next = NULL;
	}
	free(cmp);
	return Tcmp;

}

//查看队头元素
Tree FrontQueue(Queue Q)
{
	assert(Q);
	return Q->last->x;
}

//初始化栈
void Stackcsh(Stack* S)
{
	*S = (Stack)malloc(sizeof(struct stack));
	(*S)->capacity = 100;
	(*S)->size = 0;
	(*S)->arr = (Tree)malloc(sizeof(struct tree) * (*S)->capacity);
}

//压栈
void push_S(Stack S, Tree T)
{
	if (S->capacity == S->size)
	{
		S->capacity *= 2;
		Tree cmp = (Tree)realloc(S->arr, sizeof(struct tree) * S->capacity);
		assert(cmp != NULL);
		S->arr = cmp;
	}
	S->arr[S->size++] = T;
}

//弹栈
Tree pop_S(Stack S)
{
	assert(S->size != 0);
	return S->arr[--S->size];
}

//查看栈顶元素
Tree top_S(Stack S)
{
	assert(S->size != 0);
	return S->arr[S->size - 1];
}

//初始化二叉树
void Treecsh(Tree* T)
{
	*T = NULL;
}

//创造树节点
Tree czjd(SJLX x)
{
	Tree T = (Tree)malloc(sizeof(struct tree));
	T->x = x;
	T->Zson = NULL;
	T->Yson = NULL;
	T->Height = 1;
	return T;
}

//无旋转求树高
int Tree_H(Tree T)
{
	return (T->Zson->Height > T->Yson->Height ? T->Zson->Height : T->Yson->Height) + 1;
}

//LL旋转函数
int LLTree(Tree* T)
{
	Tree T_, T_L, T_LR;
	T_ = *T;
	T_L = (*T)->Zson;
	T_LR = (*T)->Zson->Yson;
	*T = T_L;
	T_L->Yson = T_;
	T_->Zson = T_LR;
	T_->Height--;
	return (*T)->Height;
}

//LR旋转函数
int LRTree(Tree* T)
{
	if ((*T)->Height == 2)
	{
		Tree T_, T_L, T_LR;
		T_ = *T;
		T_L = (*T)->Zson;
		T_LR = (*T)->Zson->Yson;
		*T = T_LR;
		T_L->Yson = NULL;
		T_->Zson = NULL;
		T_LR->Yson = T_;
		T_LR->Zson = T_L;
	}
	else
	{
		Tree T_, T_L, T_LR, T_LRL, T_LRR;
		T_ = *T;
		T_L = (*T)->Zson;
		T_LR = (*T)->Zson->Yson;
		T_LRL = (*T)->Zson->Yson->Zson;
		T_LRR = (*T)->Zson->Yson->Yson;
		*T = T_LR;
		T_L->Yson = T_LRL;
		T_->Zson = T_LRR;
		T_LR->Yson = T_;
		T_LR->Zson = T_L;
		T_L->Height = Tree_H(T_L);
		T_->Height = Tree_H(T_);
		return (*T)->Height = Tree_H(*T);
	}
}

//RR旋转函数
int RRTree(Tree* T)
{
	Tree T_, T_R, T_RL;
	T_ = *T;
	T_R = (*T)->Yson;
	T_RL = (*T)->Yson->Zson;
	*T = T_R;
	T_R->Zson = T_;
	T_->Yson = T_RL;
	T_->Height--;
	return (*T)->Height;
}

//RL旋转函数
int RLTree(Tree* T)
{
	if ((*T)->Height == 2)
	{
		Tree T_, T_R, T_RL;
		T_ = *T;
		T_R = (*T)->Yson;
		T_RL = (*T)->Yson->Zson;
		*T = T_RL;
		T_R->Zson = NULL;
		T_->Yson = NULL;
		T_RL->Zson = T_;
		T_RL->Yson = T_R;
	}
	else
	{
		Tree T_, T_R, T_RL, T_RLR, T_RLL;
		T_ = *T;
		T_R = (*T)->Yson;
		T_RL = (*T)->Yson->Zson;
		T_RLR = (*T)->Yson->Zson->Yson;
		T_RLL = (*T)->Yson->Zson->Zson;
		*T = T_RL;
		T_R->Zson = T_RLR;
		T_->Yson = T_RLL;
		T_RL->Zson = T_;
		T_RL->Yson = T_R;
		T_R->Height = Tree_H(T_R);
		T_->Height = Tree_H(T_);
		return (*T)->Height = Tree_H(*T);
	}
}

//插入数据，平衡树，并且返回树的高度
int push_Tree(Tree* T, Tree Tx)
{
	//判断是否插入此位置
	if (*T == NULL)
	{
		*T = Tx;
		return Tx->Height;
	}
	//判断是否插入失败
	else if ((*T)->x == Tx->x)
	{
		return -1;
	}
	//判断是否左递归
	else if ((*T)->x > Tx->x)
	{
		int h = push_Tree(&(*T)->Zson, Tx);
		//判断是否插入失败
		if (h == -1)
		{
			return -1;
		}
		//无旋转情况
		else if (h==1)
		{
			return (*T)->Height = 2;
		}
		else if ((*T)->Yson != NULL && (*T)->Zson->Height - (*T)->Yson->Height != 2)
		{
			return (*T)->Height = Tree_H(*T);
		}
		//判断是否LL旋转
		else if ((*T)->Zson->Zson != NULL &&
			(*T)->Zson->Height == (*T)->Zson->Zson->Height + 1 &&
			(*T)->Zson->Height == (*T)->Height &&
			((*T)->Yson == NULL || (*T)->Height - (*T)->Yson->Height == 2))
		{
			//LL旋转函数
			return LLTree(T);
		}
		//LR旋转
		else
		{
			return LRTree(T);
		}
	}
	//判断是否右递归
	else if ((*T)->x > Tx->x)
	{
		int h = push_Tree(&(*T)->Yson, Tx);
		//判断是否插入失败
		if (h == -1)
		{
			return -1;
		}
		//无旋转情况
		else if (h == 1)
		{
			return (*T)->Height = 2;
		}
		else if ((*T)->Zson != NULL && (*T)->Yson->Height - (*T)->Zson->Height != 2)
		{
			return (*T)->Height = Tree_H(*T);
		}
		//判断是否RR旋转
		else if ((*T)->Yson->Yson != NULL &&
			(*T)->Yson->Height == (*T)->Yson->Yson->Height + 1 &&
			(*T)->Yson->Height == (*T)->Height &&
			((*T)->Zson == NULL || (*T)->Height - (*T)->Zson->Height == 2))
		{
			//RR旋转函数
			return RRTree(T);
		}
		//RL旋转
		else
		{
			return RLTree(T);
		}
	}
}

//插入数据(总),插入失败返回-1，插入成功返回树的高度
int push_x(Tree* T, SJLX x)
{
	//调用创造节点函数创造节点
	Tree Tx = czjd(x);
	//插入数据并且平衡树
	int h = push_Tree(T,Tx);
	if (h == -1)
		return -1;
	else
		return (*T)->Height = h;
}

//查找数据，返回数据地址，查找失败返回NULL
Tree find_T(Tree T, SJLX x)
{
	/*if (T == NULL || T->x == x)
		return T;
	if (T->x > x)
		return find_T(T->Zson, x);
	if (T->x < x)
		return find_T(T->Yson, x);*/
	Tree cmp = T;
	while (cmp && cmp->x != x)
	{
		if (cmp->x > x)
			cmp = cmp->Zson;
		else
			cmp = cmp->Yson;
	}
	return cmp;
}

//前序遍历树,并返回树节点的个数，可传操作函数
int traverse_QT(Tree T, void* (op_F)(Tree))
{
	if (T == NULL)
		return 0;
	int size = 1;
	op_F(T);
	size += traverse_QT(T->Zson, op_F);
	size += traverse_QT(T->Yson, op_F);
	return size;
}

//中序遍历树,并返回树节点的个数，可传操作函数
int traverse_ZT(Tree T, void* (op_F)(Tree))
{
	if (T == NULL)
		return 0;
	Stack S;
	Stackcsh(&S);
	Tree cmp = T;
	int size = 0;
	while (cmp || S->size != 0)
	{
		while (cmp)
		{
			push_S(S, cmp);
			size++;
			cmp = cmp->Zson;
		}
		cmp = pop_S(S);
		op_F(cmp);
		cmp = cmp->Yson;
	}
	return size;
}

//后序遍历树,并返回树节点的个数
int traverse_HT(Tree T)
{
	if (T == NULL)
		return 0;
	Tree cmp = T;
	Stack S,Scmp;
	Stackcsh(&S);
	Stackcsh(&Scmp);
	int size = 0;
	while (cmp || Scmp->size != 0)
	{
		while (cmp)
		{
			push_S(S, cmp);
			push_S(Scmp, cmp);
			size++;
			cmp = cmp->Yson;
		}
		cmp = pop_S(Scmp);
		cmp = cmp->Zson;
	}
	while (S->size)
	{
		printf("%d ", pop_S(S)->x);
	}
	printf("\n");
	return size;
}

//层序遍历，并返回树的节点数
int traverse_T(Tree T)
{
	if (!T)
	{
		return 0;
	}
	int size = 0;
	Tree cmp = T;
	Queue Q;
	Queuecsh(&Q);
	InQueue(&Q, cmp);
	while (Q)
	{
		cmp = OutQueue(&Q);
		size++;
		if (cmp->Zson)
			InQueue(&Q, cmp->Zson);
		if (cmp->Yson)
			InQueue(&Q, cmp->Yson);
	}
	return size;
}

//LL旋转函数
void LLTree_(Tree T)
{
	Tree T_, T_L, T_R, T_LL, T_LR;
	T_ = T;
	T_L = T->Zson;
	T_R = T->Yson;
	T_LL = T->Zson->Zson;
	T_LR = T->Zson->Yson;
	SJLX cmp = T->x;
	T->x = T_L->x;
	T_L->x = cmp;
	T_->Zson = T_LL;
	T_->Yson = T_L;
	T_L->Zson = T_LR;
	T_L->Yson = T_R;
	//整理树高
	if (T->Yson->Yson == NULL)
	{
		T->Yson->Height = 1;
	}
	else
	{
		T->Yson->Height = T->Yson->Zson->Height+1;
	}
	T->Height = Tree_H(T);
}

//RR旋转函数
void RRTree_(Tree T)
{
	Tree T_, T_R, T_L, T_RR, T_RL;
	T_ = T;
	T_R = T->Yson;
	T_L = T->Zson;
	T_RR = T->Yson->Yson;
	T_RL = T->Yson->Zson;
	SJLX cmp = T->x;
	T->x = T_R->x;
	T_R->x = cmp;
	T_->Yson = T_RR;
	T_->Zson = T_R;
	T_R->Yson = T_RL;
	T_R->Zson = T_L;
	//整理树高
	if (T->Zson->Zson == NULL)
	{
		T->Zson->Height = 1;
	}
	else
	{
		T->Zson->Height = T->Zson->Yson->Height + 1;
	}
	T->Height = Tree_H(T);
}

//删除节点,删除成功返回树高，失败返回-1
void pop_x(Tree* T, SJLX x)
{
	Tree Xcmp, cmp, Scmp, Scmpson;
	cmp = *T;
	Stack S;
	Stackcsh(S);
	//寻找删除节点，并把路过节点放入栈中
	while (cmp || cmp->x != x)
	{
		push_S(S, cmp);
		if (cmp->x > x)
			cmp = cmp->Zson;
		else
			cmp = cmp->Yson;
	}
	//判断是否有该节点
	if (!cmp)
	{
		return -1;
	}
	//判断是否删除只有一个节点的树
	if (S->size == 0)
	{
		*T = NULL;
		free(cmp);
		return 0;
	}
	//记录删除数据节点
	Xcmp = cmp;
	//判断该节点位置
	if (cmp->Zson == cmp->Yson)
	{
		Scmp = top_S(S);
		if (Scmp->Zson == cmp)
			Scmp->Zson = NULL;
		else
			Scmp->Yson = NULL;
		Scmpson = NULL;
		free(cmp);
	}
	else if (cmp->Yson == NULL)
	{
		Scmp = top_S(S);
		if (Scmp->Zson == cmp)
			Scmp->Zson = cmp->Zson;
		else
			Scmp->Yson = cmp->Zson;
		Scmpson = cmp->Zson;
		free(cmp);
	}
	else if (cmp->Zson == NULL)
	{
		Scmp = top_S(S);
		if (Scmp->Zson == cmp)
			Scmp->Zson = cmp->Yson;
		else
			Scmp->Yson = cmp->Yson;
		Scmpson = cmp->Yson;
		free(cmp);
	}
	//该节点的左右儿子都不为空
	else
	{
		//寻找替代节点,并把路过节点继续放入栈中
		push_S(S, cmp);
		cmp = cmp->Zson;
		while (cmp->Zson == NULL || cmp->Yson == NULL)
		{
			push_S(S, cmp);
			cmp = cmp->Yson;
		}
		//将替代节点的数据的数据拷贝到删除节点，删除替代节点
		Xcmp->x = cmp->x;
		if (cmp->Zson == cmp->Yson)
		{
			Scmp = top_S(S);
			if (Scmp->Zson == cmp)
				Scmp->Zson = NULL;
			else
				Scmp->Yson = NULL;
			Scmpson = NULL;
			free(cmp);
		}
		else if (cmp->Yson == NULL)
		{
			Scmp = top_S(S);
			if (Scmp->Zson == cmp)
				Scmp->Zson = cmp->Zson;
			else
				Scmp->Yson = cmp->Zson;
			Scmpson = cmp->Zson;
			free(cmp);
		}
		else if (cmp->Zson == NULL)
		{
			Scmp = top_S(S);
			if (Scmp->Zson == cmp)
				Scmp->Zson = cmp->Yson;
			else
				Scmp->Yson = cmp->Yson;
			Scmpson = cmp->Yson;
			free(cmp);
		}
	}
	//平衡树
	while (S->size)
	{
		Scmp = pop_S(S);
		//判断删除数据在左还是右
		if (Scmp->Zson == Scmpson)
		{


		}
		else
		{
		}
	}
}
