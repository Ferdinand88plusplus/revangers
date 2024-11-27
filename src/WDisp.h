#ifndef _TRIP_ROUTER_H_
#define _TRIP_ROUTER_H_

#include "global.h"
#include "3d/3d_math.h"
#include "3d/3dobject.h"
#include "units/hobj.h"
#include "terra/vmap.h"
#include <vector>

#define START_RAIN_VAL	0
#define START_TRIP_VAL	0


struct TripDispatcher {
	bool TripEffect = START_TRIP_VAL;
	size_t TripTime = 0;
	size_t RealTripCD;
	size_t TripStartCD;
	float TripSin = 0;

	// if fps is changing 20 <-> 60
	void UpdateTimers();
	void Tick();

	void Reset() {
		TripEffect = START_TRIP_VAL;
		TripTime = 0;
		TripSin = 0;
	}
};



struct RainDrop {
	Vector Pos;
	Vector Vel;
	bool Destroyed = 0;
	int LifeTime;

	void Tick();

};

struct RainDispatcher {
	bool RainEffect = START_RAIN_VAL;
	int RainDelta = 1;
	int RainMax = 100;
	int RainPower = 0;
	Vector GenerateCenter;

	std::vector<RainDrop *> drops;

	size_t RainTime = 0;


	void Tick();

	void Reset() {
		RainEffect = START_RAIN_VAL;
		RainPower = 0;
	}
};

extern TripDispatcher TripD;
extern RainDispatcher RainD;

void ResetWeather();
void TickWeather();

#endif