#include <iostream>
#include <string>

class Employer {
public:
    virtual void print() = 0;
};

class President : public Employer {
public:
    void print() override {
        std::cout << "President: Manages the entire organization." << std::endl;
    }
};

class Manager : public Employer {
public:
    void print() override {
        std::cout << "Manager: Manages departments and teams." << std::endl;
    }
};

class Worker : public Employer {
public:
    void print() override {
        std::cout << "Worker: Performs specific tasks and operations." << std::endl;
    }
};

int main() {
    President putin;
    Manager scarlett;
    Worker joe;

    putin.print();
    scarlett.print();
    joe.print();
}