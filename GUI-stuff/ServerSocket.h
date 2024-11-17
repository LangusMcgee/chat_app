#include <winsock2.h>
#include <memory>
#include <vector>
#include "Timer.h"

struct ClientSocket;
struct ServerSocket : public Timer
{
public:
	ServerSocket(int _port);
	~ServerSocket();
	std::shared_ptr<ClientSocket> accept();
private:
	void on_tick() override;
	SOCKET m_socket;
	std::vector<std::shared_ptr<ClientSocket>> m_clients;
	ServerSocket(const ServerSocket& _copy);
	ServerSocket& operator=(const ServerSocket& _assign);
};