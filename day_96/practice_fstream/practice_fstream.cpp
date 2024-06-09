#include <iostream>
#include < fstream>
#include <string>
#include < vector>
#include <filesystem>

using namespace std;

namespace fs = std::filesystem;

int main() {
	fs::path dir = "example_directory";
	fs::create_directory(dir);
	fs::path file = "example_directory/example_file.txt";

	ofstream outfile(file);
	outfile << "hello, filesystem!" << endl;
	outfile.close();

	cout << "file created: " << file << endl;
}