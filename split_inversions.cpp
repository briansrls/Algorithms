#include <vector>
#include <iostream>
using namespace std;

vector<int> Merge(vector<int> &B, vector<int> &C)
{
  int bcount = 0;
  int ccount = 0;
  vector<int> A(0, A.size()+C.size());
  for(int i = 0; i < A.size(); i++)
  {
    if(bcount > B.size()-1)
    {
     copy(C.begin()+ccount, C.end(), A.begin()+i);
     return A;
    }
    if(ccount > C.size()-1)
    {
      copy(B.begin()+bcount, B.end(), A.begin()+i);
      return A;
    }
    if(B[bcount] < C[ccount])
    {
      A[i] = B[bcount];
      bcount++;
    }
    else
    {
      A[i] = C[ccount];
      ccount++;
    }
  }
}

vector<int> MergeSort(vector<int> A)
{
  if(A.size()/2 < A.size()){
    vector<int> B(A.begin(), A.begin()+A.size()/2);
    vector<int> C(A.begin()+A.size()/2+1, A.end());
    MergeSort(B);
    MergeSort(C);
    return Merge(B, C);
  }
}

int main()
{

  vector<int> A;
  A = {1, 2, 3, 4, 1, 2, 3, 4};
  A = MergeSort(A);
  for(std::vector<int>::iterator it = A.begin(); it!=A.end(); ++it)
  	cout << *it << " ";
  cout << endl;
}
