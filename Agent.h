#pragma once
class Agent
{
public: virtual double GetNextEventTime();
	  virtual void ExecuteEvent();
};

