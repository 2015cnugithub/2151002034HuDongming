#ifndef Figure
#define Figure
enum TYPE {LINE, CIRCLE, RECTANGLE, TRIANGLE};
class FigureLink;				// ��ǰ���� 
class Figure
{
	friend class FigureLink;	// FigureLink�����Ӳ�ͬͼ�λ���������������
	protected:
		TYPE type;		// ͼ�����ֱ�� = LINE, Բ = CIRCLE, ���� = RECTANGLE, ������ = TRIANGLE
int cx, cy;				// ����ͼ�ε�����λ������
int linestyle;			// ������ʽ
int linewidth;			// ���߿��
int linecolor;			// ������ɫ
int fillpattern;		// ���ͼ�ε������ʽ
int fillcolor;			// ���ͼ�ε������ɫ
static Figure* ptr;		// ָ��Ҫ���������ͼ�λ��ƶ���
Figure* next;			// ָ����������һ��ͼ�λ��ƶ���	
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
virtual void Draw() = 0;	// ͼ�λ��Ʋ����Ľӿڹ���
vitural void Insert() = 0;	// ͼ�λ�������������������Ľӿڹ���
void show();				// ��ͼ�η�ʽ�°�ָ����ʽ��ʾͼ�εĸ������ԣ�����λ���������Գ��⣩��
}��
#endif