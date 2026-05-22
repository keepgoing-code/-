#include<iostream>
#include<string>
#define MAX 1000  // 注意这里是大写 MAX
using namespace std;

//设计联系人结构体
struct Person{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Address; 
};  // ← 添加分号

//通讯录结构体
struct Addressbooks
{
    //通讯录中保存联系人的数组
    struct Person personArray[MAX];
    //通讯录中当前记录联系人的个数 
    int m_Size; 
};  // ← 添加分号

//添加联系人 
void addPerson(Addressbooks *abs)
{
    //判断通讯录是否已满，如果已满不再添加
    if(abs->m_Size == MAX)  // ← 改为大写 MAX
    {
        cout << "通讯录已满,无法添加" << endl; 
        return;
    }
    else
    {
        //添加具体联系人
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;
        
        //年龄 
		int age;
		cout<<"请输入年龄" <<endl;
		cin>>age; 
		abs->personArray[abs->m_Size].m_Age = age;
		
		//性别
		cout<<"请输入性别"<<endl;
		cout<<"1-男性 2-女性"<<endl;
		int sex=0;
		//只有输入为1或2的时候 才会退出循环 
		//当输入其他时候  需要重新输入 
		while(true){
		cin>>sex;
			if(sex==1||sex==2) 
		{
			abs->personArray[abs->m_Size].m_Sex=sex;
			break;
		}
		cout<<"请重新输入"<<endl; 
		}		
	
	//手机 
		string phone;
		cout<<"请输入手机号码" <<endl;
		cin>>phone; 
		abs->personArray[abs->m_Size].m_Phone =phone;
		
		//住址
		string address;
		cout<<"请输入地址"<<endl;
		cin>>address;
		abs->personArray[abs->m_Size].m_Address=address; 
        // 添加完成后要增加人数计数
        //更新通讯录人数 
        abs->m_Size++;
        cout << "添加成功！" << endl;
        system("pause");//请按任意键继续
		system("cls");//清屏操作 
    }
}

//显示所有的联系人 
void showPerson(Addressbooks*abs){
	//判断通讯录中人数是否为0 如果 
	if(abs->m_Size==0) cout<<"当前没有添加联系人"<<endl;
	else
	{
		for(int i=0; i < abs->m_Size;i++)
		{
			cout<<"姓名: "<<abs->personArray[i].m_Name<<"\t";
			cout<<"年龄: "<<abs->personArray[i].m_Age<<"\t";
			cout<<"性别: "<<(abs->personArray[i].m_Sex==1?"男":"女")<<"\t";
			cout<<"手机号码: "<<abs->personArray[i].m_Phone<<"\t";//水平制表符 空出来8个字符 
			cout<<"住址: "<<abs->personArray[i].m_Address<<endl;
		}
		cout<<endl;	
	 } 
	 
	 system("pause");
	 system("cls");
} 

/*
//显示所有的联系人 
void showPerson(Addressbooks* abs){
    //判断通讯录中人数是否为0
    if(abs->m_Size == 0) {
        cout << "当前没有添加联系人" << endl;
    } else {
        for(int i = 0; i < abs->m_Size; i++) {
            cout << "姓名：" << abs->personArray[i].m_Name <<"\t";
            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
            cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t;  // 性别显示更友好
            cout << "手机号码：" << abs->personArray[i].m_Phone << "\t";
            cout << "住址：" << abs->personArray[i].m_Address << endl;
        }   
    } 
    system("pause");
    system("cls");
}
*/

//检测联系人是否存在 封装一个函数 该函数查找通讯录里联系人
//可以方便后续修改联系人和删除联系人等操作
int isExist(Addressbooks*abs,string name)
{
		for(int i=0;i< abs->m_Size ;i++)
		{
			if(abs->personArray[i].m_Name==name)
			{
				 return i;
			 } 
		 } 
		  return -1;
		 
 } 




//菜单
void showMenu()
{
    cout << "**********************" << endl;
    cout << "*****1.添加联系人*****" << endl;
    cout << "*****2.显示联系人*****" << endl;
    cout << "*****3.删除联系人*****" << endl;
    cout << "*****4.查找联系人*****" << endl;
    cout << "*****5.修改联系人*****" << endl;
    cout << "*****6.清空联系人*****" << endl;
    cout << "*****0.退出通讯录*****" << endl; 
    cout << "**********************" << endl;
}
 
int main(){
    //创建通讯录结构体变量
    Addressbooks abs;
    //初始化通讯录中当前人员个数 
    abs.m_Size = 0; 
    
    int select = 0;//创建用户选择输入的变量 
    //使用循环目的是为了在不退出（不输入0的情况下可以重新回到程序）
	//如果不使用循环 那么每次运行结果最后都是直接退出 
    while(true)  //当输入为0的时候会退出循环 从而达到退出通讯录的目的 
    {
        //菜单调用 
        showMenu();    
        cin >> select;
        switch(select){
            case 1://添加联系人 
                addPerson(&abs);//利用地址传递可以修饰实参 
                break;
            case 2://显示联系人 
              showPerson(&abs); 
                break;
            case 3://删除联系人 
            {
            	//调试查找联系人 
            	/*
            调试isExist函数是否能找到联系人 
			cout<<"请输入删除联系人的姓名"<<endl; 
            string name;
            cin>>name;
			if(isExist(&abs,name)==-1)
			cout<<"没有这个联系人"<<endl;
			else cout<<"找到这个联系人"<<endl; 
			 system("pause");
			 system("cls");
			}
           */
                break;
            case 4://查找联系人 
                break;
            case 5://修改联系人 
                break;
            case 6://清空联系人 
                break;
            case 0://退出通讯录 
                cout << "欢迎下次使用" << endl;
                system("pause");
                return 0; 
                break;
        } 
    }
    return 0;
}
