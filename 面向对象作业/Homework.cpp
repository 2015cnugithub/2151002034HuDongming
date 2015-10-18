#include <iostream>
#include <string>
using namespace std;
class Worker
{
public:
	string name;
	string sex;
	double pay_per_hour;
	int age;
	int dengji;
	void InitDengji(string name_val,string sex_val,int age_val,double pay_per_hour_val,int dengji_val)
	{
		name=name_val;
		sex=sex_val;
		age=age_val;
		pay_per_hour=pay_per_hour_val;
		dengji=dengji_val;
	}
	virtual double Compute_pay(double hours)
	{
		return 0;
	}
	string getName()
	{
		return name;
	}
	friend ostream& operator<<(ostream &out,Worker &worker)
	{
		cout<<"姓名："<<worker.name<<endl;
		cout<<"性别："<<worker.sex<<endl;
		cout<<"年龄："<<worker.age<<endl;
		cout<<"小时工资额:"<<worker.pay_per_hour<<endl;
		cout<<"薪金等级:"<<worker.dengji<<endl;
		return out;
	}
	
};
class HourlyWorker:public Worker
{
public:
	HourlyWorker(string nm,string sx,int ag,double py,int dg)
	{
		InitDengji(nm,sx,ag,py,dg);
	}
	double Compute_pay(double hours)
	{
		if(hours<=40)
			return hours*pay_per_hour;
		else
			return hours*pay_per_hour+1.5*pay_per_hour*(hours-40);
	}
};
class SalariedWorker:public Worker
{
public:
	SalariedWorker(string nm,string sx,int ag,double py,int dg)
	{
		InitDengji(nm,sx,ag,py,dg);
	}
	double Compute_pay(double hours)
	{
		if(hours>=35)
			return 40*pay_per_hour;
		else
			return hours*pay_per_hour+0.5*pay_per_hour*(35-hours);
	}
};
int main()
{
	Worker *worker[5];
	string name;
	string sex;
	double pay_per_hour;
	int dengji,age;
	for(int i=0;i<5;i++){
		cout<<"请输入员工信息："<<endl;
		cin>>name>>sex>>age>>pay_per_hour>>dengji;
		if(dengji==30||dengji==50)
		{
			worker[i]=new SalariedWorker(name,sex,age,pay_per_hour,dengji);
		}
		else if(dengji==10||dengji==20||dengji==40)
		{
			worker[i]=new HourlyWorker(name,sex,age,pay_per_hour,dengji);
		}
	}
	char ch;
	int number;
	double work_time;
	do
	{
		
			fflush(stdin);
			for(int i=1;i<=5;i++)
			{
				cout<<i<<":"<<worker[i-1]->getName()<<endl;
			}
			cout<<"请选择要查询的工人序号：";
			cin>>number;
			if(number>=5||number<0)
			{
				cout<<"您输入的序号有误，请重新输入！"<<endl;
				continue;
			}
			else
			{
				cout<<*worker[number];
				cout<<"请输入此工人每周工作时间：";
				cin>>work_time;
				cout<<"此工人薪资是："<<worker[number]->Compute_pay(work_time)<<"元"<<endl;
			}
		
			cout<<"你是否要继续查询？(y/n)";
            cin>>ch;
		
		}while(ch=='Y'||ch=='y');
			return 0;
			system("pause");
}
	



