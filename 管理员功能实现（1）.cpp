//实现管理员的功能2，修改/更新路线
void Ad_Function_Two(graph G) {
	printf("请输入更新之后的路线：\n");
	printf("格式为：城市1 城市2 路程 费用 时间\n");
	edge E = (edge)malloc(sizeof(struct ENode));
	scanf("%s%s%d%d%d", E->city1, E->city2, &E->mileage, &E->cost, &E->time);
	E->v1 = Search_CityName(G, E->city1);//现在原先的邻接表中查找两城市的位置
	E->v2 = Search_CityName(G, E->city2);
	if (E->v1 == -1 || E->v2 == -1) {//如果有一个城市没有找到对应的邻接表中的位置，说明该路线不存在
		printf("该路线不存在！\n");
		return;
	}
	else {
		Modify_Path(G, E);
		printf("修改成功！\n");
	}
}

//实现管理员的功能3，添加新路线
void Ad_Function_Three(graph G) {
	printf("请输入新的路线：\n");
	printf("格式为：城市1 城市2 路程 费用 时间\n");
	edge E = (edge)malloc(sizeof(struct ENode));
	scanf("%s%s%d%d%d", E->city1, E->city2, &E->mileage, &E->cost, &E->time);
	Insert_Path(G, E);
	printf("添加路线成功！\n");
	Save_File(G);//输入新的路线之后进行保存
}

//实现管理员的功能4，查询所有路线
void Ad_Function_Four(graph G) {
	Show_Path(G);
}