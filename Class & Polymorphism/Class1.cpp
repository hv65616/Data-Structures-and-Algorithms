#include <iostream>
using namespace std;
class Student
{
    string name;

public:
    int age;
    bool gender;
    Student()
    {
        cout << "Default Constructor" << endl;
    }
    Student(string s, int a, bool g)
    {
        name = s;
        age = a;
        gender = g;
    }
    Student(Student &a)
    {
        cout << "Copy Constructor" << endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }
    ~Student()
    {
        cout << "Destructor Called" << endl;
    }
    void setter(string s)
    {
        name = s;
    }
    void getter()
    {
        cout << name << endl;
    }
    void printInfo()
    {
        cout << "-----" << endl;
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
    }
    bool operator==(Student &a)
    {
        if (name == a.name && age == a.age && gender == a.gender)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    // Student arr[3];
    // for (int i = 0; i < 3; i++)
    // {
    //     string s;
    //     cout << "Name: ";
    //     cin >> s;
    //     arr[i].setter(s);
    //     cout << "Gender: ";
    //     cin >> arr[i].gender;
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     arr[i].printInfo();
    // }
    // arr[1].getter();

    Student a("Himanshu", 20, 1);
    // a.printInfo();
    Student b;
    Student c(a);
    // c.printInfo();
    if (c == a)
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not Same" << endl;
    }
    return 0;
}