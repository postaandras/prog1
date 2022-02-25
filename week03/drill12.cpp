/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double){return 1;}

double square(double x) {return x*x;}



int main()
{
    using namespace Graph_lib;
    
    int xmax= 1280;
    int ymax = 720;
    
    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};
    
    int x_orig = xmax/2;
    int y_orig = ymax/2;
    
    
    //image
    Image ii {Point{600,400}, "badge.jpg"};
    win.attach(ii);
    
    //Axises
    int xlength = xmax-40;
    int ylength = ymax-40;
    
    int xscale = 30;
    int yscale = 50;
    
    Axis x {Axis::x, Point{20, y_orig}, xlength, xlength/xscale, "x"};
    Axis y {Axis::y, Point{x_orig, ylength+20}, ylength, ylength/yscale, "y"};
    
    win.attach(x);
    win.attach(y);
    
    
    //Functions
    
    int rmin = -10;
    int rmax = 15;
    
    int n_points = 1000;
    
    Point origo {x_orig, y_orig};
    
    Function s (one, rmin, rmax, origo, n_points, xscale, yscale);
    Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
    Function cos_func ([] (double x) {return cos(x);}, rmin, rmax, origo, n_points, xscale, yscale);
    s.set_style(Line_style(Line_style::dash, 4));
    
    
    win.attach(s);
    win.attach(sq);
    win.attach(cos_func);
    
    
    
    //Polygon
    Polygon poly;
    
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});
    poly.add(Point{100,350});
    poly.set_fill_color(Color::green);
    
    win.attach(poly);
    
    
    
    //Rectange
    
    Rectangle r {Point{200,200}, 100, 50};
    r.set_fill_color(Color::blue);
    r.set_style(Line_style(Line_style::dash, 6));
    win.attach(r);
    
    //Text
    Text t {Point{400,200}, "Hello graphics!"};
    //t.set_font(Font::times_itallic);
    t.set_font_size(30);
    win.attach(t);
    
    
    //Circle
    Circle c {Point{400,400}, 50};
    win.attach(c);
    
    
    
    win.wait_for_button();
}

