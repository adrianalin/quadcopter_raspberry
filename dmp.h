#ifndef DMP_H
#define DMP_H

#define YAW 0
#define PITCH 1
#define ROLL 2
#define DIM 3

class DMP {
public:
	DMP();
	void getAttitude();
	void set_com();
	void initialize();
	bool initialized;
	float ypr[3];
	float gyro[3];

private:
	bool dmpReady;         // set true if DMP init was successful
	float lastval[3];
	float m_ypr_off[3];    //dmp offsets
};

#endif
