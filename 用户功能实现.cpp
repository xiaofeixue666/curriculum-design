void Function_One(graph G) {//实现用户的功能1，查询城市路线
	char city1[10], city2[10];//开两个数组输入两个城市名称
	printf("请输入两个城市的名称（起点和终点）：\n");
	scanf("%s%s", city1, city2);
	int v1 = Search_CityName(G, city1);//现在原先的邻接表中查找两城市的位置
	int v2 = Search_CityName(G, city2);
	if (v1 == -1 || v2 == -1) {//防止重复输出没有路线的信息，在查询之前就先进行判断
		//如果两个城市中有一个或两个没找到在邻接表中的位置，说明该路线不存在
		printf("抱歉！暂时没有%s到达%s的路线！\n", city1, city2);
		return;
	}
	if (v1 == v2) {
		printf("您已经在该城市中，无需查找路线！\n");
		return;
	}
	//直接调用已经写好的函数
	if (!Floyd_Cost(G, v1, v2))//费用最少
		printf("抱歉！暂时没有%s到达%s的路线！\n", city1, city2);
	else {
		Floyd_Mileage(G, v1, v2);//路程最少
		Floyd_Time(G, v1, v2);//时间最少
		Bfs(G, v1, v2);//中转站最少
	}
}

//实现用户的功能3，查询当前城市可以到达的城市
void Function_Three(graph G) {
	char city[10];
	printf("请输入当前城市：\n");
	scanf("%s", city);
	int v = Search_CityName(G, city);
	if (v == -1) {
		printf("抱歉！暂时不存在该城市!\n");
		return;
	}
	Floyd_path(G, city);
}