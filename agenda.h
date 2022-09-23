#pragma once
/*
 * agenda.h
 */
#ifndef AGENDA_H_
#define AGENDA_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "person.h"

using namespace std;

class Agenda
{
public:
    vector<Person> contacts;

    void load(string filename)
    {
        ifstream input(filename);

        string line;
        while (getline(input, line))
        {
            // Lendo os valores do arquivo
            vector<string> words;
            words.clear();
            string tmp = "";
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] == ',')
                {
                    words.push_back(tmp);
                    tmp = "";
                }
                else
                {
                    tmp += line[i];
                }
            }

            if (tmp.size() > 0)
            {
                words.push_back(tmp);
            }

            contacts.push_back(Person(words[0], words[1], words[2], words[3]));
        }

        input.close();
    }

    void save()
    {

        ofstream file("contacts.csv");

        for (int i = 0; i < contacts.size(); i++)
        {
            file << contacts[i].name << "," << contacts[i].email << "," << contacts[i].phone << "," << contacts[i].birthdate;

            if (i < contacts.size() - 1)
            {
                file << endl;
            }
        }

        file.close();
    }

    void sort_contacts()
    {
        sort(contacts.begin(), contacts.end());
    }

    void print()
    {

        cout << "----------------------------------" << endl;
        cout << "Name"
             << "\t\t"
             << "Email"
             << "\t\t\t"
             << "Phone"
             << "\t\t\t"
             << "Birthdate" << endl;
        for (int i = 0; i < contacts.size(); i++)
        {
            cout << contacts[i].name << "\t" << contacts[i].email << "\t" << contacts[i].phone << "\t\t" << contacts[i].birthdate << endl;
        }
        cout << "----------------------------------" << endl;
    }

    void detail(string name)
    {
        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].name == name)
            {
                cout << "----------------------------------" << endl;
                cout << "Name: " << contacts[i].name << endl;
                cout << "Email: " << contacts[i].email << endl;
                cout << "Phone: " << contacts[i].phone << endl;
                cout << "Birthdate: " << contacts[i].birthdate << endl;
                cout << "----------------------------------" << endl;
                return;
            }
        }

        cout << "Essa pessoa nao existe." << endl;
    }

    void remove(string name)
    {
        int position = -1;

        for (int i = 0; i < contacts.size(); i++)
        {
            if (contacts[i].name == name)
            {
                contacts.erase(contacts.begin() + i);
                return;
            }
        }

        cout << "Essa pessoa nao existe." << endl;
    }
};

#endif