#include "ServiceUnit.h"
#include "Model.h"

bool ServiceUnit::IsFree()
{

	if (customerOnService == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ServiceUnit::TakeCustomer(Customer* customer)
{
	if (IsFree())
	{
		customerOnService = customer;
		serviceTime = Model::GetT() + SimulateServiceTime();
	}
	
}

double ServiceUnit::SimulateServiceTime()
{
	//generate random variable with exp distribution
	return log(double(rand()) / RAND_MAX) / lambda;
}

double ServiceUnit::GetServiceTime()
{
	return serviceTime;
}

void ServiceUnit::DeleteCustomer()
{
	delete customerOnService;
	customerOnService = nullptr;
}
