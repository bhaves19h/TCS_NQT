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



/*
Ayush is working on a string transformation algorithm. He wants to convert a source string A into a target string B. Both strings have the same length N and consist only of lowercase English letters.

To transform the string, Ayush can perform the following operation any number of times:

Choose any subset of indices from the current string A.
Among the characters present at the chosen indices, find the smallest (lexicographically smallest) character. Let this character be s.
Replace the characters at all chosen indices with s.

Your task is to determine the minimum number of operations required to transform A into B. If it is impossible to perform the transformation, return -1.

Input

The function receives two strings:

A – the initial string.
B – the target string.

Both strings have the same length and contain only lowercase English letters.

Output

Return a single integer representing the minimum number of operations required to transform A into B. If the transformation is impossible, return -1.

Example 1

Input

A = "dcba"
B = "cbba"

Output

2

Explanation

Choose the subset containing 'd' and 'c'. The smallest character is 'c', so 'd' becomes 'c':

dcba → ccba

Choose the second 'c' only. The smallest character in the subset is 'b', so that 'c' becomes 'b':

ccba → cbba

Minimum operations = 2.

Example 2

Input

A = "aab"
B = "bba"

Output

-1

Explanation

The transformation requires changing 'a' to 'b', which is impossible because the operation can only replace characters with the smallest character in the chosen subset. Hence, characters can never increase lexicographically.

Constraints
1 ≤ N ≤ 2 × 10^5
A.length = B.length = N
A and B contain only lowercase English letters ('a'–'z')*/
