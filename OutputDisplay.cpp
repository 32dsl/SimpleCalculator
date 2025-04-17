#include <iostream>
#include <iomanip>
#include "Structions.h"

using namespace std;

// 显示欢迎界面
void showWelcome() {
    cout << "========================\n"
        << "   简易控制台计算器   \n"
        << "========================\n"
        << "支持运算符: + - * / x\n"
        << "输入 'q' 退出程序\n"
        << "========================\n\n";
}

// 格式化输出计算结果
void displayResult(const CalculationResult& result) {
    cout << "\n[计算结果] ";
    if (result.success) {
        cout << fixed << setprecision(2) << result.value;
    }
    else {
        cout << "!!! " << result.errorMsg;
    }
    cout << "\n\n";
}

// 询问是否继续计算
bool askContinue() {
    char choice;
    while (true) {
        cout << "继续计算？(y/n): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (tolower(choice) == 'y') return true;
        if (tolower(choice) == 'n') return false;

        cout << "无效输入，请输入 y 或 n\n";
    }
}

// 显示退出信息
void showExit() {
    cout << "\n感谢使用计算器，再见！\n";
}