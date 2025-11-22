#include <iostream>

using namespace std;

class Student {
protected:
    string firstName;
    string lastName;
    string group;
    double averageGrade;

public:
    Student(string first, string last, string grp, double avgGrade)
        : firstName(first), lastName(last), group(grp), averageGrade(avgGrade) {
    }


    virtual void printInfo() {
        cout << "Student: " << firstName << " " << lastName << endl;
        cout << "Group: " << group << endl;
        cout << "Average grade: " << averageGrade << endl;
    }
};

class Aspirant : public Student {
private:
    string researchTopic;
    string scienceSupervisor;
public:
public:
    Aspirant(string first, string last, string grp, double avgGrade,
        string topic, string supervisor)
        : Student(first, last, grp, avgGrade),
        researchTopic(topic),
        scienceSupervisor(supervisor) {
    }

        void printInfo() override {
            cout << "Aspirant: " << firstName << " " << lastName << endl;
            cout << "Group: " << group << endl;
            cout << "Average Grade: " << averageGrade << endl;
            cout << "Research topic: " << researchTopic << endl;
            cout << "Research supervisor: " << scienceSupervisor << endl;
        }
    };

int main()
{
    Student student1("Oleg", "Kot", "p-422", 4.2);
    Student student2("Sergey", "Kebab", "p-422", 4.8);

    Aspirant aspirant1("Kirill", "Bogomolov", "s-212", 3.7, "Ancient people", "Alexandr China");
    Aspirant aspirant2("Gomer", "Simpson", "s-218", 4.9, "Mechanical engineering", "John Doe");

    cout << "First Student: " << endl;
    student1.printInfo();
    cout << "Second Student: " << endl;
    student2.printInfo();

    cout << "\n";

    cout << "First Aspirant: " << endl;
    aspirant1.printInfo();
    cout << "Second Aspirant: " << endl;
    aspirant2.printInfo();
}