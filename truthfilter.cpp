#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

string trim(const string &s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && isspace(*it))
		it++;

	string::const_reverse_iterator rit = s.rbegin();
	while (rit.base() != it && isspace(*rit))
		rit++;

	return string(it, rit.base());
}

	
vector<string> &split(const string &s, char delim, vector<string> &elems) 
{
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) 
	{
		elems.push_back(trim(item));
		//elems.push_back(item);
	}
	return elems;
}


	
vector<string> split(const string &s, char delim) 
{
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}

	
vector<vector<int> > getTruthTable(int n) 
{
	// n is the size of the element set
	// This will produce all the possible combinations of truth tables for that size
	int rows = (int)pow(2, n);
	int value = 0;
	vector<int> row;
	vector<vector<int> > truthValues;
	for (int i = 0; i < rows; i++) {
		cout << " " << i+1 << "  ";
		for (int j = n - 1; j >= 0; j--) {
			value = (i / (int)pow(2, j)) % 2;
			row.push_back(value);
			cout <<  value << " ";
		}
		truthValues.push_back(row);
		row.clear();
		cout << endl;
	}

	return truthValues;
}



int main()
{
	string ss, str;
	cout << "Please input a 3CNF using integers starting at 1: " << endl;
	//string str = "-1v-2v-4 ^ -4v2v3 ^ -3v1v2 ^ -1v4v5";
	getline(cin, str);
	cout << endl;
	char delimiter = '^';
	vector<string> viktor = split(str, delimiter);
	vector<string> viktoria;
	set<std::string> clauses;
	set<string> distinctVariables;
	delimiter = 'v';
	for (int i = 0; i<viktor.size(); i++) 
	{
		cout << "Clause " << i << ": " << viktor[i] << std::endl;
		viktoria = split(viktor[i], delimiter);
		for (int j = 0; j < viktoria.size(); j++) 
		{
			cout << viktoria[j];
			string s = viktoria[j];
			replace(s.begin(), s.end(), '-', ' '); // replace all '-' to ' '
			distinctVariables.insert(trim(s));
		}
		cout << std::endl;
	}
	int intDistinctVar = 0;//added
	cout << "row ";
	for (set<string>::iterator i = distinctVariables.begin(); i != distinctVariables.end(); i++) 
	{
		cout << *i << " ";
		intDistinctVar++;//added
	}
	//cout << endl;
	int prettyprintSize = str.size() + (distinctVariables.size() * 2);
	cout << str << endl;
	vector<vector<int> > truthTableCombinations = getTruthTable(distinctVariables.size()); //create truth table after getting amount of variables with 'distinctVariables'
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//cout << "end of provided program " << endl;//added from here down
	bool var1 = false;
        bool var2 = false;
        bool var3 = false;
    	int rowss = (int)pow(2, intDistinctVar);
    	bool rowExprVal[rowss];
    	int counts = 0;
    	for(int d = 0; d < rowss; d++)
    	{
        	//cout << "Row " << d+1 << endl;
        	for (int h = 0; h < viktor.size(); h++)
        	{
            		viktoria = split(viktor[h], delimiter);
            		for (int k = 0; k < viktoria.size(); k++)
            		{
                		string victoria = viktoria[k];
                		string absVictoria = viktoria[k];
                		replace(absVictoria.begin(), absVictoria.end(), '-', ' '); // replace all '-' to ' '
                		int tempo = atoi(absVictoria.c_str());
                		int temp = atoi(victoria.c_str());
               	 		for(set<string>::iterator ite = distinctVariables.begin(); ite != distinctVariables.end(); ite++)
	                	{
					string tempor = *ite;
					//cout << " tempor " << tempor << endl;
					int s = atoi(tempor.c_str());
				//	cout << "distinct val( s val) " << s << endl;
				//	cout << "tempo(current clause var " << tempo << endl;
        	            		if(s == tempo)
        	            		{
               		         		if(temp < 0 )
                       		 		{
						//	cout << "neg" << temp;
                     		       			temp = 0;
						//	cout << "zero " << temp << endl;
                     		   		}
                        			else if(temp > 0)
                        			{	
						//	cout << "pos " << temp; 
                            				temp = 1;
						//	cout << "one " << temp << endl;
                        			}
                        			//int tempVal = truthTableCombinations[d][s];
                        			if(truthTableCombinations[d][counts] == temp)
                        			{
                            				//cout << " |row " << d+1 << " col. " << s+1 << " var. " << tempo << " true| ";
                            				if(k == 0)
                            				{
                                				var1 =  1;
                                				//cout <<" true ";
                                				//cout << var1;
                            				}
                         	   			else if(k == 1)
                            				{
                               	 				var2 = 1;
                               		 			//cout << " true ";
                              				  	//cout << var2;
                            				}
                            				else if(k == 2)
                            				{
                                				var3 = 1;
                                				//cout << " true ";
         	                     				//cout << var3;
                	           			}
						//	cout << endl;

                        			}
                        			else if(truthTableCombinations[d][counts] != temp)
                        			{
                            				//cout << " |row " << d+1 << " col. " << s+1 << " var. " << tempo << " false| ";
                            				if(k == 0)
                            				{
						//		cout << endl;
                                				var1 = 0;
						//		cout << " false ";
                               			//	        cout << var1;
                            				}
                            				else if(k == 1)
                            				{
								var2 = 0;
                                		//		cout << " false ";
                               			//	 	cout << var2;
                            				}
                            				else if(k == 2)
                            				{
                                				var3 = 0         ;
                                		//		cout << " false ";
                                		//		cout << var3;
                            				}
						//	cout << endl;
                        			}
                   			}
					counts++;
                		}
				counts = 0;
            		}
            		if(var1 == 0 && var2 == 0 && var3 == 0)
            		{
				rowExprVal[d] = 0;	
			}
            		else
            		{
                		rowExprVal[d] = 1;
            		}
        	}
    	}
	cout << endl;
	cout << endl;
    	for(int t = 0; t < rowss; t++)
    	{
		bool switcher = rowExprVal[t];
		if(switcher == 0)
		{
			cout << "row " << t+1 << " is ";
			cout << " Not Satisfied!" << endl;
		}
    	}
	cout << endl;
} 



