#include "InvestmentCalculator.h"

#include <iostream>
#include <limits>

using namespace std;

int main() {
    // Create object for investment calculations
    InvestmentCalculator calculator;

    // Gather input from user
    calculator.collectUserInput();

    // Display input values back to the user
    calculator.displayInputScreen();

    // Pause before showing reports
    cout << "Press Enter to continue..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Display both yearly reports
    calculator.displayReportWithoutMonthlyDeposits();
    calculator.displayReportWithMonthlyDeposits();

    return 0;
}