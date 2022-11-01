/*
  Primality test: Check whether the given Number is prime or not. 
  Naive : T(n)=O(n)
  Optimal: T(n)=O(log(n))
  

  Instead of checking the divisor all the way to n check it through root(n) as if a*b=N 
  then one pair is always below root(n) and another is always above root(n)
  
  Eg . 
  For n=12
  divisors are: 1,2,3,4,6,12
  Pair: (1,12) (2,6) (3,4)
  So if we check the values 1 , 2 , 3 then no need to check for other values as one of the factor will always be among 
  1, 2, 3. 
  So we run the loop till sqrt(n) 

*/
#include<bits/stdc++.h>
using namespace std;

bool Primalty_Test(int n)
{
    if(n==1)
    return false;
    
    for(int i=2;i*i<=n;i++)
    if(n%i==0) return false;

    return true;
}

int main()
{
    int n;
    cin>>n;
    cout<<"The Number is Prime: "<<(Primalty_Test(n)?"True":"False");
}