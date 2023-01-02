//实现管理员功能7,查看管理员账号
void Ad_Function_Seven() {
	system("cls");
	printf("-------------------------------管理员名单-------------------------------\n");
	printf("________________________________________________________________________\n");
	printf("|%10s\t\t|%10s\t\t|%10s\t\t|\n", "管理员用户名", "管理员账号", "管理员密码");
	printf("________________________________________________________________________\n");
	for (int i = 0; i < adsum; i++) {
		printf("|%10s\t\t|%10s\t\t|%10s\t\t|\n", Ad_Name[i], Ad_Number[i], password[i]);
		printf("________________________________________________________________________\n");
	}
	printf("当前管理员人数为：%d人\n", adsum);
}

//实现管理员功能8,注销管理员账号
void Ad_Functino_Eight() {
	printf("请输入想要注销的管理员用户名：\n");
	scanf("%s", ad_name);
	int i = Sreach_Adname(ad_name), choice;
	if (i == -1)printf("不存在该管理员用户名！\n");
	else {
		while (1) {
			printf("请输入对应的管理员密码：\n");
			hide_password(key, 21);//隐藏密码输入
			if (strcmp(key, password[i]) != 0)printf("\n密码错误！请重新输入\n");
			else break;
		}
		printf("\n请确认是否注销该管理员账号？(是：1/否：0)\n");
		scanf("%d", &choice);
		if (choice == 1) {
			for (int j = i; j < adsum - 1; j++) {
				strcpy(Ad_Name[j], Ad_Name[j + 1]);//将用户名前移
				strcpy(password[j], password[j + 1]);//将密码前移
				strcpy(Ad_Number[j], Ad_Number[j + 1]);//将账号前移
			}
			adsum--;
			save_password();//保存新的数组
			printf("管理员账号注销成功！\n");
		}
		else return;
	}
}