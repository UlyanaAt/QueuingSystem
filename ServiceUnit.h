#pragma once
#include "Agent.h"
#include "Customer.h"
class ServiceUnit : public Agent
{
private: Customer* customerOnService = nullptr;
private: double serviceTime = double::MaxValue;
private: double lambda = 2;
public: bool IsFree();
public: void TakeCustomer(Customer* customer);
public: double SimulateServiceTime();
public: double GetServiceTime();
public: void DeleteCustomer();
};

