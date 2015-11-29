#include<graphics.h>
#include <conio.h>
#include <dos.h>
#include "iostream"
#include <stdio.h>
#include<Windows.h>

using namespace std;
class FigureLink;//超前声明
class Figure
{
	friend class FigureLink;
protected:
    int cx,cy;
	Figure *ptr;//指向将要插入链表的图形绘制对象
	Figure *next;//指向链表中的下一个图形绘制对象f
public:
	Figure(int x, int y)
	{
		cx = x;
		cy = y;
		next = 0;
	}
	virtual void draw()=0;//图形绘制操作的接口规则
	virtual void insert()=0;//图形绘制类对象插入链表的借口规则
	void hide()
	{
      int sc=getcolor();
	  setcolor(BLACK);
	  draw();
	  setcolor(sc);
	}
	void move()
	{
	  int sc=getcolor();
	  setcolor(BLACK);
	  draw();
	  setcolor(sc);
	  cx+=1;
 	  draw();
	}
};

class Circle  :public Figure	//圆形
{
private:
	int radius;//半径
public:
	Circle(int x, int y,int rad):Figure(x,y)
	{
		radius = rad;
	}
	void draw();
	void insert();
};

void Circle::draw()
{
	circle(cx,cy,radius);
}

void Circle::insert()
{
	ptr  =new Circle(cx,cy,radius);
}

class Rect:public Figure	//矩形
{
private:
	int width;
	int length;
public:
	Rect(int w, int l, int x, int y):Figure(x,y)
	{
		width = w;
		length = l;
	}
	void draw();
	void insert();
};

void Rect::draw()
{
	rectangle(cx-width/2,cy-length/2,cx+width/2,cy+length/2);
}

void Rect::insert()
{
	ptr = new Rect(width,length,cx,cy);
}

class Triangle:public Figure	//三角形
{
private:
	int isTriangle;
	int dibianSide;
	int heightSide;
public:
	Triangle(int dSide,int hSide,int isT,int x,int y):Figure(x,y)
	{
		dibianSide = dSide;
		heightSide = hSide;
		isTriangle = isT;
	}
	void draw();
	void insert();
};

void Triangle::draw()
{
	if(isTriangle==1)
	{
	   int pts[] = {cx-dibianSide/2,cy+heightSide/2,cx+dibianSide/2,cy+heightSide/2,cx+dibianSide/2,cy-heightSide/2};
       drawpoly(3,pts);
	}
	else
	{
	   int pts[6] = {cx-dibianSide/2,cy+heightSide/2,cx+dibianSide/2,cy+heightSide/2,cx-dibianSide/2,cy-heightSide/2};
	   drawpoly(3,pts);
	}
}

void Triangle::insert()
{
	ptr = new Triangle(dibianSide,heightSide,isTriangle,cx,cy);
}

class FigureLink
{
 protected:
	Figure *figure_head;
 public:
	FigureLink()
	{
		figure_head = 0;
	}
	~FigureLink()
	{}
	void insert(Figure *figureNode);
	void draw();
	void hide();
	void move();
};

void FigureLink::insert(Figure *figureNode)
{
	figureNode->next = NULL;
	figureNode->insert();
	if(figure_head)
	{
		figureNode->ptr->next = figure_head;
		figure_head = figureNode->ptr;
	}
	else 
	figure_head = figureNode->ptr;
}

void FigureLink::draw()
{
	Figure *p;
	p = figure_head;
	while(p)
	{
		p->draw();
		p = p->next;
	}
}

void FigureLink::hide()
{
	Figure *p = figure_head;
	while(p)
	{
		p->hide();
		p = p->next;
	}
}

void FigureLink::move()
{
	Figure *p = figure_head;
	while(p)
	{
		p->move();
		p = p->next;
	}
}

class Vehicle//车辆类
{
protected:
	FigureLink figurLink;
	int WheelSize;
	int startX;
	int startY;
public:
	void draw();
	void hide();
	void move();
};

void Vehicle::draw()
{
	figurLink.draw();
}

void Vehicle::hide()
{
	figurLink.hide();
}

void Vehicle::move()
{
	int speed=10;
    for(int i=0;i<600;i++)
	{
       	figurLink.move();
		Sleep(speed);
		if(kbhit())
		{
			int select = getch();
			if(select==43||select==61)
			{
			  speed-=5;
			}
			else if(select==45||select==189)
			{
				 speed+=5;
			}
			else if(select==80||select==112)
			{ 
			
				while(true)
				{
				   char c = getch();
				   if(select==80||select==112)
				   {
						break;
				   }
				}
			}
		
			else if(select==69||select==101)
			{
			     break;
			}
		
		}
	}
   
}

class Car:public Vehicle
{
public:
	Car(int d, int startX, int startY);
};

Car::Car(int d,int x,int y)
{
	WheelSize = d;
	startX = x;
	startY = y;
	Figure *p;
	p=new Triangle(d,d,1,x+1.75*d,y-2.5*d);
	figurLink.insert(p);

	p=new Rect(3.5*d,d,x+4*d,y-2.5*d);
	figurLink.insert(p);

	p=new Triangle(d,d,2,x+6.25*d,y-2.5*d);
	figurLink.insert(p);

	p=new Rect(8*d,d,x+4*d,y-1.5*d);
	figurLink.insert(p);

	p=new Circle(x+1.75*d,y-0.5*d,0.5*d);
	figurLink.insert(p);

	p=new Circle(x+6.25*d,y-0.5*d,0.5*d);
	figurLink.insert(p);
}

class Truck : public Vehicle
{
  public:
	Truck(int d, int x, int y);
};

Truck::Truck(int d,int x,int y)
{
	WheelSize=d;
	startX = x;
	startY = y;

	Figure *p;
	p=new Rect(9*d,4*d,x+4.5*d,y-3*d);
    figurLink.insert(p);

	p=new Rect(2*d,3*d,x+2+10*d,y-2.5*d);
    figurLink.insert(p);

	p=new Circle(x+d,y-0.5*d,0.5*d);
    figurLink.insert(p);

	p=new Circle(x+2.25*d,y-0.5*d,0.5*d);
	figurLink.insert(p);

	p=new Circle(x+6.75*d,y-0.5*d,0.5*d);
    figurLink.insert(p);

	p=new Circle(x+8*d,y-0.5*d,0.5*d);
    figurLink.insert(p);

	p=new Circle(x+10*d,y-0.5*d,0.5*d);
    figurLink.insert(p);
}

int main()
{
	initgraph(800,640);
	outtextxy(20,10,"Please select :   1. Car  2. Truck  3. Exit");
	rectangle(20,30,780,635);
	outtextxy(25,35,"Press <S> key to start moving");
	outtextxy(25,50,"Press <P> key to pause/continue moving");
	outtextxy(25,65,"Press <E> key to end moving");
	outtextxy(25,80,"Press <+> key to speed up");
	outtextxy(25,95,"Press <-> key to speed down");

	Vehicle *vehicle;
	vehicle = 0;
    Car car(20,45,365);
	Truck truck(20,45,365);
	char select;
    select = getch();
    while(select!='3')
	{
		if(select=='1')
		{
			if(vehicle) 
			{
			  vehicle->hide();
			}
			vehicle = &car;
			vehicle->draw();
		
		}
		else if(select=='2')
		{
			if(vehicle) 
			{
			  vehicle->hide();
			}
			vehicle = &truck;
			vehicle->draw();
			
		}
		else if(select=='S'||select=='s')
		{
			if(vehicle)
			{
			  vehicle->move();
			}
		}
		select = getch();
	}

   closegraph();
   system("pause");
   return 0;
}