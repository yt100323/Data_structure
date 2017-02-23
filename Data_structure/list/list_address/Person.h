#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <ostream>

using namespace std;

class Person
{
	friend ostream &operator<<(ostream &out, const Person &person);
public:
	Person &operator = (Person &person);
	bool operator==(Person &person);
	string name;
	string phone;
};


#endif