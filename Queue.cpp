#include "Queue.h"

void Queue::AddCustomer(Customer* customer)
{
	customers.push(customer);
}

bool Queue::isEmpty()
{
	if (customers.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

Customer* Queue::GetNextCustomer()
{
	return customers.front();
}

void Queue::RemoveCustomer()
{
	customers.pop();
}
