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
		cout<<"������"<<worker.name<<endl;
		cout<<"�Ա�"<<worker.sex<<endl;
		cout<<"���䣺"<<worker.age<<endl;
		cout<<"Сʱ���ʶ�:"<<worker.pay_per_hour<<endl;
		cout<<"н��ȼ�:"<<worker.dengji<<endl;
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
		cout<<"������Ա����Ϣ��"<<endl;
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
			cout<<"��ѡ��Ҫ��ѯ�Ĺ�����ţ�";
			cin>>number;
			if(number>=5||number<0)
			{
				cout<<"�����������������������룡"<<endl;
				continue;
			}
			else
			{
				cout<<*worker[number];
				cout<<"������˹���ÿ�ܹ���ʱ�䣺";
				cin>>work_time;
				cout<<"�˹���н���ǣ�"<<worker[number]->Compute_pay(work_time)<<"Ԫ"<<endl;
			}
		
			cout<<"���Ƿ�Ҫ������ѯ��(y/n)";
            cin>>ch;
		
		}while(ch=='Y'||ch=='y');
			return 0;
			system("pause");
}
	



