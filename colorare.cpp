#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

// functie care calculeaza base ^ exponent % mod extrasa din laboratorul 1
int fast_pow(int base, int exponent, int mod) {
	if (exponent == 0) {
		return 1;
	}

	// daca exponentul este par, returnez patratul lui base ^ exponent / 2 % mod
	if (exponent % 2 == 0) {
		int result = fast_pow(base, exponent / 2, mod);
		return 1LL * result * result % mod;
	}

	// daca exponentul este impar, returnez base * base ^ (exponent - 1) % mod
	return 1LL * base * fast_pow(base, exponent - 1, mod) % mod;
}

int main() {
	ifstream fin("colorare.in");
	ofstream fout("colorare.out");

	int K, X;
    char T, last;
	long long pictures;

    fin >> K >> X >> T;

	// daca in primul grup sunt 2 sau mai multe dreptunghiuri orizontale
	if (X >= 2 && T == 'H') {
		// pentru primele 2 dreptunghiuri orizontale exista 18 posibilitati
		pictures = 18;
		// pentru fiecare dreptunghi orizontal in plus, exista 3 posibilitati
		if (X > 2) {
			pictures = (pictures % MOD * fast_pow(3, X - 2, MOD)) % MOD;
		}
	} else {
		// pentru primele 2 dreptunghiuri verticale exista 6 posibilitati
		pictures = 6;
		// pentru fiecare dreptunghi vertical in plus, exista 2 posibilitati
		if (X > 2) {
			pictures = (pictures % MOD * fast_pow(2, X - 2, MOD)) % MOD;
		}
	}
	// pastrez tipul ultimului dreptunghi din grup
	last = T;

	// parcurg restul grupurilor
	for (int i = 1; i < K; i++) {
		fin >> X >> T;

		// daca grupul curent contine dreptunghiuri orizontale
		if (T == 'H') {
			// daca grupul anterior contine dreptunghiuri orizontale
			if (last == 'H') {
				// exista 3 posibilitati pentru fiecare dreptunghi
				pictures = (pictures % MOD * fast_pow(3, X, MOD)) % MOD;
			} else {
				/* daca grupul anterior contine dreptunghiuri verticale exista
				2 posibilitati pentru primul dreptunghi */ 
				pictures = (pictures * 2 % MOD);
				// pentru restul dreptunghiurilor exista 3 posibilitati
				pictures = (pictures % MOD * fast_pow(3, X - 1, MOD)) % MOD;
			}
		} else {
			// daca grupul curent contine dreptunghiuri verticale
			if (last == 'H') {
				/* iar cel vechi contine dreptunghiuri orizontale, exista
				1 posibilitate pentru primul dreptunghi si 2 pentru restul */  
				pictures = (pictures % MOD * fast_pow(2, X - 1, MOD)) % MOD;
			} else {
				/* daca si grupul anterior contine dreptunghiuri verticale,
				exista 2 posibilitati pentru fiecare dreptunghi */ 
				pictures = (pictures % MOD * fast_pow(2, X, MOD)) % MOD;
			}
		}
		// pastrez tipul ultimului dreptunghi din grup
		last = T;
	}

	fout << pictures << "\n";

	return 0;
}
