
//Scmp = pop_S(S);
////判断不旋转
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
////判断LL旋转
//else if (Scmp->Zson->Zson != NULL &&
//	Scmp->Zson->Zson->Height == Scmp->Zson->Height - 1 &&
//	(Scmp->Yson == NULL || Scmp->Zson->Height - Scmp->Yson->Height == 2))
//{
//	//调用LL旋转函数
//	LLTree_(Scmp);
//}
////判断RR旋转
//else if (Scmp->Yson->Yson != NULL &&
//	Scmp->Yson->Yson->Height == Scmp->Yson->Height - 1 &&
//	(Scmp->Zson == NULL || Scmp->Yson->Height - Scmp->Zson->Height == 2))
//{
//	//调用RR旋转函数
//	RRTree_(Scmp);
//}
//else if ()