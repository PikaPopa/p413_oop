#include <iostream>
#include <string>

using namespace std;

class Transport {
protected:
    string name;
    double speed;
    double costPerKm;
    double capacity;

public:
    Transport(string n, double s, double cost, double cap)
        : name(n), speed(s), costPerKm(cost), capacity(cap) {
    }

    virtual double calculateTime(double distance, double weight) const = 0;
    virtual double calculateCost(double distance, double weight) const = 0;
    virtual void printInfo() const = 0;
};

class Car : public Transport {
public:
    Car(string n, double s, double cost, double cap)
        : Transport(n, s, cost, cap) {
    }

    double calculateTime(double distance, double weight) const override {
        if (weight > capacity) return -1;
        return distance / speed;
    }

    double calculateCost(double distance, double weight) const override {
        if (weight > capacity) return -1;
        return distance * costPerKm;
    }

    void printInfo() const override {
        cout << "Car '" << name << "' (" << speed << " km/h, "
            << capacity << " kg)" << endl;
    }
};

class Bicycle : public Transport {
public:
    Bicycle(string n, double s, double cost, double cap)
        : Transport(n, s, cost, cap) {
    }

    double calculateTime(double distance, double weight) const override {
        if (weight > capacity) return -1;
        double effectiveSpeed = speed * (1 - weight / (capacity * 2));
        return distance / effectiveSpeed;
    }

    double calculateCost(double distance, double weight) const override {
        if (weight > capacity) return -1;
        return distance * costPerKm;
    }

    void printInfo() const override {
        cout << "Bicycle '" << name << "' (" << speed << " km/h, "
            << capacity << " kg)" << endl;
    }
};

class Carriage : public Transport {
public:
    Carriage(string n, double s, double cost, double cap)
        : Transport(n, s, cost, cap) {
    }

    double calculateTime(double distance, double weight) const override {
        if (weight > capacity) return -1;
        double effectiveSpeed = speed * (1 - weight / (capacity * 1.5));
        return distance / effectiveSpeed;
    }

    double calculateCost(double distance, double weight) const override {
        if (weight > capacity) return -1;
        return distance * costPerKm * (1 + weight / capacity);
    }

    void printInfo() const override {
        cout << "Carriage '" << name << "' (" << speed << " km/h, "
            << capacity << " kg)" << endl;
    }
};

int main() {
    Car car("Sedan", 80, 15, 500);
    Bicycle bicycle("Mountain", 15, 5, 20);
    Carriage carriage("Horse", 10, 8, 300);

    Transport* transports[] = { &car, &bicycle, &carriage };

    double distance = 50;
    double weight = 100;

    cout << "=== TRANSPORT CALCULATION ===" << endl;
    cout << "Distance: " << distance << " km, Weight: " << weight << " kg\n" << endl;

    for (int i = 0; i < 3; i++) {
        transports[i]->printInfo();
        double time = transports[i]->calculateTime(distance, weight);
        double cost = transports[i]->calculateCost(distance, weight);

        if (time > 0) {
            cout << "Time: " << time << " h, Cost: " << cost << " rub" << endl;
        }
        else {
            cout << "Transport impossible!" << endl;
        }
        cout << endl;
    }
}