#include "ArrivalProcess.h"
#include "MyForm.h"
#include "Customer.h"
#include <string>
#include "Model.h"

ArrivalProcess::ArrivalProcess(MySystem* system)
{
	this->system = system;
	nextArrivalTime = SimulateInterarrivalTime();
}

double ArrivalProcess::SimulateInterarrivalTime()
{
	//generate random variable with exp distribution
	double t = log(double(rand()) / RAND_MAX) / lambda;
	return t;
}

void ArrivalProcess::ExecuteEvent()
{
	Model::eventKind = 0;
	Customer* customer = new Customer();
	system->TakeCustomer(customer);
	nextArrivalTime += SimulateInterarrivalTime();
}

double ArrivalProcess::GetNextEventTime()
{
	return nextArrivalTime;
}
