#include <iostream>
using namespace std;
class Complex
{
private:
double real;
double img;
public:
Complex()
{
this->real = 0;
this->img = 0;
}
Complex(double real, double img)
{
this->real = real;
this->img = img;
}
Complex operator+(const Complex &other)
{
return Complex(real + other.real, img + other.img);
}
Complex operator*(const Complex &other)
{
double res_real = (real * other.real) - (img * other.img);
double res_img = (real * other.img) + (img * other.real);
return Complex(res_real, res_img);
}
friend ostream &operator<<(ostream &out, Complex &complex)
{
cout << complex.real;
if (complex.img >= 0)
{
out << " + " << complex.img << "i";
}
else
{
out << " - " << -complex.img << "i";
}
return out;
}
friend istream &operator>>(istream &in, Complex &complex)
{
cout << "Enter real part: ";
in >> complex.real;
cout << "Enter imaginary part: ";
in >> complex.img;
return in;
}
};
int main()
{
Complex c1, c2;
cout << "Enter first complex number: \n";
cin >> c1;
cout << "Enter second complex number: \n";
cin >> c2;
Complex sum = c1 + c2;
Complex product = c1 * c2;
cout << "Sum: " << sum << endl;
cout << "Product: " << product << endl;
return 0;
}
