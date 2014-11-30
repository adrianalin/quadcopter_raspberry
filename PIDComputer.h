/*
 * PIDComputer.h
 *
 *  Created on: Nov 30, 2014
 *      Author: adrian
 */

#ifndef PIDCOMPUTER_H_
#define PIDCOMPUTER_H_

#include "pid.h"

class DMP;

class PIDComputer {
public:
	PIDComputer(DMP* imu);
	~PIDComputer();
	void initialize();
	void compute();
	PID yprSTAB[3];
	PID yprRATE[3];
	float thr;
	float ypr_setpoint[3]; 	// received from mobile app - thrust, yaw,pitch, roll

private:
	DMP* m_imu;
	float m_PIDout[3];
};

#endif /* PIDCOMPUTER_H_ */
