#include <iostream>
#include <string>

using namespace std;

//Function prototypes
void patientManagement();
void appointmentScheduling();
void userAuthentication();
void staffManagement();

//sub functions in patient management 
void add();//Add new patients
void displayPatients();//Display all patients' information 

//sub functions in appiontment scheduling
void book();//Book an appiontment by entering patient name and slot number
void cancel();//Cancel an appointment by clearing slots
void displayAppointments();// Display all appointment slots and their status (booked or available).
   
//Global variables



//sub menus
void patientManagement() {
    int choice;
    do{
        cout<<"\n\n\n\t\t----Patient Management Menu----";
        cout<<"\n\t\t1.Add Patient";
        cout<<"\n\t\t2.View Patient Information";
        cout<<"\n\t\t3.Back to Main Menu";
        
        cout<<"\n\n\t\tEnter your choice: ";
        cin>>choice;

        switch(choice) 
        {
            case 1:
               add();
               break;
            case 2:
               displayPatients();
               break;
            case 3:
                return;
            default:
                cout<<"\n\t\t\tInvalid input!" 
                <<"\n\t\t\tPlease select the valid option from the given menu.";

        }
    } 
    while (choice != 3);
}

void appointmentScheduling() {
    int choice;
    do{
        cout<<"\n\n\n\n\t\t----Appointment Scheduling Menu----";
        cout<<"\n\t\t1.Book an Appointment";
        cout<<"\n\t\t2.Cancel an Appointment";
        cout<<"\n\t\t3.View Appointments";
        cout<<"\n\t\t4.Back to Main Menu";
        
        cout<<"\n\t\tEnter your choice: ";
        cin>>choice;

        switch(choice) 
        {
            case 1:
                book();
                break;
            case 2:
                cancel();
                break;
            case 3:
                displayAppointments();
                break;
            case 4:
                return;
            default:
                cout<<"\n\t\t\tInvalid input!" 
                <<"\n\t\t\tPlease select the valid option from the given menu.";  
        }
    } 
    while (choice != 4);
}

int main()
{ 
    cout<<"\n\t\t\t\t\t------Hospital management system--------";
    
    userAuthentication();//declaring as global variables
    
    cout<<"\n\n\t\t\t>>>>>>>>>>>>>";
    cout<<"\n\t\t\t* MAIN MENU *";
    cout<<"\n\t\t\t>>>>>>>>>>>>>";
     
   int choice;
    do{
        cout<<"\n\n\n\t\t\t1.Patient management";
        cout<<"\n\t\t\t2.Appointemnt scheduling";
        cout<<"\n\t\t\t3.Staff management";
        cout<<"\n\t\t\t4.Exit";
        
        cout<<"\n\n\t\t\tEnter Your Choice: ";
		cin>>choice;
        
        switch(choice)
        {
            case 1:
              patientManagement();
              break;
            case 2:
              appointmentScheduling();
              break;
            case 3:  
              staffManagement();
              case 4:
              break;
            default:
            cout<<"\n\t\t\tInvalid input!" 
                <<"\n\t\t\tPlease select the valid option from the given menu.";

        }
    }
    while(choice!=4);
   
   return 0;
}
