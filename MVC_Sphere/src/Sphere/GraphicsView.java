/*
 * GraphicsView.java
 *
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

/**
 *
 * @author cnu
 */
package Sphere;

import java.util.Observer;
import java.util.Observable;
import java.awt.*;
//该类为图形视图，用图形显示球
public class GraphicsView extends javax.swing.JPanel implements Observer {
    
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	int x;
	int y;
	double radius;
    
    /** Creates a new instance of GraphicsView */
    public GraphicsView() {
        this.setSize(200, 200);
        this.setBackground(new Color(255,255,255));
    }
    
    public void update(Observable o, Object arg) {
        Sphere s=(Sphere)o;
        radius=s.getRadius();
        //调用paintComponent()函数，重新画
        repaint();
    }
   
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        int X = this.getWidth();
        int Y = this.getHeight();
       // int r=(int)radius;
        int d = (int)radius*2;
        //int r2=(int)radius/2;
        //用一个圆和两个椭圆模拟一个球
        g.drawOval((X-d)/2, (Y-d)/2, d, d);
	    g.drawOval((X-d)/2, Y/2 - d/8, d, d/4);
	    g.drawOval( X/2-d/8, (Y-d)/2, d/4, d);
	    g.drawOval((X-d)/2, (Y-d)/2, d, d);
    }
    public double getRadius()
    {
    	return radius;
    }
   
}
