#include <iostream>

void f(int& i) { std::cout << "lvalue ref: " << i << "\n"; }
void f(int&& i) { std::cout << "rvalue ref: " << i << "\n"; }

// In C++0x, we could use a normal or lvalue reference to bind temporary object, but only if it was const:
// const int& val = getValue(); // OK
// int& val = getValue(); // NOT OK

/*
In C++11, however, the rvalue reference lets us bind a mutable reference to an rvalue,
but not an lvalue. In other words,
rvalue references are perfect for detecting whether a value is a temporary object or not.
*/

/*
 * const int&& val = getValue(); // OK
 * int&& val = getValue(); //  OK
 * */

/*The printReference() function taking a const lvalue reference will accept any argument whether it be an lvalue or an rvalue.*/
void printReference (const int& value)
{
    std::cout << value;
}

/* the second overloaded printReference*() taking only an rvalue reference. */
void printReference (int&& value)
{
    std::cout << value;
}

int getValue () // return by value as temporary object
{
    int ii = 10;
    return ii;
}

int main()
{
    int i = 77;
    f(i);    // lvalue ref called
    f(99);   // rvalue ref called

    f(std::move(i));  // rvalue ref called,

    std::cout << getValue(); // The getValue() is an rvalue. It is a temporary object. Note that the value being returned is not a reference to ii, but it's just a temporary value.


    return 0;
}

