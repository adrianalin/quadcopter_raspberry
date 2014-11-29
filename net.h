#ifndef SOCKET_H
#define SOCKET_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


#include "net.h"
#include "servo.h"
#include "pid.h"
#include "dmp.h"
#include "parser.h"
#include "custom_timer.h"


class Socket
{
public:
	Socket();
	~Socket();

	void set_port(int port);
	void create();
	void Close();
	void exec_remoteCMD();
	unsigned char m_data[256];

private:
	sockaddr_in m_address;
	unsigned short m_port;
	int m_socket;
	unsigned char m_lastdata[256];
	int get_cmd(float& ,float& ,float& ,float&);
	int get_cmd();
};

extern Socket remote;

#endif
