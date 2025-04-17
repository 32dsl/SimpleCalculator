#include <string>

class CalculationResult {
public:
    double value;
    std::string errorMsg;
    bool success;
}; 
class InputData
{
public:
    double num1;
    double num2;
    char op;
};
void showWelcome();
void displayResult(const CalculationResult& result);
bool askContinue();
void showExit();

double calculate(double num1, double num2, char op);
CalculationResult compute(const InputData& input);

bool isValidNumber(const std::string& input, double& num);
bool isValidOperator(char op);
InputData getInput();