#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;


void displayMenu();
double checkBalance(double balance); 
void depositMoney(double &balance, double amount);
void withdrawalMoney(double &balance, double amount, double dailyLimit);
void exitATM();

int main() {
double balance = 0.0;
double depositAmount = 0.0;
double withdrawalAmount = 0.0;
double dailyLimit = 1000.0;
int options;

do {
    displayMenu();
    cout<< "Enter your choice: ";
    cin>> options;

switch (options) {
    case 1:             // Check balance
cout<< "Your current balance is: "<< checkBalance(balance)<<endl;
    break;



    case 2: {            // Depositing Money
cout<< "Enter the deposit amount: ";
cin>> depositAmount;

    if (depositAmount <= 0) {
    cout<< "Deposit amount has to be positive "<<endl;
    } else {
    depositMoney(balance, depositAmount);
    }
    break;
}



    case 3: {           // Withdrawing Money
cout<< "Enter the withdrawal amount: ";
cin>> withdrawalAmount;

    if (withdrawalAmount <= 0) {
    cout<< "Withdrawal amount has to be positive "<<endl;
    } else {
    withdrawalMoney(balance, withdrawalAmount, dailyLimit);
    }
    break;
}



    case 4:        // Exiting the ATM
exitATM();
return 0;

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
    balance += amount;
    cout<< "Your transaction has been successful: "<<amount<<endl;
    cout<< "Your new balance is " <<balance<<endl;
}



void withdrawalMoney(double &balance, double amount, double dailyLimit) {    // Option/Case 3
    if (amount <= 0) {
        cout<< "Denied. Withdrawal amount has to be greater than zero "<<endl;
    } else if (amount > balance) {
        cout<< "Decline. Your current balance is "<<balance<<endl;
    } else if (amount > dailyLimit) {
        cout<< "The daily withdrawal limit is "<<dailyLimit<<endl;
    } else {
        balance -= amount;
        cout<< "Your transaction has been successful "<<amount<<endl;
        cout<< "Your new balance is " <<balance<<endl;
    }
}



void exitATM() {      // Option/Case 4
cout<< "Thank you for using this ATM. Goodbye"<<endl;
}
