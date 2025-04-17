#include <iostream>
#include <string>
#include <limits>
#include "Structions.h"
using namespace std;

// �������������Ƿ���Ч
bool isValidNumber(const string& input, double& num) {
    try {
        size_t pos;
        num = stod(input, &pos);
        return (pos == input.length());  // ȷ�������ַ�����������
    }
    catch (...) {
        return false;
    }
}

// ���������Ƿ���Ч
bool isValidOperator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == 'x' || op == 'X');
}

// ��ȡ�û����벢����
InputData getInput() {
    InputData data;
    string input1, input2;
    char op;

    while (true) {
        cout << "�������һ������: ";
        cin >> input1;

        if (!isValidNumber(input1, data.num1)) {
            cout << "��Ч���֣����������룡" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "����������� (+, -, *, /): ";
        cin >> op;

        if (!isValidOperator(op)) {
            cout << "��Ч����������������룡" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "������ڶ�������: ";
        cin >> input2;

        if (!isValidNumber(input2, data.num2)) {
            cout << "��Ч���֣����������룡" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        data.op = op;
        break;
    }

    return data;
}

