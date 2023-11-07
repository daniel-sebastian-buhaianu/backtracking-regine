#include <fstream>
#include <iostream>
#include <cmath>
#define NMAX 30
using namespace std;
ofstream fout("regine.out");
int nrLinii, nrColoane, nrSolutii, col[NMAX];
void plaseazaRegina(int);
int main()
{
	int n;
	cout << "n = "; cin >> n;
	nrLinii = nrColoane = n;
	plaseazaRegina(0);
	fout.close();
	return 0;
}
void afiseazaSolutie()
{
	fout << "Solutia " << nrSolutii << '\n';
	for (int linie = 0; linie < nrLinii; linie++)
	{
		for (int coloana = 0; coloana < nrColoane; coloana++)
			if (coloana == col[linie])
				fout << " * ";
			else
				fout << " o ";
		fout << '\n';
	}
	fout << '\n';
}
bool potPlasaRegina(int linie, int coloana)
{
	for (int i = 0; i < linie; i++)
	{
		// exista deja o regina pe aceeasi coloana?
		if (col[i] == coloana) return 0;
		// exista deja o regina pe aceeasi diagonala?
		if (abs(col[i]-coloana) == (linie-i)) return 0;
	}
	return 1;
}
void plaseazaRegina(int linie)
{
	if (linie == nrLinii)
	{
		nrSolutii++;
		afiseazaSolutie();
	}
	else
		for (int coloana = 0; coloana < nrColoane; coloana++)
		{
			if (potPlasaRegina(linie, coloana))
			{
				col[linie] = coloana;
				plaseazaRegina(linie+1);
			}
		}
}
