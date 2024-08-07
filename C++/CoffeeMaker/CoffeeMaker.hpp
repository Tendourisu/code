//
//  CoffeeMaker.hpp
//  Demo_Day03
//
//  Created by 范静涛 on 2024/7/17.
//

#ifndef CoffeeMaker_hpp
#define CoffeeMaker_hpp

class CoffeeMaker {
public:
    //constructor, can be called as default constructro
    CoffeeMaker(unsigned CoffeePowder = 0, unsigned int Water = 0);
    //copy constructor
    CoffeeMaker(const CoffeeMaker& Source);
    //operator assignment
    CoffeeMaker& operator=(const CoffeeMaker& Source);
    //destructor
    ~CoffeeMaker();
    //non-static setters
    void AddCoffeePowder(unsigned int CoffeePowder = 1u);
    void AddWater(unsigned int Water = 1u);
    bool Make();
    bool TestAndUseWater(unsigned int WaterUsage = 1u);
    //non-static getters
    const unsigned int& CoffeePowder {m_CoffeePowder};
    const unsigned int& Water        {m_Water};
    bool IsCoffeePowderFull          {false};
    bool IsWaterFull                 {false};
private:
    //non-static data members
    unsigned int m_CoffeePowder {0u};
    unsigned int m_Water        {0u};
    //static data members
    static constexpr unsigned int MAX_COFFEEPOWDER {100u};
    static constexpr unsigned int MAX_WATER        {300u};
};

#endif /* CoffeeMaker_hpp */