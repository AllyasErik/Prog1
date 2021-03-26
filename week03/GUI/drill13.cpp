/*
    g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

int main()
{
	constexpr int xmax=1000;
	constexpr int ymax=800;
	const Point p{100,100};

	Simple_window win {p, xmax, ymax, "Canvas"};

	constexpr int grid_size = 100;
	constexpr int grid_max = 800;


	Lines grid;

	for (int x = grid_size; x <= grid_max; x+=grid_size)
	{
		grid.add(Point{x,0},Point{x,grid_max});
		grid.add(Point{0,x},Point{grid_max,x});
	}
	
	win.attach(grid);

	Vector_ref<Rectangle> vr;

	for(int i=0; i<8; ++i)
	{
		vr.push_back(new Rectangle(Point(i*grid_size, i*grid_size), grid_size, grid_size));
		vr[i].set_fill_color(Color::red);
		win.attach(vr[i]);
	}

	Vector_ref<Image> vi;

	vi.push_back(new Image(Point(0,200), "hamburger.jpg"));
	vi.push_back(new Image(Point(0,400), "hamburger.jpg"));
	vi.push_back(new Image(Point(0,600), "hamburger.jpg"));

	constexpr int i_size = 200;

	for(int i = 0; i < vi.size(); ++i)
	{
		//vi[i].set_mask(Point(100,100), i_size, i_size);
		win.attach(vi[i]);
	}

	Image SB(Point(0,0), "spongebob.jpg");

	win.attach(SB);

	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < 8; ++j)
		{
			win.wait_for_button();
			if(j < 7) SB.move(100,0);
			else if(i!=7) SB.move(-700,100);
		}

	win.wait_for_button();
}
