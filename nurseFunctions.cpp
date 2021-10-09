#include"nurseFunctions.hpp"
int globalCount=1;
patient *waitingHead;
patient *waitingTemp;
patient *lastWaitingNode;
patient *historyHead;
patient *historyTemp;

/**********************************************/
/* Developer Name: Loke Weng Khay             */
/* Function: To display Nurse menu opotions   */
/**********************************************/
void nurseMenu()
{
	int selection;
	bool input = false;
	cout<<"\n**********************************\n*           Nurse Menu           *\n**********************************\n";
	cout<<"1. Add new patient on the waiting list\n";
	cout<<"2. Change the patient order according to the priority on the waiting list\n";
	cout<<"3. View all patients on the original waiting list\n";
	cout<<"4. Calling the patient to be treated\n";
	cout<<"5. Search patient from the waiting list based on Patient ID or First Name\n";
	cout<<"6. Sort the waiting list by patient's current visit time\n";
	cout<<"7. Logout\nYour selection: ";
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
		addPatient();
	}
	else if(selection==2)
	{
		changePatientStatus();
	}
	else if(selection==3)
	{
		waitingTemp=waitingHead;
		cout<<"\n\n**********************************\n*All Waiting Patient Details*\n**********************************\n";
		displayAll(waitingTemp);
		
	}
	else if(selection==4)
	{
		callPatient();
	}
	system("pause");
	system("cls");
}
/**********************************************/
/* Developer Name: Loke Weng Khay             */
/* Function: To automatically hard code data  */
/**********************************************/
void autoAddData()
{
	string fName[]= {"Atlanta","Toby","Dafydd","Elyas","Elias","Sohaib","Lilly-Grace","Freddie","Abbas","Montana"};
	string lName[]= {"John","Handley","Archer","Atkins","Clay","Pham","Werner","Head","Moreno","Arroyo"};
	int Age[]={24,34,56,12,34,54,76,34,75,23};
	string Gender[]={"Male","Male","Female","Female","Female","Male","Female","Male","Male","Female"};
	string pNum[]={"015-371-1793","012-224-0752","018-659-9312","015-696-8387","010-777-7327","019-622-0126","013-521-1895","014-455-9844","017-287-3053","016-833-1355"};
	string address[]={"1465 Bernardo Street, Tampa, 33607, Florida","613 Spring Avenue, Warminster,	18974, Pennsylvania","2565 Bel Meadow Drive, PORTLAND, 65067, Missouri","2893 Prudence Street, 	Detroit, 48219, Michigan",
	"4433 Dancing Dove Lane, CHAUTAUQUA, 67334, Kansas","4841 Lakeland Terrace, Southfield, 48034, Michigan","1044 Crestview Manor, Indianapolis, 46241, Indiana","1962 Filbert Street, Philadelphia, 19103, Pennsylvania",
	"2881 Cottrill Lane, Saint Louis, 63109, Missouri","3749 Pooz Street, GREENSBORO, 27415, North Carolina"};
	string sickdesc[]={"Heart Attack","Stroke","Common Cold","Fever","Cough","Diabetes Mellitus","AIDS","Broken Bone","Seizures","Elastic Inflammation"};
	string Date[]={"10/04/2022","22/02/2022","28/03/2022","13/07/2022","07/03/2022","14/04/2022","14/06/2022","05/11/2021","15/03/2022","22/04/2022"};
	string Time[]={"15:10","07:15","11:21","22:26","15:11","09:25","16:48","05:03","05:51","00:20"};
	string dis[]={"Yes","Yes","No","No","No","No","No","No","No","No"};
	

	int count=0;
	while(count<10)
	{
		insertPatientIntoList(fName[count],lName[count],Age[count],Gender[count],pNum[count],address[count],sickdesc[count],Date[count],Time[count],dis[count]);
		count++;
	}
}
/************************************************************************/
/* Developer Name: Loke Weng Khay                                       */
/* Nurse Function 1.1: add new patient                                  */
/* Function: To get user information to be added into the waiting list  */
/************************************************************************/
void addPatient()
{
	cout<<"\n\n**********************************\n*       Add New Patient         *\n**********************************";
	// get current date/time 
   	time_t now = time(0);
   
  	tm *ltm = localtime(&now);
  	
	patient* list;
	string fname1, lname1,gender1,pnum1,add1,sickdesc1,disabled1;
	char date1[15],time1[6];
	string no,street,city,state;
	int age1;
	
	cin.ignore();
	cout<<"\nEnter First Name:\n";
	getline(cin,fname1);
	cout<<"Enter Last Name:\n";
	getline(cin,lname1);
	cout<<"Age: "<<endl;
	bool vrf1=false,vrf2=false,vrf3=false;
	while(vrf1!=true)
	{
		cin>>age1;
		if(age1>0 && age1<122)
		{
			vrf1=true;
		}
		else if(cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout<<"Please Enter Appropriate Age:\n";
		}
		else
		{
			cout<<"Please Enter Appropriate Age:\n";
		}
	}
	cout <<"Gender: "<<endl;
	cin.ignore();
	while(vrf2!=true)
	{
		getline(cin,gender1);
		if(strcasecmp(gender1.c_str(),"male")==0)
		{
			vrf2=true;
			gender1="Male";
		}
		else if(strcasecmp(gender1.c_str(),"female")==0)
		{
			vrf2=true;
			gender1="Female";
		}
		else
		{
			cout<<"Please Enter Appropriate Gender:\n";
		}
	}
	cout <<"Phone Number: "<<endl;
	getline(cin,pnum1);
	cout <<"Address No:\nNo. ";
	getline(cin,no);
	cout<<"Street:\n";
	getline(cin,street);
	cout<<"City:\n";
	getline(cin,city);
	cout<<"State:\n";
	getline(cin,state);
	add1="No. " + no + ", " + street + ", " + city + ", " + state;
	cout <<"Sickness Description: "<<endl;
	getline(cin,sickdesc1);
	strftime(date1,12,"%d/%m/%Y",ltm);
	strftime(time1,6,"%H:%M",ltm);
	cout <<"Disability Option: "<<endl;
	while(vrf3!=true)
	{
		getline(cin,disabled1);
		if(strcasecmp(disabled1.c_str(),"yes")==0)
		{
			vrf3=true;
			disabled1="Yes";
		}
		else if(strcasecmp(disabled1.c_str(),"no")==0)
		{
			vrf3=true;
			disabled1="No";
		}
		else
		{
			cout<<"Please Enter Appropriate Response:\n";
		}
	}
	int date_size = sizeof(date1) / sizeof(char);
    int time_size = sizeof(time1) / sizeof(char);
  
    string date2 = convertToString(date1, date_size);
    string time2 = convertToString(time1, time_size);
	if(disabled1=="No")
  	{
  		//MUST CHANGE ON FINAL DATE
  		insertPatientIntoList(fname1,lname1,age1,gender1,pnum1,add1,sickdesc1,date2,time2,disabled1);
	}
	else if(disabled1=="Yes")
	{
		priorityPatient(fname1,lname1,age1,gender1,pnum1,add1,sickdesc1,date2,time2,disabled1);
	}
}
/******************************************/
/* Developer Name: Loke Weng Khay         */
/* Function: To convert time into string  */
/******************************************/
string convertToString(char* arr, int size)
{
    string s = "";
    for (int a=0; a<size;a++) 
	{
        s = s + arr[a];
    }
    return s;
}
/***********************************************/
/* Developer Name: Loke Weng Khay              */
/* Function: To add patient into waiitng list  */
/***********************************************/
//MUST CHANGE ON FINAL DATE
void insertPatientIntoList(string fname,string lname,int age,string gender,string pnumber,string add,string sickdesc,string date,string time,string disabled) 
{
	//step 1: create a new node
	patient* newnode = new patient;
	
	//step 2: assign value to the newnode
	newnode->PID=globalCount;
	globalCount++;
	newnode->FirstName=fname;
	newnode->LastName=lname;
	newnode->Age=age;
	newnode->Gender=gender;
	newnode->Phone=pnumber;
	newnode->Address=add;
	newnode->SicknessDescription=sickdesc;
	newnode->VisitDate=date;
	newnode->VisitTime=time;
	newnode->DisabilityOption=disabled;
	newnode->DoctorName="NULL";
	newnode->MedicineInformation="NULL";
	newnode->next = NULL;
	
	if (waitingHead == NULL) 
	{
		waitingHead = newnode;
		lastWaitingNode=newnode;
	}
	else
	{
		//waitingTemp = waitingHead;
		//search the last item in the list
		/**while (waitingTemp->next != NULL)
		{
			waitingTemp = waitingTemp->next;
		}
		waitingTemp->next = newnode;**/
		lastWaitingNode->next=newnode;
		lastWaitingNode=lastWaitingNode->next;
	}
}
/************************************************************************/
/* Developer Name: Loke Weng Khay                                       */
/* Nurse Function 1.2: Modify patient priority status    		        */
/* Function: To change high risk patient in fornt of the waiitng list   */
/************************************************************************/
void changePatientStatus()
{
	int num;
	bool vrf4=false;
	cout<<"\n\n**********************************\n*     Modify Patient Priority    *\n**********************************\n";
	cout<<"Modify by:\n1. Adding new patient record\n2. Modify existing patient record\nYour Selection: ";
	
	while(vrf4!=true)
	{
		cin>>num;
		if(num==1)
		{
			vrf4=true;;
			addPatient();
		}
		else if(num==2)
		{
			vrf4=true;
			searchPatient();
		}
		else if(cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout<<"Please Enter Appropriate Response:\n";
		}
		else
		{
			cout<<"Please Enter Appropriate Response:\n";
		}
	}
}
/************************************************************************/
/* Developer Name: Loke Weng Khay                                       */
/* Function: Add high risk patient in front of the queue                */
/************************************************************************/
void priorityPatient(string fname,string lname,int age,string gender,string pnumber,string add,string sickdesc,string date,string time,string disabled) 
{
	//step 1: create a new node
	patient* newnode = new patient;
	patient* tempNode = new patient;
	
	//step 2: assign value to the newnode
	newnode->PID=globalCount;
	globalCount++;
	newnode->FirstName=fname;
	newnode->LastName=lname;
	newnode->Age=age;
	newnode->Gender=gender;
	newnode->Phone=pnumber;
	newnode->Address=add;
	newnode->SicknessDescription=sickdesc;
	newnode->VisitDate=date;
	newnode->VisitTime=time;
	newnode->DisabilityOption=disabled;
	newnode->DoctorName="NULL";
	newnode->MedicineInformation="NULL";
	newnode->next = NULL;
	if (waitingHead == NULL) 
	{
		waitingHead = newnode;
	}
	else
	{
		waitingTemp = waitingHead;
		bool checkOthers=false;
		int location=0,count=0;
		while(checkOthers!=true)
		{	
			if(waitingTemp->DisabilityOption=="Yes")
			{
				location++;
			}
			if(waitingTemp->next!=NULL)
			{
				waitingTemp=waitingTemp->next;
				count++;
			}
			else if(waitingTemp->next==NULL)
			{
				checkOthers=true;
			}
		}
		tempNode=waitingHead;
		if(checkOthers==true)
		{
			int num=0;
			waitingTemp = waitingHead;
			while(num<count &&  waitingTemp!=NULL)
			{
				if(location==0)
				{
					newnode->next=waitingHead;
					waitingHead=newnode;
					break;
				}
				else if(num==location && location>0)
				{
					newnode->next=waitingTemp;
					tempNode->next=newnode;
				}
				if(num>0)
				{
					tempNode=tempNode->next;
				}
				waitingTemp=waitingTemp->next;
				num++;
			}
		}	
	}
}
/******************************************************************************/
/* Developer Name: Loke Weng Khay                                             */
/* Function: To search high risk patient to be put in front of waiitng list   */
/******************************************************************************/
void searchPatient()
{
	int num2;
	bool vrf5=false;
	cout<<"\n\n**********************************\n*         Search Methods         *\n**********************************\n";
	cout<<"Search patient using:\n1. ID number\n2. First and Last Name\nYour Selection: ";
	while(vrf5!=true)
	{
		cin>>num2;
		if(num2==1)	
		{
			int id;
			vrf5=true;
			cout<<"\n\n**********************************\n*      Search Patient by ID      *\n**********************************\n";
			cout<<"Enter ID number\n";
			cin>>id;
			searchById(id);
		}
		else if(num2==2)
		{
			string fName2,lName2;
			vrf5=true;
			cin.ignore();
			cout<<"\n\n**********************************\n*     Search Patient by name     *\n**********************************\n";
			cout<<"Enter Patient First Name\n";
			getline(cin,fName2);
			cout<<"Enter Patient Last Name\n";
			getline(cin,lName2);
			searchByName(fName2,lName2);
		}
		else if(cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout<<"Please Enter Appropriate Response:\n";
		}
		else
		{
			cout<<"Please Enter Appropriate Response:\n";
		}
	}
}
/*******************************************************/
/* Developer Name: Loke Weng Khay                      */
/* Function: To search high risk patient by Id number  */
/*******************************************************/
void searchById(int id)
{
	waitingTemp=waitingHead;
	patient *test = new patient;
	struct patient* sort=copyList(waitingTemp);
	int size=0;
	test=sort;
	while(sort!=NULL)
	{
		sort=sort->next;
		size++;
	}
	sort=test;
	bubbleSort(&sort,size);
	if (binarySearch(sort, id) == NULL)
	{
		cout<<"ID found\n";	
	}
   	else
   	{
   		cout<<"ID not found\n";
	}
	delete sort;
}
patient* copyList(patient* head)
{
    if (head == NULL) 
	{
        return NULL;
    }
    else 
	{
		patient *newnode= new patient;
        newnode->PID=head->PID;
		newnode->FirstName=head->FirstName;
		newnode->LastName=head->LastName;
		newnode->Age=head->Age;
		newnode->Gender=head->Gender;
		newnode->Phone=head->Phone;
		newnode->Address=head->Address;
		newnode->SicknessDescription=head->SicknessDescription;
		newnode->VisitDate=head->VisitDate;
		newnode->VisitTime=head->VisitTime;
		newnode->DisabilityOption=head->DisabilityOption;
		newnode->DoctorName=head->DoctorName;
		newnode->MedicineInformation=head->MedicineInformation;
 
        // recursively set the `.next` pointer of the new node by recurring
        // for the rest nodes
        newnode->next = copyList(head->next);
        return newnode;
    }
}
/*******************************************************/
/* Developer Name: Loke Weng Khay                      */
/* Function: To swap nodes                             */
/*******************************************************/
struct patient* swap(struct patient* ptr1, struct patient* ptr2)
{
    struct patient* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}
  
