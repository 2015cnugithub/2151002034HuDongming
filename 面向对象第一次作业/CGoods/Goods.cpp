#include<iostream>
using namespace std;
#include "Goods.h"
CGoods::CGoods(long no_val,char *p_name_val,double price_val)
{
	no=no_val;
	price=price_val;
	p_name=new char[strlen(p_name_val)+1];
	strcpy(p_name,p_name_val);
	count++;
}
CGoods::~CGoods()
{
  delete p_name;
}
CGoods::CGoods(CGoods &c)
{
	no=c.no;
	p_name=new char[strlen(c.p_name)+1];
	strcpy(p_name,c.p_name);
	count++;
}
void CGoods::print()const
{
	cout<<"��Ʒ�ţ�\t"<<no<<endl;
	cout<<"��Ʒ�۸�:\t"<<price<<endl;
	cout<<"��Ʒ����\t"<<p_name<<endl;
	cout<<"��Ʒ������\t"<<count<<endl;
	cout<<endl;
}
int CGoods::getCount()
{
	return count;
}

bool CGoods::operator <(const CGoods &c_r)const
{
	if(price<c_r.price)
		return true;
	else
		return false;
}
bool CGoods::operator ==(const CGoods &c_r)const
{
	if(price==c_r.price)
		return true;
	else
		return false;
}
int CGoods::count=0;
char* getName(CGoods &g)
{
	return g.p_name;
}
void main()
{
	
	CGoods c1(20151004,"ASUS",4300);
	c1.print();
	CGoods c2(20161004,"Apple",4800);
	c2.print();
	CClothes cl(1008,"�侯��ѵ��",178,"5031���ھ�����");
	cl.print();
	cl.usedfor();
	CFood cf(1009,"�ѱ���ҵ",3.5,"���ϼѱ���ҵ��ҵ");
	cf.print();
	cf.usedfor();
}
	






	

