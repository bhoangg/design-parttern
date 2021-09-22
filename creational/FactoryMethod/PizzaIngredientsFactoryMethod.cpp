#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

enum PIZZA_TYPE{
    CHEESE=1,
    PEPPERONI=2,
    CLAM=3,
    VEGGIE=4
};

//ingredients
class Dough{
public:
    virtual string getName() const =0;
};
class Sauce{
public:
    virtual string getName() const =0;
};
class Cheese{
public:
    virtual string getName() const =0;
};
class Veggies{
public:
    virtual string getName() const =0;
};
class Pepperoni{
public:
    virtual string getName() const =0;
};
class Clams{
public:
    virtual string getName() const =0;
};

// vegetables
class Galic : public Veggies{
public:
    string getName() const {
        return "Galic";
    }
};
class Onion : public Veggies{
public:
    string getName() const {
        return "Onion";
    }
};
class Mushroom : public Veggies{
public:
    string getName() const {
        return "Mushroom";
    }
};
class RedPepper : public Veggies{
public:
    string getName() const {
        return "RedPepper";
    }
};
class Spinach : public Veggies{
public:
    string getName() const {
        return "Spinach";
    }
};
class BlackOlives : public Veggies{
public:
    string getName() const {
        return "BlackOlives";
    }
};

// same
class SlicedPeperoni : public Pepperoni{
public:
    string getName() const {
        return "SlicedPeperoni";
    }
};

// NewYork ingredients
class ThinCurstDough : public Dough{
public:
    string getName() const {
        return "ThinCurstDough";
    }
};
class MarinaraSauce : public Sauce{
public:
    string getName() const {
        return "MarinaraSauce";
    }
};
class ReggianoCheese : public Cheese{
public:
    string getName() const {
        return "ReggianoCheese";
    }
};
class FreshClam : public Clams{
public:
    string getName() const {
        return "FreshClam";
    }
};

// Chicago ingredients
class ThickCurstDough: public Dough{
public:
    string getName() const {
        return "ThickCurstDough";
    }
};
class PlumTomatoSauce : public Sauce{
public:
    string getName() const {
        return "PlumTomatoSauce";
    }};
class MozzarellaCheese : public Cheese{
public:
    string getName() const {
        return "MozzarellaCheese";
    }
};
class FrozenClam : public Clams{
public:
    string getName() const {
        return "FrozenClam";
    }
};

class PizzaIngredientFacotry{
public:
    PizzaIngredientFacotry(){};
    virtual Dough* createDough()=0;
    virtual Sauce* createSauce()=0;
    virtual Cheese* createCheese()=0;
    virtual Pepperoni* createPepperoni()=0;
    virtual Clams* createClam()=0;
    
};

class NYPizzaIngredientFactory : public PizzaIngredientFacotry{
public:
    NYPizzaIngredientFactory(){};
    Dough* createDough(){
        return new ThinCurstDough();
    }
    Sauce* createSauce(){
        return new MarinaraSauce();
    }
    Cheese* createCheese(){
        return new MozzarellaCheese();
    }
    Clams* createClam(){
        return new FreshClam();
    }
    Pepperoni* createPepperoni(){
        return new SlicedPeperoni();
    }
    Veggies* createVeggies(){
        return new Onion();
    }
};

class ChicagoPizzaIngredientFactory : public PizzaIngredientFacotry{
public:
    ChicagoPizzaIngredientFactory(){};
    Dough* createDough(){
        return new ThickCurstDough();
    }
    Sauce* createSauce(){
        return new PlumTomatoSauce();
    }
    Cheese* createCheese(){
        return new ReggianoCheese();
    }
    Clams* createClam(){
        return new FrozenClam();
    }
    Pepperoni* createPepperoni(){
        return new SlicedPeperoni();
    }
    Veggies* createVeggies(){
        return new Onion();
    }
};

