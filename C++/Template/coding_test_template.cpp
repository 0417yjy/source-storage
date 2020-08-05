#include <iostream>
#include <string>

using namespace std;

/* Write your own Classes, Structures, or Functions here */

/* Main Function */
int main(void) {
    int test_num;
    string input;

    /* Define the number of test cases */
    cin >> test_num;
    cin.ignore();
    string* answers = new string[test_num];

    for(int i=0;i<test_num;i++) {
        /* Get input */
        getline(cin, input);

        /* Write your solution here */

        /* Store the results to answer array */
        // answers[i] = [RETURN_THE_ANSWER];
    }

    /* Print outputs here */
    cout << endl;
    for (int i = 0; i < test_num; i++)
        cout << answers[i] << endl;

	return 0;
}