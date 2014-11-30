#ifndef SERVOS
#define SERVOS

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SERVO_MIN 1000
#define YAW 0
#define PITCH 1
#define ROLL 2
#define DIM 3

class Servo {

public:
	Servo();
	void openBlaster();
	void close_blaster();
	bool Is_open_blaster();
	void initialize();
	bool isInitialized();
	void update(float, float []);
	void stopServo();
	void setServo();
	int servoval[4];

private:
	bool m_initialized;
	int m_servoId[4];
	FILE* fid_servo;
};

extern Servo ESC;

#endif
