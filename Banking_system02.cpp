#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Account {
protected:
    string customerName;
    long long int accountNo;
    string typeOfAccount;
    int balance;

public:
    Account() {
        balance = 5000;
    }

    void input() {
        cout << "Enter customer name: ";
        cin.ignore();
        getline(cin, customerName);
        cout << "Enter account number: ";
        cin >> accountNo;
        cout << "Enter type of account: ";
        cin >> typeOfAccount;
    }

    void display() {
        cout << "\nCustomer Name: " << customerName;
        cout << "\nAccount Number: " << accountNo;
        cout << "\nType: " << typeOfAccount;
        cout << "\nBalance: " << balance << endl;
    }

    void deposit() {
        int amount;
        cout << "\nEnter amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "\nAmount deposited successfully. Updated balance: " << balance << endl;
    }
};

class CurrentAccount : public Account {
public:
    void issueCheque() {
        cout << "Your chequebook will be issued shortly." << endl;
    }

    void withdrawal() {
        int amount;
        cout << "\nEnter the amount to withdraw: ";
        cin >> amount;
        if (balance >= amount) {
            balance -= amount;
            if (balance < 500) {
                cout << "Penalty imposed (₹50).\n";
                balance -= 50;
            } else {
                cout << "No penalty imposed.\n";
            }
            cout << "Withdrawal successful. Updated balance: " << balance << endl;
        } else {
            cout << "Insufficient balance. Withdrawal not possible.\n";
        }
    }
};

class SavingAccount : public Account {
public:
    void updateBalance() {
        int timePeriod;
        const int rate = 10; // Interest rate
        cout << "\nEnter time period (in years) for interest calculation: ";
        cin >> timePeriod;

        balance = balance + (balance * (pow(1 + rate / 100.0, timePeriod) - 1));
        cout << "Balance updated with interest. Updated balance: " << balance << endl;
    }

    void withdrawal() {
        int amount;
        cout << "\nEnter amount to withdraw: ";
        cin >> amount;
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal successful. Updated balance: " << balance << endl;
        } else {
            cout << "Insufficient balance. Withdrawal not possible.\n";
        }
    }
};

int main() {
    int choice;
    CurrentAccount currentAccount;
    SavingAccount savingAccount;

    do {
        cout << "\n--- Bank Menu ---\n";
        cout << "1. Current Account\n";
        cout << "2. Saving Account\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int currentChoice;
            currentAccount.input();
            do {
                cout << "\n--- Current Account Menu ---\n";
                cout << "1. Display Account\n";
                cout << "2. Deposit Money\n";
                cout << "3. Withdraw Money\n";
                cout << "4. Issue Chequebook\n";
                cout << "5. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> currentChoice;

                switch (currentChoice) {
                case 1:
                    currentAccount.display();
                    break;
                case 2:
                    currentAccount.deposit();
                    break;
                case 3:
                    currentAccount.withdrawal();
                    break;
                case 4:
                    currentAccount.issueCheque();
                    break;
                case 5:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            } while (currentChoice != 5);
            break;

        case 2:
            int savingChoice;
            savingAccount.input();
            do {
                cout << "\n--- Saving Account Menu ---\n";
                cout << "1. Display Account\n";
                cout << "2. Deposit Money\n";
                cout << "3. Withdraw Money\n";
                cout << "4. Update Balance with Interest\n";
                cout << "5. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> savingChoice;

                switch (savingChoice) {
                case 1:
                    savingAccount.display();
                    break;
                case 2:
                    savingAccount.deposit();
                    break;
                case 3:
                    savingAccount.withdrawal();
                    break;
                case 4:
                    savingAccount.updateBalance();
                    break;
                case 5:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            } while (savingChoice != 5);
            break;

        case 3:
            cout << "Exiting program. Thank you for banking with us!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
