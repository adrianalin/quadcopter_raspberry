#ifndef NET_H
#define NET_H

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


class Net
{
public:
	Net();
	~Net();
	void set_port(int port);
	void create();
	void closeConnection();
	void exec_remoteCMD();

private:
	Parser m_parser;
	sockaddr_in m_address;
	unsigned short m_port;
	int m_socket;
	unsigned char m_data[256];
	unsigned char m_lastData[256];
	int get_cmd(float& ,float& ,float& ,float&);
	int get_cmd();
};

extern Net remote;

#endif
