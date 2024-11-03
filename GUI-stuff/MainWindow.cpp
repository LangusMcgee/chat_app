#include "MainWindow.h"
#include <iostream>
#include <stdexcept>

MainWindow::MainWindow()
	: Fl_Window(640, 480, "hello"), Timer(1.0),
	m_maincol(0,0,w(), h()),
	m_bottomrow(0,0,0,0),
	m_menubar(0,0,0,0),
	m_content(),
	m_prev(0,0,0,0),
	m_spacer(0,0,0,0),
	m_next(0,0,0,0)

{
	add_resizable(m_maincol);
	m_maincol.add_resizable(m_menubar);
	//m_maincol.add_resizable(m_content);
	m_maincol.add_resizable(m_bottomrow);

	m_maincol.fixed(m_menubar, 30);
	m_maincol.fixed(m_bottomrow, 40);

	m_bottomrow.type(Fl_Flex::ROW);
	m_bottomrow.margin(5);
	m_bottomrow.add_resizable(m_prev);
	m_bottomrow.add_resizable(m_spacer);
	m_bottomrow.add_resizable(m_next);
	m_bottomrow.fixed(m_prev, 120);
	m_bottomrow.fixed(m_next, 120);

	//m_content.color(fl_rgb_color(255, 255, 255));
	//m_content.box(FL_DOWN_BOX);

	m_menubar.add("&File/&Open", "^o", NULL);
	m_menubar.add("&File/&Save", "^s", NULL, 0, FL_MENU_DIVIDER);
	m_menubar.add("&File/&Quit", "^q", NULL);

	m_menubar.add("&Edit/&Undo", "^z", NULL);
	m_menubar.add("&Edit/&Redo", "^y", NULL, 0, FL_MENU_DIVIDER);
	m_menubar.add("&Edit/&Copy", "^c", NULL);
	m_menubar.add("&Edit/&Paste", "^v", NULL);

	m_menubar.add("&Help/&About", NULL, NULL);
}

MainWindow::~MainWindow()
{
	std::cout << "MainWindow Destructed..." << std::endl;
}

void MainWindow::on_close(Fl_Widget* _Widget, void* _userdata)
{
	MainWindow* win = (MainWindow*)_userdata;
	win->hide();
}

void MainWindow::on_tick()
{
	std::cout << "tick" << std::endl;
}