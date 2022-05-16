#pragma once
#include <string>

using namespace std;

class BitString
{
private:

	unsigned long first;
	unsigned long second;

public:
	BitString(unsigned long f, unsigned long s);
	BitString(const BitString& b);
	BitString();

	BitString& operator =(const BitString& b);
	operator string() const;
	friend ostream& operator << (ostream& out, BitString& b);
	friend istream& operator >> (istream& in, BitString& b);



	unsigned long getFirst()const { return first; }
	unsigned long getSecond()const { return second; }

	void setFirst(unsigned long f) { first = f; }
	void setSecond(unsigned long s) { second = s; }

	void Read();
	void Display();
	void Init(unsigned long l, unsigned long r);
	string toString();

	void Not();
	friend BitString And(BitString l, BitString r);
	friend BitString Or(BitString l, BitString r);
	friend BitString XOr(BitString l, BitString r);

	void ShiftLeft(int pos);
	void ShiftRight(int pos);

	BitString& operator++();
	BitString& operator--();
	BitString operator++(int);
	BitString operator--(int);


};