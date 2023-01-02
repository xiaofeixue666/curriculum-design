long long D[MVNum][MVNum], P[MVNum][MVNum];

//用Folyd算法生成当前城市能到达的所有城市
void Floyd_path(graph G, char city[]) {
	int v = -1;
	for (int i = 0; i < G->Nv; i++)//对两个矩阵进行初始化
		if (strcmp(G->G[i].CityName, city) == 0) {
			v = i;
			break;
		}

	for (int i = 0; i < G->Nv; i++)//对Path矩阵进行初始化
		for (int j = 0; j < G->Nv; j++) {
			P[i][j] = -1;//
		}
	//memset(P,-1,sizeof P);
	for (int i = 0; i < G->Nv; i++) {
		adjoin p = G->G[i].FirstEdge;
		while (p != NULL) {
			P[i][p->adjv] = 1;
			P[p->adjv][i] = 1;
			p = p->Next;
		}
	}

	for (int k = 0; k < G->Nv; k++)//floyd算法
		for (int i = 0; i < G->Nv; i++)
			for (int j = 0; j < G->Nv; j++)
				if (P[i][k] == 1 && P[k][j] == 1) {
					P[i][j] = 1;
				}

	printf("%s 能够到达的所有城市:", G->G[v].CityName);
	for (int i = 0; i < G->Nv; i++) {
		if (P[v][i] == 1 && v != i)
			printf("%s ", G->G[i].CityName);
	}
	printf("\n\n");
}

//用该函数来递归查找P数组中的路径
void print_path(graph G, int i, int j) {
	int k = P[i][j];//找到上一个中转站/顶点（中转城市）
	if (k == -1)
		//说明没有中转顶点，直接返回
		return;
	print_path(G, i, k);//寻找i和k之间
	printf("%s->", G->G[k].CityName);
	print_path(G, k, j);//寻找k和j之间

}

