#include <FL/Fl_Widget.H>
#include <FL/Fl_PNG_Image.H>

class CWidget : Fl_Widget
{
public:
	CWidget();

private:
	int m_x{ -1 };
	int m_y{ -1 };
	void draw();
	int handle(int _event);
	Fl_PNG_Image cat;
};