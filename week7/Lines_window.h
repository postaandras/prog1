#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Window  //
{
Lines_window(Point xy, int w, int h, const string& title); //
Open_polyline lines; //
private: //
	Button next_button; 
	Button quit_button;
	
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	
	void next();
	void quit(); //
	
	Menu color_menu;
	Menu style_menu;
	Button color_button;
    Button style_button;

    void change_color(Color col) { lines.set_color(col); }
    void changes(Line_style sty) { lines.set_style(sty); }

	void hide_color_menu() { color_menu.hide(); color_button.show(); }
	void hide_style_menu() { style_menu.hide(); style_button.show(); }
	void color_menu_pressed() { color_button.hide(); color_menu.show(); }
	void style_menu_pressed() { style_button.hide(); style_menu.show(); }

	void red_pressed() { change_color(Color::red);}
	void blue_pressed() { change_color(Color::blue);}
	void black_pressed() { change_color(Color::black);}
	void close_pressed() {hide_color_menu();}


	void solid_pressed() { changes(Line_style::solid);}
    void dash_pressed() { changes(Line_style::dash);}
    void dot_pressed() { changes(Line_style::dot);}
    void style_close_pressed() {hide_style_menu();}

	

	
};
