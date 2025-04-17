#include <iostream>
#include <string>
#include <limits>
#include "Structions.h"
using namespace std;

// 检查输入的数字是否有效
bool isValidNumber(const string& input, double& num) {
    try {
        size_t pos;
        num = stod(input, &pos);
        return (pos == input.length());  // 确保整个字符串都是数字
    }
    catch (...) {
        return false;
    }
}

// 检查运算符是否有效
bool isValidOperator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == 'x' || op == 'X');
}

// 获取用户输入并解析
InputData getInput() {
    InputData data;
    string input1, input2;
    char op;

    while (true) {
        cout << "请输入第一个数字: ";
        cin >> input1;

        if (!isValidNumber(input1, data.num1)) {
            cout << "无效数字，请重新输入！" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "请输入运算符 (+, -, *, /): ";
        cin >> op;

        if (!isValidOperator(op)) {
            cout << "无效运算符，请重新输入！" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "请输入第二个数字: ";
        cin >> input2;

        if (!isValidNumber(input2, data.num2)) {
            cout << "无效数字，请重新输入！" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        data.op = op;
        break;
    }

    return data;
}

