#include "ServiceBlock.h"

bool ServiceBlock::HasFreeUnit()
{
	ServiceUnit* unit = FindFreeUnit();
	if (unit != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ServiceBlock::AcceptCustomer(Customer* customer)
{
	ServiceUnit* unit = FindFreeUnit();
	if (unit != nullptr)
	{
		unit->TakeCustomer(customer);
	}
	
}

ServiceUnit* ServiceBlock::FindFreeUnit()
{
	for each (ServiceUnit* unit in units)
	{
		if (unit->IsFree())
		{
			return unit;
		}
		else
		{
			return nullptr;
		}
	}
}

double ServiceBlock::GetNextEventTime()
{
	double minTime = double::MaxValue;
	if (!HasFreeUnit())
	{
		for each (ServiceUnit * unit in units)
		{
			if (unit->GetServiceTime() < minTime)
			{
				minTime = unit->GetServiceTime();
			}
		}
	}
	unitNextEventTime = minTime;
	return unitNextEventTime;
}

ServiceBlock::ServiceBlock()
{
	for (int i = 0; i < 5; i++)
	{
		units[i] = new ServiceUnit();
	}
}

void ServiceBlock::DeleteCustomer()
{
	for (int i = 0; i < 5; i++)
	{
		if (!units[i]->IsFree())
		{
			units[i]->DeleteCustomer();
			return;
		}
	}
}

ServiceBlock::~ServiceBlock()
{
	for (int i = 0; i < 5; i++)
	{
		delete units[i];
	}
}


