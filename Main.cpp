#include <iostream>
#include "Structions.h"

using namespace std;

int main() {
    showWelcome();  // ��ʾ��ӭ����

    bool running = true;
    while (running) {
        // ��ȡ����
        InputData input = getInput();

        // ����˳�ָ��
        if (input.op == 'q' || input.op == 'Q') {
            running = false;
            continue;
        }

        // ִ�м���
        CalculationResult result = compute(input);

        // ��ʾ���
        displayResult(result);

        // ѯ���Ƿ����
        running = askContinue();
    }

    showExit();  // ��ʾ�˳���Ϣ
    return 0;
}