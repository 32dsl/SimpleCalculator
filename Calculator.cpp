#include <stdexcept>
#include "Structions.h"

using namespace std;

double calculate(double num1, double num2, char op) {
    switch (op) {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
    case 'x':
    case 'X':
        return num1 * num2;
    case '/':
        if (num2 == 0) {
            throw runtime_error("错误：不能除以零");
        }
        return num1 / num2;
    default:
        throw runtime_error("错误：无效运算符");
    }
}

CalculationResult compute(const InputData& input) {
    CalculationResult result;
    try {
        result.value = calculate(input.num1, input.num2, input.op);
        result.success = true;
    }
    catch (const runtime_error& e) {
        result.errorMsg = e.what();
        result.success = false;
    }
    return result;
}