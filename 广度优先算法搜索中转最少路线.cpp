//下面这三个数组用与Bfs也就是广搜，搜索中转站最少的路线
int d[MVNum] = { 0 }, p[MVNum] = { 0 };
bool vis[MVNum];//用vis数组标记已经遍历过的邻接点
//用数组d来保存路线的长度,用数组P来保存广搜的路径

//将v1到v2的中转站最少的路线打印出来,需要先执行Bfs函数
void Print_Path(graph G, int v1, int v2) {
	if (v2 == v1)printf("%s", G->G[v1].CityName);//递归结束标志
	//刚进来时，v1肯定不等于v2，但是因为v1是起点，所以会递归到v1==v2时才会进行输出
	else if (p[v2] == -1)return;
	else {
		Print_Path(G, v1, p[v2]);//这里进行递归，直到v1==v2
		printf("->%s", G->G[v2].CityName);
	}
}

//用广度优先搜索算法搜索中转站最少的路线,需要用到队列
void Bfs(graph G, int v1, int v2) {
	printf("从 %s 至 %s 中转站最少的路线为:", G->G[v1].CityName, G->G[v2].CityName);
	memset(vis, false, sizeof vis);//将vis数组全部赋值为false
	memset(p, -1, sizeof p);//将数组p全部赋值为-1，表示没有初始路径
	queue q = CreateQ();//创建一个队列
	push(q, v1);//入队
	vis[v1] = true;//标记
	while (!empty(q)) {//当队列不为空时继续执行
		int v = front(q);//将队头出列
		pop(q);//出队，队头出队后马上将队头删除
		adjoin t = G->G[v].FirstEdge;
		while (t != NULL) {
			if (!vis[t->adjv]) {//如果这个邻接点没有遍历过
				vis[t->adjv] = true;//进行标记
				p[t->adjv] = v;//记录父节点
				d[t->adjv] = d[v] + 1;//中转站+1
				push(q, t->adjv);//入队
			}
			t = t->Next;
		}
	}
	Print_Path(G, v1, v2);//将路径进行打印
	printf(" 中转站的个数为:%d \n\n", d[v2] - 1);
	//输出中转站个数并进行换行，进行-1是因为d[v2]已经将v2也就是终点城市算进去了
}

