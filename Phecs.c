#include "Phecs.h"

//��ʼ������
void Queuecsh(Queue* Q)
{
	(*Q) = NULL;
}

//���
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

//����
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

//�鿴��ͷԪ��
Tree FrontQueue(Queue Q)
{
	assert(Q);
	return Q->last->x;
}

//��ʼ��ջ
void Stackcsh(Stack* S)
{
	*S = (Stack)malloc(sizeof(struct stack));
	(*S)->capacity = 100;
	(*S)->size = 0;
	(*S)->arr = (Tree)malloc(sizeof(struct tree) * (*S)->capacity);
}

//ѹջ
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

//��ջ
Tree pop_S(Stack S)
{
	assert(S->size != 0);
	return S->arr[--S->size];
}

//�鿴ջ��Ԫ��
Tree top_S(Stack S)
{
	assert(S->size != 0);
	return S->arr[S->size - 1];
}

//��ʼ��������
void Treecsh(Tree* T)
{
	*T = NULL;
}

//�������ڵ�
Tree czjd(SJLX x)
{
	Tree T = (Tree)malloc(sizeof(struct tree));
	T->x = x;
	T->Zson = NULL;
	T->Yson = NULL;
	T->Height = 1;
	return T;
}

//����ת������
int Tree_H(Tree T)
{
	return (T->Zson->Height > T->Yson->Height ? T->Zson->Height : T->Yson->Height) + 1;
}

//LL��ת����
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

//LR��ת����
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

//RR��ת����
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

//RL��ת����
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

//�������ݣ�ƽ���������ҷ������ĸ߶�
int push_Tree(Tree* T, Tree Tx)
{
	//�ж��Ƿ�����λ��
	if (*T == NULL)
	{
		*T = Tx;
		return Tx->Height;
	}
	//�ж��Ƿ����ʧ��
	else if ((*T)->x == Tx->x)
	{
		return -1;
	}
	//�ж��Ƿ���ݹ�
	else if ((*T)->x > Tx->x)
	{
		int h = push_Tree(&(*T)->Zson, Tx);
		//�ж��Ƿ����ʧ��
		if (h == -1)
		{
			return -1;
		}
		//����ת���
		else if (h==1)
		{
			return (*T)->Height = 2;
		}
		else if ((*T)->Yson != NULL && (*T)->Zson->Height - (*T)->Yson->Height != 2)
		{
			return (*T)->Height = Tree_H(*T);
		}
		//�ж��Ƿ�LL��ת
		else if ((*T)->Zson->Zson != NULL &&
			(*T)->Zson->Height == (*T)->Zson->Zson->Height + 1 &&
			(*T)->Zson->Height == (*T)->Height &&
			((*T)->Yson == NULL || (*T)->Height - (*T)->Yson->Height == 2))
		{
			//LL��ת����
			return LLTree(T);
		}
		//LR��ת
		else
		{
			return LRTree(T);
		}
	}
	//�ж��Ƿ��ҵݹ�
	else if ((*T)->x > Tx->x)
	{
		int h = push_Tree(&(*T)->Yson, Tx);
		//�ж��Ƿ����ʧ��
		if (h == -1)
		{
			return -1;
		}
		//����ת���
		else if (h == 1)
		{
			return (*T)->Height = 2;
		}
		else if ((*T)->Zson != NULL && (*T)->Yson->Height - (*T)->Zson->Height != 2)
		{
			return (*T)->Height = Tree_H(*T);
		}
		//�ж��Ƿ�RR��ת
		else if ((*T)->Yson->Yson != NULL &&
			(*T)->Yson->Height == (*T)->Yson->Yson->Height + 1 &&
			(*T)->Yson->Height == (*T)->Height &&
			((*T)->Zson == NULL || (*T)->Height - (*T)->Zson->Height == 2))
		{
			//RR��ת����
			return RRTree(T);
		}
		//RL��ת
		else
		{
			return RLTree(T);
		}
	}
}

//��������(��),����ʧ�ܷ���-1������ɹ��������ĸ߶�
int push_x(Tree* T, SJLX x)
{
	//���ô���ڵ㺯������ڵ�
	Tree Tx = czjd(x);
	//�������ݲ���ƽ����
	int h = push_Tree(T,Tx);
	if (h == -1)
		return -1;
	else
		return (*T)->Height = h;
}

//�������ݣ��������ݵ�ַ������ʧ�ܷ���NULL
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

//ǰ�������,���������ڵ�ĸ������ɴ���������
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

//���������,���������ڵ�ĸ������ɴ���������
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

//���������,���������ڵ�ĸ���
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

//������������������Ľڵ���
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

//LL��ת����
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
	//��������
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

//RR��ת����
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
	//��������
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

//ɾ���ڵ�,ɾ���ɹ��������ߣ�ʧ�ܷ���-1
void pop_x(Tree* T, SJLX x)
{
	Tree Xcmp, cmp, Scmp, Scmpson;
	cmp = *T;
	Stack S;
	Stackcsh(S);
	//Ѱ��ɾ���ڵ㣬����·���ڵ����ջ��
	while (cmp || cmp->x != x)
	{
		push_S(S, cmp);
		if (cmp->x > x)
			cmp = cmp->Zson;
		else
			cmp = cmp->Yson;
	}
	//�ж��Ƿ��иýڵ�
	if (!cmp)
	{
		return -1;
	}
	//�ж��Ƿ�ɾ��ֻ��һ���ڵ����
	if (S->size == 0)
	{
		*T = NULL;
		free(cmp);
		return 0;
	}
	//��¼ɾ�����ݽڵ�
	Xcmp = cmp;
	//�жϸýڵ�λ��
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
	//�ýڵ�����Ҷ��Ӷ���Ϊ��
	else
	{
		//Ѱ������ڵ�,����·���ڵ��������ջ��
		push_S(S, cmp);
		cmp = cmp->Zson;
		while (cmp->Zson == NULL || cmp->Yson == NULL)
		{
			push_S(S, cmp);
			cmp = cmp->Yson;
		}
		//������ڵ�����ݵ����ݿ�����ɾ���ڵ㣬ɾ������ڵ�
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
	//ƽ����
	while (S->size)
	{
		Scmp = pop_S(S);
		//�ж�ɾ��������������
		if (Scmp->Zson == Scmpson)
		{


		}
		else
		{
		}
	}
}
