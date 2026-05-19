#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    string accountNumber;
    string type;
    double balance;

public:
    void createAccount() {
        cout << "\n--- Create New Account ---\n";

        cout << "Account Number: ";
        cin >> accountNumber;
        cin.ignore();

        cout << "Account Holder Name: ";
        getline(cin, name);

        cout << "Account Type (Saving/Current): ";
        getline(cin, type);

        cout << "Initial Balance: ";
        cin >> balance;

        if (balance < 0) balance = 0;

        cout << "Account Created Successfully!\n";
    }

    void deposit() {
        double amount;
        cout << "\nEnter Deposit Amount: ";
        cin >> amount;

        if (amount > 0) {
            balance += amount;
            cout << "Deposit Successful! New Balance: " << balance << endl;
        } else {
            cout << "Invalid Amount!\n";
        }
    }

    void withdraw() {
        double amount;
        cout << "\nEnter Withdrawal Amount: ";
        cin >> amount;

        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Withdrawal Successful! Remaining Balance: " << balance << endl;
        } else {
            cout << "Insufficient Balance or Invalid Amount!\n";
        }
    }

    void display() {
        cout << "\n========================";
        cout << "\nAccount No : " << accountNumber;
        cout << "\nName       : " << name;
        cout << "\nType       : " << type;
        cout << "\nBalance    : " << balance;
        cout << "\n========================\n";
    }

    string getAccountNumber() {
        return accountNumber;
    }
};

// ---- SYSTEM STORAGE ----
BankAccount accounts[100];
int countAccounts = 0;

// ---- FUNCTIONS ----
void createAccount() {
    accounts[countAccounts].createAccount();
    countAccounts++;
}

void showAccounts() {
    if (countAccounts == 0) {
        cout << "\nNo accounts found!\n";
        return;
    }

    for (int i = 0; i < countAccounts; i++) {
        accounts[i].display();
    }
}

void searchAccount() {
    string accNo;
    cout << "\nEnter Account Number: ";
    cin >> accNo;

    for (int i = 0; i < countAccounts; i++) {
        if (accounts[i].getAccountNumber() == accNo) {
            cout << "\nAccount Found!\n";
            accounts[i].display();
            return;
        }
    }

    cout << "Account Not Found!\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====";
        cout << "\n1. Create Account";
        cout << "\n2. Show All Accounts";
        cout << "\n3. Search Account";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                showAccounts();
                break;
            case 3:
                searchAccount();
                break;
            case 4:
                cout << "Exiting Program...\n";
                return 0;
            default:
                cout << "Invalid Choice!\n";
        }
    }
}
