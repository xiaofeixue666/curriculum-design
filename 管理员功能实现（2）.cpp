//将文件中存储的所有用户名和密码都读取进password和Ad_Name数组中
void Read_Ad_Password() {
	FILE* fpr = fopen("adname_password.txt", "r");//打开文件，如果文件不存在会自动创建文件
	int i = 0;
	adsum = 0;//先将管理员人数清零，因为是重新将所有管理员再输入数组
	//不清零会导致重复进入管理员界面的时会显示的人数超过10人
	if (fpr == NULL)return;
	while (fscanf(fpr, "%s %s %s", ad_name, ad_number, key) != EOF) {
		strcpy(Ad_Name[i], ad_name);//将文件中的用户名、账号密码都写入数组中
		strcpy(Ad_Number[i], ad_number);
		strcpy(password[i++], key);
		adsum++;//管理员用户个数++
	}
	fclose(fpr);//关闭文件指针
}

//实现管理员的功能6，注册管理员账号
void Ad_Function_Six() {
	if (adsum >= 10) {//如果当前管理员账号有10个，则不允许再添加管理员账号
		printf("管理员账号已满！无法再进行注册！\n");
	}
	else {
		while (1) {
			printf("请输入新的管理员用户名：\n");
			scanf("%s", ad_name);
			int i = Sreach_Adname(ad_name);
			if (i == -1) {
				strcpy(Ad_Name[adsum], ad_name);
				break;
			}
			else printf("该用户名已存在！请重新输入！\n");
		}
		while (1) {
			printf("请输入对应的管理员账号：\n");
			scanf("%s", ad_number);
			int i = Sreach_Adnumber(ad_number);
			if (i == -1) {
				strcpy(Ad_Number[adsum], ad_number);
				break;
			}
			else printf("该账号已存在！请重新输入！\n");
		}
		printf("请输入对应的管理员密码：\n");
		hide_password(key, 21);//隐藏密码输入
		strcpy(password[adsum++], key);
		save_password();//将新注册的管理员账号进行保存，保存进文件中
		printf("\n注册成功！\n");
	}
	system("pause");//请按任意键继续
}
