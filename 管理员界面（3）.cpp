//将修改后的账号密码保存 
void save_password() {
	FILE* fp = fopen("adname_password.txt", "w+");//打开管理员文件
	//“w+”：首先建立一个新文件，进行写操作，然后从头开始写(若文件存在，原内容将全部消失)
	for (int i = 0; i < adsum; i++)
		fprintf(fp, "%s %s %s\n", Ad_Name[i], Ad_Number[i], password[i]);
	//将数组中的所有管理员用户名、账号和密码写入文件中
	fclose(fp);//关闭文件
}

void hide_password(char* pswd, unsigned maxlen) {//隐藏密码进行输入 
	int index = 0;
	char buff = '\0';
	while ((buff = getch()) != '\r') {
		if (buff == '\b' && index != 0) {
			index--;
			printf("\b \b");
		}
		else if (index < maxlen - 1 && buff != '\b') {
			pswd[index++] = buff;
			putchar('*');
		}
	}
	pswd[index] = '\0';
}

int Change_Password() {//修改密码
	int i;
	while (1) {
		printf("请输入要修改密码的管理员用户名:\n");
		scanf("%s", ad_name);
		i = Sreach_Adname(ad_name);
		if (i == -1) printf("不存在该管理员！请重新输入!\n");
		else break;
	}
	printf("请输入原来的密码：\n");
	while (1) {
		hide_password(key, 21);//隐藏密码输入
		printf("\n");
		if (strcmp(key, password[i]) != 0) {
			printf("密码错误！\n");
		}
		else break;
	}
	printf("请输入想要更改的管理员密码：\n");
	hide_password(password[i], 21);//隐藏密码输入
	save_password();//重新保存文件
	printf("\n修改成功！\n");
	return 0;
}

void Printflove() {//打印爱心 
	float a, x, y;
	for (y = 1.5f; y > -1.5f; y -= 0.1f) {
		for (x = -1.5f; x < 1.5f; x += 0.05f) {
			a = x * x + y * y - 1;
			char ch = a * a * a - x * x * y * y * y <= 0.0f ? '*' : ' ';
			putchar(ch);
		}
		printf("\n");
		printf("\t\t\t  ");
	}
}

void Goodbye() {//结束程序 
	system("cls");
	printf("\t\t\t\t        欢迎下次使用！~再见！~~           \n");
	exit(0);
}