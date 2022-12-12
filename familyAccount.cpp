#include <iostream>
#include <string>
#include <unistd.h>
#include <limits> 

using namespace std;

// parent class
class parent {
	private:
		string name;
		
	protected:
		int balance;
		
	public: 
		// Constructor
		parent(double b,string n){
			balance=b;
			name=n;
		}
		// Destructor
		~ parent(){
			cout << "Destructor"<< endl;  
		}
		//Function to set the balance 
		void setBalance(double b){
			balance=b;
		}
		// Function to return the balance
		double balanceValue(){
			return balance;
		}
		//Function to set the name
		void setName(string n){
			name=n;
		}
		// Function to return the name
		string nameValue(){
			return name;
		}
		// Function to show the balance  
	 	void inquiry(){
			cout << "Current balance: $" << balance  << endl;  
		}
		
		// Function to withdraw an amount from ATM
    	void withdraw()
    	{
    		double amount;
    		string cancel;
        	cout << "\nEnter amount to be withdrawn\n";
        	
        	/*when withdrawl amount is greater than the balance, 
        	ask the user to enter a lesser amount or to cancel the transaction and return to the ATM Menu
        	*/
        	
			while(1){
				// Check if user's input is a number
    			if(cin >> amount) {
    				try{
    					// Balance is greater than amount to withdraw
    					if (amount<balance){
    						balance-=amount;
 							cout << "\n$" << amount <<" withdrawal successful" << endl;
        					cout << "Current account balance: $" << balance  << endl;
    						break;
    					}
						//withdraw amount is greater than the balance
    					else{
    						throw 'E';
    					}
					}
					catch(char E){
						
						cout << "\nInsufficient fund!" << endl;
 						cout << "Your current balance is: $" << balance  << endl;
 						cout << "To continue your transaction enter yes and choose a lesser amount or enter no to cancel your transaction."<< endl;
 						cin>> cancel;
 						if(cancel=="yes" ||cancel=="YES")
 							cout << "\nPlease try a lesser amount\n";
 						else
 							break;
					}
    				
    			}
    			// If the input is not a number diplay message Invalid input. Please enter 4 digit.
      			else {
      				cin.clear();
      				cin.ignore(numeric_limits<streamsize>::max(), '\n');
      				cout << "Invalid input. Please enter 4 digit."<< endl;
      			}		
			
			}
			
        }
        // Method to determine if a string is a number
			inline bool isNumber(const string& str)
			{
    			for (char const &c : str) {
        			if (std::isdigit(c) == 0) return false;
    			}
    			return true;
			}

        // Function to transfer in ATM
    	void transfert()
    	{
    		double amount;
    		string cancel;
    		string bankAccount; // we assume that a bank account number is a 12 digit number
			int attemptBank=2;
    		int attempts=2;
			// Ask user to enter the bank account number to transfer
			cout << "\nEnter the bank account number to transfer\n";
        	cin >> bankAccount;
			/*when the input is not a number or the number'size is different of 12.
        	After 3 unsuccessful attempts return to the ATM Menu
        	*/
			while(((!isNumber(bankAccount))|| (bankAccount.size()!=12)) && (attemptBank>0)){
 				cout << "Incorrect bank account number!" << endl;
 				cout << "Please try again. You have "<< attemptBank<<" remaining attempt." << endl;
 				attemptBank--;
 				cin >> bankAccount;
 			}
			// When the bank account number is valid
				if(isNumber(bankAccount) && bankAccount.size()==12){
        		cout << "\nEnter amount to be tranfered\n";
        		
        		/*when transfert amount is greater than the balance, 
        		ask the user to enter a lesser amount or to cancel the transaction and return to the ATM Menu
        		*/
        		
				while(1){
					// Check if user's input is a number
    				if(cin >> amount) {
    					try{
    						// Balance is greater than amount to withdraw
    						if (amount<balance){
    							balance-=amount;
 								cout << "\n$" << amount <<" transfert successful" << endl;
        						cout << "Current account balance: $" << balance  << endl;
    							break;
    						}
							//tr ansfer is greater than the balance
    						else{
    							throw 'E';
    						}
						}
						catch(char E){
							
							cout << "\nInsufficient fund!" << endl;
 							cout << "Your current balance is: $" << balance  << endl;
 							cout << "To continue your transaction enter yes and choose a lesser amount or enter no to cancel your transaction."<< endl;
 							cin>> cancel;
 							if(cancel=="yes" ||cancel=="YES")
 								cout << "\nPlease try a lesser amount\n";
 							else
 								break;
						}
    					
    				}
    				// If the input is not a number diplay message Invalid input. Please enter 4 digit.
      				else {
      					cin.clear();
      					cin.ignore(numeric_limits<streamsize>::max(), '\n');
      					cout << "Invalid input. Please enter 4 digit."<< endl;
      				}		
				
				}
			}	
        }
	
};

