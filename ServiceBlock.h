#pragma once
#include "Agent.h"
#include "ServiceUnit.h"
#include "Customer.h"
class ServiceBlock : public Agent
{
private: ServiceUnit* units[5];
private: double unitNextEventTime;
public: bool HasFreeUnit();
public: void AcceptCustomer(Customer* customer);
public: ServiceUnit* FindFreeUnit();
public: double GetNextEventTime();
public: ServiceBlock();
public: void DeleteCustomer();
public: ~ServiceBlock();
};

