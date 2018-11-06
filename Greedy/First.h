#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class First {

public:

	void exe() {

		in.open("data1.txt");
		in >> n;
		for (int i = 1; i <= n; i++) {

			v[i].p = i;
			in >> v[i].t1;
			in >> v[i].t2;
		}

		quickSort(1, n);
		greedy();
		write(l);
	}

private:

	ifstream in;

	struct Data {

		int p;
		int t1;
		int t2;
	
	}v[10];

	int n, l, a[10];

	void quickSort(int l, int r) {

		if (l < r) {

			int piv = l;
			int i = l;
			int j = r;
			Data aux;

			while (v[i].t2 < v[piv].t2)
				i++;

			while (v[j].t2 > v[piv].t2)
				j--;

			if (i < j) {
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}

			aux = v[piv];
			v[piv] = v[j];
			v[j] = v[piv];

			quickSort(l, j - 1);
			quickSort(j + 1, r);

		}
	}

	void greedy() {
	
		l = 1;
		a[1] = 1;
		for (int i = 2; i <= n; i++)
			if (v[i].t1 >= v[a[l]].t2)
				a[++l] = i;
	}

	void write(int l) {

		for (int i = 1; i <= l; i++)
			if(a[i] != 0)
			cout << v[a[i]].p << " : " << v[a[i]].t1 << " - " << v[a[i]].t2 << endl;
	}

};