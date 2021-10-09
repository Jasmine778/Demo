#include<iostream>
#include"doctorFunctions.hpp"

int main(int argc, char *argv[]) 
{
	autoAddData();

	//Login Function Here
	cout<<"Welcome\n";
	nurseMenu();
	nurseMenu();
	while(true)
	{
		doctorMenu();
	}
	return 0;
}

