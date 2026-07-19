# 📘 C++ Input Handling Cheat Sheet

*A quick-reference guide for handling tricky `cin` / `getline` input scenarios — built for TCS NQT and other competitive coding platforms.*

![C++](https://img.shields.io/badge/language-C%2B%2B17-blue)
![Category](https://img.shields.io/badge/category-Competitive%20Programming-orange)
![Status](https://img.shields.io/badge/status-Reference%20Guide-brightgreen)

---

## 📑 Table of Contents

- [Fast I/O](#-fast-io)
- [Read Integer then Full String](#-read-integer-then-full-string)
- [Reading Comma-Separated Integers](#-reading-comma-separated-integers)
- [Why use `cin >> ws`?](#-why-use-cin--ws)
- [Read n Integers Normally](#-read-n-integers-normally)
- [Read an Entire Line of Numbers](#-read-an-entire-line-of-numbers)
- [Read n Lines of Strings](#-read-n-lines-of-strings)
- [Read Exactly Two Lines](#-read-exactly-two-lines)
- [Example: Product of Array Except Self](#-example-product-of-array-except-self)
- [Read Until EOF](#-read-until-eof-bulletproof-pattern)
- [⭐ The Recommended Template](#-the-recommended-template-ultimate-brahmastra)
- [Alternative: getline-based Splitting](#-alternative-using-getline)
- [Summary Table](#-summary-table)
- [Common Bug Walkthrough](#-common-bug-walkthrough-splitting-on-a-single-space)

---

## 🚀 Fast I/O

Untie C++ streams from the C standard streams and disable synchronization for a significant speed boost on large inputs.

```cpp
ios_base::sync_with_stdio(false); // don't sync C++ streams with C stdio
cin.tie(NULL);                    // untie cin from cout (no auto-flush before each input)
```

> 💡 **Tip:** Always put these two lines at the very top of `main()` in competitive programming — they cost nothing and can save you from TLE (Time Limit Exceeded).

---

## 📌 Read Integer then Full String

A classic pitfall: reading a number with `cin >>` leaves a trailing `'\n'` in the buffer, which `getline()` then reads as an empty line.

```cpp
string user_string;
int n;

cin >> n; // reads the integer but leaves '\n' in the input buffer

if (cin >> ws && getline(cin, user_string))
{
    // user_string now contains the complete, correctly-read line
}
```

### Why `ws`?
`std::ws` is a stream manipulator that consumes (skips) all leading whitespace — spaces, tabs, and newlines — before the next read. Placing it before `getline()` clears the leftover `'\n'` from the previous `cin >>`.

---

## 📌 Reading Comma-Separated Integers

**Input:**
```
1,2,3,4,5
```

```cpp
string line;
getline(cin, line);       // read the full line as one string

stringstream ss(line);    // wrap the string in a stream for parsing

string token;
vector<int> arr;

while (getline(ss, token, ',')) // split on ',' instead of the default '\n'
{
    arr.push_back(stoi(token)); // convert each piece from string to int
}
```

### Line-by-line explanation

| Code | Purpose |
|------|---------|
| `getline(cin, line);` | Reads the complete raw line of input, including commas. |
| `stringstream ss(line);` | Treats the string as an input stream so it can be tokenized. |
| `getline(ss, token, ',');` | Splits the string every time a comma is encountered. |
| `stoi(token);` | Converts each extracted string token into an integer. |

---

## 📌 Why use `cin >> ws`?

**Example Input:**
```
2
Hello World
ChatGPT
```

**❌ Without `ws`:**
```cpp
cin >> test_cases;
getline(cin, str); // BUG: reads the leftover '\n', not "Hello World"
```
**Output:** `(empty string)` — because `cin >> test_cases` consumes `2` but leaves the newline character sitting in the buffer, which `getline()` immediately picks up.

**✅ With `ws`:**
```cpp
cin >> ws;         // discard the leftover newline (and any other whitespace)
getline(cin, str);  // now correctly reads "Hello World"
```

---

## 📌 Read n Integers Normally

Use this when the input is straightforward — a count `n` followed by `n` space-separated values.

**Input:**
```
5
1 2 3 4 5
```

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n; // number of elements

    vector<int> arr(n); // pre-sized vector

    for (int i = 0; i < n; i++)
        cin >> arr[i]; // cin >> automatically skips whitespace/newlines

    for (int x : arr)
        cout << x << " ";

    return 0;
}
```

---

## 📌 Read an Entire Line of Numbers

Useful when you can't fully trust `n`, or the numbers might span an unpredictable number of lines/spaces.

**Input:**
```
5
1 2 3 4 5
```

```cpp
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n; // read count (not strictly relied upon below)

    string dummy;
    getline(cin, dummy); // consume leftover '\n' after cin >> n

    string line;
    getline(cin, line);  // read the actual data line

    stringstream ss(line);

    string token;
    vector<int> arr;

    while (getline(ss, token, ' '))
    {
        if (!token.empty()) // guards against consecutive spaces
            arr.push_back(stoi(token));
    }

    for (int x : arr)
        cout << x << " ";

    return 0;
}
```

### ✅ Advantage
Even if `n` doesn't match the actual count of numbers on the line —

```
n = 3
Input:
1 2
```

— this approach still correctly reads `1 2`, because it depends on the **content of the line**, not on the declared value of `n`.

---

## 📌 Read n Lines of Strings

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cin.ignore(); // flush the leftover newline after cin >> n

    vector<string> words;
    string current;

    for (int i = 0; i < n; i++)
    {
        getline(cin, current); // read one full line per iteration
        words.push_back(current);
    }

    for (string s : words)
        cout << s << endl;

    return 0;
}
```

---

## 📌 Read Exactly Two Lines

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1;
    string str2;

    getline(cin, str1); // reads first line
    getline(cin, str2); // reads second line

    cout << str1 << endl;
    cout << str2 << endl;

    return 0;
}
```

---

## 📌 Example: Product of Array Except Self

A full worked example combining safe line parsing with a real algorithmic problem — computes, for each index, the product of all other elements without using division.

```cpp
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    int n;
    cin >> n;

    // skip to the end of the current line, discarding everything (incl. '\n')
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string line;
    getline(cin, line);

    stringstream ss(line);

    string token;
    vector<long long> arr; // long long guards against overflow on products

    while (getline(ss, token, ' '))
    {
        if (!token.empty())
            arr.push_back(stoll(token));
    }

    int size = arr.size();
    vector<long long> ans(size, 1);

    // Pass 1: prefix products (product of everything to the left of i)
    long long left = 1;
    for (int i = 0; i < size; i++)
    {
        ans[i] = left;
        left *= arr[i];
    }

    // Pass 2: multiply in suffix products (product of everything to the right of i)
    long long right = 1;
    for (int i = size - 1; i >= 0; i--)
    {
        ans[i] *= right;
        right *= arr[i];
    }

    for (long long x : ans)
        cout << x << " ";

    return 0;
}
```

---

## 📌 Read Until EOF (Bulletproof Pattern)

Use this when the number of values to read isn't guaranteed or specified in advance.

```cpp
int n;
cin >> n;

vector<long long> arr;
long long temp;

while (cin >> temp) // loop continues until EOF or a bad read
{
    arr.push_back(temp);
}
```

> Works reliably until the input stream ends — great for platforms that pipe input via file redirection or `Ctrl+D`.

---

## ⭐ The Recommended Template (Ultimate Brahmastra)

The safest, cleanest general-purpose pattern for parsing a line of space-separated integers.

```cpp
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    cin.ignore(); // discard leftover newline after cin >> n

    string line;
    getline(cin, line); // grab the full line of numbers

    stringstream ss(line);

    vector<int> arr;
    int val;

    while (ss >> val) // stream extraction auto-skips ANY amount of whitespace
    {
        arr.push_back(val);
    }

    for (int x : arr)
        cout << x << " ";

    return 0;
}
```

### Why this is the best approach
- ✅ Handles multiple/irregular spaces automatically — no manual empty-string checks needed.
- ✅ No need to manually split or validate tokens.
- ✅ Cleaner and safer than `getline(ss, val, ' ')`.
- ✅ Highly recommended default for TCS NQT and similar platforms.

---

## 📌 Alternative Using `getline()`

Functionally similar to the template above, but splits manually on the space character. Requires an explicit empty-token check.

```cpp
int n;
cin >> n;

cin.ignore();

string line;
getline(cin, line);

stringstream ss(line);

vector<int> arr;
string val;

while (getline(ss, val, ' '))
{
    if (!val.empty()) // required: prevents stoi("") crashes on double spaces
        arr.push_back(stoi(val));
}
```

---

## 🔥 Summary Table

| Situation | Recommended Approach |
|-----------|----------------------|
| Fast Input | `ios::sync_with_stdio(false); cin.tie(NULL);` |
| Integer + String on separate reads | `cin >> ws` + `getline()` |
| Read a full raw line | `getline(cin, line)` |
| Space-separated numbers | `stringstream ss(line); while (ss >> val)` |
| Comma-separated numbers | `getline(ss, token, ',')` |
| Read exactly `n` integers | `for (...) cin >> arr[i];` |
| Read `n` lines of strings | `getline()` inside a loop |
| Unknown number of values | `while (cin >> x)` |
| **Best all-purpose TCS template** | `cin.ignore()` + `getline()` + `stringstream` + `ss >> val` |

---

## 🐛 Common Bug Walkthrough: Splitting on a Single Space

A frequently copy-pasted (and subtly broken) pattern:
//can work easily for array input with " " , ","
```cpp
string line;
getline(cin, line);
stringstream ss(line);
vector<int> arr;
string val;

// ⚠️ This looks safe but is NOT — getline(ss, val, ' ') does NOT skip
// consecutive spaces the way ss >> val does.
while (getline(ss, val, ' ')) {
    arr.push_back(stoi(val));
}
```

### What's actually going on, step by step

| Line | What it does |
|------|---------------|
| `string line;` | Declares an empty string to hold the full raw input line. |
| `getline(cin, line);` | Reads one entire line from `cin` (e.g. `"1 2 3"` or `"1,2,3"`) until Enter is pressed. |
| `stringstream ss(line);` | Wraps `line` in a stream object so it can be parsed token-by-token, just like `cin`. |
| `vector<int> arr;` | A dynamic array that will hold the final parsed integers. |
| `string val;` | A temporary holder for each raw token pulled out of the stream. |
| `while (getline(ss, val, ' '))` | Reads from `ss` up to the next space character and stores that chunk in `val`. |
| `arr.push_back(stoi(val));` | Converts `val` to an integer (`stoi` = **st**ring-**to**-**i**nteger) and appends it to `arr`. |

### ⚠️ Hidden problems

1. **Consecutive spaces** — Input like `1   2` (multiple spaces) produces one or more **empty strings** `""` between real tokens, because `getline(ss, val, ' ')` splits on *every single* space character rather than treating runs of spaces as one delimiter.
2. **Comma-separated input** — If the input is actually `1,2,3` (commas, not spaces), there's no space character to split on at all. The *entire* string `"1,2,3"` gets loaded into `val` in one shot.

### 💥 Resulting crash

- `stoi("1,2,3")` throws `std::invalid_argument`, because a comma isn't a valid part of an integer literal — the program crashes.
- `stoi("")` on an empty token (from a double space) also throws `std::invalid_argument` — same crash, different cause.

### ✅ The fix

Either guard every token with an emptiness check:

```cpp
while (getline(ss, val, ' '))
{
    if (!val.empty())
        arr.push_back(stoi(val));
}
```

...or — better — avoid the problem entirely by using `ss >> val`, which automatically skips any amount of whitespace (see the [Ultimate Brahmastra template](#-the-recommended-template-ultimate-brahmastra) above):

```cpp
int val;
while (ss >> val)
{
    arr.push_back(val);
}
```

---

## 📄 License

Feel free to use, adapt, and share this cheat sheet for study or reference purposes.