//child class
class child : public parent {

		private: 
			int age;
			// used to set a limit for each child withdrawl
			double withdrawLimit; 
    		
		public:
		void setAge(int a){
			age=a;  
		}
		int ageValue(int a){
			return age;  
		}
		//Constructor
		child(double b,string n,int a): parent(b,n)
		{
			age=a;  
			
			// for older child set withdrawal limit to 500
    		if(a==20)
    			withdrawLimit=500;
    		// for younger child set withdrawal limit to 300
    		else
    			withdrawLimit=300;
		}
		// Destructor
		~ child(){
			cout << "Destructor"<< endl;  
		}
		
		// Function to withdraw an amount  ATM
    	void withdraw()
    	{
    		double amount;
    		string cancel;
    		
    		// Withdrawl limit has not been exceeded
    		if (withdrawLimit>0){
    			cout << "\nYou can withdraw up to "<<withdrawLimit<<"\n";
        		cout << "\nEnter amount to be withdrawn\n";
        		/*when withdrawl amount is greater than the balance, 
        		ask the user to enter a lesser amount or to cancel the transaction and return to the ATM Menu
        		*/
        		
				while(1){
					// Check if user's input is a number
    				if(cin >> amount) {
    					try{
    						// Balance is greater than amount to withdraw and the limit has not been reached
    						if ((amount<balance)&&(amount<=withdrawLimit)){
    							balance-=amount;
    							withdrawLimit-=amount;
 								cout <<"\n$" << amount <<" withdrawal successful" << endl;
        						cout << "Current account balance: $" << balance  << endl;
    							break;
    						}
							//amount is greater than the balance
    						else
    							if(amount>balance)
    								throw 'E';
    							//amount is greater than remaining withdrawl limit
    							else
    								throw 1;
						}
						catch(char E){
							
							cout << "\nInsufficient fund!" << endl;
 							cout << "Your current balance is: $" << balance  << endl;
 							cout << "To continue your transaction enter yes and choose a lesser amount or enter no to cancel your transaction."<< endl;
 							cin>> cancel;
 							if(cancel=="yes" ||cancel=="YES")
 								cout << "\nPlease try a lesser amount\n";
 							else
 								break;
						}
    					catch(int){
							
							cout << "\nYou can withdraw up to "<<withdrawLimit<<"\n";
 							cout << "To continue your transaction enter yes and choose a lesser amount or enter no to cancel your transaction."<< endl;
 							cin>> cancel;
 							if(cancel=="yes" ||cancel=="YES")
 								cout << "\nPlease try a lesser amount\n";
 							else
 								break;
						}
    				}
    			// If the input is not anumber diplay message Invalid input. Please enter 4 digit.
      			else {
      				cin.clear();
      				cin.ignore(numeric_limits<streamsize>::max(), '\n');
      				cout << "Invalid input. Please enter 4 digit."<< endl;
      			}		
			
			}
        		
			}
			else // Withdrawl limit has been reached
			{
				cout << "\nYou have reached your daily withdrawal limit\n";
				sleep(2);
			}
		}
};

