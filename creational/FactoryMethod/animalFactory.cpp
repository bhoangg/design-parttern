#include<iostream>
#include<vector>
#include <memory>

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
    };
    virtual void sound(){
        cout << "woof!!" << '\n';
    }
};

class Cat : public Animal {
public:
    Cat(){
    };
    virtual void sound(){
        cout << "meow!!" << '\n';
    }
};

class Duck : public Animal {
public:
    Duck(){
    };
    virtual void sound(){
        cout << "quack!!" << '\n';
    }
};

class AnimalFactory{
public:
    unique_ptr<Animal> createAnimal(int type){
        Animal* animal;
        switch (type) {
            case DOG:
            {
                animal = new Dog;
                cout << "Buy a dog!!!" << '\n';
                break;
            }
            case CAT:
            {
                animal = new Cat;
                cout << "Buy a cat!!!" << '\n';
                break;
            }
            case DUCK:
            {
                animal = new Duck;
                cout << "Buy a duck!!!" << '\n';
                break;
            }
            default :
            {
                cout << "Unknown type!!!" << endl;
                break;
            }
        }
        return unique_ptr<Animal>(animal);
    }
};

typedef vector<shared_ptr<Animal>> LIST_Animal;

class McDonald{
public:
    McDonald(){
    }
    void buyAnimal(int type){
        shared_ptr<Animal> animal = factory.createAnimal(type);
        // cout << animal.use_count() << endl;
        if(animal.use_count())
            m_animal.push_back(animal);
    }

    void test(){
        for(auto it : m_animal){
            // cout << it.use_count() << endl;
            it->sound();
        }
    }
private:
    LIST_Animal m_animal;
    AnimalFactory factory;
};

int main(int argc, char* argv[]){
     McDonald mc;

     mc.buyAnimal(DOG);
     mc.buyAnimal(CAT);
     mc.buyAnimal(DUCK);

     mc.test();

     return 0;
}
