/*
Sieve of Erathosthenes: If we need to find whether the number is prime or not in a list of numbers then individual
primality exceeds the time as for each query the time taken is O(sqrt(n)).

Instead of working on the query elemnts we will generate all the prime numbers from 1 to N
(N is the maximum among query or the maximum range of value).

// For this
        1) We will need an array of N+1 elements and each index represent the number itself. We will mark all the
        values in the array as 1 initially.
        2) Mark the index 1 as 0 because it is a composite number.
        3) Mark values divisible by 2 as 0 except 2 cause it is prime.
        4) Similarily Mark values divisible by 3 , 4 , 5 and so on except them.
        5) If a number is already marked as 0 then no need to find its multiple as they will be already covered.
        6) Go like this till the last elements or for optimality sqrt(n) elements.

    **Note: we can further optimize by taking the multiple from square of number.
    Example : for multiple of 7
    We need not check for 14,21,28,35,42 as they are less than square of 7. Because when we covered 2,3,4,5,6 we already
    covered values less than square of 7.

    **Note: So we start our for loop from nth multiple till the value is less than maximum n.

    Preprocessing Time: O(Nlog(log N))
    Answer Query : O(1)
    Space :O(N)
*/

#include <bits/stdc++.h>
using namespace std;

void Sieve_of_eratosthenes(vector<int> &isPrime)
{
    int n = isPrime.size();
    // element 0 and 1 is not prime
    isPrime[0]=0;
    isPrime[1] = 0;

    // For loop till (n/2)
    // We will start from 2 as prime can have multiple of 1 in it.
    for (int i = 2; i*i<=n ; i++)
    {
        // Mark all the multiple to 0
        // we will start multiple from ith as previous one are already covered
        //Check for only values marked as 1 cause values already declared composite 
        //so its multiple also gets covered already
        if (isPrime[i])
        {
            for(int j=i*i;j<=n;j+=i)
            isPrime[j]=0;
        }
    }
}

int main()
{

    vector<int> isPrime(1000000, 1);
    Sieve_of_eratosthenes(isPrime);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (isPrime[n] == 1)
            cout << "Prime" << endl;
        else
            cout << "Composite" << endl;
    }
}