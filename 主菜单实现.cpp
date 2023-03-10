//-----下面是函数功能实现

void Welcome_Print() {//打印主菜单界面
	system("cls");//清屏 
	time_t t;
	struct tm* p;
	time(&t);
	p = gmtime(&t);
	printf("\t\t\t\t\n");//界面
	printf("\t\t\t\t--------------北京时间：%d年%02d月%02d日%02d时%02d分---------------\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
	printf("\t\t\t\t------------------欢迎进入交通咨询系统-----------------------\n");
	printf("\t\t\t\t----------------------用户功能菜单---------------------------\n");
	printf("\t\t\t\t--                    1.查询城市路线                       --\n");
	printf("\t\t\t\t--                    2.查询所有路线                       --\n");
	printf("\t\t\t\t--                    3.查询可到达城市                     --\n");
	printf("\t\t\t\t--                    4.进入管理员界面                     --\n");
	printf("\t\t\t\t--                    0.退出咨询系统                       --\n");
	printf("\t\t\t\t-------------------------------------------------------------\n");
}

void Welcome() {//主菜单界面 
	//进入操作前先创建一个图，并将文件中的数据输进去
	graph G = CreateG();
	while (1) {//操作需要可以持续进行，用一个死循环
		Welcome_Print();
		printf("请输入你所想查询信息的选项（数字）: ");
		int choice;
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			Function_One(G);
			break;
		case 2:
			Ad_Function_Four(G);
			break;
		case 3:
			Function_Three(G);
			break;
		case 4:
			Welcome_Ad(G);
			Welcome_Print();
			break;
		case 0:
			Goodbye();
			break;
		}
		printf("是否要继续进行操作？(是：1/否：0)\n");
		scanf("%d", &choice);
		if (choice == 0)Goodbye();
	}
}