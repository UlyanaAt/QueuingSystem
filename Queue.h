#pragma once
#include "Agent.h"
#include <queue>
#include "Customer.h"
using namespace std;
class Queue : public Agent
{
private: queue <Customer*> customers;
public: void AddCustomer(Customer* customer);
	  bool isEmpty();
	  Customer* GetNextCustomer();
	  void RemoveCustomer();

};

