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
        cout << "Prepare pizza: " << name << endl;
        cout << "Tossing dough ..." << endl;
        cout << "Adding sauce ..." << endl;
        for(auto topping:toppings){
            cout << " " << topping << endl;
        }
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
protected:
    string name;
    string dough;
    string sauce;
    vector<string> toppings;
};

class CheesePizza : public Pizza{};
class PepperoniPizza : public Pizza{};
class ClamPizza : public Pizza{};
class VeggiePizza : public Pizza{};

class NYStyleCheesePizza : public Pizza{
public:
    NYStyleCheesePizza(){
        name = "NY Style Sauce and Cheese Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Sauce";

        toppings.push_back("Grated Reggiano Cheese");
    }
};

class ChicagoStyleCheesePizza : public Pizza{
public:
    ChicagoStyleCheesePizza(){
        name = "Chicago Style Sauce and Cheese Pizza";
        dough = "Extra thick Crust Dough";
        sauce = "Plum Tomato Sauce";

        toppings.push_back("Shredded Mozzarella Cheese");
    }
};

class PizzaStore{
public:
    PizzaStore(){} 
    Pizza* orderPizza(int type){
        Pizza* pizza;

        pizza = createPizza(type);
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
protected:
    virtual Pizza* createPizza(int type) = 0;
};

class NYStylePizzaStore : public PizzaStore{
public:
    NYStylePizzaStore(){};
private:
    Pizza* createPizza(int type){
        Pizza * p=nullptr;
        switch(type){
            case(CHEESE):
                p = new NYStyleCheesePizza();
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

class ChicagoStylePizzaStore : public PizzaStore{
public:
    ChicagoStylePizzaStore(){};
private:
    Pizza* createPizza(int type){
        Pizza * p=nullptr;
        switch(type){
            case(CHEESE):
                p = new ChicagoStyleCheesePizza();
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

int main (int argc, char* argv[]){
    PizzaStore* chicagoStore = new ChicagoStylePizzaStore;
    PizzaStore* nyStore = new NYStylePizzaStore;

    Pizza* pizza = chicagoStore->orderPizza(CHEESE);
    cout << endl;
    pizza = nyStore->orderPizza(CHEESE);

    return 0;
}
