#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
int main() {
    int number;
    cin >> number;
    queue<pair<int, vector<int>>> steps;
    unordered_set<int> allX;
    steps.push({ 1, {1} });
    allX.insert(1);
    while (!steps.empty()) {
        int middle = steps.front().first;
        vector<int> way = steps.front().second;
        steps.pop();
        int nextNumber[] = { middle + 1, middle * 2, middle * 3 };
        for (int x : nextNumber) {
            if (x == number) {
                way.push_back(x);
                cout << way.size() - 1 << endl;
                for (int elem : way) {
                    cout << elem << " ";
                }
                return 0;
            }
            if (x < number && allX.find(x) == allX.end()) {
                vector<int>newWay = way;
                newWay.push_back(x);
                steps.push({ x, newWay });
                allX.insert(x);

            }
        }
    }
    return 0;
}
