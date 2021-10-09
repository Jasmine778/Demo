#include"doctorFunctions.hpp"

void doctorMenu()
{
	int selection;
	bool input = false;
	cout<<"\n**********************************\n*           Doctor Menu          *\n**********************************\n";
	cout<<"1. View all patients on the original waiting list\n";
	cout<<"2. Search Specific Patient from the patient's visit history and modify patient records\n";
	cout<<"3. Sort and display all records from the patient's visit history list in descending order\n";
	cout<<"4. Search patients from the patient's visit history list based on sickness description or first name\n";
	cout<<"5. Logout\nYour Selection: ";
	while(input!=true)
	{
		cin>>selection;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout<<"Invalid input entered\nEnter Again\n";
		}
		else if(selection<=0 && selection>=8)
		{
			cout<<"Invalid input entered\nEnter Again\n";
		}
		else if(selection>0 && selection<8)
		{
			input=true;
		}
	}
	if(selection==1)
	{
		waitingTemp=waitingHead;
		cout<<"\n\n**********************************\n*   All Waiting Patient Details  *\n**********************************\n";
		displayAll(waitingTemp);
		/*
		//To check the transfering of data
		historyTemp=historyHead;
		while(historyTemp!=NULL)
		{
			cout<<"\n\n**********************************\n*    History Patient Details    *\n**********************************\n";
			cout <<"ID: "<<historyTemp->PID<< endl;
			cout <<"Name: "<< historyTemp->FirstName<<" "<<historyTemp->LastName<<endl;
			cout <<"Age: "<<historyTemp->Age<<endl;
			cout <<"Gender: "<< historyTemp->Gender<<endl;
			cout <<"Phone Number: "<< historyTemp->Phone<<endl;
			cout <<"Address: "<< historyTemp->Address<<endl;
			cout <<"Sickness Description: "<< historyTemp->SicknessDescription<<endl;
			cout <<"Visit Date: "<< historyTemp->VisitDate<<endl;
			cout <<"Visit Time: "<< historyTemp->VisitTime<<endl;
			cout <<"Disability Option: "<< historyTemp->DisabilityOption<<endl;
			cout <<"Doctor Name: "<< historyTemp->DoctorName<<endl;
			cout <<"Medicine Information: "<<historyTemp->MedicineInformation<<endl<<endl;
			historyTemp=historyTemp->next;
		}*/
	}
	system("pause");
	system("cls");
}
