#include <FL/FL.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <memory>
#include <vector>
#include "wsa.h"
#include "ServerSocket.h"
#include "MainWindow.h"

int main(int argc, char* argv[])
{
	//init mainwindow
	MainWindow m;

	m.show(argc, argv);



	// initialise winsock
	Wsa wsa;
	printf("Initialized Winsock\n");
	//initialise server socket to allow clients to connect
	ServerSocket server(8080);
	printf("Server listening on port 8080\n");
	//Create a client socket
	return Fl::run();
}
