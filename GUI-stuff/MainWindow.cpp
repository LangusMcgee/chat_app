#include "MainWindow.h"
#include "ServerSocket.h"
#include "ClientSocket.h"
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

	m_menubar.add("&Create Server", NULL, NULL);
	m_menubar.add("&Join Server", NULL, NULL, 0, FL_MENU_DIVIDER);
	m_menubar.add("&Quit", NULL, NULL);
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
	//std::cout << "tick, this is in the 'on_tick' virtual func in MainWindow.cpp..." << std::endl;
}