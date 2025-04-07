#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;


void displayMenu();
double checkBalance(double balance); 
void depositMoney(double &balance, double amount);
void withdrawalMoney(double &balance, double amount, double &dailyWithdrawal, double dailyLimit);
void exitATM();


double dailyWithdrawal = 0.0;

int main() {
double balance = 0.0;
double depositAmount = 0.0;
double withdrawalAmount = 0.0;
double dailyLimit = 1000.0;
int options = 0;

cout<< "Welcome to the ATM"<<endl;
    
do {
    displayMenu();
    cout<< "Enter your choice: ";
    cin>> options;

switch (options) {
    case 1:               // Check balance
    balance = checkBalance(balance);
cout<< "Your current balance is "<<fixed<<setprecision(2)<<balance<<endl;
    break;



    case 2: {            // Depositing Money
cout<< "Enter the deposit amount: ";
cin>> depositAmount;
        
depositMoney(balance, depositAmount);
cout<< "The amount has been deposited "<<fixed<<setprecision(2)<<depositAmount<< "Your new balance is "<<fixed<<setprecision(2)<<balance<<endl;
    break;
}


    case 3: {           // Withdrawing Money
cout<< "Enter the withdrawal amount ";
cin>> withdrawalAmount;

withdrawalMoney(balance, withdrawalAmount, dailyWithdrawal, dailyLimit);
cout<< "Your new balance is "<<fixed<<setprecision(2)<<balance<<endl;
    break;
}


    case 4:        // Exiting the ATM
exitATM();
break;

default:
cout<< "Error. Choose one of the following options "<<endl;
    }
} while (options != 4);

return 0;
}



void displayMenu() {
cout<< "Welcome to the ATM"<<endl;
cout<< "1. Check Balance"<<endl;
cout<< "2. Deposit Money"<<endl;
cout<< "3. Withdraw Money"<<endl;
cout<< "4. Exit"<<endl;
}


double checkBalance(double balance) {     // Option/Case 1
    return balance;
}



void depositMoney(double &balance, double amount) {     // Option/Case 2
    if (amount > 0) {
    balance += amount;
    } else {
cout<< "Error. Amount has to be positive "<<endl;
    }
}



void withdrawalMoney(double &balance, double amount, double dailyLimit) {    // Option/Case 3
if (amount > 0) {
if (amount <= balance) {
if (dailyWithdrawal + amount <= dailyLimit) {
    balance -= amount;
    dailyWithdrawal += amount;
    cout<< "Your withdrawal was successful"<<endl;
} else {
    cout<< "You have reached the daily withdrawal limit of 1000 "<<dailyLimit<< " Your total is" <<dailyWithdrawal<< "." <<endl;
        }
} else {
    cout<< "Decline. You cannot withdraw more than your current balance"<<endl;
        }
} else {
    cout<< "Denied. Withdrawal amount has to be greater than zero"<<endl;
    }
}




void exitATM() {      // Option/Case 4
cout<< "Thank you for using this ATM. Goodbye"<<endl;
}
