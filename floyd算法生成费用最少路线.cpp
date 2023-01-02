//用Folyd算法生成任意两个城市之间的费用最少的路线
bool Floyd_Cost(graph G, int v1, int v2) {
	for (int i = 0; i < G->Nv; i++)//对两个矩阵进行初始化
		for (int j = 0; j < G->Nv; j++) {
			if (i == j)D[i][j] = 0;//如果相同说明是同一点
			else D[i][j] = INT_MAX;//否则先全部赋值为无穷大
			P[i][j] = -1;//一开始路径都没有
		}
	for (int i = 0; i < G->Nv; i++) {//记录所有相邻城市之间的费用
		adjoin p = G->G[i].FirstEdge;
		while (p != NULL) {
			D[i][p->adjv] = p->cost;//将边上的费用这个权值赋给数组D
			p = p->Next;
		}
	}
	for (int k = 0; k < G->Nv; k++)//floyd算法
		for (int i = 0; i < G->Nv; i++)
			for (int j = 0; j < G->Nv; j++)
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					//因为路费不会是负数，所以不用加特判了
					if (i != j)P[i][j] = k;
				}
	if (D[v1][v2] >= INT_MAX) return false;
	//如果最后的路线总费用大于等定义好的无穷大，那么说明路线不存在
	printf("从 %s 至 %s 花费最小的路线为:%s->", G->G[v1].CityName, G->G[v2].CityName, G->G[v1].CityName);
	print_path(G, v1, v2);
	printf("%s 共花费%d元\n\n", G->G[v2].CityName, D[v1][v2]);
	return true;
}
