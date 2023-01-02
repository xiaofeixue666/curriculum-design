//进入管理员界面，需要输入密码
void Enter_Ad() {
	system("cls");//清屏 
	time_t t;
	struct tm* p;
	time(&t);
	p = gmtime(&t);
	printf("进入管理员界面需要进行登录\n");
	int i, j;
	while (1) {
		printf("请输入管理员用户名或者账号：\n");
		scanf("%s", ad_number);
		i = Sreach_Adname(ad_number);
		j = Sreach_Adnumber(ad_number);
		if (i == -1 && j == -1) printf("不存在该用户名或账号！请重新输入!\n");
		else {
			if (i == -1)i = j;
			break;
		}
	}
	int sum = 0;//开一个变量来记录输错密码的次数，错误此时超过5次关闭系统
	while (1) {
		printf("请输入管理员密码：\n");
		hide_password(key, 21);
		printf("\n");
		if (strcmp(key, password[i]) != 0) {
			sum++;
			if (sum >= 5) {
				printf("多次输入密码错误！系统关闭！\n");
				sum = 0;
				exit(0);
			}
			else {
				printf("密码错误！请重新输入！你还有%d次机会！\n", 5 - sum);
			}
		}
		else {
			printf("登陆成功！\n");
			break;
		}
	}
	system("pause");
}