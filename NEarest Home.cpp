#include <iostream>
#include <fstream>
#include <iomanip>
#include<string>
#include<Windows.h>
#include<sstream>
#include<conio.h>
using namespace std;
string stringValidation(string Name)
	{
	Again:
		int len = Name.length();
		if (len == 0)
		{
			"Enter Correct Name please : ";
			getline(cin, Name);
			goto Again;

		}
		for (int i = 0; i < len; i++)
		{
			if (Name[i] == '1' || Name[i] == '2' || Name[i] == '3' || Name[i] == '4' || Name[i] == '5' ||
				Name[i] == '6' || Name[i] == '7' || Name[i] == '8' || Name[i] == '9' || Name[i] == '0' ||
				Name[i] == ' ')//
			{
				cout << "--->ERROR!\n PLEASE ENTER CORRECT NAME = \t";
				getline(cin, Name);
				goto Again;
			}
		}
		return Name;
	}

string location[15];
class Graph
{
private:
	double** Distance_Wighted;
	int Size;
public:
	Graph()
	{
		Distance_Wighted = NULL;
		Size = 0;
	}
	void create()
	{
		int vertex;
		int adjver;
		int weight;
		ifstream fin;
		fin.open("Distances.txt");
		fin >> Size;
		Distance_Wighted = new double*[Size];
		for (int i = 0; i < Size; i++)
		{
			Distance_Wighted[i] = new double[Size];

		}
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				Distance_Wighted[i][j] = 0;
			}
		}
		for (int i = 0; i < Size; i++)
		{
			fin >> vertex;
			fin >> adjver;
			while (adjver != -999)
			{
				fin >> weight;
				Distance_Wighted[vertex][adjver] = weight;
				fin >> adjver;
			}
		}
	}
	void nearest(int i)
	{
		
//phlay 5 islea skip kea hain 
//bcz wo names thay locations k us sa agay ghar start ho rhay hain
		for (int j = 5; j < 15; j++)
		{
			int k = j + 1;
			j = 5 + i;
			if (Distance_Wighted[i][j] < Distance_Wighted[i][k])
			{
				cout << location[j] << " is the Nearest Avaialble Home  to your Location" << endl;
				cout << "Minimum distance b/w " << location[i] << " and " << location[j] << " is : " << Distance_Wighted[i][j] << " Km(Approx)" << endl;
				return;
			}
		}
	}

};


int main()
{
	Graph obj;
	string locationInput;
	int temp = 0;
	ifstream fin;
	fin.open("Locations.txt");
	for (int i = 0; i < 15; i++)
	{
		getline(fin, location[i]);
	}
	obj.create();
		     cout << " Enter Your Location "<<endl;
			 cout << "    D-Ground    " << endl;
	         cout << "    Canal Road  " << endl;
	         cout << "    Housing Colony " << endl;
	         cout << "    Civil Lines " << endl;
	         cout << "    Heaven Habitant" << endl;
			 getline(cin, locationInput);
			for (int i = 0; i < 15; i++)
			{
				if (locationInput == location[i])
				{
					temp = i;
				}

			}
			obj.nearest(temp);
			cout << endl;
		
	return 0;
}

