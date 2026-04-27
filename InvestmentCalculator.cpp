#include "InvestmentCalculator.h"

#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>

using namespace std;

// Default constructor
InvestmentCalculator::InvestmentCalculator() {
    m_initialInvestment = 0.0;
    m_monthlyDeposit = 0.0;
    m_annualInterest = 0.0;
    m_numberOfYears = 0;
}

// Mutators
void InvestmentCalculator::setInitialInvestment(double t_initialInvestment) {
    m_initialInvestment = t_initialInvestment;
}

void InvestmentCalculator::setMonthlyDeposit(double t_monthlyDeposit) {
    m_monthlyDeposit = t_monthlyDeposit;
}

void InvestmentCalculator::setAnnualInterest(double t_annualInterest) {
    m_annualInterest = t_annualInterest;
}

void InvestmentCalculator::setNumberOfYears(int t_numberOfYears) {
    m_numberOfYears = t_numberOfYears;
}

// Accessors
double InvestmentCalculator::getInitialInvestment() const {
    return m_initialInvestment;
}

double InvestmentCalculator::getMonthlyDeposit() const {
    return m_monthlyDeposit;
}

double InvestmentCalculator::getAnnualInterest() const {
    return m_annualInterest;
}

int InvestmentCalculator::getNumberOfYears() const {
    return m_numberOfYears;
}

// Helper function to validate double input
double InvestmentCalculator::getValidatedDouble(const char* t_prompt) const {
    double value = 0.0;

    while (true) {
        cout << t_prompt;
        cin >> value;

        try {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid input. Please enter a numeric value.\n");
            }

            if (value < 0) {
                throw runtime_error("Value cannot be negative. Please try again.\n");
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        catch (const exception& e) {
            cout << e.what();
        }
    }
}

// Helper function to validate integer input
int InvestmentCalculator::getValidatedInt(const char* t_prompt) const {
    int value = 0;

    while (true) {
        cout << t_prompt;
        cin >> value;

        try {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid input. Please enter a whole number.\n");
            }

            if (value <= 0) {
                throw runtime_error("Value must be greater than 0. Please try again.\n");
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        catch (const exception& e) {
            cout << e.what();
        }
    }
}

// Converts annual interest rate to monthly decimal rate
double InvestmentCalculator::calculateMonthlyRate() const {
    return (m_annualInterest / 100.0) / 12.0;
}

// Collects all user input and stores it in the object
void InvestmentCalculator::collectUserInput() {
    m_initialInvestment = getValidatedDouble("Initial Investment Amount: ");
    m_monthlyDeposit = getValidatedDouble("Monthly Deposit: ");
    m_annualInterest = getValidatedDouble("Annual Interest: ");
    m_numberOfYears = getValidatedInt("Number of Years: ");
}

// Displays the user input summary screen
void InvestmentCalculator::displayInputScreen() const {
    cout << "\n**********************************" << endl;
    cout << "********** Data Input ************" << endl;
    cout << fixed << setprecision(2);
    cout << "Initial Investment Amount: $" << m_initialInvestment << endl;
    cout << "Monthly Deposit: $" << m_monthlyDeposit << endl;
    cout << "Annual Interest: %" << m_annualInterest << endl;
    cout << "Number of Years: " << m_numberOfYears << endl;
}

// Displays report without monthly deposits
void InvestmentCalculator::displayReportWithoutMonthlyDeposits() const {
    double currentBalance = m_initialInvestment;
    double monthlyRate = calculateMonthlyRate();

    cout << "\n\n  Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "=====================================================================" << endl;
    cout << left << setw(10) << "Year"
        << setw(25) << "Year End Balance"
        << setw(25) << "Year End Earned Interest" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double yearlyInterest = 0.0;

        for (int month = 1; month <= 12; ++month) {
            double monthlyInterest = currentBalance * monthlyRate;
            yearlyInterest += monthlyInterest;
            currentBalance += monthlyInterest;
        }

        cout << left << setw(10) << year
            << "$" << setw(24) << fixed << setprecision(2) << currentBalance
            << "$" << setw(24) << fixed << setprecision(2) << yearlyInterest << endl;
    }
}

// Displays report with monthly deposits
void InvestmentCalculator::displayReportWithMonthlyDeposits() const {
    double currentBalance = m_initialInvestment;
    double monthlyRate = calculateMonthlyRate();

    cout << "\n\n  Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "=====================================================================" << endl;
    cout << left << setw(10) << "Year"
        << setw(25) << "Year End Balance"
        << setw(25) << "Year End Earned Interest" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double yearlyInterest = 0.0;

        for (int month = 1; month <= 12; ++month) {
            currentBalance += m_monthlyDeposit;
            double monthlyInterest = currentBalance * monthlyRate;
            yearlyInterest += monthlyInterest;
            currentBalance += monthlyInterest;
        }

        cout << left << setw(10) << year
            << "$" << setw(24) << fixed << setprecision(2) << currentBalance
            << "$" << setw(24) << fixed << setprecision(2) << yearlyInterest << endl;
    }
}