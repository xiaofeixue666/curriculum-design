//用Folyd算法生成任意两个城市之间的所用时间最少的路线
void Floyd_Time(graph G, int v1, int v2) {
	for (int i = 0; i < G->Nv; i++)//对两个矩阵进行初始化
		for (int j = 0; j < G->Nv; j++) {
			if (i == j)D[i][j] = 0;//如果相同说明是同一点
			else D[i][j] = INT_MAX;//否则先全部赋值为无穷大
			P[i][j] = -1;//一开始路径都没有
		}
	for (int i = 0; i < G->Nv; i++) {//记录所有相邻城市之间的时间
		adjoin p = G->G[i].FirstEdge;
		while (p != NULL) {
			D[i][p->adjv] = p->time;//将边上的费用这个权值赋给数组D
			p = p->Next;
		}
	}
	for (int k = 0; k < G->Nv; k++)//floyd算法
		for (int i = 0; i < G->Nv; i++)
			for (int j = 0; j < G->Nv; j++)
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					//因为时间不会是负数，所以不用加特判了
					if (i != j)P[i][j] = k;
				}
	printf("从 %s 至 %s 所花时间最少的路线为:%s->", G->G[v1].CityName, G->G[v2].CityName, G->G[v1].CityName);
	print_path(G, v1, v2);
	printf("%s 共需时间%d分钟\n\n", G->G[v2].CityName, D[v1][v2]);
}
