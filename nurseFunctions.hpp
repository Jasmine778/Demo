#include<iostream>
#include<string>
#include<cstring>
#include<ctime>
#include <cstdlib>


using namespace std;

struct patient
{
	int PID,Age;
	string FirstName, LastName, Gender, Phone, Address, SicknessDescription, VisitDate, VisitTime, DoctorName, MedicineInformation;
	string DisabilityOption; 
	patient *next;
};
extern patient *waitingHead;
extern patient *waitingTemp;
//extern patient *historyHead;
//extern patient *historyTemp;
extern patient *lastWaitingNode;

/*****************************************************************************/
/* Developer Name: Loke Weng Khay                                            */
/* Nurse automatic functions: To display menu and add data into waiting list */
/*****************************************************************************/
void nurseMenu();
void autoAddData();

/************************************************************************/
/* Developer Name: Loke Weng Khay                                       */
/* Nurse Function 1.1: add new patient                                  */
/************************************************************************/
void addPatient();
string convertToString(char*,int);
void insertPatientIntoList(string,string,int,string,string,string,string,string,string,string);

/************************************************************************/
/* Developer Name: Loke Weng Khay                                       */
/* Nurse Function 1.2: Modify patient priority status    		        */
/************************************************************************/
void changePatientStatus();
void priorityPatient(string,string,int,string,string,string,string,string,string,string);
void searchPatient();
void searchById(int);
patient* copyList(struct patient* head);
struct patient* swap(struct patient* ptr1, struct patient* ptr2);
int bubbleSort(struct patient** head, int count);
struct patient* mid_node(patient* start, patient* last);
struct patient* binarySearch(patient *head, int value);
void searchByName(string,string);
void checkChangesPriority();

/***********************************************************/
/* Developer Name: Loke Weng Khay              	           */
/* Nurse Function 1.3: Display all patient 	     	       */
/***********************************************************/
void displayAll(patient *current);

/******************************************************************/
/* Developer Name: Loke Weng Khay              	                  */
/* Nurse Function 1.4: Call the patient in the queue              */
/******************************************************************/
void callPatient();
void storeToHistory();


