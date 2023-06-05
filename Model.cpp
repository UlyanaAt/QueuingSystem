#include "Model.h"

double::Model::T = 0;
Agent*::Model::activeAgent = nullptr;
Agent*::Model::agents[2] = { nullptr, nullptr };
bool::Model::eventKind = 0; // 0 - arrival, 1 - departure

void Model::Run()
{
		double tmin = double::MaxValue;
		activeAgent = nullptr;
		for each (Agent* a in agents)
		{
			double ta = a->GetNextEventTime();
			if (ta < tmin)
			{
				tmin = ta;
				activeAgent = a;
			}
		}

		T = tmin;
		if (activeAgent != nullptr)
		{
			activeAgent->ExecuteEvent();
		}
	
}

bool Model::StopCond(double T, Agent* activeAgent)
{
	if (T > 100 || activeAgent == nullptr)
	{
		return true;
	}
}

double Model::GetT()
{
	return T;
}

void Model::FillAgents(Agent* a, Agent* b)
{
	agents[0] = a;
	agents[1] = b;
}


