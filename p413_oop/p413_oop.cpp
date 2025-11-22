#include <iostream>
#include <string>

class Worker {
private:
    std::string first_name;
    std::string last_name;
    std::string patronymic;
    std::string position;
    int year_in_company;
    double salary;

public:
    explicit Worker(std::string f, std::string l, std::string pat, std::string p, int y, double s)
        : first_name(f), last_name(l), patronymic(pat), position(p), year_in_company(y), salary(s) {
    }

    const std::string getPosition() const { return position; }
    const int getYear() const { return year_in_company; }
    const double getSalary() const { return salary; }

    void displayWorker() const {
        std::cout << "First name: " << first_name << "\n"
            << "Last name: " << last_name << "\n"
            << "Otchestvo: " << patronymic << "\n"
            << "Position: " << position << "\n"
            << "Year in company: " << year_in_company << "\n"
            << "Salary: " << salary << "\n"
            << "_ _ _ _ _ _ _ _ _ _ _ _ \n";
    }

    static void showSalary(const Worker list[], int size, double minSalary) {
        std::cout << "All people who get bigger than " << minSalary << " salary:" << std::endl;

        for (int i = 0; i < size; i++) {
            if (list[i].getSalary() > minSalary) {
                list[i].displayWorker();

            }
        }

    }

    static void showPosition(const Worker list[], int size, const std::string& position) {
        std::cout << "All people who have position " << position << ":" << std::endl;
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (list[i].getPosition() == position) {
                list[i].displayWorker();
                found = true;
            }
            else {
                std::cout << "In company there are no people who have position " << position << "." << std::endl;
            }
        }

    }
};

int main() {
    const int size = 3;

    Worker w1("Anastasia", "Olkova", "Potassiumovich", "Admin", 2000, 21444.30);
    Worker w2("Vasya", "Sorokin", "Goddamovich", "Coder", 2011, 10411.99);
    Worker w3("Oleg", "Vasilyevich", "Timofeevich", "Lead", 2012, 12500.5);

    Worker list[size] = { w1, w2, w3 };

    Worker::showPosition(list, size, "Admin");
    Worker::showSalary(list, size, 11000.10);
}