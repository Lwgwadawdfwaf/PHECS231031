
//Scmp = pop_S(S);
////�жϲ���ת
//if (Scmp->Zson == Scmp->Yson)
//{
//	Scmp->Height = 1;
//}
//else if (Scmp->Zson == NULL && Scmp->Yson->Height != 2);
//else if (Scmp->Yson == NULL && Scmp->Zson->Height != 2);
//else if (Scmp->Zson && Scmp->Yson &&
//	(Scmp->Zson->Height - Scmp->Yson->Height != 2 &&
//		Scmp->Yson->Height - Scmp->Zson->Height != 2))
//{
//	Scmp->Height = Tree_H(Scmp);
//}
////�ж�LL��ת
//else if (Scmp->Zson->Zson != NULL &&
//	Scmp->Zson->Zson->Height == Scmp->Zson->Height - 1 &&
//	(Scmp->Yson == NULL || Scmp->Zson->Height - Scmp->Yson->Height == 2))
//{
//	//����LL��ת����
//	LLTree_(Scmp);
//}
////�ж�RR��ת
//else if (Scmp->Yson->Yson != NULL &&
//	Scmp->Yson->Yson->Height == Scmp->Yson->Height - 1 &&
//	(Scmp->Zson == NULL || Scmp->Yson->Height - Scmp->Zson->Height == 2))
//{
//	//����RR��ת����
//	RRTree_(Scmp);
//}
//else if ()