#include <FL/FL.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include "MainWindow.h"

int main(int argc, char* argv[])
{
	MainWindow m;

	m.show(argc, argv);

	return Fl::run();
}
