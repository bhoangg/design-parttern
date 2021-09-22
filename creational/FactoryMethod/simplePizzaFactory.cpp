#include <iostream>
#include <vector>

using namespace std;

enum PIZZA_TYPE{
    CHEESE=1,
    PEPPERONI=2,
    CLAM=3,
    VEGGIE=4
};

class Pizza{
public:
    Pizza(){};
    void prepare(){
        cout << "Prepare pizza! \n";
    };
    void bake(){
        cout << "Bake pizza! \n";
    };
    void cut(){
        cout << "Cut pizza! \n";
    };
    void box(){
        cout << "Box pizza! \n";
    };
};

class CheesePizza : public Pizza{};
class PepperoniPizza : public Pizza{};
class ClamPizza : public Pizza{};
class VeggiePizza : public Pizza{};

class SimplePizzaFactory{
public:
    Pizza* createPizza(int type){
        Pizza * p=nullptr;
        switch(type){
            case(CHEESE):
                p = new CheesePizza();
                break;
            case(PEPPERONI):
                p = new PepperoniPizza();
                break;
            case(CLAM):
                p = new ClamPizza();
                break;
            case(VEGGIE):
                p = new VeggiePizza();
                break;
            default:
                break;
        }
        return p;
    }
};

class PizzaStore{
public:
    PizzaStore(SimplePizzaFactory f){
        factory = f;
    } 
    Pizza* orderPizza(int type){
        Pizza* pizza;

        pizza = factory.createPizza(type);
        if(pizza==nullptr)
        {
            cout << "Can't order this pizza. Please check again!!!" << endl;
            return nullptr;
        }

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }
private:
    SimplePizzaFactory factory;
};

int main (int argc, char* argv[]){
    SimplePizzaFactory pizzaFactory;
    PizzaStore pizzaStore(pizzaFactory);

    pizzaStore.orderPizza(CHEESE);

    return 0;
}
