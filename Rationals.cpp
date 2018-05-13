#include <iostream>
using namespace std;

class Rational {
private:
	int num;
	int den;
public:
	Rational(int n1, int n2) {
		num = n1;
		den = n2;
	}
	Rational(int whole_number) {
		num = whole_number;
		den = 1;
	}
	Rational() {
		num = 0;
		den = 1;
	}
	void lowestterms() {
		int low;
		if (num < den) {
			low = num;
		}
		else {
			low = den;
		}
		if (low < 0) { low *= -1; }
		for (; low >= 2; low--) {
			if (num%low == 0 && den%low == 0) {
				num /= low;
				den /= low;
				low = 1;
			}
		}
	}
	void normalize() {
		lowestterms();
		if (den < 0) {
			num *= -1;
			den *= -1;
		}
	}

	friend ostream& operator <<(ostream& outs, Rational& number) {
		number.normalize();
		outs << number.num;
		if (number.den > 1) {
			outs << '/' << number.den;
		}
		return outs;
	}
	friend istream& operator >>(istream& ins, Rational& number) {
		char c;
		ins >> number.num;
		ins >> c;
		ins >> number.den;
		return ins;
	}
	//overloading operators
	friend bool operator ==(Rational z1, Rational z2) {
		return(z1.num*z2.den == z2.num*z1.den);
	}
	friend bool operator <(Rational z1, Rational z2) {
		return(z1.num*z2.den < z2.num*z1.den);
	}
	friend Rational operator <=(Rational z1, Rational z2) {
		return(z1.num*z2.den <= z2.num*z1.den);
	}
	friend Rational operator >(Rational z1, Rational z2) {
		return(z1.num*z2.den > z2.num*z1.den);
	}
	friend Rational operator >=(Rational z1, Rational z2) {
		return(z1.num*z2.den >= z2.num*z1.den);
	}
	friend Rational operator +(Rational z1, Rational z2) {
		Rational ans;
		ans.num = z1.num*z2.den + z2.num*z1.den;
		ans.den = z1.den*z2.den;
		ans.lowestterms();
		return ans;
	}
	friend Rational operator -(Rational z1, Rational z2) {
		Rational ans;
		ans.num = z1.num*z2.den - z2.num*z1.den;
		ans.den = z1.den*z2.den;
		ans.lowestterms();
		return ans;
	}
	friend Rational operator *(Rational z1, Rational z2) {
		Rational ans;
		ans.num = z1.num * z2.num;
		ans.den = z1.den * z2.den;
		ans.lowestterms();
		return ans;
	}
	friend Rational operator /(Rational z1, Rational z2) {
		Rational ans;
		ans.num = z1.num * z2.den;
		ans.den = z1.den * z2.num;
		ans.lowestterms();
		return ans;
	}
};
int main()
{
	cout << "Testing declarations" << endl;
	cout << "Rational x, y(2), z(-5,-6), w(1,-3);" << endl;
	Rational x, y(2), z(-5, -6), w(1, -3);
	cout << "z = " << z << ", y = " << y << ",  z = " << z
		<< ", w = " << w << endl;

	cout << "Testing >> overloading: \nEnter "
		<< "a fraction in the format "
		<< "integer_numerator/integer_denominator"
		<< endl;
	cin >> x;
	cout << "You entered the equivalent of: " << x << endl;
	cout << z << " -  (" << w << ") = " << z - w << endl;

	cout << "Testing the constructor and normalization routines: " << endl;
	y = Rational(-128, -48);
	cout << "y =Rational(-128, -48) outputs as " << y << endl;
	y = Rational(-128, 48);
	cout << "y =Rational(-128, 48)outputs as " << y << endl;
	y = Rational(128, -48);
	cout << "y = Rational(128, -48) outputs as " << y << endl;
	Rational a(1, 1);
	cout << "Rational a(1,1); a outputs as: " << a << endl;
	Rational ww = y*a;
	cout << y << " * " << a << " = " << ww << endl;

	w = Rational(25, 9);
	z = Rational(3, 5);
	cout << "Testing arithmetic and relational "
		<< " operator overloading" << endl;
	cout << w << " * " << z << " = " << w * z << endl;
	cout << w << " + " << z << " = " << w + z << endl;
	cout << w << " - " << z << " = " << w - z << endl;
	cout << w << " / " << z << " = " << w / z << endl;

	cout << w << " <  " << z << " = " << (w < z) << endl;
	cout << w << " < " << w << " = " << (w < w) << endl;
	cout << w << " <= " << z << " = " << (w <= z) << endl;
	cout << w << " <= " << w << " = " << (w <= w) << endl;

	cout << w << " >  " << z << " = " << (w > z) << endl;
	cout << w << " > " << w << " = " << (w > w) << endl;
	cout << w << " >= " << z << " = " << (w >= z) << endl;
	cout << w << " >= " << w << " = " << (w >= w) << endl;

	w = Rational(-21, 9);
	z = Rational(3, 5);
	cout << w << " * " << z << " = " << w * z << endl;
	cout << w << " + " << z << " = " << w + z << endl;
	cout << w << " - " << z << " = " << w - z << endl;
	cout << w << " / " << z << " = " << w / z << endl;
	cout << w << " <  " << z << " = " << (w < z) << endl;
	cout << w << " < " << w << " = " << (w < w) << endl;
	cout << w << " <= " << z << " = " << (w <= z) << endl;
	cout << w << " <= " << w << " = " << (w <= w) << endl;

	cout << w << " >  " << z << " = " << (w > z) << endl;
	cout << w << " > " << w << " = " << (w > w) << endl;
	cout << w << " >= " << z << " = " << (w >= z) << endl;
	cout << w << " >= " << w << " = " << (w >= w) << endl;

	char dummy;

	cin >> dummy;
	return 0;
}
