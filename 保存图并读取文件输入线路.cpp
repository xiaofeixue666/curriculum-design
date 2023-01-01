//将图进行保存，格式为：城市1 城市2 路程 费用 时间
bool Save_File(graph G) {
	bool vis[MVNum][MVNum] = { false };//开一个布尔类型的二维数组进行标记，防止重复输出相同的路线
	FILE* fpw = fopen("path.txt", "w");//以只写的形式打开文本文件
	//若文件不存在则新建，否则，从起始位置开始写入文件，会覆盖文件原来的内容
	if (fpw == NULL)return false;//如果打开文件失败则退出
	for (int i = 0; i < G->Nv; i++) {
		adjoin p = G->G[i].FirstEdge;//将指针指向邻接表的该位置的表头结点的下一个结点
		while (p != NULL) {
			if (!vis[i][p->adjv] && !vis[p->adjv][i]) {
				fprintf(fpw, "%s %s %d %d %d\n", G->G[i].CityName, p->CityName, p->mileage, p->cost, p->time);
				vis[i][p->adjv] = true;
				vis[p->adjv][i] = true;
			}
			p = p->Next;
		}
	}
	fclose(fpw);//关闭文件指针
	return true;
}

//读取文件，将文件中的路线全部输进图G中
bool Read_File(graph G) {
	FILE* fpr = fopen("path.txt", "r");
	//以只读的形式打开文本文件，不存在则退出
	edge E = (edge)malloc(sizeof(struct ENode));//给一条边开辟空间，用来进行读取输入
	if (fpr == NULL)return false;//如果文件不存在或文件为空，则退出
	//用while语句将所有的路线都插入图G中
	while (fscanf(fpr, "%s %s %d %d %d", E->city1, E->city2, &E->mileage, &E->cost, &E->time) != EOF)
		Insert_Path(G, E);//直接将从文件中读出的路线插入图G中，并且不用保存
	fclose(fpr);//关闭文件指针
	return true;
}
