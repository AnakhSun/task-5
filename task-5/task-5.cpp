#include <iostream>
#include <string>

using namespace std;
int main()
{
    int t = 1;
    while (t) {

        int s;
        cout << "Input mass size: ";
        cin >> s;
        int* source = new int[s];
        int flag = 0;
        int new_len = 0;
        int n;

        cout << "Input mass: ";
        for (int i = 0; i < s; i++) {
            cin >> n;
            source[i] = n;
        }

        for (int i = 0; i < s; i++) {
            //cout << "i = " << i << " new_len = " << new_len << endl;
            if (source[i] == 0) {
                if (flag == 0) {
                    new_len += 1;
                }
                flag = 1;
            }
            else {
                new_len += 1;
                flag = 0;
            }
        }

        //cout << "new len = " << new_len << endl;
        string* result = new string[new_len];
        int g = 0;
        int zero_count = 0;
        int p = 0;
        int j = 0;

        for (int i = 0; i < s; i++) {
            j = i;
            while (source[j] == 0) {
                zero_count += 1;
                j += 1;
            }
            if (source[i] == 0) {
                result[p] = "0" + to_string(zero_count);
                p += 1;
                i += zero_count - 1;
            }
            else {
                result[p] = to_string(source[i]);
                p += 1;
                zero_count = 0;
            }
        }

        for (int i = 0; i < new_len; i++) {
            cout << result[i] << "\t";
        }

        cout << endl << "do u wanna continue? 1 - yes; 0 - no:   - ";
        cin >> t;
    }
    //test
}