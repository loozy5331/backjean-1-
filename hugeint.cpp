#include <iostream>
#include <array>
#include <iostream>
#include <string>
#include <cctype>// isdigit function prototype
using namespace std;

class HugeInt
{
	friend std::ostream &operator<<(std::ostream &, const HugeInt &); // 연산자 오버로딩
public:
	static const int digits = 30; 
	HugeInt(long = 0);
	HugeInt(const std::string &); 
	HugeInt operator+(const HugeInt &) const;

	HugeInt operator+(int) const;

	HugeInt operator+(const std::string &) const;
private:
	std::array< short, digits > integer;
};

HugeInt::HugeInt(long value)
{
	for (short &element : integer)
		element = 0;

	// place digits of argument into array 
	for (size_t j = digits - 1; value != 0 && j >= 0; --j)
	{
		integer[j] = value % 10;
		value /= 10;
	} 
}
 
HugeInt::HugeInt(const string &number)
{
	// initialize array to zero
	for (short &element : integer)
		element = 0;

	// place digits of argument into array
	size_t length = number.size();

	for (size_t j = digits - length, k = 0; j < digits; ++j, ++k)
		if (isdigit(number[k])) // ensure that character is a digit
			integer[j] = number[k] - '0';
} // end HugeInt conversion constructor

  // addition operator; HugeInt + HugeInt
HugeInt HugeInt::operator+(const HugeInt &op2) const
{
	HugeInt temp; // temporary result
	int carry = 0;

	for (int i = digits - 1; i >= 0; --i)
	{
		temp.integer[i] = integer[i] + op2.integer[i] + carry;

		
		if (temp.integer[i] > 9)
		{
			temp.integer[i] %= 10;  
			carry = 1;
		} 
		else 
			carry = 0;
	} 

	return temp; 
} 

  // addition operator; HugeInt + int
HugeInt HugeInt::operator+(int op2) const
{
	return *this + HugeInt(op2);
} 

 
HugeInt HugeInt::operator+(const string &op2) const
{
	
	return *this + HugeInt(op2);
} 

  // overloaded output operator
ostream& operator<<(ostream &output, const HugeInt &num)
{
	size_t i;

	for (i = 0; (i < HugeInt::digits) && (0 == num.integer[i]); ++i)
		; // skip leading zeros

	if (i == HugeInt::digits)
		output << 0;
	else
		for (; i < HugeInt::digits; ++i)
			output << num.integer[i];

	return output;
} // end function operator<<
/*
int main()
{
	HugeInt n1(7654321);
	HugeInt n2(7891234);
	HugeInt n3("99999999999999999999999999999");
	HugeInt n4("1");
	HugeInt n5;

	cout << "n1 is " << n1 << "\nn2 is " << n2
		<< "\nn3 is " << n3 << "\nn4 is " << n4
		<< "\nn5 is " << n5 << "\n\n";

	n5 = n1 + n2;
	cout << n1 << " + " << n2 << " = " << n5 << "\n\n";

	cout << n3 << " + " << n4 << "\n= " << (n3 + n4) << "\n\n";

	n5 = n1 + 9;
	cout << n1 << " + " << 9 << " = " << n5 << "\n\n";

	n5 = n2 + "10000";
	cout << n2 << " + " << "10000" << " = " << n5 << endl;
} // end main
*/
