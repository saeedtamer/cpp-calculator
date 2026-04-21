#include <iostream>
#include <string>
#include <vector>
#include<cctype>
#include<cmath>
using namespace std;

int main() {

    string input, num="", word="", record, choise="y";
    vector<double> numbers;
    vector<char> ops;
    char A;
    vector<string> history;

    do {
        input.clear();
        num.clear();
        numbers.clear();
        record.clear();

        cout << "Enter expression: ";
        getline(cin, input);

        for(int i=0; i<input.size(); i++) {
            record = input[i] + " ";
        }

        for(char c: input) {
            if(isdigit(c)) {
                num+=c;
            }
            else if(isalpha(c)) {
                word+=c;
            } else {
                if(num!="") {
                    numbers.push_back(stod(num));
                    num="";
                }
                if(word!="") {
                    ops.push_back(word[0]);
                    word="";
                }

                if(c!=' ') {
                    ops.push_back(c);
                }
            }
        }
        if(word!="") {
            ops.push_back(word[0]);
        }
        if(num!="") {
            numbers.push_back(stod(num));
        }

        for(double s: numbers) {
            cout << s << " ";
        }
        for(char c: ops) {
            cout << c << " ";
        }

        for(int i=0 ; i<ops.size() ; i++) {
            if(ops[i]=='s') {
                numbers[i]=sqrt(numbers[i]);

                ops.erase(ops.begin()+i);

                i--;
            }
        }

        for(int i=0 ; i<ops.size() ; i++) {
            if(ops[i]=='^') {
                numbers[i]=pow(numbers[i],numbers[i+1]);

                numbers.erase(numbers.begin()+i+1);
                ops.erase(ops.begin()+i);

                i--;
            }
        }

        for(int i=0 ; i<ops.size() ; i++) {



            if(ops[i]=='*'||ops[i]=='/') {
                if(ops[i]=='*') {
                    numbers[i]=numbers[i]*numbers[i+1];
                }
                else if(ops[i]=='/') {
                    numbers[i]=numbers[i]/numbers[i+1];
                }

                numbers.erase(numbers.begin()+i+1);
                ops.erase(ops.begin()+i);

                i--;

            }
        }

        for(int i=0 ; i<ops.size() ; i++) {
            if(ops[i]=='+') {
                numbers[i]=numbers[i]+numbers[i+1];
            }
            else if(ops[i]=='-') {
                numbers[i]=numbers[i]-numbers[i+1];
            }
            numbers.erase(numbers.begin()+i+1);
            ops.erase(ops.begin()+i);
            i--;
        }

        cout << numbers[0] << endl;

        record = record + " = " + to_string(numbers[0]);
        history.push_back(record);

        cout << "Press Y to recalculate" << endl;
        cin >> A;
        cin.ignore();
    } while(A=='y'||A=='Y');

    cout << "Do you want to see HISTORY (Y/N)" << endl;
    cin >> choise;
    if(choise=="y"||choise=="Y") {
        for(string s: history) {
            cout << s << endl;
        }
    }
    return 0;
}