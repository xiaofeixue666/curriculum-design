//将图G中的某条路线进行修改
void Modify_Path(graph G, edge E) {
	E->v1 = Search_CityName(G, E->city1);//现在原先的邻接表中查找两城市的位置
	E->v2 = Search_CityName(G, E->city2);
	if (E->v1 == -1 || E->v2 == -1) {//如果有一个城市没有找到对应的邻接表中的位置，说明该路线不存在
		printf("该路线不存在！\n");
		return;
	}
	adjoin p = G->G[E->v1].FirstEdge;//将城市1所在的邻接表的位置的表头指针赋给p
	while (p != NULL) {
		if (p->adjv == E->v2) {//用指针p进行遍历查找城市2
			p->cost = E->cost;//找到后进行数据修改
			p->mileage = E->mileage;
			p->time = E->time;
			break;//找到了直接退出循环
		}
		p = p->Next;//没找到继续找
	}
	p = G->G[E->v2].FirstEdge;//将城市2所在的邻接表的位置的表头指针赋给p
	while (p != NULL) {
		if (p->adjv == E->v1) {//用指针p进行遍历查找城市1
			p->cost = E->cost;//找到后进行数据修改
			p->mileage = E->mileage;
			p->time = E->time;
			break;//找到了直接退出循环
		}
		p = p->Next;//没找到继续找
	}
	Save_File(G);//将修改后的路线进行保存
}
