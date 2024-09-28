#include <bits/stdc++.h>

using namespace std;

// functie care calculeaza suma maxima a lungimilor cuvintelor
int maxSum(vector<pair<int, int>> &pairs, int sum, int idx_neg) {
    int n = pairs.size();

    // initializez o matrice pentru programare dinamica
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    /* iterez peste perechi incepand de la
	indexul de dupa prima diferenta negativa */ 
    for (int i = idx_neg + 1; i <= n; i++) {
        // obtin opusul diferentei negative si lungimea perechii curente
        int diff = -pairs[i - 1].first, length = pairs[i - 1].second;

        // trec prin toate sumele posibile
        for (int j = 0; j <= sum; j++) {
            // daca suma curenta este mai mica sau egala cu diferenta
            if (j <= diff) {
                // suma maxima este aceeasi cu suma maxima fara perechea curenta
                dp[i - idx_neg][j] = dp[i - idx_neg - 1][j];
            } else {
                /* altfel, este maximul dintre aceeasi si suma maxima fara
				diferenta perechii curente plus lungimea perechii curente */
                dp[i - idx_neg][j] =
                max(dp[i - idx_neg - 1][j],
                    dp[i - idx_neg - 1][j - diff] + length);
            }
        }
    }

    // returnez suma maxima a lungimilor cuvintelor
    return *max_element(dp[n - idx_neg].begin() + 1, dp[n - idx_neg].end());
}

int main() {
	ifstream fin("criptat.in");
	ofstream fout("criptat.out");

	int n;
	fin >> n;

	vector<vector<int>> alphabet(n, vector<int>(26, 0));
	vector<int> lengths(n);
	for (int i = 0; i < n; i++) {
		string s;
		fin >> s;

		// salvez lungimea cuvantului si frecventa fiecarui caracter
		int len = s.length();
		lengths[i] = len;
		for (int j = 0; j < len; j++) {
			alphabet[i][s[j] - 'a']++;
		}
	}

	int max_len = -INT_MAX;
	// parcurg fiecare litera din alfabet
	for (int i = 0; i < 26; i++) {
		vector<pair<int, int>> diffs;
		// parcurg fiecare cuvant
		for (int j = 0; j < n; j++) {
			/* formez o pereche cu diferenta dintre frecventa literei curente
			si frecventa celorlalte litere si lungimea cuvantului */
			diffs.push_back({alphabet[j][i] - (lengths[j] - alphabet[j][i]),
            lengths[j]});
		}
		// sortez descrescator perechile dupa diferenta
		sort(diffs.begin(), diffs.end(), greater<pair<int, int>>());

		int sum = 0, length = 0, idx_neg = n;
		for (int j = 0; j < n; j++) {
			// la prima diferenta negativa, salvez indexul si ies din bucla
			if (diffs[j].first < 0) {
				idx_neg = j;
				break;
			}

			// adaug diferenta pozitiva la suma totala a diferentelor
			sum += diffs[j].first;
			// adaug lungimea cuvantului la lungimea totala a parolei
			length += diffs[j].second;
		}

		// daca nu a fost nicio diferenta pozitiva, trec la urmatoarea litera
		if (sum == 0)
			continue;

		// compar maximul curent cu lungimea + suma maxima a lungimilor ramase
		max_len = max(max_len, length + maxSum(diffs, sum, idx_neg));
	}

	fout << max_len << "\n";

	return 0;
}
