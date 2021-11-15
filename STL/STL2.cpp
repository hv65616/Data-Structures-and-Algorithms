//Nested Vector
#include <bits/stdc++.h>
using namespace std;
void print(vector<pair<int, int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    cout << endl;
}
void print2(vector<int> v1)
{
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
}
int main()
{
    cout << "Pair of Vector";
    vector<pair<int, int>> v = {{1, 2}, {3, 4}}; // Creating a vector of pair with values already inserted
    print(v); //Printing of Vector
    vector<pair<int, int>> v1; //Creating a vector of type pair
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v1.push_back(make_pair(x, y)); //Inserting the pair back into the vector
    }
    print(v1); //Printing of vector
    cout << "Array of Vector";
    int N;
    cin >> N;
    vector<int> V[N]; //Vector of size N
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            V[i].push_back(x); //Pushing elements into a vector array
        }
    }
    for (int i = 0; i < N; i++)
    {
        print2(V[i]);
    }
    cout << "Vector Of Vector" << endl;
    vector<vector<int>> vt; // Creating a vector of vector
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        vector<int> vt1; //This another vector is for the vector of vector
        for (int j = 0; j < x; j++)
        {
            int a;
            cin >> a;
            vt1.push_back(a);
        }
        vt.push_back(vt1);
    }
    return 0;
}