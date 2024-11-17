#include <winsock2.h>
#include <memory>
#include <string>

struct ServerSocket;
struct ClientSocket
{
	ClientSocket();
	~ClientSocket();
	bool receive(std::string& _message);
	void send(const std::string& _message);
	bool closed;
private:
	friend struct ServerSocket;
	SOCKET m_socket;
	ClientSocket(const ClientSocket& _copy);
	ClientSocket& operator=(const ClientSocket& _assign);
};