// Function to display the ATM menu
void atmMenu(){
		cout << "\nEnter Your Choice" << endl;  
		cout << "E. Enquiry" << endl;
    	cout << "W. Withdraw" << endl;
    	cout << "T. Transfer" << endl;
    	cout << "X. Exit" << endl;
}
int main()
{
    cout << "Enter your 4 digit pin code" << endl;
	int pin=0;
	char choice;
	int attempt=3; // number of tries		
    	while((pin!=1111)&&(pin!=2222)&&(pin!=3333))
 		{
			
					attempt--;
    				// Check if user's input is a number
    				if((cin >> pin)) {
    					try{
    						// exit the while loop if pin is equal to 1111 or 2222 or 3333
    						if ((pin==1111)||(pin==2222)||(pin==3333))
    							break;	
							// If the input is a number but different from 1111, 2222, and 3333 diplay message Incorrect pin.
    						else
    							throw 'E';
						}
						catch(char E){
							if(attempt>0)	
								cout << "Incorrect pin. Try again! You have "<< attempt<<" remaining tries!"<< endl;
							else
							{
								cout<<"You have reached the maximum number of tries. Please try later"<< endl;
								exit(1);
							}
				
						
    					}
    				}
    				// If the input is not anumber diplay message Invalid input. Please enter 4 digit.
      				else 
      					if(attempt>0)	
      					{
      						cin.clear();
      						cin.ignore(numeric_limits<streamsize>::max(), '\n');
      						cout << "Invalid input. Please enter 4 digit. You have "<< attempt<<" remaining tries!"<< endl;
      					}	
      					else
							{
								cout<<"You have reached the maximum number of tries. Please try later"<< endl;
								exit(1);
							}
    				
		}
		
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~Welcome to MyBank ATM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
             << "~~~~~~~~~\n\n";
    // create parent object and two child object
    parent p(100000,"Smith");
    child c1(1000,"John Smith",20);
    child c2(1000,"Alex Smith",15);
             	
	do{
			// display the ATM menu
			atmMenu();
			cin >> choice;
			// parent 
			if(pin==1111){
				
				switch (choice) {
        			case 'E':
        			case 'e':
            			p.inquiry();
    					break;
        			case 'W':
        			case 'w':
            			p.withdraw();
    	 				break;
    	 			case 'T':
        			case 't':
            			p.transfert();
    	 				break;
        			case 'X':
        			case 'x':
        				cout<< "Thanks for choosing us as your bank. Visit us again!" << endl;
    	 				exit(1);
            			break;
        			
        			default: // Return to the ATM menu
            			cout << "\nInvalid choice. Please try again\n";
    	 				
        			}
			
			}
			else 
				// Child 1
				if(pin==2222){
					
					switch (choice) {
        				case 'E':
        				case 'e':
            				c1.inquiry();
            				break;
        				case 'W':
        				case 'w':
            				c1.withdraw();
    	 					break;
    	 				case 'T':
        				case 't':
            				c1.transfert();
    	 					break;
        				case 'X':
        				case 'x':
        					cout<< "Thanks for choosing us as your bank. Visit us again!" << endl;
    	 					exit(1);
            				break;
        				
        				default: // Return to the ATM menu
            				cout << "\nInvalid choice. Please try again\n";
    	 					
        				}
				}
				// pin=3333 Child 2
				else{
					switch (choice) {
        				case 'E':
        				case 'e':
            				c2.inquiry();
            				break;
        				case 'W':
        				case 'w':
            				c2.withdraw();
    	 					break;
    	 				case 'T':
        				case 't':
            				cout<< "You are not allowed to perform this transaction!" << endl;
    	 					break;
        				case 'X':
        				case 'x':
        					cout<< "Thanks for choosing us as your bank. Visit us again!" << endl;
    	 					exit(1);
            				break;
        				
        				default: // Return to the ATM menu
            				cout << "\nInvalid choice. Please try again\n";
    	 					
        				}
				}
    		// Choices to select from the menu
    	} while(choice!='X' && choice!='x');
	
	
	return 0;
}
