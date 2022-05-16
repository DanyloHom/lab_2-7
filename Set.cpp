#include "Set.h"
#include <iostream>

using namespace std;

Set::Set()
{	
	a.setFirst(0);
	a.setSecond(0);
}

Set::Set(const Set& s)
{
	a.setFirst(s.a.getFirst());
	a.setSecond(s.a.getSecond());
}

Set::Set(BitString b)
{
	a = b;
}

Set& Set::operator=(const Set& s)
{
	a = s.a;
	return *this;
}

Set::operator string() const
{
	return string(a);
}

void Set::setA(unsigned long l, unsigned long r)
{
	a.setFirst(l);
	a.setSecond(r);
}

void Set::Read()
{
	a.Read();
}

void Set::Display()
{
	a.Display();
}

void Set::Init(unsigned long l, unsigned long r)
{
	a.Init(l, r);
}

string Set::toString()
{
	return a.toString();
}

void Set::Exclude(int pos)
{
	if (pos <= 32)
		a.setFirst(a.getFirst() & ~(~(~0 << 1) << pos));
	if (pos > 32 && pos <= 64)
		a.setSecond(a.getSecond() & ~(~(~0 << 1) << pos));
	else cout << "wrong argument" << endl;
}

void Set::Include(int pos)
{
	if (pos <= 32)
		a.setFirst(a.getFirst() | ~(~0 << 1) << pos);
	if (pos > 32 && pos <= 64)
		a.setSecond(a.getSecond() | ~(~0 << 1) << pos);
	else cout << "wrong argument" << endl;
}

int Set::Count()
{
	int count = 0;
	unsigned long l = a.getFirst();
	unsigned long r = a.getSecond();

	while (l) {             //poky l ne stane 0
		count += l & 1;		//dodayemo do count kzhnu odynychku
		l >>= 1;			//rozglyadaemo nastypnyi bit
	}

	while (r) {				//poky r ne stane 0
		count += r & 1;		//dodayemo do count kzhnu odynychku
		r >>= 1;			//rozglyadaemo nastypnyi bit
	}

	return count;
}

Set& Set::operator++()
{
	a++;
	return *this;
}

Set& Set::operator--()
{
	a--;
	return *this;
}

Set Set::operator++(int)
{
	Set tmp(*this);
	a++;
	return tmp;
}

Set Set::operator--(int)
{
	Set tmp(*this);
	a--;
	return tmp;
}



ostream& operator<<(ostream& out, Set& s)
{
	out << s.a;
	return out;
}

istream& operator>>(istream& in, Set& s)
{
	in >> s.a;
	return in;
}

Set Union(Set l, Set r)
{
	Set A;
	A.a = Or(l.a, r.a);

	return A;
}

Set Intersection(Set l, Set r)
{
	Set A;
	A.a = And(l.a, r.a);

	return A;
}

Set Substraction(Set l, Set r)
{
	Set A;
	A.a = XOr(l.a, r.a);

	return A;

}