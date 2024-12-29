#include <iostream>
#include <string.h>
#include <cstring>
#include <ctype.h>
#include <iomanip>
using namespace std;
int num=0, Gender, n, flag=1;
string pname[100];
string gender[100];
int pid[100];
int age[100];
float weight[100];
float height[100];
string p_discription[100];
string name;
char x;

void add(){
	b:
	cout<<"Please enter the number of patients you want to add:\n";
	cin>>n;
	if(cin.fail()|| n<0){
		cin.clear(); cin.ignore();
		cout<<"Enter number only"<<endl;
		goto b;
	}
	num+=n;
	cout<<"PLease enter their details:\n";
	for(int i=num-n;i<num;i++){
		cout<<"Enter the name of the "<<i<<" patient: ";
		cin.ignore();
		getline(cin, pname[i]);
		i:
        cout << "Enter gender: \n1. Male\n2. Female"<<endl;
        cin>>Gender;
        if(cin.fail()|| Gender < 1 || Gender > 2){
			cin.clear(); cin.ignore();
			cout<<"Enter proper input!"<<endl;
			goto i;
		}
        if(Gender==1)
        gender[i]="Male";
		else
		gender[i]="Female";
		j:
        cout << "Enter the patient ID: "<<endl;
        cin>>pid[i];
		if(cin.fail()){
			cin.clear(); cin.ignore();
			cout<<"Enter proper input"<<endl;
			goto j;
		}
		l:
		cout<<"Enter the Age of the patient: ";
		cin>>age[i];
		if(cin.fail()|| age[i]<0){
			cin.clear(); cin.ignore();
			cout<<"Enter proper input!"<<endl;
			goto l;
		}
		m:
		cout<<"Enter the Weight of the patient: ";
		cin>>weight[i];
		if(cin.fail()|| weight[i]<0){
			cin.clear(); cin.ignore();
			cout<<"Enter proper input!"<<endl;
			goto m;
		}
		n:
		cout<<"Enter the Height of the patient: ";
		cin>>height[i];
		if(cin.fail()|| height[i]<0){
			cin.clear(); cin.ignore();
			cout<<"Enter proper input!"<<endl;
			goto n;
		}
		cout<<"Enter the medical history of the patient: ";
		cin.ignore();
		getline(cin, p_discription[i]);
	}
}

void display(){
	cout << "\n=== Patient Medical Records ===\n";
		cout << left << setw(20) << "Name" << setw(10) << "Gender" << setw(20) << "ID" << setw(10) << "Age"<< setw(10)<<"Weight"<< setw(10)<<"Height"<< setw(20)<< "Medical history" << "\n";
            cout << string(95, '-') << "\n";

            for (int i=0;i<num;i++) {
                cout << left << setw(20) << pname[i]
                     << setw(10) << gender[i]
                     << setw(20) << pid[i]
                     << setw(10)<< age[i]<<setw(10)<<weight[i]<<setw(10)<<height[i]<< setw(20)<<  fixed << p_discription[i] << "\n";
            }
}

void search(){
	cout<<"Enter the name of the patient: ";
		cin.ignore();
		getline(cin, name);
		for(int i=0;i<num;i++){	
		if(name == pname[i]){
			cout << "\n=== Patient Medical Records ===\n";
			cout << left << setw(20) << "Name" << setw(10) << "Gender" << setw(20) << "ID" << setw(10) << "Age"<<setw(10)<<"Weight"<< setw(10)<<"Height"<< setw(20)<< "Medical history" << "\n";
            cout << string(95, '-') << "\n";
			cout << left << setw(20) << pname[i]
                     << setw(10) << gender[i]
                     << setw(20) << pid[i]
                     << setw(10)<< age[i]<<setw(10)<< setprecision(2)<<weight[i]<<setw(10)<< setprecision(2)<<height[i]<<setw(20) <<  fixed  << p_discription[i] << "\n";
			break;
		}
	}
}

int main(){
	//float weight[100];
	do{
	int choice;
	a:
	cout << "\n=== Patient Management System Menu ===\n";
	cout<<"1. Add patient. \n2. Display all patients. \n3. Search for a patient. \n4. Exit"<<endl;
	cout << "Enter your choice: ";
	cin>>choice;
	if(cin.fail()){
		cin.clear(); cin.ignore();
		cout<<"Enter number only"<<endl;
		goto a;
	}
	switch(choice){
	case 1:
		add();
		break;
	case 2:
		display();
		break;
	case 3:
		search();
		break;
		case 4:
			cout<<"Thank You!";
			flag = 0;
			break;
	default: 
		cout<<"Enter a proper input!"<<endl;
		goto a;
	}
	if(flag==1){
	cout<<"Do you want to continue? Y/N\n";
	cin>>x;
	}
}while((x=='Y' || x=='y') && flag == 1);
	return 0;		
}