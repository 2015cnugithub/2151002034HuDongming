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
	cout<<"商品号：\t"<<no<<endl;
	cout<<"商品价格:\t"<<price<<endl;
	cout<<"商品名：\t"<<p_name<<endl;
	cout<<"商品总数：\t"<<count<<endl;
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
	CClothes cl(1008,"武警作训服",178,"5031后勤军工厂");
	cl.print();
	cl.usedfor();
	CFood cf(1009,"佳宝乳业",3.5,"济南佳宝乳业工业");
	cf.print();
	cf.usedfor();
}
	






	

