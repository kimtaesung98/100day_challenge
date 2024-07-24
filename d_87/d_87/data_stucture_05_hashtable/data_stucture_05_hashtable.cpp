#include <iostream>
#include <vector>
#include <list>
using namespace std;

class hashtable {
private:
	static const int hashgroups = 10;
	vector<list<pair<int, string >>> table;
public:
	hashtable() {
		table.resize(hashgroups);
	}
	int hashfunction(int key) {
		return key % hashgroups;
	}
	void insertItem(int key, string value) {
		int hashvalue = hashfunction(key);
		auto& cell = table[hashvalue];
		auto bitr = begin(cell);
		bool keyexists = false;
		for (; bitr != end(cell); bitr++) {
			if (bitr->first == key) {
				keyexists = true;
				bitr->second = value;
				break;
			}
		}
		if (!keyexists) {
			cell.emplace_back(key, value);
		}
	}
	void removeitem(int key) {
		int hashvalue = hashfunction(key);
		auto& cell = table[hashvalue];
		auto bitr = begin(cell);
		bool keyexists = false;
		for (; bitr != end(cell); bitr++) {
			if (bitr->first == key) {
				keyexists = true;
				bitr = cell.erase(bitr);
				break;
			}
		}
	}
	string searchtable(int key) {
		int hashvalue = hashfunction(key);
		auto& cell = table[hashvalue];
		auto bitr = begin(cell);
		for (; bitr != end(cell); bitr++) {
			if (bitr->first == key) {
				return bitr->second;
			}
		}
		return "not found";
	}
	void printtable() {
		for (int i = 0; i < i < hashgroups; i++) {
			if (table[i].size() == 0)continue;
			auto bitr = table[i].begin();
			for (; bitr != table[i].end(); bitr++) {
				cout << "key: " << bitr->first << "value: " << bitr->second << endl;
			}
		}
	}
};
int main() {
	hashtable HT;
	HT.insertItem(905, "Jim");
	HT.insertItem(201, "Tom");
	HT.insertItem(332, "Bob");
	HT.insertItem(124, "Sally");
	HT.insertItem(107, "Sandy");
	HT.insertItem(929, "Barb");
	HT.insertItem(928, "Rob");

	HT.printtable();

	HT.removeitem(332);
	HT.removeitem(100);

	cout << HT.searchtable(124) << endl;
	cout << HT.searchtable(100) << endl;

	return 0;
}
