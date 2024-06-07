#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

class Account {
private:
    string name;
    double balance;
    string filename;
public:
    Account(string name) : name(name), balance(0.0) {
        filename = "accounts/" + name + ".txt";
        if (fs::exists(filename)) {
            cout << "Account already exists. Loading data..." << endl;
            loadAccount();
        }
        else {
            cout << "Creating new account for " << name << endl;
            saveAccount();
        }
    }

    void deposit(double amount) {
        balance += amount;
        saveAccount();
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Not enough balance" << endl;
        }
        else {
            balance -= amount;
            saveAccount();
        }
    }

    void viewAccount() {
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }

    void deleteAccount() {
        if (fs::remove(filename)) {
            cout << "Account deleted successfully" << endl;
        }
        else {
            cout << "Error deleting account" << endl;
        }
    }

private:
    void saveAccount() {
        ofstream outfile(filename);
        outfile << name << endl;
        outfile << balance << endl;
        outfile.close();
    }

    void loadAccount() {
        ifstream infile(filename);
        infile >> name;
        infile >> balance;
        infile.close();
    }
};

int main() {
    fs::create_directory("accounts");

    string name;
    int choice;
    double amount;

    cout << "Enter your name: ";
    cin >> name;

    Account myAccount(name);

    do {
        cout << "1. Deposit money" << endl;
        cout << "2. Withdraw money" << endl;
        cout << "3. View account" << endl;
        cout << "4. Delete account" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            myAccount.deposit(amount);
            break;
        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            myAccount.withdraw(amount);
            break;
        case 3:
            myAccount.viewAccount();
            break;
        case 4:
            myAccount.deleteAccount();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 5);

    return 0;
}
