/这个头文件用来设计系统的界面
//#include"graph.h"//引入图的头文件

//其实也可以直接定义一个管理员的结构体，但是因为已经实现了，就没管太多
char Ad_Name[15][20], ad_name[20];//存放管理员用户名称和输入管理员用户名称
char Ad_Number[15][20], ad_number[20];//用来存放管理员账号
char password[15][20], key[20];//用来存放管理员密码
int adsum = 0;//使用一个变量来记录用户个数

void save_password();//保存管理员用户名、账号和密码 

void hide_password(char* pswd, unsigned maxlen);//隐藏密码进行输入 

void Enter_Ad();//进入管理员界面，需要输入密码

void Welcome();//主菜单界面,无需密码进入

void Welcome_Print();//打印主菜单界面

void Welcome_Ad_Print();//打印管理员界面

void Welcome_Ad(graph G);//进入管理员界面,需要进行登录

int Change_Password();//修改管理员密码

void Printflove();//打印爱心

void Goodbye();//结束程序 

void Function_One(graph G);//实现用户的功能1，查询城市路线

void Function_Three(graph G);//实现用户的功能3

void Ad_Function_Two(graph G);//实现用户/管理员的功能2,修改/更新路线

void Ad_Function_Three(graph G);//实现管理员的功能3，添加新路线

void Ad_Function_Four(graph G);//实现管理员的功能4，查询所有路线

void Ad_Function_Six();//实现管理员的功能6，注册管理员账号

void Ad_Function_Seven();//实现管理员功能7,查看管理员账号

void Ad_Functino_Eight();//实现管理员功能8,注销管理员账号

void Ad_Function_Nine();//实现管理员功能9,修改管理员用户名

//将文件中存储的所有用户名和密码都读取进password和Ad_Name数组中
void Read_Ad_Password();

int Sreach_Adname(char adname[]);//在数组Ad_name中找到用户名的位置

int Sreach_Adnumber(char adnumber[]);//在数组Ad_Number中找到账号的位置