#ifndef Goods
#define Goods
class CGoods
{
private:
	long no;
	char *p_name;
	double price;
	static int count;
public:
	CGoods(long no_val=0,char *p_name_val="",double price_val=0.00);
	CGoods(CGoods &c);
void set(long no_val,char *p_name_val,double price_val)
{
   no=no_val;
   p_name=new char[strlen(p_name_val)+1];
   strcpy(p_name,p_name_val);
   price=price_val;
};
void print()const;
int getCount();
virtual void usedfor()const
{
	cout<<"该商品用于\t"<<endl;
}
friend char*getName(CGoods &g);
bool operator < (const CGoods &c_r)const;
bool operator ==(const CGoods &c_r)const;
template<class T>
friend operator>(const T &r_a,const T &r_b)
{
	if(r_a.price>r_b.price)
		return true;
	else
		return false;
}
~CGoods();
};
class CClothes:public CGoods
{
private :
	char *p_brand;
public:
	CClothes(long no_val=0,char *p_name_val="",double price_val=0.00,char *p_b="")
	{
		CGoods::set(no_val,p_name_val,price_val);
		p_brand=new char[strlen(p_b)+1];
		strcpy(p_brand,p_b);
	}
	void usedfor()const
	{
	    cout<<"该商品品牌:"<<p_brand<<endl;
		cout<<"服饰\t"<<endl<<endl;
	}
	~CClothes()
	{
       delete p_brand;
	}
};
class CFood:public CGoods
{
  private:
	char *p_brand;
	public:
	CFood(long no_val=0,char *p_name_val="",double price_val=0.00,char *p_b="")
	{
		CGoods::set(no_val,p_name_val,price_val);
		p_brand=new char[strlen(p_b)+1];
		strcpy(p_brand,p_b);
	}
    void usedfor()const
	{
		cout<<"该商品品牌:"<<p_brand<<endl;
		cout<<"食品\t"<<endl<<endl;
	}
	~CFood()
	{
       delete p_brand;
	}
};
#endif