/*
Algorithm:
n!

int result

find prime numbers between 2 and n //Sieve of Eratosthenes

for each prime number p
	for 1 .. logp(n)
		result += n/(p^i)
*/

#include <iostream>
#include <cmath>
using namespace std;

int perform_sieve(int data);

int main(){
    int n;
    int result = 0;

    //TODO: Change to read from a file
    cout << "Enter number: ";
    cin >> n;
    result = perform_sieve(n);
    cout << "Result is: " << result << endl;
}

int perform_sieve(int n){
	
	int result = 0;
	bool primes[n+1];

	for(int i = 0; i < n+1; i++){
 		primes[i] = true;
  	  }

 	   primes[0] = false;
 	   primes[1] = false;

 	   int p = 2;

	    while(p <= n){
	        for(int i = p+p; i < n + 1; i += p){
 	           primes[i] = false;
  	      }

   	     int maxI = log(n)/log(p);
    	    for(int i = 1; i < maxI + 1; i++){
     	       result += n/(pow(p, i));
    	    }

    	    do{
      	      p++;
      	  } while(primes[p] == false);
   	 }
	return result;
}
