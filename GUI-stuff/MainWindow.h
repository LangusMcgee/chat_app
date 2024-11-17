#pragma once
#include <FL/FL.H>
#include "FL/Fl_Window.H"
#include "FL/Fl_Button.H"
#include "FL/Fl_Flex.H"
#include "FL/Fl_Menu_Bar.h"
#include "FL/Fl_Box.h"
#include "CWidget.h"
#include "Timer.h"
struct ServerSocket;
struct ClientSocket;
struct MainWindow : public Fl_Window, public Timer
{
public:
	MainWindow();
	~MainWindow();
private:
	ServerSocket* m_server;
	ClientSocket* m_client;
	static void on_close(Fl_Widget* _Widget, void* _userdata);
	void on_tick() override;

	Fl_Flex m_maincol;
	Fl_Flex m_bottomrow;
	Fl_Menu_Bar m_menubar;
	CWidget m_content;
	Fl_Button m_prev;
	Fl_Box m_spacer;
	Fl_Button m_next;
};
