//实现图的头文件，用邻接表实现
//#include"queue.h"//引入队列头文件，其中已包含头文件和结构体

//定义/初始化一个图，如果文件中有路线也把路线插入图中
graph CreateG();

//判断图是否为空
bool empty(graph G);

//在图G中查找城市名称，如果不存在则返回错误信息ERROR，存在则返回该城市所在邻接表的下标位置
int Search_CityName(graph G, char city[]);

//往图G中插入一条新的路线E
void Insert_Path(graph G, edge E);

//将邻接表进行输出，测试用
void show(graph G);

//将所有的路线进行输出
void Show_Path(graph G);

//将图中的某条路线进行修改
void Modify_Path(graph G, edge E);

//将图进行保存,格式为：城市1 城市2 路程 费用 时间
bool Save_File(graph G);

//读取文件，将文件中的路线全部输进邻接表中
bool Read_File(graph G);

//用该函数来递归查找P数组中的路径
void print_path(graph G, int i, int j);

//用Folyd算法生成当前城市能到达的所有城市
void Floyd_path(graph G, char city[]);

//用Folyd算法生成任意两个城市之间的费用最少的路线
void Floyd_Cost(graph G, char city1[], char city2[]);

//用Folyd算法生成任意两个城市之间的路程最少的路线
void Floyd_Mileage(graph G, char city1[], char city2[]);

//用Folyd算法生成任意两个城市之间的所用时间最少的路线
void Floyd_Time(graph G, char city1[], char city2[]);

//用广度优先搜索算法搜索中转站最少的路线，需要用到队列
void Bfs(graph G, char city1[], char city2[]);

//将v1到v2的中转站最少的路线打印出来
void Print_Path(graph G, int v1, int v2);

//----下面是具体实现的函数

//定义/初始化一个图
graph CreateG() {
	graph G = (graph)malloc(sizeof(struct GNode));//建立图/开辟空间
	G->Ne = 0;//初始边数为0
	G->Nv = 0;//初始的顶点/城市数目也为0
	for (int i = 0; i < MVNum; i++)//将图中的全部顶点的表头指针赋为空NULL
		G->G[i].FirstEdge = NULL;
	Read_File(G);//将文件中的路线输入图中
	return G;//将图返回
}

//判断图是否为空
bool empty(graph G) {
	return G->Nv == 0;
}

//在图G中查找城市名称，如果不存在则返回错误信息Error，存在则返回该城市所在邻接表的下标位置
int Search_CityName(graph G, char city[]) {
	if (empty(G))return Error;//如果当前图为空，则直接返回错误信息
	for (int i = 0; i < G->Nv; i++) //否则进行查找
		if (strcmp(G->G[i].CityName, city) == 0)return i;//找到了直接返回下标
	return Error;//没找到返回错误信息
}

//往图G中插入一条新的路线
void Insert_Path(graph G, edge E) {
	E->v1 = Search_CityName(G, E->city1);//现在原先的邻接表中查找两城市的位置
	E->v2 = Search_CityName(G, E->city2);
	if (E->v1 == -1)E->v1 = G->Nv++;//没找到就在图中加入新的点，同时图中的顶点数+1
	if (E->v2 == -1)E->v2 = G->Nv++;
	adjoin p = (adjoin)malloc(sizeof(struct AdjVNode));//开辟一个新的邻接点
	p->adjv = E->v2; p->cost = E->cost;//给邻接点赋值：
	p->mileage = E->mileage; p->time = E->time; strcpy(p->CityName, E->city2);
	strcpy(G->G[E->v1].CityName, E->city1);//将城市名称放入顶点数据
	adjoin s = G->G[E->v1].FirstEdge;//用尾插法将邻接点与邻接表进行连接
	if (s == NULL) {
		p->Next = G->G[E->v1].FirstEdge;
		G->G[E->v1].FirstEdge = p;
	}
	else {
		while (s->Next != NULL)s = s->Next;
		p->Next = s->Next;
		s->Next = p;
	}
	adjoin q = (adjoin)malloc(sizeof(struct AdjVNode));//无向边需要在边的两头都加入邻接点
	q->adjv = E->v1; q->cost = E->cost;//给邻接点赋值
	q->mileage = E->mileage; q->time = E->time; strcpy(q->CityName, E->city1);
	strcpy(G->G[E->v2].CityName, E->city2);//将城市名称放入顶点数据
	s = G->G[E->v2].FirstEdge;//用尾插法将邻接点与邻接表进行连接
	if (s == NULL) {
		q->Next = G->G[E->v2].FirstEdge;
		G->G[E->v2].FirstEdge = q;
	}
	else {
		while (s->Next != NULL)s = s->Next;
		q->Next = s->Next;
		s->Next = q;
	}
	G->Ne++;//最后图的边的数目+1
}

//将邻接表进行输出，测试用
void show(graph G) {
	for (int i = 0; i < G->Nv; i++) {
		printf("%s 可以去的城市:", G->G[i].CityName);
		adjoin p = G->G[i].FirstEdge;//将指针指向邻接表的该位置的表头结点的下一个结点
		while (p != NULL) {
			printf("%s（费用为：%d） ", p->CityName, p->cost);
			p = p->Next;
		}
		printf("\n\n");
	}
}
