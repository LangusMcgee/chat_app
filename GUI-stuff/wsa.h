#pragma once
#include <winsock2.h>

struct Wsa
{
	Wsa();
	~Wsa();

private:
	WSADATA m_wsadata;
	Wsa(const Wsa& _copy);
	Wsa& operator=(const Wsa& _assign);
};