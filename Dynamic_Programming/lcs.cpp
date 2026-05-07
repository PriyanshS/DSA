#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void findLCS(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> L(m + 1, vector<int>(n + 1));

    // Building the L[m+1][n+1] matrix
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // Backtracking to find the actual sequence
    int index = L[m][n];
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs += X[i - 1];
            i--; j--;
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(lcs.begin(), lcs.end());

    cout << "String X: " << X << "\nString Y: " << Y << endl;
    cout << "LCS Length: " << L[m][n] << endl;
    cout << "LCS: " << lcs << endl;
}

int main() {
    // Testing with provided instance (a)
    string X = "EBTBCADF";
    string Y = "ABBCDGF";
    findLCS(X, Y);
    return 0;
}