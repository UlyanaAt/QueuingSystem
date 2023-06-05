#pragma once
#include "Agent.h"
#include "Customer.h"
#include "Queue.h"
#include "ServiceBlock.h"
class MySystem : public Agent
{
private: ServiceBlock* service;
private: Queue* queue;
public: void TakeCustomer(Customer* customer);
public: MySystem();
public: double GetNextEventTime();
public: void ExecuteEvent();
public: ~MySystem();
};

