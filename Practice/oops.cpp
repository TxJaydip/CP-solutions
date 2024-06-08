#include "bits/stdc++.h"
using namespace std;

class animal
{
protected:
    int heightCm;
    string givenName;
    string type;

public:
    animal()
    {
        heightCm = 100;
        type = "";
    }
    virtual void show()
    {
        cout << "base class" << endl;
    }
    animal(int heightCm, string type, string givenName)
    {

        this->heightCm = heightCm;
        this->type = type;
        this->givenName = givenName;
    }
    virtual void showHeight()
    {
        cout << "Height: " << heightCm << endl;
    }
    void showName()
    {
        cout << "Given name of animal is: " << this->givenName << endl;
    }
    void showType()
    {
        cout << "Animal is: " << type << endl;
    }
    void hello()
    {
        cout << "Hello from base" << endl;
    }
};

class dog : public animal
{
private:
    string breed;

public:
    dog(int heightCm, string givenName, string breed)
    {
        this->type = "Default";
        this->heightCm = heightCm;
        this->givenName = givenName;
        this->breed = breed;
    }
    dog()
    {
    }

    void hello(int a)
    {
        cout << "hello from derived, a: " << a << endl;
    }
    void show() override
    {
        cout << "Derived" << endl;
    }
    void showType(int price)
    {
        cout << "Dog's breed is: " << breed << ", having price: " << price << endl;
    }
    void showHeight() override
    {
        cout << "Derived virtual" << endl;
    }
};

int main()
{
    // animal myDog(10, "Dog", "Moti");
    // dog myDog2(20, "Motii", "German");

    // myDog.showName();
    // myDog.showType();

    // myDog2.showName();
    // myDog2.animal::showType();

    // animal *a;
    // dog b;
    // b.show();
    // // cout << "before" << endl;
    // // a->show();
    // // cout << "after" << endl;
    // a = &b;
    // a->show();
    // a->showHeight();
    // b.showHeight();

    dog d1;
    d1.animal::hello();
    d1.hello(2);

    return 0;
}