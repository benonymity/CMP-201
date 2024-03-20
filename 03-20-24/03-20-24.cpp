#include <iostream>
#include <string>
#include <vector>

class Employee {
  public:
    Employee(const std::string& f, const std::string& l, const std::string& Ssn)
        : first(f), last(l), ssn(Ssn) {
    }

    virtual double earning() const = 0;

    void print() const {
        std::cout << "First Name: " + first + "\nLast Name: " + last +
                         "\nSSN: " + ssn + "\n";
    }

  private:
    std::string first;
    std::string last;
    std::string ssn;
};

class SalariedEmployee : public Employee {
  public:
    SalariedEmployee(const std::string& f, const std::string& l,
                     const std::string& S, const double s)
        : Employee(f, l, S), weekly_salary(s) {
    }

    double earning() const {
        return weekly_salary;
    }

  private:
    double weekly_salary;
};

class ComissionedEmployee : public Employee {
  public:
    ComissionedEmployee(const std::string& f, const std::string& l,
                        const std::string& S, const double s, const double r)
        : Employee(f, l, S), gross_sales(s), commission_rate(r) {
    }

    double earning() const {
        return gross_sales * commission_rate;
    }

  private:
    double gross_sales;
    double commission_rate;
};

int main() {
    std::vector<Employee*> resources;

    SalariedEmployee e001{"Bill", "Smith", "24", 8000};
    ComissionedEmployee e002{"Sue", "Jones", "276-54-3598", 50000, .06};
    // Employee e007{"James", "Bond", "007"}; // Doesn't work because pure
    // virtual function

    resources.push_back(&e001);
    resources.push_back(&e002);
    // resources.push_back(&e007);

    for (size_t i = 0; i < resources.size(); i++) {
        resources[i]->print();
        std::cout << "Earnings: " + std::to_string(resources[i]->earning()) +
                         "\n";
    }

    // Employee employee{"John", "Doe", "12345678"};
    // employee.print();
    // std::cout << "Earnings: " + std::to_string(employee.earning()) +
    // "\n";
}