/****************************************************************/
/* Developer Name: Loke Weng Khay                               */
/* Function: To sort the waiting list according the PID number  */
/****************************************************************/
int bubbleSort(struct patient** head, int count)
{
    struct patient** h;
    int i, j, swapped;
  
    for (i = 0; i <= count; i++)
    {
  
        h = head;
        swapped = 0;
  
        for (j = 0; j < count - i - 1; j++) 
        {
  
            struct patient* p1 = *h;
            struct patient* p2 = p1->next;
  
            if (p1->PID > p2->PID)
            {
  
                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }
  
            h = &(*h)->next;
        }
  		
        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}
/******************************************************/
/* Developer Name: Loke Weng Khay                     */
/* Function: To find the middle node for bubble sort  */
/******************************************************/
struct patient* mid_node(patient* start, patient* last)
{
   	if (start == NULL)
   	{
   		return NULL;
	}
   	struct patient* slow = start;
   	struct patient* fast = start -> next;
   	while (fast != last)
	{
      	fast = fast -> next;
      	if (fast != last)
		{
         	slow = slow -> next;
         	fast = fast -> next;
      	}
   	}
  	return slow;
}
/******************************************************/
/* Developer Name: Loke Weng Khay                     */
/* Function: To find the patient usinf binary search  */
/******************************************************/
struct patient* binarySearch(patient *head, int value)
{
	struct patient* start = head;
	struct patient* last = NULL;
	bool IdFound=true;
	do
	{
	    patient* mid = mid_node(start, last);
	    if (mid == NULL)
	    {
	    	cout<<"ID not Found";
	    	return NULL;
		}
	    if (mid -> PID == value)
	    {
	    	IdFound=true;
	    	if(IdFound==true)
			{
				int num=0;
				string confirmation;
				cout<<"\n\n**********************************\n*        Patient Details         *\n**********************************\n";
				cout <<"ID: "<<mid->PID<< endl;
				cout <<"Name: "<< mid->FirstName<<" "<<mid->LastName<<endl;
				cout <<"Age: "<<mid->Age<<endl;
				cout <<"Gender: "<< mid->Gender<<endl;
				cout <<"Phone Number: "<< mid->Phone<<endl;
				cout <<"Address: "<< mid->Address<<endl;
				cout <<"Sickness Description: "<< mid->SicknessDescription<<endl;
				cout <<"Visit Date: "<< mid->VisitDate<<endl;
				cout <<"Visit Time: "<< mid->VisitTime<<endl;
				cout <<"Disability Option: "<< mid->DisabilityOption<<endl;
				cout <<"Doctor Name: "<< mid->DoctorName<<endl;
				cout <<"Medicine Information: "<<mid->MedicineInformation<<endl<<endl;
						
				cin.ignore();		
				cout<<"\n\n**********************************\n*          Confirmation          *\n**********************************\n";
				cout<<"Do you want to change the disability option for Mr/Mrs "<<mid->FirstName<<" "<<mid->LastName;
				if(mid->DisabilityOption=="No")
				{
					cout<<" from No to Yes?\n";
					getline(cin,confirmation);
					if(strcasecmp(confirmation.c_str(),"Yes")==0)
					{
						waitingTemp=waitingHead;
						mid->DisabilityOption="Yes";
						while(waitingTemp!=NULL)
						{
							if(waitingTemp->PID==mid->PID)
							{
								waitingTemp->DisabilityOption="Yes";
							}
							waitingTemp=waitingTemp->next;
						}
						checkChangesPriority();
					}
					else if(strcasecmp(confirmation.c_str(),"no")==0)
					{
						cout<<"No changes have been done";
					}
					else
					{
						cout<<"Please Enter Appropriate Response:\n";
					}
				}
						
				else if(mid->DisabilityOption=="Yes")
				{
					cout<<" from Yes to No?\n";
					getline(cin,confirmation);
					if(strcasecmp(confirmation.c_str(),"Yes")==0)
					{
						waitingTemp->DisabilityOption="No";
						waitingTemp=waitingHead;
						while(waitingTemp!=NULL)
						{
							if(waitingTemp->PID==mid->PID)
							{
								waitingTemp->DisabilityOption="No";
							}
							waitingTemp=waitingTemp->next;
						}
					}
					else if(strcasecmp(confirmation.c_str(),"no")==0)
					{
						cout<<"No changes have been done";
					}
				}	
			}
			break;
		}
		else if (mid -> PID < value)
		{
			start = mid -> next;
		}
	    else
	    {
	    	last = mid;
		}      
    }
    while (last == NULL || last != start || IdFound==true);
      	return NULL;	
}
/******************************************************/
/* Developer Name: Loke Weng Khay                     */
/* Function: To find the high risk patient by name    */
/******************************************************/
void searchByName(string firstName,string lastName)
{
	bool nameFound=false;
	waitingTemp=waitingHead;
	int count=0;
	
	while(nameFound!=true || waitingTemp!=NULL)
	{
		if(waitingTemp->FirstName==firstName)
		{
			if(waitingTemp->LastName==lastName)
			{
				nameFound=true;
			}
		}
		if(waitingTemp->next!=NULL && nameFound!=true)
		{
			waitingTemp = waitingTemp->next;
			count++;
		}
		else if(waitingTemp->next==NULL || nameFound==true )
		{
			break;
		}
	}
	if(nameFound==true)
	{
		int num=0;
		string confirmation;
		waitingTemp=waitingHead;
		patient *newnode = new patient;
		patient *tempNode = new patient;
		patient *tempNode2 = new patient;
		while(num<count || waitingTemp!=NULL)
		{
			if(num==count)
			{
				cout<<"\n\n**********************************\n*        Patient Details         *\n**********************************\n";
				cout <<"ID: "<<waitingTemp->PID<< endl;
				cout <<"Name: "<< waitingTemp->FirstName<<" "<<waitingTemp->LastName<<endl;
				cout <<"Age: "<<waitingTemp->Age<<endl;
				cout <<"Gender: "<< waitingTemp->Gender<<endl;
				cout <<"Phone Number: "<< waitingTemp->Phone<<endl;
				cout <<"Address: "<< waitingTemp->Address<<endl;
				cout <<"Sickness Description: "<< waitingTemp->SicknessDescription<<endl;
				cout <<"Visit Date: "<< waitingTemp->VisitDate<<endl;
				cout <<"Visit Time: "<< waitingTemp->VisitTime<<endl;
				cout <<"Disability Option: "<< waitingTemp->DisabilityOption<<endl;
				cout <<"Doctor Name: "<< waitingTemp->DoctorName<<endl;
				cout <<"Medicine Information: "<<waitingTemp->MedicineInformation<<endl<<endl;
				
				
				cout<<"\n\n**********************************\n*          Confirmation          *\n**********************************\n";
				cout<<"Do you want to change the disability option for Mr/Mrs "<<firstName<<" "<<lastName;
				if(waitingTemp->DisabilityOption=="No")
				{
					cout<<" from No to Yes? (Yes/No)\n";
					getline(cin,confirmation);
					if(strcasecmp(confirmation.c_str(),"Yes")==0)
					{
						waitingTemp->DisabilityOption="Yes";
						checkChangesPriority();
					}
					else if(strcasecmp(confirmation.c_str(),"no")==0)
					{
						cout<<"No changes have been done";
					}
					else
					{
						cout<<"Please Enter Appropriate Response:\n";
					}
				}
				else if(waitingTemp->DisabilityOption=="Yes")
				{
					cout<<" from Yes to No? (Yes/No)\n";
					getline(cin,confirmation);
					if(strcasecmp(confirmation.c_str(),"Yes")==0)
					{
						waitingTemp->DisabilityOption="No";
					}
					else if(strcasecmp(confirmation.c_str(),"no")==0)
					{
						cout<<"No changes have been done";
					}
				}
				break;	
			}
			else
			{
				waitingTemp = waitingTemp->next;
				++num;
			}
		}
	}
	else if(nameFound==false)
	{
		cout<<"Name not found\n";
	}
}
/***************************************************************************/
/* Developer Name: Loke Weng Khay                                          */
/* Function: To change the waiting list order for the high risk patient    */
/***************************************************************************/
void checkChangesPriority()
{

	bool found=false;
	patient *tempNode = new patient;
	patient *tempNode1 = new patient;
	patient *tempNode2 = new patient;
	int count10=0;
	tempNode=waitingHead;
	tempNode1=waitingHead;
	tempNode2=waitingHead;
	waitingTemp=waitingHead;
	while(waitingTemp!=NULL || found!=true)
	{
		bool valid = false;
		if(waitingTemp->DisabilityOption=="Yes")
		{
		
			if(waitingTemp->DisabilityOption=="Yes" && count10==0)
			{
				
				while(valid!=true || waitingTemp!=NULL)
				{
					if(waitingTemp->DisabilityOption=="No")
					{
						if(waitingTemp->next->DisabilityOption=="Yes")
						{
							valid=true;
							waitingTemp=waitingTemp->next;
							break;
						}
					}
					waitingTemp=waitingTemp->next;
				}
			}
		}
		else if(waitingTemp->DisabilityOption=="No" && count10==0)
		{
			while(valid!=true || waitingTemp!=NULL)
			{
				if(waitingTemp->DisabilityOption=="No")
				{
					if(waitingTemp->next->DisabilityOption=="Yes")
					{
						valid=true;
						waitingTemp=waitingTemp->next;
						break;
					}
				}
				waitingTemp=waitingTemp->next;
			}
			
		}
		if(valid==true)
		{
			bool checkOthers=false;
			int location=0,count=0,count2=-1;
			while(checkOthers!=true)
			{	
				if(tempNode->DisabilityOption=="Yes")
				{
					count2++;
					location=count;
				}
				if(tempNode->next!=NULL)
				{
					tempNode=tempNode->next;
					count++;
					
				}
				else if(tempNode->next==NULL)
				{
					checkOthers=true;
				}
			}
			tempNode=waitingHead;
			tempNode1 = waitingHead;
			
			if(checkOthers==true)
			{
				int num=0;
				
				while(num<count ||  tempNode!=NULL)
				{
					if(count2==0 && location!=count)
					{
						int count4=0;
						while(count4<location)
						{	
							count4++;
							if(count4>=location)
							{
								break;
							}
							else
							{
								tempNode2=tempNode2->next;
							}
						}
						tempNode2->next=waitingTemp->next;
						waitingTemp->next=waitingHead;
						waitingHead=waitingTemp;
						found=true;
						break;
					}
					else if(count2==0 && location==count)
					{
						int count3=0;
						while(count3<location)
						{	
							count3++;
							if(count3>=location)
							{
								break;
							}
							else
							{
								tempNode2=tempNode2->next;
							}
						}
						tempNode2->next=NULL;
						waitingTemp->next=waitingHead;
						waitingHead=waitingTemp;
						found=true;
						break;
					}
					else if(num==location && count2>0 && location!=count)
					{
						
						int count5=0,count6=0;
						while(count5<location)
						{	
							count5++;
							if(count5>=location)
							{
								break;
							}
							else
							{
								tempNode2=tempNode2->next;
							}
						}
						tempNode2->next=waitingTemp->next;
						while(count6<count2)
						{
							count6++;
							if(count6>=count2)
							{
								break;
							}
							else
							{
								tempNode1=tempNode1->next;
							}
						}
						waitingTemp->next=tempNode1->next;
						tempNode1->next=waitingTemp;
						found=true;
					}
					else if(num==location && count2>0 && location==count)
					{
						
						int count7=0,count8=0;
						while(count7<location)
						{	
							count7++;
							if(count7>=location)
							{
								break;
							}
							else
							{
								tempNode2=tempNode2->next;
							}
						}
						tempNode2->next=NULL;
						while(count8<count2)
						{
							count8++;
							if(count8>=count2)
							{
								break;
							}
							else
							{
								tempNode1=tempNode1->next;
							}
						}
						waitingTemp->next=tempNode1->next;
						tempNode1->next=waitingTemp;
						found=true;
					}
					tempNode=tempNode->next;
					num++;
				}
			}	
		}
		waitingTemp=waitingTemp->next;
		count10++;
	}
}
/***********************************************************/
/* Developer Name: Loke Weng Khay              	           */
/* Nurse Function 1.3: Display all patient 	     	       */
/* Function: To display all patient in the waiitng list    */
/***********************************************************/
void displayAll(patient *current)
//void displayAll()
{
	
	//waitingTemp = waitingHead;
	/*while(waitingTemp != NULL)
	{
		cout <<"ID: "<<waitingTemp->PID<< endl;
		cout <<"Name: "<< waitingTemp->FirstName<<" "<<waitingTemp->LastName<<endl;
		cout <<"Age: "<<waitingTemp->Age<<endl;
		cout <<"Gender: "<< waitingTemp->Gender<<endl;
		cout <<"Phone Number: "<< waitingTemp->Phone<<endl;
		cout <<"Address: "<< waitingTemp->Address<<endl;
		cout <<"Sickness Description: "<< waitingTemp->SicknessDescription<<endl;
		cout <<"Visit Date: "<< waitingTemp->VisitDate<<endl;
		cout <<"Visit Time: "<< waitingTemp->VisitTime<<endl;
		cout <<"Disability Option: "<< waitingTemp->DisabilityOption<<endl;
		cout <<"Doctor Name: "<< waitingTemp->DoctorName<<endl;
		cout <<"Medicine Information: "<<waitingTemp->MedicineInformation<<endl<<endl;
		waitingTemp = waitingTemp->next;
	}**/
	cout <<"ID: "<<current->PID<< endl;
	cout <<"Name: "<< current->FirstName<<" "<<current->LastName<<endl;
	cout <<"Age: "<<current->Age<<endl;
	cout <<"Gender: "<< current->Gender<<endl;
	cout <<"Phone Number: "<< current->Phone<<endl;
	cout <<"Address: "<< current->Address<<endl;
	cout <<"Sickness Description: "<< current->SicknessDescription<<endl;
	cout <<"Visit Date: "<< current->VisitDate<<endl;
	cout <<"Visit Time: "<< current->VisitTime<<endl;
	cout <<"Disability Option: "<< current->DisabilityOption<<endl;
	cout <<"Doctor Name: "<< current->DoctorName<<endl;
	cout <<"Medicine Information: "<<current->MedicineInformation<<endl<<endl;
	
	if(current->next!=NULL)
	{
		displayAll(current->next);
	}
}
/******************************************************************/
/* Developer Name: Loke Weng Khay              	                  */
/* Nurse Function 1.4: Call the patient in the queue              */
/* Function: To notify the patient that they can visit the doctor */
/******************************************************************/
void callPatient()
{
	cout<<"\n\n**********************************\n*          Notification          *\n**********************************\n";
	cout<<"Mr/Mrs "<<waitingHead->FirstName<<" "<<waitingHead->LastName<<", please enter the doctor's room, the doctor is ready to see you\n";
	storeToHistory();
}
/*********************************************************************************************/
/* Developer Name: Loke Weng Khay              	                                             */
/* Function: To store the patient info to the history info and update the waiting list queue */
/*********************************************************************************************/
void storeToHistory()
{
	if(historyHead==NULL)
	{
		historyHead=waitingHead;
		waitingHead=waitingHead->next;
		historyHead->next=NULL;
	}
	else
	{
		historyTemp=historyHead;
		historyHead=waitingHead;
		waitingHead=waitingHead->next;
		historyHead->next=historyTemp;
	}
}
