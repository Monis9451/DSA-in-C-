#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

class Node
{
    public:
    string Name;
    string Purpose;
    int CNIC;
    int Priority;
    Node* next;

    Node(string name, string purpose, int cnic, char choice)
    {
        Name = name;
        Purpose = purpose;
        CNIC = cnic;
        switch (choice)
        {
        case 'D':
            Priority = 3;
            break;
        case 'G':
            Priority = 2;
            break;
        case 'S':
            Priority = 1;
            break;
        
        default:
            cout << "Invalid priority" << endl;
            break;
        }
    next = nullptr;
    }
};

class P_Queue
{
    public:
    Node* front = nullptr;
    void enQueue(string name, string purpose, int cnic, char choice)
    {
        Node* New = new Node(name, purpose, cnic, choice);
        if(front == nullptr)
        {
            front = New;
        }
        else
        {
            Node* prev = nullptr;
            Node* curr = front;
            while(front != nullptr)
            {
                if(curr->Priority < New->Priority)
                {
                    break;
                }
                prev = curr;
                curr = curr->next;

            }
            if(prev == nullptr)
            {
                New->next = front;
                front = New;
                return;
            }
            New->next = prev->next;
            prev->next = New;
        }
    }

    void deQueue()
    {
        if(front == nullptr)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            Node* toDel = front;
            front = front->next;
            delete toDel;
        }
    }

    void print()
    {
        if(front == nullptr)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            int count = 1;
            Node* curr = front;
            while(curr != nullptr)
            {
                cout << "\t====================================================================\n";
                cout << "\t--------------COSTUMER " << count << "-----------------------------\n";
                cout << "\t NAME ::" << curr->Name << endl;
                cout << "\t PURPOSE ::" << curr->Purpose << endl;
                cout << "\t CNIC ::" << curr->CNIC << endl;
                curr = curr->next;
                count++;
            }
        }
    }
};

int main()
{
    string name;
    string purpose;
    int cnic;
    bool exit = true;
    P_Queue obj;
    int choice = 0;
    while(exit)
    {
                system("color 0b");
        cout << R"(
        =====================================================================
         ____              _    _                             _
        | __ )  __ _ _ __ | | _(_)_ __   __ _   ___ _   _ ___| |_ ___ _ __ ___
        |  _ \ / _` | '_ \| |/ / | '_ \ / _` | / __| | | / __| __/ _ \ '_ ` _ \
        | |_) | (_| | | | |   <| | | | | (_| | \__ \ |_| \__ \ ||  __/ | | | | |
        |____/ \__,_|_| |_|_|\_\_|_| |_|\__, | |___/\__, |___/\__\___|_| |_| |_|
                                        |___/       |___/
        =======================================================================
        )";
        cout << "\t=================================================================\n";
        cout << "\t------------------MENU------------------------------------------\n";
        cout << "\t=================================================================\n";
        cout << "\t1.ENTER A USER ...........\n";
        cout << "\t2.REMOVE A USET.............\n";
        cout << "\t3.DISPLAY...............\n";
        cout << "\t4.EXIT.....................\n";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        char choice;
        cout << "\tEnter your name ::";
        getline(cin, name);
        cout << "\tEnter your purpose ::";
        getline(cin, purpose);
        cout << "\tEnter your cnic ::";
        cin >> cnic;
        cout << "\tPlease enter the corresponding\n";
        cout << "\tD:: Diamond card\n";
        cout << "\tG:: Gold card\n";
        cout << "\tS:: Silver card\n";
        cin >> choice;
        obj.enQueue(name, purpose, cnic, choice);
        cout << " SECESSFULLY ENTERED\n"; break;
        case 2:
        obj.deQueue();
        cout << "SECESSFULLY REMOVED\n"; break;
        case 3:
        obj.print();
        Sleep(1000);
        break;
        case 4:
        exit = false; break;
        }
        Sleep(2000);
        system("cls");
    }

    return 0;
}