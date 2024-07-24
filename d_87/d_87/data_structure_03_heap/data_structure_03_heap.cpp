#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
void buildheap(vector<int>& arr) {
	int n = arr.size();
	//cout << n << endl;
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}
}
void printheap(vector<int>& arr) {
	for (int val : arr) {
		cout << val << " ";
	}
	cout << endl;
}
int main() {
	vector<int> arr = { 4,10,3,5,1 };
	buildheap(arr);
	printheap(arr);
}