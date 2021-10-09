#include<iostream>
#include<string>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include"nurseFunctions.hpp"

using namespace std;

struct history
{
	int PID,Age;
	string FirstName, LastName, Gender, Phone, Address, SicknessDescription, VisitDate, VisitTime, DoctorName, MedicineInformation;
	string DisabilityOption; 
	history *next;
};
extern history *historyHead;
extern history *historyTemp;
extern history *lastHistoryNode;

/******************************************************************************/
/* Developer Name: Loke Weng Khay                                             */
/* Doctor automatic functions: To display menu and add data into waiting list */
/******************************************************************************/
void doctorMenu();

