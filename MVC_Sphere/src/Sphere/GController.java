package Sphere;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import java.util.Observable;

import javax.swing.JOptionPane;

public class GController implements MouseWheelListener{
	
	Sphere sphere;
	GraphicsView g = new GraphicsView();
	public GController(Observable o)
	{
		sphere = (Sphere)o;
		sphere.addObserver(g);
	    g.addMouseWheelListener(this);
		g.update(sphere,null);
	}
	
	public GraphicsView getView(){
		return g;
	}
	
	
//计算当前点击的点与指定原点的距离
	 protected double pointDistance(double x1, double y1, double x2, double y2) {
		    return Math.pow(((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)), 1/2.0);
	 }

	
/*
 * 滚轮控制图形放大放小
 */
	public void mouseWheelMoved(MouseWheelEvent e) {
		final double limitR = 175;
		int count = e.getWheelRotation();
	    int direction = (Math.abs(count) > 0) ? 0 : 1;
	    if(direction==1){
	    	if(g.radius + count*3 >limitR){
	    		JOptionPane.showMessageDialog(null,"放大超出显示范围啦~");
	    	}
	    	else
	    	{
	    		g.radius = count*3 + g.radius;
	    		sphere.setRadius(g.radius);
	    		g.repaint();
	    	}
	    	
	    }
	    if(direction==0){
	    	if(g.radius - count*3<0){
	    		JOptionPane.showMessageDialog(null,"太小了就看不见了！");
	    	}
	    	else
	    		g.radius = g.radius - count*3 ;
	    	sphere.setRadius(g.radius);
	    	g.repaint();

	   }
	    
	}
}
