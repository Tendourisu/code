//
//  CoffeeMaker.cpp
//  Demo_Day03
//
//  Created by 范静涛 on 2024/7/17.
//

#include "CoffeeMaker.hpp"

CoffeeMaker::CoffeeMaker(unsigned CoffeePowder, unsigned int Water){
    AddCoffeePowder(CoffeePowder);
    AddWater(Water);
}

CoffeeMaker::CoffeeMaker(const CoffeeMaker& Source){
    AddCoffeePowder(CoffeePowder);
    AddWater(Water);
}

CoffeeMaker& CoffeeMaker::operator=(const CoffeeMaker& Source){
    if (this != &Source) {
        m_CoffeePowder = 0;
        m_Water        = 0;
        AddCoffeePowder(CoffeePowder);
        AddWater(Water);
    }
    return *this;
}

CoffeeMaker::~CoffeeMaker(){
    //
}

void CoffeeMaker::AddCoffeePowder(unsigned int CoffeePowder){
    m_CoffeePowder += CoffeePowder;
    if (m_CoffeePowder >= MAX_COFFEEPOWDER) {
        m_CoffeePowder     = MAX_COFFEEPOWDER;
        IsCoffeePowderFull = true;
    }
    else{
        IsCoffeePowderFull = false;
    }
}

void CoffeeMaker::AddWater(unsigned int Water){
    m_Water += Water;
    if (m_Water >= MAX_WATER) {
        m_Water = MAX_WATER;
        IsWaterFull = true;
    }
    else{
        IsWaterFull = false;
    }
}

bool CoffeeMaker::Make() {
    if (m_Water > 0 && m_CoffeePowder > 0) {
        m_Water--;
        m_CoffeePowder--;
        IsWaterFull = false;
        IsCoffeePowderFull = false;
        return true;
    }
    else {
        return false;
    }
}

bool CoffeeMaker::TestAndUseWater(unsigned int WaterUsage){
    if (m_Water > WaterUsage) {
        m_Water-= WaterUsage;
        IsWaterFull = false;
        return true;
    }
    else {
        return false;
    }
}
