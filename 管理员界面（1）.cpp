void Welcome_Ad_Print() {//打印管理员界面
	system("cls");//清屏 
	time_t t;
	struct tm* p;
	time(&t);
	p = gmtime(&t);
	printf("\t\t\t\t--------北京时间：%d年%02d月%02d日%02d时%02d分------\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, 8 + p->tm_hour, p->tm_min);
	printf("\t\t\t\t---------------管理员功能菜单-----------------\n");
	printf("\t\t\t\t--       修改管理员密码 ----------1         --\n");
	printf("\t\t\t\t--       修改/更新路线  ----------2         --\n");
	printf("\t\t\t\t--       添加新路线     ----------3         --\n");
	printf("\t\t\t\t--       显示所有路线   ----------4         --\n");
	printf("\t\t\t\t--       退出管理员界面 ----------5         --\n");
	printf("\t\t\t\t--       注册管理员账号 ----------6         --\n");
	printf("\t\t\t\t--       查看管理员账号 ----------7         --\n");
	printf("\t\t\t\t--       注销管理员账号 ----------8         --\n");
	printf("\t\t\t\t--       修改管理员名称  ---------9         --\n");
	printf("\t\t\t\t--       退出咨询系统   ----------0         --\n");
	printf("\t\t\t\t----------------------------------------------\n");
}

void Welcome_Ad(graph G) {//进入管理员界面
	Read_Ad_Password();//先将文件中的管理员用户名和密码读取出来
	int choice;
	if (adsum == 0) {
		printf("当前系统没有管理员账号，是否进行注册？(是：1/否：0)\n");
		scanf("%d", &choice);
		if (choice == 1) Ad_Function_Six();//进行注册
		else return;//否则退出管理员界面
	}
	Enter_Ad();//需要先进行登录
	while (1) {//操作需要可以持续进行，用一个死循环
		Welcome_Ad_Print();//将管理员界面打印出来
		printf("请输入你想进行的操作（数字）: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			Change_Password();//修改管理员的密码
			break;
		case 2:
			Ad_Function_Two(G);//修改/更新路线
			break;
		case 3:
			Ad_Function_Three(G);//加入新的路线
			break;
		case 4:
			Ad_Function_Four(G);//查询所有路线
			break;
		case 5:
			return;//要退出管理员界面，直接退出这个函数即可
			break;
		case 6:
			Ad_Function_Six();//注册管理员账号
			break;
		case 7:
			Ad_Function_Seven();//查看管理员账号
			break;
		case 8:
			Ad_Functino_Eight();//注销管理员账号
			break;
		case 9:
			Ad_Function_Nine();//修改管理员用户名
			break;
		case 0:
			Goodbye();//退出系统（直接结束整个程序）
			break;
		}
		printf("是否要继续进行操作？(是：1/否：0)\n");
		scanf("%d", &choice);
		if (choice == 0)Goodbye();
	}
}