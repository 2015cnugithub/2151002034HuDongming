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
	
	
//���㵱ǰ����ĵ���ָ��ԭ��ľ���
	 protected double pointDistance(double x1, double y1, double x2, double y2) {
		    return Math.pow(((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)), 1/2.0);
	 }

	
/*
 * ���ֿ���ͼ�ηŴ��С
 */
	public void mouseWheelMoved(MouseWheelEvent e) {
		final double limitR = 175;
		int count = e.getWheelRotation();
	    int direction = (Math.abs(count) > 0) ? 0 : 1;
	    if(direction==1){
	    	if(g.radius + count*3 >limitR){
	    		JOptionPane.showMessageDialog(null,"�Ŵ󳬳���ʾ��Χ��~");
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
	    		JOptionPane.showMessageDialog(null,"̫С�˾Ϳ������ˣ�");
	    	}
	    	else
	    		g.radius = g.radius - count*3 ;
	    	sphere.setRadius(g.radius);
	    	g.repaint();

	   }
	    
	}
}
