#include <iostream>
#include <string>
using namespace std;

struct Account {
    string name;
    double interestRate;
    double balance;
};

// Function to print account details
void printAccount(const Account &acc) {
    cout << "\nAccount: " << acc.name << endl;
    cout << "Rate: " << acc.interestRate << "%" << endl;
    cout << "Balance: " << acc.balance << "\n" << endl;
}

// Deposit function
void deposit(Account &acc) {
    double amount;
    do {
        cout << "\nAmount deposited: ";
        cin >> amount;
        if (amount < 0)
            cout << "Please enter a value larger than or equal to 0\n";
    } while (amount < 0);
    acc.balance += amount;
    cout << "Balance: " << acc.balance << endl;
}

// Withdraw function
void withdraw(Account &acc) {
    double amount;
    do {
        cout << "\nAmount withdrawn: ";
        cin >> amount;
        if (amount < 0)
            cout << "Please enter a value larger than or equal to 0\n";
    } while (amount < 0);
    acc.balance -= amount;
    cout << "Balance: " << acc.balance << endl;
}

// Add interest function
void addInterest(Account &acc) {
    int days;
    cout << "\nInterest for how many days: ";
    cin >> days;

    double dailyRate = acc.interestRate / 365.0;
    double interestPercent = dailyRate * days;
    cout << "Rate is " << acc.interestRate << "% PA = " << interestPercent << "%\n";

    double interestAmount = (interestPercent / 100.0) * acc.balance;
    cout << "Interest = " << interestAmount << endl;

    acc.balance += interestAmount;
    cout << "Balance = " << acc.balance << endl;
}

int main() {
    Account acc;

    // Get initial account details
    cout << "Enter account name: ";
    getline(cin, acc.name);
    cout << "Enter interest percent (+/-): ";
    cin >> acc.interestRate;
    cout << "Enter initial amount: ";
    cin >> acc.balance;

    int option;
    do {
        // Display menu
        cout << "\nActions:\n";
        cout << "1: Print account details\n";
        cout << "2: Deposit\n";
        cout << "3: Withdraw\n";
        cout << "4: Add interest\n";
        cout << "5: Quit\n";
        cout << "Option: ";
        cin >> option;

        switch (option) {
            case 1: printAccount(acc); break;
            case 2: deposit(acc); break;
            case 3: withdraw(acc); break;
            case 4: addInterest(acc); break;
            case 5: cout << "Goodbye!\n"; break;
            default: cout << "Invalid option. Please try again.\n";
        }

    } while (option != 5);

    return 0;
}
