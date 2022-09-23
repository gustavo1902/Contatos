#pragma once
/*
 * person.h
 */
#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

using namespace std;

class Person
{
public:
    string name;
    string email;
    string phone;
    string birthdate;

    Person(string _name, string _email, string _phone, string _birthdate)
    {
        this->name = _name;
        this->email = _email;
        this->phone = _phone;
        this->birthdate = _birthdate;
    }

    bool operator<(Person B)
    {
        return this->name < B.name;
    }
};

#endif