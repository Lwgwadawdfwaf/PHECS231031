#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//�������ʽдһ��ƽ�������

#define SJLX int //�������ݵ�����
typedef struct tree* Tree;//��������������˵���������ڵ�

//����������ṹ��
struct tree
{
	SJLX x;
	struct tree* Zson;//���������ָ��
	struct tree* Yson;//�����Ҷ���ָ��
	int Height;//���ĸ߶�
};

typedef struct stack* Stack;//������ջ

//����ջ�ṹ��
struct stack
{
	Tree* arr;//ջ����
	int size;//ջ��С
	int capacity;//ջ����
};

typedef struct queue* Queue;//����������

//������нṹ��
struct queue
{
	struct queue* last;//������һ���ڵ��ַ
	Tree x;//��������
	struct queue* next;//������һ���ڵ��ַ
};


//��ʼ������
void Queuecsh(Queue* Q);

//���
void InQueue(Queue Q, Tree T);

//����
Tree OutQueue(Queue Q);

//�鿴��ͷԪ��
Tree FrontQueue(Queue Q);

//��ʼ��ջ
void Stackcsh(Stack* S);

//ѹջ
void push_S(Stack S, Tree T);

//��ջ
Tree pop_S(Stack S);

//�鿴ջ��Ԫ��
Tree top_S(Stack S);

//��ʼ��������
void Treecsh(Tree* T);

//�������ڵ�,�����ش�������ڵ�ĵ�ַ
Tree czjd(SJLX x);

//LL��ת����
int LLTree(Tree* T);

//LR��ת����
int LRTree(Tree* T);

//LL��ת����
int LLTree(Tree* T);

//LR��ת����
int LRTree(Tree* T);

//�������ݣ�ƽ����������ʧ�ܷ���-1������ɹ��������ĸ߶�
int push_Tree(Tree* T, Tree tx);

//��������x��ƽ����������ʧ�ܷ���-1������ɹ��������ĸ߶�
int push_x(Tree* T, SJLX x);

//�������ݣ��������ݵ�ַ������ʧ�ܷ���NULL
Tree find_T(Tree T, SJLX x);

//ǰ�������,���������ڵ�ĸ������ɴ���������
int traverse_QT(Tree T,void*(op_F)(Tree));

//���������,���������ڵ�ĸ������ɴ���������
int traverse_ZT(Tree T, void* (op_F)(Tree));

//���������,���������ڵ�ĸ���
int traverse_HT(Tree T);

//������������������Ľڵ���
int traverse_T(Tree T);

//LL��ת����
void LLTree_(Tree T);

//RR��ת����
void RRTree_(Tree T);

//LR��ת����
void LRTree_(Tree T);

//RL��ת����
void RLTree_(Tree T);

//ɾ���ڵ�,ɾ���ɹ��������ߣ�ʧ�ܷ���-1
void pop_x(Tree* T, SJLX x);


