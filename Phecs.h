#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//链表的形式写一个平衡二叉树

#define SJLX int //定义数据的类型
typedef struct tree* Tree;//重命名树，或者说重命名树节点

//定义二叉树结构体
struct tree
{
	SJLX x;
	struct tree* Zson;//树的左儿子指针
	struct tree* Yson;//数的右儿子指针
	int Height;//树的高度
};

typedef struct stack* Stack;//重命名栈

//定义栈结构体
struct stack
{
	Tree* arr;//栈数组
	int size;//栈大小
	int capacity;//栈容量
};

typedef struct queue* Queue;//重命名队列

//定义队列结构体
struct queue
{
	struct queue* last;//队列上一个节点地址
	Tree x;//储存数据
	struct queue* next;//队列下一个节点地址
};


//初始化队列
void Queuecsh(Queue* Q);

//入队
void InQueue(Queue Q, Tree T);

//出队
Tree OutQueue(Queue Q);

//查看队头元素
Tree FrontQueue(Queue Q);

//初始化栈
void Stackcsh(Stack* S);

//压栈
void push_S(Stack S, Tree T);

//弹栈
Tree pop_S(Stack S);

//查看栈顶元素
Tree top_S(Stack S);

//初始化二叉树
void Treecsh(Tree* T);

//创造树节点,并返回创造的树节点的地址
Tree czjd(SJLX x);

//LL旋转函数
int LLTree(Tree* T);

//LR旋转函数
int LRTree(Tree* T);

//LL旋转函数
int LLTree(Tree* T);

//LR旋转函数
int LRTree(Tree* T);

//插入数据，平衡树，插入失败返回-1，插入成功返回树的高度
int push_Tree(Tree* T, Tree tx);

//插入数据x，平衡树，插入失败返回-1，插入成功返回树的高度
int push_x(Tree* T, SJLX x);

//查找数据，返回数据地址，查找失败返回NULL
Tree find_T(Tree T, SJLX x);

//前序遍历树,并返回树节点的个数，可传操作函数
int traverse_QT(Tree T,void*(op_F)(Tree));

//中序遍历树,并返回树节点的个数，可传操作函数
int traverse_ZT(Tree T, void* (op_F)(Tree));

//后序遍历树,并返回树节点的个数
int traverse_HT(Tree T);

//层序遍历，并返回树的节点数
int traverse_T(Tree T);

//LL旋转函数
void LLTree_(Tree T);

//RR旋转函数
void RRTree_(Tree T);

//LR旋转函数
void LRTree_(Tree T);

//RL旋转函数
void RLTree_(Tree T);

//删除节点,删除成功返回树高，失败返回-1
void pop_x(Tree* T, SJLX x);


