#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

double GetResultOfCalculations(string obrZapis) {
    stack<double> stackOfNums;

    for (int i = 0; i < obrZapis.length(); i++) {

        if (obrZapis[i] >= '0' && obrZapis[i] <= '9') {

            string num;
            
            while (i < obrZapis.length() && (obrZapis[i] >= '0' && obrZapis[i] <= '9' || obrZapis[i] == '.')) {
                num += obrZapis[i];
                i++;
            }

            i--;
            stackOfNums.push(stod(num));
        }
        else if (obrZapis[i] == '+' || obrZapis[i] == '-' || obrZapis[i] == '*' || obrZapis[i] == '/') {
            double num2 = stackOfNums.top();
            stackOfNums.pop();
            double num1 = stackOfNums.top();
            stackOfNums.pop();

            switch (obrZapis[i]) {
            case '+':
                stackOfNums.push(num1 + num2);
                break;
            case '-':
                stackOfNums.push(num1 - num2);
                break;
            case '*':
                stackOfNums.push(num1 * num2);
                break;
            case '/':
                stackOfNums.push(num1 / num2);
                break;
            }
        }
        else if (obrZapis[i] == '^') {
            
            double num2 = stackOfNums.top();
            stackOfNums.pop();
            double num1 = stackOfNums.top();
            stackOfNums.pop();

            stackOfNums.push(pow(num1, num2));
        }
    }
    return stackOfNums.top();
}

int main() {

    cout << "Enter the inverse Polish record expression in the following format:  5 1 2 + 4 * + 3 -   " << endl;
    

    string obrZapis = "";

    obrZapis = "3 5 +";

    getline(cin, obrZapis);

    double result = GetResultOfCalculations(obrZapis); // Вычисление значения выражения

    cout << "Result: " << result << endl;

    return 0;
}