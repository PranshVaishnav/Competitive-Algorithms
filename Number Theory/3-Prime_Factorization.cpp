/*
  Prime Factorization: We need to print all the prime factors in terms of power of a given Number

  For example N=48
  then prime factoriztion will be (2^4)*(3^1)

  Brute Force:
          Step 1) Take a for loop till N to get all the factors which could be possible.
          Step 2) if i divides N completely increment a counter++ and Divide N by i simultaneously.
          Step 3) Print the number as i ^ counter and then make counter as 0 again .


          Time Complexity: O(n) // approx

  Optimized : We know that in a composite number one of the prime divisor is less than sqrt(n).
  In other words lets take n=100.
  so we know that minimum power we could have of a factor is 2 . (Power 1 means the same number).
  eg. 100=(10^2) so we need to check for only till sqrt(n) in first for loop.

  eg 2 . if number is 6125 is (5^3)*(7^2)
         we know that only possible greater prime factor could be 78 as 78^2 is approx 6125

  This will optimize the code to time complexity of O(sqrt(n))
  Note* : lets say a number we got at end is a single power number say 5
          then we need to print it as (N^1).{if N>1}


            Time Complexity: O(sqrt(n)) 




*/

#include <bits/stdc++.h>
using namespace std;

void getFactor()
{
    int n;
    cin >> n;

    // For loop till sqrt(n)
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            cout << "(" << i << "^" << cnt << ")"
                 << "*";
        }
    }

    // if at end the n does not becomes 0 means it has single power of that n left.
    // we do note take n==1 as no need to add (1^1) to any number the result remains same and it is also not prime

    if (n > 1)
        cout << "(" << n << "^" << 1 << ")" << endl;

    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        getFactor();
    }
}
