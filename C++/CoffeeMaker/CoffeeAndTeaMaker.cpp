# include "CoffeeAndTeaMaker.hpp"

CoffeeAndTeaMaker::CoffeeAndTeaMaker(unsigned CoffeePowder, unsigned int Water, unsigned int TeaPowder) : CoffeeMaker(CoffeePowder, Water){
    AddTeaPower(TeaPowder);
}
CoffeeAndTeaMaker::CoffeeAndTeaMaker(const CoffeeAndTeaMaker& Source) : CoffeeMaker(Source){
    AddTeaPower(Source.TeaPowder);
}
CoffeeAndTeaMaker& CoffeeAndTeaMaker::operator=(const CoffeeAndTeaMaker& Source){
    if (this != &Source) {
        m_TeaPowder    = 0;
        AddTeaPower(Source.TeaPowder);
        this->CoffeeMaker::operator=(Source);
    }
    return *this;
}
void CoffeeAndTeaMaker::AddTeaPower(unsigned int TeaPowder){
    m_TeaPowder += TeaPowder;
    if (m_TeaPowder >= MAX_TEAPOWDER) {
        m_TeaPowder = MAX_TEAPOWDER;
        IsTeaPowderFull = true;
    }
    else{
        IsTeaPowderFull = false;
    }
}
void CoffeeAndTeaMaker::MakeTea(){
    if (m_TeaPowder > 0 && TestAndUseWater(1)) {
        TestAndUseWater(1);
        m_TeaPowder--;
        IsWaterFull = false;
        IsTeaPowderFull = false;
    }
}