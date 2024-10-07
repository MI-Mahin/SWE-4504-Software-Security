#include <iostream>
using namespace std;

class Duck {
    bool rubber;
public:
    virtual ~Duck() {}

    void setRubber(bool value) {
        rubber = value;
    }
    void quack() {
        if (rubber)
            cout << "Artificial Quack" << '\n';
        else
            cout << "Real Quack" << '\n';
    }
};

class RubberDuck : public Duck {
public:
    RubberDuck() {
        setRubber(true);
    }
};

class RealDuck : public Duck {
public:
    RealDuck() {
        setRubber(false);
    }
};
/*void processData(void* data, int type) {
    if (type == 1) {
        int* intPtr = (int*)data;
        cout << "Integer: " << *intPtr << endl;
    } else if (type == 2) {
        double* doublePtr = (double*)data;
        cout << "Double: " << *doublePtr << endl;
    } else {
        cout << "Unknown type!" << endl;
    }
}*/


template <typename T>
void processData(T value) {
    if constexpr (is_same<T, int>::value) {
        cout << "Integer: " << value << endl;
    } else if constexpr (is_same<T, double>::value) {
        cout << "Double: " << value << endl;
    } else {
        cout << "Unknown type!" << endl;
    }
}



int main() {
    int i = 42;
    double d = 3.14;

    //processData(&i, 2);

    processData(i);
    processData(d);

    Duck *d1 = new RubberDuck();
    Duck *d2 = new RealDuck();
    RealDuck *rd = dynamic_cast<RealDuck*>(d2);

    if(rd)rd->quack();
    else cout<<"Casting Error"<<'\n';

    return 0;
}
