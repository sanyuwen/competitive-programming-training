// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define all(c) c.begin(), c.end()
bool myfunction (int i,int j) { return (i<j); }
bool reverse(int i, int j) {return !(i<j);}
bool compare_as_ints(double i, double j) { return (int)i<(int)j; }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int main () {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

  // using function as comp
  std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

  // using object as comp
  std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

  // print out content:
  std::cout << "myvector contains:";
  tr(myvector,it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  
  double mydoubles[] = {3.14, 1.41, 2.72, 4.67, 1.73, 1.32, 1.62, 2.58};

  std::vector<double> mydoublevector;
  
  mydoublevector.assign(mydoubles,mydoubles+8);

  std::cout << "using default comparison:";
  std::stable_sort (all(mydoublevector));
  tr(mydoublevector,it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  mydoublevector.assign(mydoubles,mydoubles+8);
  
  std::cout << "using 'compare_as_ints' :";
  std::stable_sort (all(mydoublevector), compare_as_ints);
  tr(mydoublevector,it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  
  int a[] = {6,5,4,9,1,2,8,7,3};
  std::vector<int> thirdvector(a,a+9);
  //partial_sort(thirdvector.begin(),thirdvector.begin()+5,thirdvector.end());
  partial_sort(thirdvector.begin(),thirdvector.begin()+5,thirdvector.end(),reverse);
  std::cout << "myvector contains:";
  tr(thirdvector,it)
    std::cout << ' ' << *it;
  std::cout << '\n';


  return 0;
}