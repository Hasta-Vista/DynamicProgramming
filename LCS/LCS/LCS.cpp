#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int firstSize;
    cin >> firstSize;
    vector<int> firstSequence(firstSize);
    for (int i = 0; i < firstSize; ++i) {
        cin >> firstSequence[i];
    }
    int secondSize;
    cin >> secondSize;
    vector<int> secondSequence(secondSize);
    for (int i = 0; i < secondSize; ++i) {
        cin >> secondSequence[i];
    }
    vector<vector<int>> result(firstSize + 1, vector<int>(secondSize + 1, 0));
    for (int i = 1; i <= firstSize; ++i) {
        for (int j = 1; j <= secondSize; ++j) {
            if (firstSequence[i - 1] == secondSequence[j - 1]) {
                result[i][j] = result[i - 1][j - 1] + 1;

            }
            else {
                result[i][j] = max(result[i - 1][j], result[i][j - 1]);
            }
        }
    }
    cout << result[firstSize][secondSize] << endl;
    return 0;
}