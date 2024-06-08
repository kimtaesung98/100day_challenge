#include <iostream>
#include < fstream>
#include <string>
#include < vector>

using namespace std;

namespace fs = std::filesystem;

int main() {
	fstream file("example.txt", ios::out | ios::in | ios::trunc);
	if (!file) {
		cerr << "unable to open file example.txt";
		return 1;
	}
	file << "12345" << endl;
	file << "67890" << endl;

	file.seekg(6);
	char c;
	while (file.get(c)) {
		cout << c;
	}
	file.close();
}