#include <iostream>
#include <math.h>
//performs multiplications using the karatsuba technique on two longegers

// ex.  
//  X = 5678
//  Y = 1234
// a = 56, b = 78, c = 12, d = 34
//
// step1: Compute a*c
// step2: Compute b*d
// step3: Compute (a+b)(c+d)
// step4: Compute step3 - step2 - step1

// finally compute (10^(n/2)*a + b) * (10^(n/2)c + d)

using namespace std;

long getLength(long x){
	x = abs(x);  
	return (x < 10 ? 1 :   
		(x < 100 ? 2 :   
		(x < 1000 ? 3 :   
		(x < 10000 ? 4 :   
		(x < 100000 ? 5 :   
		(x < 1000000 ? 6 :   
		(x < 10000000 ? 7 :  
		(x < 100000000 ? 8 :  
		(x < 1000000000 ? 9 :  
		10)))))))));  
}

long karatsubaRecursion(long x, long y){

if(getLength(x)<3 || getLength(y) < 3) return x*y;
//calculate a, b, c, d
long xdigits = getLength(x);
long ydigits = getLength(y);

long a = x/(long)(pow(10, xdigits/2+1));
long b = x%(long)(pow(10, xdigits/2+1));
long c = y/(long)(pow(10, ydigits/2+1));
long d = y%(long)(pow(10, ydigits/2+1));

cout << "a, b, c, and d = " << a << " " << b << " " << c << " " << d << endl;

//compute a*c

long ac = karatsubaRecursion(a, c);
long bd = karatsubaRecursion(b, d);

long step3 = karatsubaRecursion(a+b, c+d);
long step4 = step3-bd-ac;

double N = max(ydigits, xdigits)/2 + max(ydigits,xdigits)%2;

return pow(10, N*2)*ac + pow(10, N)*step4 + bd;


}

int main(){

long x = 567;
long y = 123;
cout << karatsubaRecursion(x, y);

}
