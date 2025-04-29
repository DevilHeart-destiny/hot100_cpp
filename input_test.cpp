#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main()
{
    vector<int> res;
    // method 1
    // string line;
    // getline(cin,line);
    // istringstream iss(line);
    // int num;
    // while(iss >> num)
    // {
    //     res.push_back(num);
    // }

    // method 2
    int num;
    while(cin >> num)
    {
        res.push_back(num);
        if(cin.get() == '\n') break;
    }

    for(auto& r : res)
    {
        cout << r << ' ';
    }
    return 0;
}