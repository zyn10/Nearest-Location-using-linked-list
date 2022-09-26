#include<iostram>
#include<fstream>
using namespace std;
string Location[10];
class Graphs
{
private:
	double** Distance;
	int size;
public:
	Graphs()
	{
		Distance = NULL;
		size = 0;
	}
	void create()
	{
		int vertex;
		int adjver;
		int weight;
		ifstream fin;
		fin.open("Location_Distances.txt");
		fin >> size;
		Distance = new double*[size];
		for (int i = 0; i < size; i++)
		{
			Distance[i] = new double[size];

		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				Distance[i][j] = 0;
			}
		}
		for (int i = 0; i < size; i++)
		{
			fin >> vertex;
			fin >> adjver;
			while (adjver != -999)
			{
				fin >> weight;
				Distance[vertex][adjver] = weight;
				fin >> adjver;
			}
		}
	}
	void nearest_marquee(int i)
	{
		for (int j = 5; j < 10; j++)
		{
			int k = j + 1;
			j = 5 + i;
			if (Distance[i][j] < Distance[i][k])
			{
				cout << location[j] << " is the Nearest Marquee to your Location" << endl;
				cout << "The minimum distance between " << location[i] << " and " << location[j] << " is : " << location[i][j] << " Km(Approx)" << endl;
				return;
			}
		}
	}

};
void Nearest()
{
			 cout << "1 : D-Ground    " << endl;
	         cout << "2 : Canal Road  " << endl;
	         cout << "3 : Abdullahpur " << endl;
	         cout << "4 : Civil Lines " << endl;
	         cout << "5 : Heaven Habitant" << endl;
			 cin.ignore();
			 getline(cin, s);
			 for (int i = 0; i < 10; i++)
			 {
				if (s == location[i])
				{
					x = i;
				}

			}
			wg.nearest_marquee(x);
			cout << endl;
}
int main()
{
		Graph obj_g;
	    ifstream fin;
	    fin.open("locations.txt");
	    for (int i = 0; i < 10; i++)
	    {
		  getline(fin, marquee[i]);
	    }
	    obj_g.create();
}
