#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

void printVector(vector<int> a){
	for(vector<int>::iterator it = a.begin(); it != a.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

int permute(vector<int> a, int start){
	int count = 0;
	for(int i = start; i < a.size(); i++){
		count+=a.size()-1-i;
		for(int j = i+1; j < a.size(); j++){
			iter_swap(a.begin() + i, a.begin() + j);
			count += permute(a, i+1);
			iter_swap(a.begin() + i, a.begin() + j);
		}
	}
	return count;
}

int main(){
	vector<int> array(2, 0);
	for(int i = 0; i < array.size(); i++) array[i] = i+1;
	printVector(array);
	cout << permute(array, 0) << endl;


}
