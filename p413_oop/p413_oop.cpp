#include <iostream>
#include <string>
using namespace std;

class DomesticAnimal {
protected:
    string name;
    string breed;
    int age;

public:
    DomesticAnimal(string n, string b, int a) {
        name = n;
        breed = b;
        age = a;
    }

    virtual void Sound() = 0;

    virtual void Show() {
        cout << "Name: " << name << endl;
    }

    virtual void Type() {
        cout << "Breed: " << breed << endl;
    }
};

class Dog : public DomesticAnimal {
public:
    Dog(string n, string b, int a) : DomesticAnimal(n, b, a) {}

    void Sound() {
        cout << "Woof woof!" << endl;
    }

    void Show() {
        cout << "Dog - ";
        DomesticAnimal::Show();
    }

    void Type() {
        cout << "Dog breed: ";
        DomesticAnimal::Type();
    }
};

class Cat : public DomesticAnimal {
public:
    Cat(string n, string b, int a) : DomesticAnimal(n, b, a) {}

    void Sound() {
        cout << "Meow meow!" << endl;
    }

    void Show() {
        cout << "Cat - ";
        DomesticAnimal::Show();
    }

    void Type() {
        cout << "Cat breed: ";
        DomesticAnimal::Type();
    }
};

class Parrot : public DomesticAnimal {
public:
    Parrot(string n, string b, int a) : DomesticAnimal(n, b, a) {}

    void Sound() {
        cout << "Hello! Squawk!" << endl;
    }

    void Show() {
        cout << "Parrot - ";
        DomesticAnimal::Show();
    }

    void Type() {
        cout << "Parrot type: ";
        DomesticAnimal::Type();
    }
};

class Hamster : public DomesticAnimal {
public:
    Hamster(string n, string b, int a) : DomesticAnimal(n, b, a) {}

    void Sound() {
        cout << "Squeak squeak!" << endl;
    }

    void Show() {
        cout << "Hamster - ";
        DomesticAnimal::Show();
    }

    void Type() {
        cout << "Hamster type: ";
        DomesticAnimal::Type();
    }
};

int main() {
    Dog dog("Buddy", "German Shepherd", 3);
    Cat cat("Whiskers", "Siamese", 2);
    Parrot parrot("Polly", "Parakeet", 1);
    Hamster hamster("Fuzzy", "Syrian", 1);

    dog.Show();
    dog.Type();
    dog.Sound();
    cout << endl;

    cat.Show();
    cat.Type();
    cat.Sound();
    cout << endl;

    parrot.Show();
    parrot.Type();
    parrot.Sound();
    cout << endl;

    hamster.Show();
    hamster.Type();
    hamster.Sound();
}