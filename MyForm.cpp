#include "MyForm.h"
#include <time.h>
#include <cmath>
#include "System.h"
#include "ArrivalProcess.h"
#include "Model.h"
using namespace std;
using namespace QueuingSystem;
using namespace System::Windows::Forms;

// Application entry point
[STAThreadAttribute]
void main(cli::array<String^>^ args) {
	// Initial Application Parameters:
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	QueuingSystem::MyForm form;
	Application::Run(% form);
	srand(time(NULL));
}

System::Void QueuingSystem::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	Model::FillAgents(arr, system);

	NumOfClick += 1;

	if (NumOfClick % 2 == 0)
	{
		timer1->Stop();
	}
	else
	{
		this->chart1->Series[0]->Points->Clear();
		this->chart1->Series[1]->Points->Clear();
		timer1->Start();
	}
	
}

System::Void QueuingSystem::MyForm::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	Model::Run();

	if (Model::eventKind == 0)
	{
		this->chart1->Series[0]->Points->AddXY(Model::T, 1);
	}
	else
	{
		this->chart1->Series[1]->Points->AddXY(Model::T, 0.8);
	}
}

System::Void QueuingSystem::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	system = new MySystem();
	arr = new ArrivalProcess(system);
}

System::Void QueuingSystem::MyForm::MyForm_Closing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	delete system;
	delete arr;
	return System::Void();
}
	
