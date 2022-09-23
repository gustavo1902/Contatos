#include <iostream>
#include "agenda.h"

using namespace std;

int main()
{
    Agenda agenda;

    agenda.load("contacts.csv");

    string contact;
    int operation = -1;
    string name, email, phone, birthdate;

    while (operation != 6)
    {
        cout << "Ola, bem vindo a Agenda de Contatos" << endl;
        cout << "O que voce gostaria de fazer?" << endl;

        cout << "1 - Listar contatos" << endl;
        cout << "2 - Detalhar contato" << endl;
        cout << "3 - Adicionar contato" << endl;
        cout << "4 - Remover contato" << endl;
        cout << "5 - Salvar mudancas" << endl;
        cout << "6 - Sair" << endl;

        cin >> operation;

        switch (operation)
        {
        case 1:
            agenda.sort_contacts();
            agenda.print();
            break;
        case 2:
            cout << "Digite o nome do contato que voce quer detalhar." << endl;
            cin >> contact;
            agenda.detail(contact);
            break;
        case 3:
            cout << "Digite as informacoes na seguinte ordem: nome, email, telefone, data de nascimento." << endl;
            cin >> name >> email >> phone >> birthdate;
            agenda.contacts.push_back(Person(name, email, phone, birthdate));
            break;
        case 4:
            cout << "Digite o nome do contato que voce quer remover." << endl;
            cin >> contact;
            agenda.remove(contact);
            break;
        case 5:
            agenda.save();
            cout << "Mudancas salvas" << endl;
            break;
        case 6:
            break;
        default:
            break;
        }
    }

    return 0;
}