#include <iostream>
#include <string>
using namespace std;

int getMinMoves(string A, string B) {
    if (A.size() != B.size())
        return -1;

    int moves = 0;

    for (char c = 'z'; c >= 'a'; c--) {
        bool needMove = false;

        for (int i = 0; i < A.size(); i++) {
            if (A[i] == c) {
                if (B[i] > c)
                    return -1;

                if (B[i] < c)
                    needMove = true;
            }
        }

        if (needMove)
            moves++;
    }

    return moves;
}

int main() {
    cout << getMinMoves("dcba", "cbba") << endl; // 2
    cout << getMinMoves("aab", "bba") << endl;   // -1
    cout << getMinMoves("dec", "bbb") << endl;   // 3
    return 0;
}
