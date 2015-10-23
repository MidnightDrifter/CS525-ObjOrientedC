#include <iostream>
#include <string>
//  francis.serina@digipen.edu
using namespace std;

class A {
public:
	A(int xInit);      // conversion constructor
	A();                       // default constructor
	A(const A& other); // copy constructor

					   // operator overload
	A operator+(const A& rhs);
	const A& operator=(const A& rhs);

	string ToString();

private:
	int x;
};

A::A(int xInit) : x(xInit)
{
	cout << "A(int)\n";
}

A::A() : x(0)
{
	cout << "A()\n";
}

A::A(const A& other) {
	x = other.x;
	// x == this->x
	cout << "A(const A&)\n";
}

string A::ToString() {
	return to_string(x);
}

A A::operator+(const A& rhs) {
	cout << "A::operator+\n";

	A n; // new instance
	n.x = x + rhs.x;
	return n; // invokes a copy ctor
}

const A& A::operator=(const A& rhs) {
	x = rhs.x;
	return *this;
}
/*
void main() {
	A a;     // default ctor
	A b = 5; // conversion ctor
	A c(10); // conversion ctor
			 //a = 5;   // assignment operator ATTEMPTS to make rhs type equal to lhs type
			 // since we have an int to A conversion ctor, 5 is converted to A(5)

			 //int x, y, z;
			 //x = (y = (z = 5)); // demonstration that assignment operator returns non-void

	a = c; // Expected Behavior: copy c.x to a.x
	a = b + c; // Expected Behavior: a.x = 15

	cout << "b+b  " << (b + b).ToString() << "\n";
	cout << "done\n";
}*/