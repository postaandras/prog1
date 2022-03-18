#include "Simple_window.h"
#include "Graph.h"

#include "std_lib_facilities.h"

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main(){
	
	int x_size = 600;
	int y_size = 600;

	Simple_window win {Point{100, 100}, x_size, y_size, "Function graphs"};

	constexpr int x_scale = 20;
	constexpr int y_scale = 20;
	
	string x_massage = "1 == " + to_string(x_scale) + " pixels";
	string y_massage = "1 == " + to_string(y_scale) + " pixels";

	Axis x {Axis::x, Point{100, 300}, 400, x_scale, x_massage};
	Axis y {Axis::y, Point{300, 500}, 400, y_scale, y_massage};

	x.set_color(Color::red);
	y.set_color(Color::red);

	win.attach(x);
	win.attach(y);
	
	constexpr int r_min = -10;
	constexpr int r_max = 11;

	constexpr int num_points = 400;

	const Point orig {x_size/2, y_size/2};

	Function f1 {one, r_min, r_max, orig, num_points, x_scale, y_scale};
	Function f2 {slope, r_min, r_max, orig, num_points, x_scale, y_scale};
	
	Text t {Point{120,400}, "x/2"};
	
	Function f3 {square,r_min, r_max, orig, num_points, x_scale, y_scale};
	Function f4 {cos, r_min, r_max, orig, num_points, x_scale, y_scale};
	f4.set_color(Color::blue);
	Function f5 {sloping_cos, r_min, r_max, orig, num_points, x_scale, y_scale};

	win.attach(f1);
	win.attach(f2);
	win.attach(t);
	win.attach(f3);
	win.attach(f4);
	win.attach(f5);
	
	win.wait_for_button();
}
