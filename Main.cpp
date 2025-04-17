#include <iostream>
#include "Structions.h"

using namespace std;

int main() {
    showWelcome();  // 显示欢迎界面

    bool running = true;
    while (running) {
        // 获取输入
        InputData input = getInput();

        // 检查退出指令
        if (input.op == 'q' || input.op == 'Q') {
            running = false;
            continue;
        }

        // 执行计算
        CalculationResult result = compute(input);

        // 显示结果
        displayResult(result);

        // 询问是否继续
        running = askContinue();
    }

    showExit();  // 显示退出信息
    return 0;
}