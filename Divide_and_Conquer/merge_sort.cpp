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

template <typename T>
void merge(vector<T>& array, vector<T>& array1, vector<T>& array2){
	//need to copy contents of array1 and 2 into array
	int i, j;
	for(i = 0, j = 0; i < array1.size(), j < array2.size(); ){
		if(array1[i] < array2[j]){
			array[i+j] = array1[i];
			i++;
		}
		else{
			array[i+j] = array2[j];
			j++;
		}
	}
	
	while(i < array1.size()){
		array[i+j] = array1[i];
		i++;
	}
	while(j < array2.size()){
		array[i+j] = array1[j];
		j++;
	}
	
	
}

template <typename T>
void merge_sort(vector<T>& array) {
	if (1 < array.size()) {
		vector<T> array1(array.begin(), array.begin() + array.size() / 2);
		merge_sort(array1);
		vector<T> array2(array.begin() + array.size() / 2, array.end());
		merge_sort(array2);
		merge(array, array1, array2);
	}
}

int main(){
	vector<int> a(25, 0);
	for(int i = 0; i < a.size(); i++){
		a[i] = a.size() -1 -i;
	}
	merge_sort(a);
	printVector(a);

}
