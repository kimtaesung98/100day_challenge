#include < iostream>
#include <fstream>
#include <filesystem>
#include <string>
using namespace std;

namespace fs = std::filesystem;

class Account {
private:
	string name;
	double balance;
public:
	Account(const string& name, double balance = 0.0) : name(name), balance(balance) {}

	void withdraw(double amount) {
		if (amount > balance) {
			cout << "insufficient balance! " << endl;
		}
		else {
			balance -= amount;
			cout << "withdraw : " << amount << ", new balance : " << balance << endl;
		}
	} 
	void deposit(double amount) {
		balance += amount;
		std::cout << "Deposited: " << amount << ", New Balance: " << balance << std::endl;
	}
	void display()const {
		cout << "name: " << name << ",balance: " << balance << endl;
	}
	string getname() const { return name; }
	double getbalance()const { return balance; }
};
bool fileexists(const string& path) {
	return fs::exists(path);
}
void createaccountfile(const string& filepath, const string& name) {
	ofstream outfile(filepath);
	outfile << name << endl;
	outfile << 0.0 << endl;
	outfile.close();
}
Account readaccountfromfile(const string& filepath) {
	ifstream infile(filepath);
	string name;
	double balance;
	infile >> name >> balance;
	return Account(name, balance);
}
void updataaccountfile(const string& filepath, const Account& account) {
	ofstream outfile(filepath);
	outfile << account.getname() << endl;
	outfile << account.getbalance() << endl;
	outfile.close();
}
void createdirectory(const string& path) {
	if (!fs::exists(path)) {
		fs::create_directory(path);
	}
}
int main() {
	string directory = "accounts";
	string filename = "example.txt";
	string filepath = directory + "/" + filename;
	string name;
	Account account("", 0.0);

	if (fileexists(filepath)) {
		account = readaccountfromfile(filepath);
		cout << "welcome back, " << account.getname() << "!" << endl;
	}
	else {
		createdirectory(directory);
		cout << "enter your name to create a new account: ";
		cin >> name;
		account = Account(name);
		createaccountfile(filepath, name);
		cout << "account created for " << name << "!" << endl;
	}
	int choice;
	double amount;

	do {
		cout << "1. deposit\n2.withdraw\n3.view balance\n4.exit\nenter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "enter amount to deposit: ";
			cin >> amount;
			account.deposit(amount);
			updataaccountfile(filepath, account);
			break;
		case 2:
			cout << "enter amount to withdraw: ";
			cin >> amount;
			account.withdraw(amount);
			updataaccountfile(filepath, account);
			break;
		case 3:
			account.display();
			break;
		case 4:
			cout << "exiting.." << endl;
		default:
			cout << "invalid choice!" << endl;
			break;
		}
	}while (choice != 4);
	return 0;
}