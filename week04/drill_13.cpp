/*
g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Drill2 `fltk-config --ldflags --use-images`

Posta András

2022.03.04 17:54:

*/


#include "std_lib_facilities.h"
#include "Simple_window.h"
#include "Graph.h"

int main() {
	using namespace Graph_lib;
	
	
	//Creating the window
	Point starting_Point{100,100};
	int width = 800;
	int height = 1000;
	Simple_window win {starting_Point,width,height, "Canvas"};
	win.set_label("13. drill");
	
	
	//Creating the grid
	Lines grid;
	int grid_size = 100;
    	int grid_max = 800;
	for(int coord=grid_size; coord<=grid_max; coord+=grid_size){
		grid.add(Point{coord,0},Point{coord,grid_max});
		grid.add(Point{0,coord},Point{grid_max,coord});}
    
    
	grid.set_color(Color::black);
	grid.set_style(Line_style{Line_style::solid,2});
	win.attach(grid);



	//Adding the squares
	
	Vector_ref<Rectangle> squares;
	for(int n = 0; n<8; n++){
		squares.push_back(new Rectangle{Point{n*100,n*100},100,100});
		squares[squares.size()-1].set_fill_color(Color::red);
		win.attach(squares[squares.size() -1]);
	}
	

	//Adding the images
	Vector_ref<Image> Pictures;
	    
	for(int n=0; n<3; n++){
		Pictures.push_back(new Image{Point{(n+1)*200,(n)*200},"random.jpg"});
		win.attach(Pictures[n]);
	}

	//Moving image
	
	
	Vector_ref<Image> moveing;
	int x_coord = 0;
	int y_coord = 0;
	moveing.push_back(new Image{Point{x_coord,y_coord}, "badge_cropped.jpg"});
	int id = 1;
	
	
	
	win.attach(moveing[0]);

	while(x_coord<=700){
		win.detach(moveing[id-1]);
		
		
		if(y_coord<=700){
			if(
			(x_coord == 200 && y_coord == 0) ||
			(x_coord == 300 && y_coord == 0) ||
			(x_coord == 400 && y_coord == 200) ||
			(x_coord == 500 && y_coord == 200) ||
			(x_coord == 600 && y_coord == 400) ||
			(x_coord == 700 && y_coord == 400)
			)
			{
			  y_coord += 200;
			}
			
			moveing.push_back(new Image{Point{x_coord,y_coord}, "badge_cropped.jpg"});
			win.attach(moveing[id]);
			y_coord += 100;
			id++;
			win.wait_for_button();
		}
		else{
			y_coord=0;
			x_coord += 100;
		}
	}
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

