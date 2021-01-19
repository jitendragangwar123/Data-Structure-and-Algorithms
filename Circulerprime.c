#include<stdio.h> 
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>
bool isPrime(int n) 
{ 
	if (n <= 1) 
		return false; 
	if (n <= 3) 
		return true; 
		
		
	if (n % 2 == 0 || n % 3 == 0) 
		return false; 

	for (int i = 5; i * i <= n; i = i + 6) 
		if (n % i == 0 || n % (i + 2) == 0) 
			return false; 

	return true; 
} 

// Function to check if the number is circular  prime or not. 
bool checkCircularprime(int N) 
{ 
	// Count digits. 
	int count = 0, temp = N; 
	while (temp) { 
		count++; 
		temp /= 10; 
	} 

	int num = N; 
	while (isPrime(num)) { 
		int rem = num % 10; 
		int div = num / 10; 
		num = (pow(10, count - 1)) * rem + div; 

		if (num == N) 
			return true; 
	} 

	return false; 
} 

int main() 
{ 
	int N;
	scanf("%d",&N);
	
	if(N<=0)
	printf("-1");
	
	else if(checkCircularprime(N)) 
		printf("1");
	else
		printf("0");
    
	return 0; 
} 
