/*Imagine a publishing company which does marketing for book and audio cassette versions.
Create a class publication that stores the title (a string) and price (type float) of publications.
From this class derive two classes: book which adds a page count (type int) and tape which adds
a playing time in minutes (type float).

Write a program that instantiates the book and tape class, allows user to enter data and displays
the data members. If an exception is caught, replace all the data member values with zero
values.
#Approach
1.class:Publication
data members:title,price
member functions: Addd(), Display()'

Class: Book
data members: page_count
member functions: Add_book(), display_book()

class: Tape
data members: play_time
member function: add_tape(), display_tape()
*/
#include <iostream>
using namespace std;

class Publication
{
private:
    string title;
    float price;

public:
    void add()
    {
        cout << "Enter Publication Information: " << endl;
        cout << "Enter Title of Publication: " << endl;
        cin.ignore();        // to clear input buffer
        getline(cin, title); // used for big title along with spaces
        cout << "Enter Price of Publication:" << endl;
        cin >> price;
    }
    void display()
    {
        cout << "---------------------------------" << endl;
        cout << "Title of Publication    :" << title << endl;
        cout << "Publication Price       :" << price << endl;
    }
};
class book : public Publication
{
private:
    int page_count;

public:
    void add_book()
    {
        try
        {
            add(); // call function of base class
            cout << "Enter Page Count of Book   : " << endl;
            cin >> page_count;

            if (page_count <= 0)
            {
                throw page_count;
            }
        }
        catch (...)
        {
            cout << "Invalid page count....." << endl;
            page_count = 0;
        }
    }
    void display_book()
    {
        display(); // call function of base class
        cout << "Page count    : " << page_count << endl;
        cout << "--------------------------------------" << endl;
    }
};

class tape : public Publication
{
private:
    float play_time;

public:
    void add_tape()
    {
        try
        {
            add(); // call function of base class
            cout << "Enter play duration    : " << endl;
            cin >> play_time;

            if (play_time <= 0)
            {
                throw play_time;
            }
        }
        catch (...)
        {
            cout << "Invalid play time....." << endl;
            play_time = 0;
        }
    }
    void display_tape()
    {
        display(); // call function of base class
        cout << "Play Time    : " << play_time << endl;
        cout << "--------------------------------------" << endl;
    }
};
int main()
{
    book b1[10];
    tape t1[10];
    int choice = 0, b_count = 0, t_count = 0;
    do
    {
        cout << " * * *  P U B L I C A T I O N   I N F O R M A T I O N   S Y S T E M  * * *" << endl;
        cout << "-------- M E N U ---------" << endl;
        cout << "1. Add Information to Books " << endl;
        cout << "2. Add Information to Tapes " << endl;
        cout << "3. Display Information of Books " << endl;
        cout << "4. Display Information of Tapes " << endl;
        cout << "5. Exite " << endl;
        cout << " Enter Choice :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            b1[b_count].add_book();
            b_count++;
            break;
        case 2:
            t1[t_count].add_tape();
            t_count++;
            break;
        case 3:
            cout << "* * * PUBLICATION INFORMATION SYSTEM (BOOKS) * * *" << endl;
            for (int j = 0; j < b_count; j++)
            {
                b1[j].display_book();
            }
            break;
        case 4:
            cout << "* * * PUBLICATION INFORMATION SYSTEM (TAPES) * * *" << endl;
            for (int j = 0; j < t_count; j++)
            {
                t1[j].display_tape();
            }
            break;
        case 5:
            exit(0);
        }
    } while (choice != 5);

    return 0;
}

