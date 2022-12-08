#include <iostream>
using namespace std;


int main(){
	int password = 0;
	int balence;
	bool pinIsInValid = true;
	double amount;
	cout<<"Please enter your pin."<<endl;
	cin>>password;

	while(pinIsInValid){

		if(password == 1111){
			balence=100000;
			pinIsInValid = false;
		}

		else if(password == 2222){
			balence=1000;
			pinIsInValid = false;
		}


		else if(password == 3333){
			balence=1000;
			pinIsInValid = false;
		}

		else{
			cout<<"INVALID PASSWORD"<<endl;
			cout<<"Please enter your pin."<<endl;
       			cin>>password;
		}
	}

	while(password>0){
	int action;

        cout<<"Welcome! Please select one of the following actions:"<<endl;
        cout<<"1(Withdraw)"<<endl;
        cout<<"2(Deposit)"<<endl;
        cout<<"3(Transfer)"<<endl;
        cout<<"4(Check Balence)"<<endl;
        cout<<"5(Exit)"<<endl;
	
        cin>>action;
	
	if(action==1){
        	cout<<"How much do you want to withdraw?"<<endl;
                cin>>amount;
                cout<<"Amount withdrawn: $"<<amount<<endl;
                balence=balence-amount;
                cout<<"Current Balence: $"<<balence<<endl;

        }

        else if(action==2){

                cout<<"How much do you want to deposit?"<<endl;
                cin>>amount;
                cout<<"Amount deposited: $"<<amount<<endl;
                balence=balence+amount;
                cout<<"Current Balence: $"<<balence<<endl;
        }

        else if(action==3){
		
               	cout<<"How much do you want to transfer?"<<endl;
                cin>>amount;
                cout<<"Amount transfered: $"<<amount<<endl;
                balence=balence-amount;
                cout<<"Current Balence: $"<<balence<<endl;

               	
        }

        else if(action==4){

                cout<<"Curent Balence: $"<<balence<<endl;

        }

        else if(action==5){
        	password = 0;
       		break;
	}

	else if(action>5 or action<1){
	        cout<<"Not a valid option. Please try agian."<<endl;

        }


	}
	return 0;
}

