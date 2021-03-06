#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

void printVector(vector<int> a){
	for(vector<int>::iterator it = a.begin(); it != a.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}


int Partition(vector<int> &array, int p, int r){
	int part = array[r];
	int j = p-1;
	for(int i = p; i < r; i++){
		if(array[i] <= part){
			j++;
			iter_swap(array.begin()+j, array.begin()+i);
		}

	}
	iter_swap(array.begin()+r, array.begin()+j+1);
	return j+1;
}

void QuickSort(vector<int> &array, int p, int r){
	if(p < r){
		int q = Partition(array, p, r);
		QuickSort(array, p, q-1);
		QuickSort(array, q+1, r);
	}
}

int main(){
	vector<int> a(25, 0);
	for(int i = 0; i < a.size(); i++){
		a[i] = rand() % 100;
	}
	QuickSort(a, 0, a.size()-1);
	printVector(a);

}
