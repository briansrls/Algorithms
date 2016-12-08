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
int merge(vector<T>& array, vector<T>& array1, vector<T>& array2){
	//need to copy contents of array1 and 2 into array
	int i, j;
	int inversions = 0;
	for(i = 0, j = 0; i < array1.size(), j < array2.size(); ){
		if(array1[i] < array2[j]){
			array[i+j] = array1[i];
			i++;
		}
		else{
			array[i+j] = array2[j];
			j++;
			inversions+=array1.size()-i;
		}
	}
	
	while(i < array1.size()){
		array[i+j] = array1[i];
		i++;
	}
	while(j < array2.size()){
		array[i+j] = array1[j];
		j++;
		inversions++;
	}
	return inversions;	
	
}

template <typename T>
int merge_sort(vector<T>& array) {
	if (1 < array.size()) {
		int inversions = 0;
		vector<T> array1(array.begin(), array.begin() + array.size() / 2);
		inversions+=merge_sort(array1);
		vector<T> array2(array.begin() + array.size() / 2, array.end());
		inversions+=merge_sort(array2);
		return inversions+merge(array, array1, array2);
	}
}

int main(){
	vector<int> a(26, 0);
	for(int i = 0; i < a.size(); i++){
		a[i] = a.size() -1 -i;
	}
	printVector(a);
	cout << "Inversions = " << merge_sort(a) << std::endl;
	printVector(a);

}
