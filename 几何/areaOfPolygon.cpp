#include<iostream>
#include<numeric>
#include<cmath>
using namespace std;

#define m 1000
double a[m],b[m];

//caculate area of a simple polygon with n sides and coordinates of x[0...n-1], y[0...n-1] 
//If the points are labeled sequentially in the counterclockwise direction, 
//then the sum of the above determinants is positive and the absolute value signs can be omitted;
// if they are labeled in the clockwise direction, the sum of the determinants will be negative.
double area(int n){
	a[n]=a[0];
	b[n]=b[0];
	return 0.5*abs(inner_product(a,a+n,b+1,0)-inner_product(a+1,a+n+1,b,0));
} 

int main(){
	int n=4;
	a[0]=a[1]=1;
	a[2]=a[3]=-1;
	b[0]=b[3]=-1;
	b[1]=b[2]=1;
	a[0]=1;b[0]=0;
	cout<<area(4)<<endl;
	return 0;
}