#ifndef Line
#define line
#include <graphics.h>
#include <conio.h>
#include "Figure.h"
class Line:public Figure
{
private:
	int length;	// 直线长度
	int angle  //  直线与水平方向的夹角 (以度单位)
public:
	Line();
	void Insert()
	{
		ptr = new Circle(cx, cy, linestyle, linewidth, linecolor, fillpattern, fillcolor);
	}
	void draw()
	{
		show();
		initgraph(600, 600);
		setcolor(RED);
	    setfillstyle(BLUE);
		line(80,  120, 110, 120);
	}
	Line(int x, int y, TYPE tp, int style = SOLID_LINE, int lnwidth = NORM_WIDTH, 
         int lncolor = WHITE, int pattern = EMPTY_FILL, fcolor = BLACK,int length_val=5,int angle_val=45)
	{
        cx = x;					
	    cy = y;	
	    type = tp;				
	    linestyle = style;			
        fillpattern = pattern;		
        fillcolor = fcolor;			
	    linewidth = lnwidth;		
	    linecolor = lncolor;
		length = length_val;
		angle = angle_val;

	}
	void show()
	{
		cout<<"Line"<<endl;
	}


};
#endif