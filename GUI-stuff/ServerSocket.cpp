#include <ws2tcpip.h>
#include "ServerSocket.h"
#include "ClientSocket.h"
#include <stdexcept>
#include <string>
ServerSocket::ServerSocket(int _port)
	: Timer(1.0), m_socket(INVALID_SOCKET)
{
	//Address information setup
	addrinfo hints = { 0 }; // reset hints for new data.
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	addrinfo* result = NULL;


	if (getaddrinfo(NULL, std::to_string(_port).c_str(), &hints, &result) != 0)
	{
		throw std::runtime_error("Failed to resolve server address or port");
	}
	m_socket = socket(result->ai_family, result->ai_socktype, //create the server socket
		result->ai_protocol);
	if (m_socket == INVALID_SOCKET) //Check if socket is created correctly
	{
		freeaddrinfo(result);
		throw std::runtime_error("Failed to create socket");
	}
	if (bind(m_socket, result->ai_addr, result->ai_addrlen) == SOCKET_ERROR)
	{
		freeaddrinfo(result);
		throw std::runtime_error("Failed to bind socket");
	}
	freeaddrinfo(result);
	if (listen(m_socket, SOMAXCONN) == SOCKET_ERROR)
	{
		throw std::runtime_error("Failed to listen on socket");
	}
	u_long mode = 1;
	if (ioctlsocket(m_socket, FIONBIO, &mode) == SOCKET_ERROR)
	{
		throw std::runtime_error("Failed to set non-blocking");
	}
}
//destructor
ServerSocket::~ServerSocket()
{
	closesocket(m_socket);//close socket upon object destruction
}

//accepting new clients
std::shared_ptr<ClientSocket> ServerSocket::accept()
{
	SOCKET socket = ::accept(m_socket, NULL, NULL);
	if (socket == INVALID_SOCKET)
	{
		if (WSAGetLastError() != WSAEWOULDBLOCK)// checking if the error is anything but 'WSAWOULDBLOCK'
		{										// Likely that the client would have disconnected in this case...
			throw std::runtime_error("Failed to accept socket");
		}
		return std::shared_ptr<ClientSocket>(); // Returning a null pointer because there is no connection yet...
	}
	std::shared_ptr<ClientSocket> rtn = std::make_shared<ClientSocket>();
	rtn->m_socket = socket;
	return rtn;
}

void ServerSocket::on_tick()
{
	printf("--Server Tick--\n");
	std::shared_ptr<ClientSocket> client = accept();
	if (client)
	{
		printf("Client Connected!\n");
		m_clients.push_back(client);
	}
}