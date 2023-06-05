#pragma once
#include "Agent.h"
#include <list>
using namespace std;
class Model
{
public: static double T;
public: static bool eventKind;
public: static Agent* activeAgent;
public: static Agent* agents[2];
public: static void Run();
public: static bool StopCond(double T, Agent* activeAgent);
public: static double GetT();
public: static void FillAgents(Agent* a, Agent* b);
};

