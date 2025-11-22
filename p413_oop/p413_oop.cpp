#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Visa {
private:
    string country;
    string expiryDate;

public:
    Visa(string cntry, string expiry)
        : country(cntry), expiryDate(expiry) {
    }

    void printVisaInfo() const {
        cout << "  " << country << " (before " << expiryDate << ")" << endl;
    }
};

class Passport {
protected:
    string passportNumber;
    string fullName;
    string birthDate;

public:
    Passport(string number, string name, string birth)
        : passportNumber(number), fullName(name), birthDate(birth) {
    }

    virtual void printInfo() const {
        cout << "=== Passport of a citizen of Ukraine ===" << endl;
        cout << "Number: " << passportNumber << endl;
        cout << "Full name: " << fullName << endl;
        cout << "Birth date: " << birthDate << endl;
    }
};

class ForeignPassport : public Passport {
private:
    string foreignPassportNumber;
    vector<Visa> visas;

public:
    ForeignPassport(string passportNum, string name, string birth, string foreignPassportNum)
        : Passport(passportNum, name, birth), foreignPassportNumber(foreignPassportNum) {
    }

    void addVisa(const string& country, const string& expiry) {
        visas.push_back(Visa(country, expiry));
    }

    void printInfo() const override {
        cout << "=== Foreign passport ===" << endl;
        cout << "Country's passport: " << passportNumber << endl;
        cout << "Number foreign passport: " << foreignPassportNumber << endl;
        cout << "Full name: " << fullName << endl;
        cout << "Birth date: " << birthDate << endl;

        printVisas();
    }

    void printVisas() const {
        if (visas.empty()) {
            cout << "Visas: nope" << endl;
        }
        else {
            cout << "Visas:" << endl;
            for (const auto& visa : visas) {
                visa.printVisaInfo();
            }
        }
    }
};

int main() {
    Passport ukrainianPassport("884567", "Hryak Piggy Hryukovich", "15.03.1990");

    ForeignPassport foreignPassport("884567", "Hryak Piggy Hryukovich", "15.03.1990", "1234567");

    foreignPassport.addVisa("Germany", "01.09.2023");
    foreignPassport.addVisa("USA", "15.10.2023");
    foreignPassport.addVisa("China", "01.12.2023");

    ukrainianPassport.printInfo();
    cout << endl;

    foreignPassport.printInfo();
    cout << endl;
}