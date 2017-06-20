// sortingProject.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <string>


using namespace std;

struct Osoba
{
	int Id;
	char Imie[6];
	int RokUr;
	int DzienUr;
	int MiesiacUr;
};
void Print(Osoba * tab, int n);
void Init(Osoba * tab, int n);
void BubbleSort(Osoba * tab, int n);
void BubbleSortODW(Osoba * tab, int n);
void InsertionSort(Osoba * tab, int n);
void InsertionSortODW(Osoba * tab, int n);
void merge(Osoba * tab, int p, int sr, int k);
void mergeODW(Osoba * tab, int p, int sr, int k);
void mergeSort(Osoba * tab, int p, int k);
void mergeSortODW(Osoba * tab, int p, int k);
void qsort(Osoba * tab, int p, int k);
void qsortODW(Osoba * tab, int p, int k);
bool LeftOlder(Osoba * left, Osoba * right);
bool RightOlder(Osoba * left, Osoba * right);
bool LeftOlderOrEqual(Osoba * left, Osoba * right);

int main()
{
	static unsigned int rozm = 8000;
	Osoba * tt = new Osoba[rozm];
	srand(time(NULL));
	unsigned int sttime;
	unsigned int edtime;

	Init(tt, rozm);
	sttime = GetTickCount();
	BubbleSort(tt, rozm);
	edtime = GetTickCount();
	cout << "czas BS " << edtime - sttime << endl;

	sttime = GetTickCount();
	BubbleSortODW(tt, rozm);
	edtime = GetTickCount();
	cout << "czas BSODW " << edtime - sttime << endl;

	Init(tt, rozm);
	sttime = GetTickCount();
	InsertionSort(tt, rozm);
	edtime = GetTickCount();
	cout << "czas IS " << edtime - sttime << endl;

	sttime = GetTickCount();
	InsertionSortODW(tt, rozm);
	edtime = GetTickCount();
	cout << "czas ISODW " << edtime - sttime << endl;

	Init(tt, rozm);
	sttime = GetTickCount();
	mergeSort(tt, 0, rozm - 1);
	edtime = GetTickCount();
	cout << "czas MS " << edtime - sttime << endl;

	sttime = GetTickCount();
	mergeSortODW(tt, 0, rozm - 1);
	edtime = GetTickCount();
	cout << "czas MSODW " << edtime - sttime << endl;

	Init(tt, rozm);
	sttime = GetTickCount();
	qsort(tt, 0, rozm - 1);
	edtime = GetTickCount();
	cout << "czas QS " << edtime - sttime << endl;

	sttime = GetTickCount();
	qsortODW(tt, 0, rozm - 1);
	edtime = GetTickCount();
	cout << "czas QSODW " << edtime - sttime << endl;

	return 0;
}

bool LeftOlder(Osoba left, Osoba right)
{
	if (left.RokUr > right.RokUr)
		return true;
	else if (left.RokUr == right.RokUr)
		if (left.MiesiacUr > right.MiesiacUr)
			return true;
		else if (left.MiesiacUr == right.MiesiacUr)
			if (left.DzienUr > right.DzienUr)
				return true;
			else
				return false;
		else
			return false;
	else
		return false;
}

bool LeftOlderOrEqual(Osoba left, Osoba right)
{
	if (left.RokUr > right.RokUr)
		return true;
	else if (left.RokUr == right.RokUr)
		if (left.MiesiacUr > right.MiesiacUr)
			return true;
		else if (left.MiesiacUr == right.MiesiacUr)
			if (left.DzienUr >= right.DzienUr)
				return true;
			else
				return false;
		else
			return false;
	else
		return false;
}

bool RightOlder(Osoba left, Osoba right)
{
	if (left.RokUr < right.RokUr)
		return true;
	else if (left.RokUr == right.RokUr)
		if (left.MiesiacUr < right.MiesiacUr)
			return true;
		else if (left.MiesiacUr == right.MiesiacUr)
			if (left.DzienUr < right.DzienUr)
				return true;
			else
				return false;
		else
			return false;
	else
		return false;
}

void Print(Osoba * tab, int n)
{
	for (int i = 0; i<n; i++)
	{
		cout << tab[i].Id << "  ";
		for (int j = 0; j<6; j++)
			cout << tab[i].Imie[j];
		cout << " ";
		cout << tab[i].RokUr << "-";
		cout << tab[i].MiesiacUr << "-";
		cout << tab[i].DzienUr << endl;
	}
	cout << endl;
}

void Init(Osoba * tab, int n)
{
	for (int i = 0; i<n; i++)
	{
		tab[i].Id = i + 1;
		tab[i].RokUr = rand() % 114 + 1900;
		tab[i].MiesiacUr = rand() % 12 + 1;
		if (tab[i].MiesiacUr == 2)
			tab[i].DzienUr = rand() % 28 + 1;
		else if (tab[i].MiesiacUr % 2 == 0 && tab[i].MiesiacUr != 2)
			tab[i].DzienUr = rand() % 30 + 1;
		else
			tab[i].DzienUr = rand() % 31 + 1;
		tab[i].Imie[0] = rand() % 26 + 65;
		for (int j = 1; j<6; j++)
		{
			tab[i].Imie[j] = rand() % 25 + 97;
		}
	}
}

