
#include "Simple_window.h"   
#include "Graph.h" 

double one

int main(){

	int xmax=600;
	int ymax=600;	
	
	Simple_window win {Point{200,200},xmax,ymax,"Function graphs"};
	
	
	int xlength = xmax-200;
	int ylength = ymax-200;
	
	int y_orig = 300;
	int x_orig = 300;
	
	int xscale = 20;
	int yscale = 20;
	    
	Axis x {Axis::x, Point{100, y_orig}, xlength, xlength/xscale, "1 = = 20 pixels"};
	Axis y {Axis::y, Point{x_orig, ylength+100}, ylength, ylength/yscale, "1 = = 20 pixels"};
	    
	x.set_color(Color::red);  
	y.set_color(Color::red);    
	
	win.attach(x);
	win.attach(y);
	
	
	win.wait_for_button();
}
