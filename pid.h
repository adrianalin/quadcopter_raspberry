#ifndef pid
#define pid

#include <iostream>
#include <stdlib.h>
#include <fstream>

class PID {

public:
	PID();
	PID(float,float,float);
	float update_pid_std(float setpt, float input);
	void  set_Kpid(float, float, float);
	void  set_windup_bounds(float, float);
	void  reset();

private:
	void initLimits();

	//PID constants
	float m_Kp;
	float m_Ki;
	float m_Kd;

	//PID constants
	float m_ITerm;
	float m_err;
	float m_lastInput;
	float m_outmax;
	float m_outmin;
	float m_output;
};

#endif