void BubbleSort(Osoba * tab, int n)
{
	Osoba temp;
	int znak = 0;
	for (int i = 0; i<n; i++)
	{
		for (int j = 1; j<n - i; j++)
			if (LeftOlder(tab[j - 1], tab[j]))
			{
				znak = 1;
				temp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = temp;
			}
		if (znak == 0)
			return;
	}
}

void BubbleSortODW(Osoba * tab, int n)
{
	Osoba temp;
	int znak = 0;
	for (int i = 0; i<n; i++)
	{
		for (int j = 1; j<n - i; j++)
			if (RightOlder(tab[j - 1], tab[j]))
			{
				znak = 1;
				temp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = temp;
			}
		if (znak == 0)
			return;
	}
}

void InsertionSort(Osoba * tab, int n)
{
	for (int i = 1; i<n; i++)
	{
		int j = i;
		Osoba temp = tab[j];
		while (LeftOlder(tab[j - 1], temp) && (j>0))
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = temp;
	}
}

void InsertionSortODW(Osoba * tab, int n)
{
	for (int i = 1; i<n; i++)
	{
		int j = i;
		Osoba temp = tab[j];
		while (RightOlder(tab[j - 1], temp) && (j>0))
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = temp;
	}
}

void merge(Osoba * tab, int p, int sr, int k)
{
	Osoba * temptab = new Osoba[k + 1];

	for (int t = p; t <= k; t++)
	{
		temptab[t].Id = tab[t].Id;
		for (int i = 0; i<6; i++)
			temptab[t].Imie[i] = tab[t].Imie[i];
		temptab[t].RokUr = tab[t].RokUr;
		temptab[t].MiesiacUr = tab[t].MiesiacUr;
		temptab[t].DzienUr = tab[t].DzienUr;
	}
	int i = p;
	int j = sr + 1;
	int q = p;
	while (i <= sr && j <= k)
		if (RightOlder(temptab[i], temptab[j]))
		{
			tab[q] = temptab[i];
			q++;
			i++;
		}
		else
		{
			tab[q] = temptab[j];
			q++;
			j++;
		}

	while (i <= sr)
	{
		tab[q] = temptab[i];
		i++;
		q++;
	}

	delete[] temptab;
}

void mergeODW(Osoba * tab, int p, int sr, int k)
{
	Osoba * temptab = new Osoba[k + 1];

	for (int t = p; t <= k; t++)
	{
		temptab[t].Id = tab[t].Id;
		for (int i = 0; i<6; i++)
			temptab[t].Imie[i] = tab[t].Imie[i];
		temptab[t].RokUr = tab[t].RokUr;
		temptab[t].MiesiacUr = tab[t].MiesiacUr;
		temptab[t].DzienUr = tab[t].DzienUr;
	}
	int i = p;
	int j = sr + 1;
	int q = p;
	while (i <= sr && j <= k)
		if (LeftOlder(temptab[i], temptab[j]))
		{
			tab[q] = temptab[i];
			q++;
			i++;
		}
		else
		{
			tab[q] = temptab[j];
			q++;
			j++;
		}

	while (i <= sr)
	{
		tab[q] = temptab[i];
		i++;
		q++;
	}

	delete[] temptab;
}

void mergeSort(Osoba * tab, int p, int k)
{
	int s = (p + k) / 2;

	if (p<k)
	{
		mergeSort(tab, p, s);
		mergeSort(tab, s + 1, k);
		merge(tab, p, s, k);
	}
}

void mergeSortODW(Osoba * tab, int p, int k)
{
	int s = (p + k) / 2;

	if (p<k)
	{
		mergeSortODW(tab, p, s);
		mergeSortODW(tab, s + 1, k);
		mergeODW(tab, p, s, k);
	}
}

void qsort(Osoba * tab, int left, int right)
{
	int i = left, j = right;
	Osoba tmp;
	Osoba pivot = tab[(left + right) / 2];

	while (i <= j)
	{
		while (RightOlder(tab[i], pivot))
			i++;
		while (LeftOlder(tab[j], pivot))
			j--;
		if (i <= j)
		{
			tmp = tab[i];
			tab[i] = tab[j];
			tab[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j)
		qsort(tab, left, j);
	if (i < right)
		qsort(tab, i, right);
}

void qsortODW(Osoba * tab, int left, int right)
{
	int i = left, j = right;
	Osoba tmp;
	Osoba pivot = tab[(left + right) / 2];

	while (i <= j) {
		while (LeftOlder(tab[i], pivot))
			i++;
		while (RightOlder(tab[j], pivot))
			j--;
		if (i <= j) {
			tmp = tab[i];
			tab[i] = tab[j];
			tab[j] = tmp;
			i++;
			j--;
		}
	}
	if (left < j)
		qsortODW(tab, left, j);
	if (i < right)
		qsortODW(tab, i, right);
}


