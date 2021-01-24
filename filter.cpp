#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

string trim(const string &s)
{
	string const_iterator it = s.begin();
	while (it != s.end() && isspace(*it))
		it++;

	string const_reverse_iterator rit = s.rbegin();
	while (rit.base() != it && isspace(*rit))
		rit++;

	return std string(it, rit.base());
}

	vector<string> &split(const string &s, char delim, vector<std string> &elems) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(trim(item));
		//elems.push_back(item);
	}
	return elems;
}


	vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}


int main()
{
	string ss;
	cout << "Please input a 3CNF formula: " << endl;
	cout << " " << endl;
	//string str = "1v2v-4 ^ -4v2v3 ^ -3v1v2 ^ -1v4v5";
	getline(cin, str);
	char delimiter = '^';
	vector<string> viktor = split(str, delimiter);
	vector<string> viktoria;
	set<string> clauses;
	set<string> distinctVariables;
	delimiter = 'v';
	for (int i = 0; i< viktor.size(); i++) 
	{
		cout << "Clause " << i << ": " << viktor[i] << std::endl;
		viktoria = split(viktor[i], delimiter);
		for (int j = 0; j < viktoria.size(); j++) 
		{
			//std::cout << viktoria[j];
			string s = viktoria[j];
			replace(s.begin(), s.end(), '-', ' '); // replace all '-' to ' '

			distinctVariables.insert(trim(s));
		}
		cout << endl;
	}
	cout << "The distinct variables found in the expr  " << str << " are " << endl;

	for (set<string>iterator i = distinctVariables.begin(); i != distinctVariables.end(); i++) {

		cout << *i << endl;
	}
	system("pause");
}