class Pizza{
public:
    Pizza(){};
    virtual void prepare()=0;
    void bake(){
        cout << "Bake pizza! \n";
    };
    void cut(){
        cout << "Cut pizza! \n";
    };
    void box(){
        cout << "Box pizza! \n";
    };
    void setName(string name){
        this->name = name;
    }
protected:
    string name;
    Dough* dough;
    Sauce* sauce;
    Cheese* cheese;
    Clams* clam;
    Pepperoni* pepperoni;

};

class CheesePizza : public Pizza{
public:
    CheesePizza(PizzaIngredientFacotry* ingredientFactory){
        this->ingredientFactory = ingredientFactory;
    }
    void prepare(){
        cout << "Preparing " << name  << "..." << endl;
        dough = ingredientFactory->createDough();
        sauce = ingredientFactory->createSauce();
        cheese = ingredientFactory->createCheese();
        cout << "Ingredients: " << endl;
        cout << "  - Dough: " << dough->getName() << endl;
        cout << "  - Sauce: " << sauce->getName() << endl;
        cout << "  - Cheese: " << cheese->getName() << endl;
    }
private:
    PizzaIngredientFacotry* ingredientFactory;
};

class ClamPizza : public Pizza{
public:
    ClamPizza(PizzaIngredientFacotry* ingredientFactory){
        this->ingredientFactory = ingredientFactory;
    }
    void prepare(){
        dough = ingredientFactory->createDough();
        sauce = ingredientFactory->createSauce();
        cheese = ingredientFactory->createCheese();
        clam = ingredientFactory->createClam();
    }
private:
    PizzaIngredientFacotry* ingredientFactory;
};

class VeggiePizza : public Pizza{
public:
    VeggiePizza(PizzaIngredientFacotry* ingredientFactory){
        this->ingredientFactory = ingredientFactory;
    }
    void prepare(){
        dough = ingredientFactory->createDough();
        sauce = ingredientFactory->createSauce();
        cheese = ingredientFactory->createCheese();
        clam = ingredientFactory->createClam();
    }
private:
    PizzaIngredientFacotry* ingredientFactory;
};

class PepperoniPizza : public Pizza{
public:
    PepperoniPizza(PizzaIngredientFacotry* ingredientFactory){
        this->ingredientFactory = ingredientFactory;
    }
    void prepare(){
        dough = ingredientFactory->createDough();
        sauce = ingredientFactory->createSauce();
        cheese = ingredientFactory->createCheese();
        clam = ingredientFactory->createClam();
    }
private:
    PizzaIngredientFacotry* ingredientFactory;
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
        PizzaIngredientFacotry* ingredientFactory = new NYPizzaIngredientFactory();
        switch(type){
            case(CHEESE):
                p = new CheesePizza(ingredientFactory);
                p->setName("NewYork Style CheesePizza");
                break;
            case(PEPPERONI):
                p = new PepperoniPizza(ingredientFactory);
                p->setName("NewYork Style PepperoniPizza");
                break;
            case(CLAM):
                p = new ClamPizza(ingredientFactory);
                p->setName("NewYork Style ClamPizza");
                break;
            case(VEGGIE):
                p = new VeggiePizza(ingredientFactory);
                p->setName("NewYork Style VeggiePizza");
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
        PizzaIngredientFacotry* ingredientFactory = new ChicagoPizzaIngredientFactory();
        switch(type){
            case(CHEESE):
                p = new CheesePizza(ingredientFactory);
                p->setName("Chicago Style CheesePizza");
                break;
            case(PEPPERONI):
                p = new PepperoniPizza(ingredientFactory);
                p->setName("Chicago Style PepperoniPizza");
                break;
            case(CLAM):
                p = new ClamPizza(ingredientFactory);
                p->setName("Chicago Style ClamPizza");
                break;
            case(VEGGIE):
                p = new VeggiePizza(ingredientFactory);
                p->setName("Chicago Style VeggiePizza");
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
