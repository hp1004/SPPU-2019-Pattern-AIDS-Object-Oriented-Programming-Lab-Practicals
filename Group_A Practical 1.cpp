/*Implement a class Complex which represents the Complex Number data type.
Implement the following
1. Constructor (including a default constructor which
creates the complex number 0+0i).
2. Overload operator+ to add two complex
numbers.
3. Overload operator* to multiply two complex numbers.
4. Overload operators << and >> to print and read Complex Numbers. */
#include <iostream>
using namespace std;
class complex
{
public:
    // data members of complex number
    float x; // real part
    float y; // imaginary part
    // create constructor--->defualt constructor
    complex()
    {
        x = 0;
        y = 0;
    }
    // declaring methods operator overloading
    complex operator+(complex);
    complex operator*(complex);
    //passing object of istream as a input
    friend istream &operator >>(istream &input, complex &t)
    {
        cout << "Enter the real part" << endl;
        cin >> t.x;
        cout << "Enter the imaginary part" << endl;
        cin >> t.y;
    }
    friend ostream &operator <<(ostream &output, complex &t)
    {
        output << t.x << "+" << t.y << "i\n";
    }
};
complex complex::operator+(complex c)
{
    complex temp;
    temp.x = x + c.x;
    temp.y = y + c.y;
    return (temp);
}
complex complex::operator*(complex c)
{
    complex temp2;
    temp2.x = (x * c.x) - (y * c.y);
    temp2.y = (y * c.y) - (x * c.x);
    return (temp2);
}
int main()
{
    complex c1, c2, c3, c4;
    cout << "Defualt constructor value= ";
    cout<<c1;
    cout << "Enter the 1st number: " << endl;
    cin >> c1;
    cout << "Enter the 2nd number: " << endl;
    cin >> c2;
    c3 = c1 + c2;
    c4 = c1 * c2;
    cout << "The first number is ";
    cout << c1;
    cout << "\nThe second number is ";
    cout << c2;
    cout << "\nAddition is: ";
    cout << c3;
    cout << "\nMultiplication is: ";
    cout << c4;
    return 0;
}
