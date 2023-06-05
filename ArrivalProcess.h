#pragma once
#include "Agent.h"
#include "System.h"
class ArrivalProcess : public Agent
{
private: double nextArrivalTime = 0;
private: double lambda = -0.5;
private: MySystem* system;
public:ArrivalProcess(MySystem* system);
public: double GetNextEventTime();
public: double SimulateInterarrivalTime();
public: void ExecuteEvent();
};

