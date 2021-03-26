/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

double one(double x) { return 1; }

double slope (double x) { return x/2; }

double square(double x) { return x*x; }

double sloping_cos(double x) { return slope(x) + cos(x); }

int main()
{
    using namespace Graph_lib;

    constexpr int xmax = 600;
    constexpr int ymax = 600;

    constexpr int x_orig = xmax/2;
    constexpr int y_orig = ymax/2;

    constexpr int rmin = -10;
    constexpr int rmax = 11;

	constexpr int length = 400;    
    constexpr int n_points = 400;
    constexpr int x_scale = 20;
	constexpr int y_scale = 20;

    Simple_window win {Point{100,100}, xmax, ymax, "Function graphs"};

	Point origo {x_orig, y_orig};

	Axis x (Axis::x, Point(100, x_orig), length, 20, "1 == 20 pixels");
	Axis y (Axis::y, Point(x_orig, length+100), length, 20, "1 == 20 pixels");
	x.set_color(Color::red);
	y.set_color(Color::red);

	Function line (one, rmin, rmax, origo, n_points, x_scale, y_scale);

	Function slope_line (slope, rmin, rmax, origo, n_points, x_scale, y_scale);
	Text text(Point(100,385), "x/2");

	Function square_line(square, rmin, rmax, origo, n_points, x_scale, y_scale);

	Function cos_line(cos, rmin, rmax, origo, n_points, x_scale, y_scale);
	cos_line.set_color(Color::blue);

	Function sloping_cos_line(sloping_cos, rmin, rmax, origo, n_points, x_scale, y_scale);

	Mark m {origo, 'O'};
	win.attach(sloping_cos_line);
	win.attach(cos_line);
	win.attach(m);
	win.attach(cos_line);
	win.attach(text);
	win.attach(slope_line);
	win.attach(line);
	win.attach(x);
	win.attach(y);
    win.wait_for_button();

    return 0;
}
