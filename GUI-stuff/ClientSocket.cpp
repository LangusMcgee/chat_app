#include "ClientSocket.h"
#include <stdexcept>

ClientSocket::ClientSocket()
	: m_socket(INVALID_SOCKET)
{ }
ClientSocket::~ClientSocket()
{
	if (m_socket != INVALID_SOCKET) // close socket if valid
	{
		closesocket(m_socket);
	}
}

bool ClientSocket::receive(std::string& _message) // reference to the message to allow direct assignment
{
	char buffer[128] = { 0 }; //hold incoming messages
	int bytes = ::recv(m_socket, buffer, sizeof(buffer) - 1, 0); // recieve message and assign it to the buffer object
	if (bytes == SOCKET_ERROR) // check for errors
	{
		if (WSAGetLastError() != WSAEWOULDBLOCK) // if its not a blocking error then something went wrong with the read
		{
			throw std::runtime_error("Read failed");
		}
		return false; // data not yet recieved
	}
	else if (bytes == 0)
	{
		closed = true;
		return false;
	}
	_message = buffer; // store the message in _message, this means that whatever string was passed into the function will be contain the recieved message.
	return true;
}


void ClientSocket::send(const std::string& _message)
{
	int bytes = ::send(m_socket, _message.c_str(), _message.length(), 0);
	if (bytes <= 0)
	{
		throw std::runtime_error("Failed to send data");
	}
}
