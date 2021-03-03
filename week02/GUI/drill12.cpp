/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

int main()
try{
    using namespace Graph_lib;

    int xmax = 600;
    int ymax = 400;

    

    Simple_window win {Point{100,100}, xmax, ymax, "My window"};



	Axis xa {Axis::x, Point{40, 400}, 280, 5, "x axis"};
	Axis ya {Axis::y, Point{40, 400}, 280, 5, "y axis"};
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);

	


	Function sine{sin, 0, 100, Point{20,150},250,50,50};
	sine.set_color(Color::dark_green);



	Polygon poly;
	poly.add(Point(300,200));
	poly.add(Point(350,100));
	poly.add(Point(400,200));

	poly.set_color(Color::red);
	poly.set_color(Line_style::dash);

	
	

	Rectangle r {Point{150,150}, 50, 20};

	r.set_fill_color(Color::green);
	r.set_style(Line_style(Line_style::dash, 6));



	
	Closed_polyline poly_rect;
	poly_rect.add(Point(100,50));
	poly_rect.add(Point(300,100));
	poly_rect.add(Point(300,200));
	poly_rect.add(Point(200,200));
	poly_rect.add(Point(75,100));

	poly_rect.set_style(Line_style(Line_style::dash,3));
	poly_rect.set_fill_color(Color::dark_blue);
	



	Text t {Point{250,500}, "Jare jare daze"};
	t.set_font(Font::times_bold);
	t.set_font_size(30);

	


	Image ii {Point{500,500}, "badge.jpg"};



	Circle c {Point{200,400}, 100};

	


	Ellipse e (Point(100,200), 100, 50);
	e.set_color(Color::dark_red);

	


	Mark m {Point{120,250}, 'E'};

	


	ostringstream oss;

	oss << "screen size: " << x_max() << "*" << y_max()
		<< "; window size: " << win.x_max() << "*" << win.y_max();

	


	Text sizes (Point(150,40), oss.str());



	win.attach(sizes);
	win.attach(m);
	win.attach(poly_rect);
	win.attach(poly);
	win.attach(c);
	win.attach(t);
	win.attach(r);
	win.attach(sine);
	win.attach(xa);
	win.attach(ya);
	win.attach(ii);

    win.wait_for_button();
}

catch(exception& e) {
	cerr << e.what() << endl;
	return 1;
}
catch(...) {
	cerr << "some error" << endl;
	return 2;
}