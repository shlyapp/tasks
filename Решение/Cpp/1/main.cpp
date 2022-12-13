#include <iostream>
#include <string>
#include "fstream"

using namespace std;

int main()
{
    string input_file, output_file;
    cout << "Select input file: ";
    cin >> input_file;
    cout << "Select output file: ";
    cin >> output_file;

    ifstream fin(input_file, ios::in);
    ofstream fout(output_file, ios::out);

    int open = 0; int close = 0;
    char c;

    while (fin.get(c))
    {

            if (c == '{')
            {
                open++;
                continue;
            }

            if (c == '}')
            {
                close++;
                continue;
            }

            if (open == close)
                fout << c;
       
    }

}
