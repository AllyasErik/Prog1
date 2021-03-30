#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},

    color_menu{Point{x_max()-150,50}, 150, 40, Menu::vertical,"Colors"},
    color_button{Point{x_max()-150,50}, 150, 40, "color menu",
        [](Address, Address pw) {reference_to<Lines_window>(pw).hide_color_button();}},

    linestyle_menu{Point{x_max()-300,50}, 150, 40, Menu::vertical,"Linestyles"},
    linestyle_button{Point{x_max()-300,50}, 150, 40, "linestyle menu",
        [](Address, Address pw) {reference_to<Lines_window>(pw).hide_linestyle_button();}},

    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);

    color_menu.attach(new Button(Point{0,0},0,0,"red",
               [](Address, Address pw) {reference_to<Lines_window>(pw).red_color();}));
    color_menu.attach(new Button(Point{0,0},0,0,"blue",
               [](Address, Address pw) {reference_to<Lines_window>(pw).blue_color();}));
    color_menu.attach(new Button(Point{0,0},0,0,"black",
               [](Address, Address pw) {reference_to<Lines_window>(pw).black_color();}));
    attach(color_menu);
    color_menu.hide();
    attach(color_button);

    linestyle_menu.attach(new Button(Point{0,0},0,0,"solid",
               [](Address, Address pw) {reference_to<Lines_window>(pw).line_solid();}));
    linestyle_menu.attach(new Button(Point{0,0},0,0,"dash",
               [](Address, Address pw) {reference_to<Lines_window>(pw).line_dash();}));
    linestyle_menu.attach(new Button(Point{0,0},0,0,"dot",
               [](Address, Address pw) {reference_to<Lines_window>(pw).line_dot();}));
    attach(linestyle_menu);
    linestyle_menu.hide();
    attach(linestyle_button);

    attach(lines);
}

void Lines_window::changed_color(Color c)
{
    lines.set_color(c);
}

void Lines_window::red_color()
{
    changed_color(Color::red);
    hide_color_menu();
    redraw();

}

void Lines_window::blue_color()
{
    changed_color(Color::blue);
    hide_color_menu();
    redraw();

}

void Lines_window::black_color()
{
    changed_color(Color::black);
    hide_color_menu();
    redraw();

}

void Lines_window::hide_color_menu()
{
    color_menu.hide();
    color_button.show();
}

void Lines_window::hide_color_button()
{
    color_button.hide();
    color_menu.show();
}

void Lines_window::changed_linestyle(Line_style ls)
{
    lines.set_style(ls);
}

void Lines_window::line_solid()
{
    changed_linestyle(Line_style::solid);
    hide_linestyle_menu();
    redraw();
}

void Lines_window::line_dash()
{
    changed_linestyle(Line_style::dash);
    hide_linestyle_menu();
    redraw();
}

void Lines_window::line_dot()
{
    changed_linestyle(Line_style::dot);
    hide_linestyle_menu();
    redraw();
}

void Lines_window::hide_linestyle_menu()
{
    linestyle_menu.hide();
    linestyle_button.show();
}

void Lines_window::hide_linestyle_button()
{
    linestyle_button.hide();
    linestyle_menu.show();
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