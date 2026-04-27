#ifndef AIRGEAD_BANKING_INVESTMENTCALCULATOR_H_
#define AIRGEAD_BANKING_INVESTMENTCALCULATOR_H_

class InvestmentCalculator {
public:
    // Default constructor
    InvestmentCalculator();

    // Mutators
    void setInitialInvestment(double t_initialInvestment);
    void setMonthlyDeposit(double t_monthlyDeposit);
    void setAnnualInterest(double t_annualInterest);
    void setNumberOfYears(int t_numberOfYears);

    // Accessors
    double getInitialInvestment() const;
    double getMonthlyDeposit() const;
    double getAnnualInterest() const;
    int getNumberOfYears() const;

    // Main program functions
    void collectUserInput();
    void displayInputScreen() const;
    void displayReportWithoutMonthlyDeposits() const;
    void displayReportWithMonthlyDeposits() const;

private:
    // Member variables
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numberOfYears;

    // Helper functions
    double getValidatedDouble(const char* t_prompt) const;
    int getValidatedInt(const char* t_prompt) const;
    double calculateMonthlyRate() const;
};

#endif // AIRGEAD_BANKING_INVESTMENTCALCULATOR_H_#pragma once
