#ifndef PARSER_H
#define PARSER_H

#include <sstream>
#include <stdlib.h>

class Parser
{
public:
	Parser();
	~Parser();
	void parse(unsigned char data[],float &,float []);
	void parse(unsigned char data[],float &t,float &y,float &p);
};

#endif
