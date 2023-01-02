
//实现管理员功能9,修改管理员用户名
void Ad_Function_Nine() {
	printf("请输入要修改的管理员用户名：");
	scanf("%s", ad_name);
	int i = Sreach_Adname(ad_name);
	if (i == -1) printf("不存在该管理员用户名!");
	else {
		printf("请输入修改之后的管理员用户名：");
		scanf("%s", ad_name);
		strcpy(Ad_Name[i], ad_name);
		save_password();//将修改后的结果进行保存
		printf("用户名修改成功！\n");
	}
	//system("pause");//请按任意键继续
}

//在数组Ad_Name中找到用户名的位置
int Sreach_Adname(char adname[]) {
	for (int i = 0; i < adsum; i++)
		if (strcmp(adname, Ad_Name[i]) == 0)return i;//找到了直接返回该用户名的下标位置
	return Error;//没找到返回错误信息
}

//在数组Ad_Number中找到账号的位置
int Sreach_Adnumber(char adnumber[]) {
	for (int i = 0; i < adsum; i++)
		if (strcmp(Ad_Number[i], adnumber) == 0)return i;
	return Error;
}

//引入界面头文件，里面已经包含了图的实现
//#include"interface.h"

int main() {

	Welcome();

	return 0;
}
