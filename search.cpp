#include <iostream>     
#include <algorithm>    
#include <vector>     
using namespace std;
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define all(c) c.begin(), c.end()
#define vi vector<int>
#define viter vector<int>::iterator

int main () {
  int myints[] = {32,71,12,45,26,80,53,33};
  vi a(myints,myints+8);
  sort(all(a));
  viter low = lower_bound(all(a),32);  //first element does not less than 32
  viter up = upper_bound(all(a),32);  //first element greater than 32
  cout<<*low<<endl;
  cout<<*up<<endl;
  return 0;
}