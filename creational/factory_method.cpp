#include<iostream>
#include<vector>

using namespace std;

enum ANIMAL {
    DOG = 1,
    CAT = 2,
    DUCK = 3
};

class Animal{
public:
    Animal(){};
    virtual void sound()=0;
};

class Dog : public Animal {
public:
    Dog(){
        cout << "Buy a dog!!!" << '\n';
    };
    void sound(){
        cout << "woof!!" << '\n';
    }
};

class Cat : public Animal {
public:
    Cat(){
        cout << "Buy a cat!!!" << '\n';
    };
    void sound(){
        cout << "meow!!" << '\n';
    }
};

class Duck : public Animal {
public:
    Duck(){
        cout << "Buy a duck!!!" << '\n';
    };
    void sound(){
        cout << "quack!!" << '\n';
    }
};

Animal* animalFactory(int type){
    Animal* animal;
    switch (type) {
        case DOG:
        {
            animal = new Dog;
            break;
        }
        case CAT:
        {
            animal = new Cat;
            break;
        }
        case DUCK:
        {
            animal = new Duck;
            break;
        }
        default :
        {
            cout << "Unknown type!!!" << endl;
            animal = nullptr;
            break;
        }
    }
    return animal;
}

typedef vector<Animal*> LIST_Animal;

class McDonald{
public:
    McDonald(){
    }
    void buyAnimal(int type){
        Animal* animal = animalFactory(type);
        if(animal)
            m_animal.push_back(animal);
    }
private:
    LIST_Animal m_animal;
};

int main(int argc, char* argv[]){
     McDonald mc;

     mc.buyAnimal(DOG);
     mc.buyAnimal(CAT);
     mc.buyAnimal(DUCK);

     return 0;
}
