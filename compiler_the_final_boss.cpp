ios_base::sync_with_studio(false);
cin.tie(NULL):

string s;
stringstream(s);
int n;
cin>>n;
if(cin>>ws && getline(cin,user_string)){
    
}

string line;
getline(cin, line);
stringstream ss(line);
string token;
vector<int> arr;

while (getline(ss, token, ',')) {
    arr.push_back(stoi(token));
}


getline(cin, line);Grabs the whole raw input line as one text string.stringstream ss(line);Turns that text string into an input stream (treating the string like a file or keyboard input).while (getline(ss, token, ','))Chops the string stream into smaller pieces (token) every time it hits a comma.arr.push_back(stoi(token));Converts each text piece (like "12") into an actual integer (12) and saves it.
/*Line 1 (cin >> test_cases): Reads the integer 2. It stops right at the \n, leaving \n\r sitting in the buffer.Line 2 (cin >> ws): Steps in and aggressively eats up that hanging \n\r until it reaches the letter 'H'.Line 3 (getline(cin, user_string)): Cleanly reads "Hello World" without skipping a beat.*/


#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n); // Initialize vector with size n
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Directly populate the vector
    }

    // Print the array
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }
    return 0;
}

//ye tbh use krna jb line 1/n 2/n 3/n me input le rhi ho




#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    // Clear the leftover newline character from the input buffer
    string dummy;
    getline(cin, dummy); 

    string line;
    getline(cin, line); // Read the actual line of numbers

    stringstream ss(line);
    string token;
    vector<int> arr; // Start with an empty vector

    while (getline(ss, token, ' ')) {
        if (!token.empty()) { // Handle potential extra spaces
            arr.push_back(stoi(token));
        }
    }

    // Print the array
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < (int)arr.size() - 1) cout << " ";
    }
    return 0;
}
//ye ek sath sare input le lega , isko n se koi lena dena nhi h , agr n =3 or sirf 2 hi likha fir b chl jayega





//agar n line tk string ka input read krna ho tho

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Fast I/O for TCS Compiler
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n; // Reads the number '2'

    cin.ignore(); // CRITICAL: Removes the '\n' right after the number '2'

    vector<string> words;
    string current_word;

    // Loop exactly 'n' times to read the next lines
    for (int i = 0; i < n; i++) {
        if (getline(cin, current_word)) {
            words.push_back(current_word);
        }
    }

    // Example processing: Printing the stored strings
    cout << "--- Stored Strings ---" << "\n";
    for (int i = 0; i < words.size(); i++) {
        cout << "Index " << i << ": " << words[i] << "\n";
    }

    return 0;
}


//or sirf do line ka string input 
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Fast I/O for TCS Compiler
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2;

    // Read Line 1
    getline(cin, str1);

    // Read Line 2
    getline(cin, str2);

    // Verification Output
    cout << "String 1: " << str1 << "\n";
    cout << "String 2: " << str2 << "\n";

    return 0;
}


//practice code 
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    // Clear the leftover newline and any trailing spaces after 'n'
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string line;
    getline(cin, line); // Read the line: "1 2 3 4"

    stringstream ss(line);
    string token;
    vector<long long> arr; // Use long long to handle large products

    // Parse the input elements
    while (getline(ss, token, ' ')) {
        if (!token.empty()) {
            arr.push_back(stoll(token)); // stoll converts string to long long
        }
    }

    int size = arr.size();
    if (size == 0) return 0;

    // Output vector initialized to 1
    vector<long long> ans(size, 1);

    // Step 1: Calculate prefix products
    // ans[i] will contain the product of all elements to the left of i
    long long left_product = 1;
    for (int i = 0; i < size; i++) {
        ans[i] = left_product;
        left_product *= arr[i];
    }

    // Step 2: Calculate suffix products on the fly
    // Multiply ans[i] by the product of all elements to the right of i
    long long right_product = 1;
    for (int i = size - 1; i >= 0; i--) {
        ans[i] *= right_product;
        right_product *= arr[i];
    }

    // Print the result array
    for (int i = 0; i < size; i++) {
        cout << ans[i];
        if (i < size - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}





// Alternative TCS-bulletproof input structure
int n;
if (cin >> n) {
    vector<long long> arr;
    long long temp;
    // Reads strictly until the buffer runs out, ignoring spacing and invisible line quirks
    while (cin >> temp) {
        arr.push_back(temp);
    }
    // Proceed with Prefix/Suffix logic...
}
