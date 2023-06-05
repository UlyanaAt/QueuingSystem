#include "System.h"
#include "ServiceBlock.h"
#include "Model.h"

void MySystem::TakeCustomer(Customer* customer)
{
	if (service->HasFreeUnit())
	{
		service->AcceptCustomer(customer);
	}
	else
	{
		queue->AddCustomer(customer);
	}
}

MySystem::MySystem()
{
	service = new ServiceBlock();
	queue = new Queue();
}

double MySystem::GetNextEventTime()
{
	return service->GetNextEventTime();
}

void MySystem::ExecuteEvent()
{
	Model::eventKind = 1;
	if (!queue->isEmpty())
	{
		service->AcceptCustomer(queue->GetNextCustomer());
		queue->RemoveCustomer();
	}
	service->DeleteCustomer();
}

MySystem::~MySystem()
{
	delete service;
	delete queue;
}


