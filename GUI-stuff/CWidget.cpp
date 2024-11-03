#include "CWidget.h"
#include <FL/fl_draw.H>
#include <iostream>
#include <FL/Fl_Box.H>

CWidget::CWidget() : Fl_Widget(0, 0, 0, 0), cat("image/cat.png")
{

}

void CWidget::draw()
{
    fl_draw_box(FL_DOWN_BOX, x(), y(), w(), h(), fl_rgb_color(100, 149, 237));
    fl_color(fl_rgb_color(255, 0, 0));
    cat.draw(32, 32);
    fl_draw("Hello World", x() + 10, y() + 10);
}

int CWidget::handle(int _event)
{
    if (_event == FL_PUSH || _event == FL_DRAG)
    {
        std::cout << "Clicked or dragged the mouse! " << Fl::event_x() << " " << Fl::event_y() << std::endl;

        return 1;
    }

    return Fl_Widget::handle(_event);
}