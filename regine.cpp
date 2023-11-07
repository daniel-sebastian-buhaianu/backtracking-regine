#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
ofstream fout("regine.out");
int n, NrSol, C[30];
void Plaseaza_Regina(int);
int main()
{
	cout << "n = "; cin >> n;
	Plaseaza_Regina(0);
	return 0;
}
void Afisare()
{
	int i, j;
	fout << "Solutia nr. " << ++NrSol << '\n';
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			if (j == C[i]) fout << " * ";
			else fout << " o ";
		fout << '\n';
	}
	fout << '\n';
	fout.close();
}
void Plaseaza_Regina(int k)
{
	// cand apelam functia Plaseaza_Regina cu parametrul k
	// am plasat deja regine pe liniile 0,1,...,k-1
	int i, j;
	if (k == n) // am obtinut o solutie
		Afisare(); // prelucrarea solutiei consta in afisare
	else // trebuie sa mai plasam regine pe liniile k, k+1, ... , n-1
		for (i = 0; i < n; i++)
		{
			// verific daca pot plasa regina de pe linia k in coloana i
			for (j = 0; j < k; j++)
				if (C[j] == i || abs(C[j]-i) == (k-j)) break;
			if (j == k) // valoarea i respecta conditiile interne
			{
				C[k] = i; // i este un candidat, il extrag imediat
				Plaseaza_Regina(k+1);
			}
		}
}
