#include <bits/stdc++.h>

using namespace std;

int main() {
	ifstream fin("compresie.in");
	ofstream fout("compresie.out");

	int n, m;
	fin >> n;
	vector<long long> A(n);
	for (int i = 0; i < n; i++) {
		fin >> A[i];
	}

	fin >> m;
	vector<long long> B(m);
	for (int i = 0; i < m; i++) {
		fin >> B[i];
	}

	int i = 0, j = 0, max_length = 0;
	// parcurg vectorii A si B simultan
	while (i < n && j < m) {
		// daca elementele de pe pozitiile curente sunt egale
		if (A[i] == B[j]) {
			// trec la urmatoarele elemente si actualizez lungimea maxima
			i++;
			j++;
			max_length++;
		} else {
			/* altfel, construiesc o suma cu elementele urmatoare pentru
			elementul curent pana e egala cu suma celuilalt vector */
			long long sumA = A[i], sumB = B[j];

			while (sumA != sumB) {
				if (sumA < sumB) {
					// trec la urmatorul element din vectorul A si actualizez suma
					i++;
					if (i < n) {
						sumA += A[i];
					} else {
						// daca am ajuns la finalul vectorului A, ies din bucla
						break;
					}
				} else {
					/* daca suma elementelor din vectorul B este mai mica trec la
					urmatorul element din vectorul B si actualizez suma */ 
					j++;
					if (j < m) {
						sumB += B[j];
					} else {
						// daca am ajuns la finalul vectorului B, ies din bucla
						break;
					}
				}
			}

			// trec la urmatoarele elemente si actualizez lungimea maxima
			i++;
			j++;
			max_length++;
		}
	}

	// daca nu am parcurs complet ambii vectori afisez -1
	if (i < n || j < m) {
		fout << "-1\n";
		return 0;
	}

	fout << max_length << "\n";

	return 0;
}
