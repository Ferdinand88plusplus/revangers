#include "WDisp.h"
#include "runtime.h"
#include "particle/df.h"

TripDispatcher TripD;
RainDispatcher RainD;

#define DROP_SIZE 20
#define DropFallSpeed -1
#define DropRenderQuality 8
#define DropRenderLength 2

extern uchar *FireColorTable;

uchar *DropColorTable = 0;

bool WeatherInited = 0;

void InitWeather()
{
	WeatherInited = 1;

	DropColorTable = new uchar[256 << 8];

	memcpy(DropColorTable, FireColorTable, 256 << 8);
	/*
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < 256; j++) {
			DropColorTable[i + j] = FireColorTable[i+j];
		}
	}*/
}

void ResetWeather() {
	if (!WeatherInited)
		InitWeather();

	TripD.Reset();
	RainD.Reset();
	
	TripD.UpdateTimers();

}

void TickWeather() {
	TripD.Tick();
	RainD.Tick();
}

void RainDrop::Tick()
{
	
	if (!LifeTime--)
		Destroyed = 1;

	Vector DropBeg = Pos;
	Vector DropEnd = Pos + Vel;
	
	DropBeg.z += 64;
	DropEnd.z += 64;

	ScreenLineTrace(DropBeg, DropEnd, DropColorTable, 0);

	Pos += Vel;
}

void RainDispatcher::Tick() 
{
	if (!RainEffect)
		return;
	RainTime++;
	if (RainPower < RainMax)
		RainPower += RainDelta;

	RainDrop *drop = 0;

	for (int i = 0; i < drops.size(); i++) {
		drop = drops[i];
		drop->Tick();
		if (drop->Destroyed) {
			drops.erase(drops.begin() + i);
			delete drop;
			i--;
		}
	}

	//if (RND(RainMax * 2 - RainPower))
	//	return;

	drop = new RainDrop;
	Vector dropPos;
	Vector dropTail;
	int delta =256;

	dropPos.z = GenerateCenter.z + DROP_SIZE;
	dropPos.x = (GenerateCenter.x - delta) + RND(delta*2);
	dropPos.y = (GenerateCenter.y - delta) + RND(delta*2);

	dropTail = dropPos;
	dropTail.z -= DROP_SIZE;

	drop->Pos = dropPos;
	drop->Vel = Vector(-10, 0, 0 );
	drop->LifeTime = 50;
	drops.push_back(drop);


}

void TripDispatcher::UpdateTimers()
{
	RealTripCD = 75 * GAME_TIME_COEFF;
	TripStartCD = 50 * GAME_TIME_COEFF;
}

void TripDispatcher::Tick()
{
	if (!TripEffect)
		return;
	TripTime++;
	TripSin = 1 + sin(TripTime / GAME_TIME_COEFF);
}
