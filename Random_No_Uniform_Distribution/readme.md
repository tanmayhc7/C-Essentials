Task 1
Implement a function coin_flip(…). The function takes no input arguments and returns a number: 0 or 1.  
coin_flip(…) should be designed such that the probability of returning a 0 or a 1 is the same. 
That is to say, coin_flip(…) should have a uniform distribution.
```
unsigned int coin_flip() {
    //fill in code here (feel free to use standard C/C++ libraries)
}
```
Task 2
Implement a function custom_random(…). custom_random(…) takes an integer N and outputs a random number between 1 and N (inclusive). 
•	custom_random(…) should return numbers uniformly distributed across the range: 1 to N (inclusive). 
•	You must use coin_flip(…) from step one as the only source for randomness for custom_random(…).
That is to say: do not call a different random number generator directly in custom_random(…).
```
unsigned int custom_random(unsigned int N){
//fill in code here (use coin_flip(…) from step one)
//do not call a random number generator directly
}
```
•	Display the results to shows the distribution produced by custom_random(10)is uniform. Let N= 10, use 20000 samples. 
•	Only source of randomness can be coin_flip(…).
•	Develop a test case to show that the function custom_random(…) has a uniform distribution between 1 and N (inclusive). 
