#ifndef Figure
#define Figure
enum TYPE {LINE, CIRCLE, RECTANGLE, TRIANGLE};
class FigureLink;				// 超前声明 
class Figure
{
	friend class FigureLink;	// FigureLink是连接不同图形绘制类对象的链表类
	protected:
		TYPE type;		// 图形类别：直线 = LINE, 圆 = CIRCLE, 矩形 = RECTANGLE, 三角形 = TRIANGLE
int cx, cy;				// 绘制图形的中心位置坐标
int linestyle;			// 画线样式
int linewidth;			// 画线宽度
int linecolor;			// 画线颜色
int fillpattern;		// 封闭图形的填充样式
int fillcolor;			// 封闭图形的填充颜色
static Figure* ptr;		// 指向将要插入链表的图形绘制对象
Figure* next;			// 指向链表中下一个图形绘制对象	
public:
Figure(int x, int y, TYPE tp, int style = SOLID_LINE, int lnwidth = NORM_WIDTH, 
int lncolor = WHITE, int pattern = EMPTY_FILL, fcolor = BLACK)
{
	cx = x;					
	cy = y;	
	type = tp;				
	linestyle = style;			
    fillpattern = pattern;		
    fillcolor = fcolor;			
	linewidth = lnwidth;		
	linecolor = lncolor;		
}
virtual ~Figure() {}
virtual void Draw() = 0;	// 图形绘制操作的接口规则
vitural void Insert() = 0;	// 图形绘制类对象插入链表操作的接口规则
void show();				// 在图形方式下按指定格式显示图形的各项属性（中心位置坐标属性除外）。
}；
#endif