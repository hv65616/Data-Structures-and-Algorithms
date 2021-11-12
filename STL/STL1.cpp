#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++) //v.size()->O(1)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    cout << "Pairs" << endl;
    pair<int, int> p; //Creating of pair p
    p = make_pair(1, 2); //Making a pair of number 1 and 2
    cout << p.first << " " << p.second << endl; //Displaying the first part of pair and second part of pair

    pair<int, int> &p1 = p; //Call by reference of pair p into pair p1
    p1.first = 2; // This will modify the first value of pair p with the value passed
    cout << p.first << " " << p.second << endl;

    pair<int, int> parray[3]; //Creating the integer type pair
    parray[0] = {1, 1}; 
    parray[1] = {2, 2};
    parray[2] = {3, 3};
    for (int i = 0; i < 3; i++)
    {
        cout << parray[i].first << " " << parray[i].second << endl;
    }
    swap(parray[0], parray[2]);  //Swapping the value of parray[2] with values of parray[0]
    for (int i = 0; i < 3; i++)
    {
        cout << parray[i].first << " " << parray[i].second << endl;
    }
    cout << endl;

    cout << "Vectors" << endl;
    vector<int> v; //Initializing the vector v
    int n;
    cout << "Enter the size of vector:" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a); //v.push_back() -> O(1) //Pushing back all values into vector
    }
    printVector(v);
    v.pop_back(); //Remove the last element from the vector 
    printVector(v);
    v.pop_back();
    printVector(v);
    vector<int> v2 = v; //Call by value
    v2.push_back(6);
    printVector(v);
    printVector(v2);
    vector<int> &v3 = v; //Call by refernce
    v3.push_back(7);
    printVector(v);
    printVector(v2);
    printVector(v3);
    return 0;
}