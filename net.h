#ifndef NET_H
#define NET_H

#include <netinet/in.h>

#include "net.h"
#include "servo.h"
#include "pid.h"
#include "dmp.h"
#include "parser.h"

class PIDComputer;

class Net
{
public:
	Net(PIDComputer* pidComp, DMP* imu);
	~Net();
	void set_port(int port);
	void create();
	void closeConnection();
	void exec_remoteCMD();

private:
	int get_cmd(float& ,float& ,float& ,float&);
	int get_cmd();

	PIDComputer* m_pidComp;
	DMP* m_imu;
	Parser m_parser;
	sockaddr_in m_address;
	unsigned short m_port;
	int m_socket;
	unsigned char m_data[256];
	unsigned char m_lastData[256];
};

#endif
