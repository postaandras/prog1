#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title) :
    Window{xy,w,h,title},
    
    next_button{Point{x_max()-250,0}, 80, 20, "Add point", 
    [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},

    quit_button{Point{x_max()-100,0}, 100, 20, "Quit", 
    [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},

    next_x{Point{x_max()-460,0}, 50, 20, "next x:"},
    next_y{Point{x_max()-335,0}, 50, 20, "next y:"},
    xy_out{Point{100,0}, 100, 20, "current (x,y):"},

    color_menu{Point{x_max()-100,40},100,40,Menu::vertical,"Color"},
    style_menu{Point{x_max()-100,200},100,40,Menu::vertical,"Style"},

    color_button{Point{x_max()-100,40}, 100, 40, "color menu", 
    [](Address, Address pw) {reference_to<Lines_window>(pw).color_menu_pressed();}},
    style_button{Point{x_max()-100,200},100,40,"style menu", 
    [](Address, Address pw) {reference_to<Lines_window>(pw).style_menu_pressed();}}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);
    xy_out.put("");

	color_menu.attach(new Button(Point{0,0},0,0,"close", 
    [](Address, Address pw) {reference_to<Lines_window>(pw).close_pressed();}));
    color_menu.attach(new Button(Point{0,0},0,0,"red",
    [](Address, Address pw) {reference_to<Lines_window>(pw).red_pressed();}));
    color_menu.attach(new Button(Point{0,0},0,0,"blue",
    [](Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed();}));
    color_menu.attach(new Button(Point{0,0},0,0,"black", 
    [](Address, Address pw) {reference_to<Lines_window>(pw).black_pressed();}));
    
    attach(color_menu);
    attach(color_button);
    color_menu.hide();
    
    style_menu.attach(new Button(Point{0,0},0,0,"close",
    [](Address, Address pw) {reference_to<Lines_window>(pw).style_close_pressed();}));
    style_menu.attach(new Button(Point{0,0},0,0,"solid",
    [](Address, Address pw) {reference_to<Lines_window>(pw).solid_pressed();}));
    style_menu.attach(new Button(Point{0,0},0,0,"dash",
    [](Address, Address pw) {reference_to<Lines_window>(pw).dash_pressed();}));
    style_menu.attach(new Button(Point{0,0},0,0,"dot",
    [](Address, Address pw) {reference_to<Lines_window>(pw).dot_pressed();}));
    attach(style_menu);
    attach(style_button);
    style_menu.hide();
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}
