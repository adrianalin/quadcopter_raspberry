/*
 * PIDComputer.cpp
 *
 *  Created on: Nov 30, 2014
 *      Author: adrian
 */

#include "PIDComputer.h"
#include "dmp.h"
#include "servo.h"

extern Servo ESC;

#define PID_STAB

PIDComputer::PIDComputer(DMP* imu) :
	m_imu(imu)
{
	// TODO Auto-generated constructor stub

}

PIDComputer::~PIDComputer() {
	// TODO Auto-generated destructor stub
}

void PIDComputer::initialize()
{
	//initilization of PID constants
	yprRATE[YAW].set_Kpid(3.5,0.1,0.1);
	yprRATE[PITCH].set_Kpid(1.2, 0.02, 0.05);
	yprRATE[ROLL].set_Kpid(1.2, 0.02, 0.05);

	yprSTAB[PITCH].set_Kpid(1.9, 0.12, 0.012);
	yprSTAB[ROLL].set_Kpid(1.9, 0.12, 0.012);
}

void PIDComputer::compute()
{
	//1- get attitude of the drone
	m_imu->getAttitude();

	// printf("ATTITUDE: %7.2f %7.2f %7.2f\n",imu.ypr[YAW],
	// 	 imu.ypr[PITCH],
	// 	 imu.ypr[ROLL]);

#ifdef PID_STAB
	//Stabilization is only done on Pitch and Roll
	//Yaw is Rate PID only
	for (int i=1; i<DIM; i++) {
		m_PIDout[i] = yprSTAB[i].update_pid_std(ypr_setpoint[i], m_imu->ypr[i]);
	}
	m_PIDout[0] = ypr_setpoint[0];

	// printf("PITCH: %7.2f %7.2f %7.2f\n",Timer.ypr_setpoint[PITCH],
	// 	 imu.ypr[PITCH],
	// 	 Timer.PIDout[PITCH]);

	// printf("ROLL: %7.2f %7.2f %7.2f\n",Timer.ypr_setpoint[ROLL],
	// 	 imu.ypr[ROLL],
	// 	 Timer.PIDout[ROLL]);

	for (int i = 0; i < DIM; i++) {
		m_PIDout[i] = yprRATE[i].update_pid_std(m_PIDout[i], m_imu->gyro[i]);
	}

	// printf("YAW: %7.2f %7.2f %7.2f\n",Timer.ypr_setpoint[YAW],
	// 	 imu.gyro[YAW],
	// 	 Timer.PIDout[YAW]);


	// printf("PITCH: %7.2f %7.2f %7.2f\n",Timer.ypr_setpoint[PITCH],
	// 	 imu.gyro[PITCH],
	// 	 Timer.PIDout[PITCH]);

	// printf("ROLL:  %7.2f %7.2f %7.2f\n",Timer.ypr_setpoint[ROLL],
	// 	 imu.gyro[ROLL],
	// 	 Timer.PIDout[ROLL]);
#endif

	//4-2 Calculate PID on rotational rate
#ifdef PID_RATE
	for (int i=0;i<DIM;i++){
		Timer.m_PIDout[i] =
				yprRATE[i].update_pid_std(Timer.ypr_setpoint[i],
						imu.gyro[i],
						Timer.dt);
	}
	//printf("%7.2f  %7.2f\n",imu.gyro[PITCH],Timer.PIDout[PITCH]);
#endif


	ESC.update(thr, m_PIDout);
	//printf("%7.2f  %7.2f\n",Timer.thr,Timer.PIDout[ROLL]);
}
