// contact_01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class account {
private:
    string name;
    double remain;
public:
    account(string name):name(name),remain(0.0) {
        ofstream outfile("myaccount.txt", ios::app);//파일 끝에 추가 ios::app
        outfile << name << endl;
        addContact();
        outfile.close();
    }
    void deposit_(double amount) {
        ofstream outfile("myaccount.txt", ios::app);//파일 끝에 추가 ios::app

        remain += amount;
        outfile << "deposit: " << amount << "new balance: " << remain << endl;;
        outfile.close();
    }
    void withdraw_(double amount) {
        ofstream outfile("myaccount.txt", ios::app);//파일 끝에 추가 ios::app
        
        if (remain < amount) {
            cout << "not enough to withdraw money" << endl;
            cout << "check account: " << remain << endl;
        }
        else {
            remain -= amount;
            outfile << "withdraw: " << amount << " new balance: " << remain << endl;
        }
        outfile.close();
    }
    void addContact();
    void viewContact();
    bool found();
    void delete_account(const string& name);
};
void account:: addContact() {
    ofstream outfile("myaccount.txt", ios::app);//파일 끝에 추가 ios::app
    int data = 0;
    double  remain, withdraw, deposit;
    outfile << "withdraw: " << 0.0 << "deposit: " << 0.0 << "remain: " << 0.0 << endl;
    outfile.close();
}
void account::viewContact() {//
    //읽기 클라스 ifstream
    ifstream infile("myaccount.txt");//infile이라는 파일
    string line;
    while (getline(infile,line) ) {
        cout << line << endl;
    }
    infile.close();
}
/*
bool account::found() {
    //통장 여부 묻는 함수
}
*/
void account:: delete_account(const string& name) {
    ifstream infile("myaccount.txt");
    ofstream tempfile("temp.txt");
    string line;
    bool found = false;
    while (getline(infile, line)) {
        if (line == name) {
            found = true;
            for (int i = 0; i < 4; ++i) {
                getline(infile, line);
            }
        }
        else {
            tempfile << line << endl;
        }
    }
    infile.close();
    tempfile.close();
    remove("account.txt");
    rename("temp.txt", "myaccount.txt");

    if (found) {
        cout << "account delete successfully." << endl;
    }
    else {
        cout << "account not found." << endl;
    }
}
int main(){

    string name;
    int choice;
    double money;
    //통장 여부는 다음 단계에서 구현하기 found func
        cout << "ctreate your account" << endl;
        cout << "input your name :";
        cin >> name;
        account myaccount(name);

    do {
        cout << "1. add money" << endl;
        cout << "2. withdraw money" << endl;
        cout << "3. view account" << endl;
        cout << "4. delete account" << endl;
        cout << "5. exit" << endl;
        cout << "enter your choice: " << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> money;
            myaccount.deposit_(money);
            break;
        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> money;
            myaccount.withdraw_(money);
            break;
        case 3:
            myaccount.viewContact();
            break;
        case 4:
            cout << "delete account:" << endl;
            myaccount.delete_account(name);
            //
            break;
        case 5:
            cout << "exiting..." << endl;
        default:
            cout << "invalid choice" << endl;
        }
    } while (choice != 4);
}