#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );
	Open_polyline lines;

	bool wait_for_button();

private:
	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	Menu color_menu;
	void red_color();
	void blue_color();
	void black_color();
	void changed_color(Color c);

	Button color_button;
	void hide_color_menu();
	void hide_color_button();

	Menu linestyle_menu;
	void line_solid();
	void line_dash();
	void line_dot();
	void changed_linestyle(Line_style ls);

	Button linestyle_button;
	void hide_linestyle_menu();
	void hide_linestyle_button();

	void next();
	void quit();

};