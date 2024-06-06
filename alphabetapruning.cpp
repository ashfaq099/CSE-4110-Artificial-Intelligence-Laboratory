#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;
const int MAX = numeric_limits<int>::max();
const int MIN = numeric_limits<int>::min();

int alphaBetaPrune(int depth, int nodeIndex, bool maximizingPlayer, const vector<int>& values, int alpha, int beta, int maxDepth) {
    if (depth == maxDepth) {
        return values[nodeIndex];
    }

    if (maximizingPlayer) {
        int maxEval = MIN;
        for (int i = 0; i < 2; ++i) {
            int eval = alphaBetaPrune(depth + 1, nodeIndex * 2 + i, false, values, alpha, beta, maxDepth);
            maxEval = max(maxEval, eval);
            alpha = max(alpha, maxEval);
            if (beta <= alpha) {
                break;
            }
        }
        return maxEval;
    } else {
        int minEval = MAX;
        for (int i = 0; i < 2; ++i) {
            int eval = alphaBetaPrune(depth + 1, nodeIndex * 2 + i, true, values, alpha, beta, maxDepth);
            minEval = min(minEval, eval);
            beta = min(beta, minEval);
            if (beta <= alpha) {
                break;
            }
        }
        return minEval;
    }
}

int main() {
    int n;
    cout << "Enter the number of values: ";
    cin >> n;
    vector<int> values(n);
    cout << "Enter the values: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    int maxDepth = log2(n);

    int alpha = MIN;
    int beta = MAX;

    int optimalValue = alphaBetaPrune(0, 0, true, values, alpha, beta, maxDepth);

    cout << "The Optimal value: " << optimalValue << endl;
    return 0;
}
