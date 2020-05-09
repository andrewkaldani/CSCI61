//source: https://www.geeksforgeeks.org/enumeration-of-binary-trees/
// based on summation equation f(i-1)*f(n-i)
#include <iostream>
#include <cmath>
int binary(int n);
using namespace std;
int main()
{
  // 5 trees with 3 nodes
  //14 with 4 nodes
  int i;
  cout<<"Enter a number: "<<endl;
  cin>>i;
  cout<<"There are "<<binary(i)<<" possible binary trees with "
  <<i<<" nodes."<<endl;

}
int binary(int n)
{
  if(n==0||n==1){
    return 1;
  }

  else{
    int i =1;
    int sum=0;
    while(i<=n){
     sum += binary(i-1)*binary(n-i);
     i++;
   }
    return sum;
  }
}
