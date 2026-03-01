#include <iostream>
#include <string>

using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

unsigned fact(unsigned);
unsigned mult(unsigned , unsigned );
unsigned power(unsigned, unsigned);
unsigned product(unsigned, unsigned);
unsigned fibtr(unsigned n, unsigned temp, unsigned goal) {
    // base case 1
    if (n == 0) {
        return 0;
    }

    // base case 2
    else if (n == 1) {
        return temp;
    }
    // recursive case
    return fibtr(n - 1, goal ,temp+goal);
}
unsigned fib(unsigned n)
{
    return fibtr(n, 1, 1);
}
unsigned facttr(unsigned n, unsigned a)
{
    if (n <= 1)
    {
        return a;
    }
    return facttr(n - 1, a * n);
}
unsigned multtr(unsigned x, unsigned y, unsigned total) {
    // base case
    if (y == 0) {
        return total;
    }

    // recursive case
    return multtr(x, y - 1, total + x);
}
unsigned powertr(unsigned x, unsigned y, unsigned total)
{
    // base case
    if (y == 0) {
        return total;
    }

    // recursive case
    return powertr(x, y - 1, total * x);
}
unsigned producttr(unsigned x, unsigned y, unsigned total)
{
    if (x > y) {
        return total;
    }

    // recursive case
    return producttr(x+1, y, total * x);
}
/*******************************************************************************
 * Description:
 * Starting point of the program. Calls various recursive functions that can be
 * optimized using tail recursion.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/
int main() {
    //// try a ridiculous case that won't work without tail recursion
    cout << "6 * 123000 = " << mult(6, 123000) << endl;
    //
    //// these functions can't demonstrate the usefulness of tail recursion
    //// due to data type overflow, but still, good practice
    cout << "3 ^ 10 = " << power(3, 10) << endl;
    cout << "8 * 9 * ... * 15 = " << product(8, 15) << endl;
    cout << "10! = " << fact(10) << endl;
    // without tail recursion, this next call is going to take a while
    cout << "50th Fibonacci number is " << fib(50) << endl;
    cout << "\n--- Edge Cases ---\n";

    //Multiplication with zero
    cout << "0 * 5 = " << mult(0, 5) << endl;
    // Expected: 0

    //  Factorial of 0
    cout << "0! = " << fact(0) << endl;
    // Expected: 1

    // Power with exponent 0
    cout << "5 ^ 0 = " << power(5, 0) << endl;
    // Expected: 1

    // Fibonacci base case
    cout << "fib(0) = " << fib(0) << endl;
    // Expected: 0
    //product
    cout << "product(10, 5) = " << product(10, 5) << endl;
    //Expected:1
    // terminate
    return 0;
}

/*******************************************************************************
 * Function definitions below are NOT tail recursive!
 * TODO: make them tail recursive :)
*******************************************************************************/

unsigned fact(unsigned n) {
   
    
    return facttr(n,1);
}

unsigned mult(unsigned x, unsigned y) {

   return multtr(x, y, 0);
}

unsigned power(unsigned x, unsigned y) {
    return powertr(x, y, 1);
}

unsigned product(unsigned x, unsigned y) {
    return producttr(x, y, 1);
}

