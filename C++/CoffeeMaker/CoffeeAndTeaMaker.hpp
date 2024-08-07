#ifndef CoffeeAndTeaMaker_hpp
#define CoffeeAndTeaMaker_hpp

# include "CoffeeMaker.hpp"


class CoffeeAndTeaMaker : public CoffeeMaker{
public:
    //constructor, can be called as default constructro
    CoffeeAndTeaMaker(unsigned CoffeePowder = 0, unsigned int Water = 0, unsigned int TeaPowder = 0);
    //copy constructor
    CoffeeAndTeaMaker(const CoffeeAndTeaMaker& Source);
    //operator assignment
    CoffeeAndTeaMaker& operator=(const CoffeeAndTeaMaker& Source);
    //destructor
    ~CoffeeAndTeaMaker();
    //non-static setters
    void AddTeaPower(unsigned int TeaPowder = 1u);
    void MakeTea();
    void MakeCoffee();
    //non-static getters
    const unsigned int& TeaPowder {m_TeaPowder};
    bool IsTeaPowderFull          {false};
    
private:
    //non-static data members
    unsigned int m_TeaPowder {0u};
    //static data members
    static constexpr unsigned int MAX_TEAPOWDER {100u};
};



#endif /* CoffeeAndTeaMaker_hpp */
