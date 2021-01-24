#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>

struct  clause
{
	int var1;
	int var2;
	int var3;
};

using namespace std;

int main()
{
	clause temp;
	int obj1, obj2, obj3;
	vector<clause> clauses;
	cout << "Please input a 3CNF formula: " << endl;
	while(cin >> obj1)
	{
		cin>>obj1;
		cin>>obj2;
		cin>>obj3;
		temp.var1 = obj1;
		temp.var2 = obj2;
		temp.var3 = obj3;
		clauses.push_back(temp);
	}
	for(int i = 0; i < clauses.size(); i++)
	{
		cout << clauses[i] << endl;
	}
}

