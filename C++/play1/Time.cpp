//
//  Time.cpp
//  Demo_Day_01_Time
//
//  Created by 范静涛 on 2024/7/15.
//

#include "Time.hpp"
#include <iostream>
#include <string>
#include <sstream>

const unsigned int Time::MinHour   {0};
const unsigned int Time::MinMinute {0};
const unsigned int Time::MinSecond {0};
const unsigned int Time::MaxHour   {23};
const unsigned int Time::MaxMinute {59};
const unsigned int Time::MaxSecond {59};


//Constructor without parameter
Time::Time(){
    Set(MinHour, MinMinute, MinSecond);
}

//Constructor with parameters
Time::Time(unsigned int Hour, unsigned int Minute, unsigned int Second){
    Set(Hour, Minute, Second);
}

//Copy Constructor
Time::Time(const Time& Source){
    m_uiHour   = Source.Hour;
    m_uiMinute = Source.Minute;
    m_uiSecond = Source.Second;
}

//Assignment Operator
Time& Time::operator=(const Time& Source){
    if (this != &Source) {
        m_uiHour   = Source.Hour;
        m_uiMinute = Source.Minute;
        m_uiSecond = Source.Second;
    }
    return *this;
}

//Destructor
Time::~Time(){
}

//Setters(non-static member functions)
//Set hour, minute, second to time object
void Time::Set(unsigned int Hour, unsigned int Minute, unsigned int Second){
    if (IsValid(Hour, Minute, Second)) {
        SetHour(Hour);
        SetMinute(Minute);
        SetSecond(Second);
    }
    else{
        SetHour(MinHour);
        SetMinute(MinMinute);
        SetSecond(MinSecond);
    }
}

//Set hour to time object
void Time::SetHour(unsigned int Hour){
    m_uiHour = Hour <= MaxHour ? Hour : MinHour;
    
}

//Set minute to time object
void Time::SetMinute(unsigned int Minute){
    m_uiMinute = Minute <= MaxMinute ? Minute : MinMinute;
}

//Set second to time object
void Time::SetSecond(unsigned int Second){
    m_uiSecond = Second <= MaxSecond ? Second : MinSecond;
}

//non-static getters
unsigned int Time::GetSecondesFromMiddelNight() const{
    return m_uiHour * 3600 + m_uiMinute * 60 + m_uiSecond;
}

//To Be Removed
void Time::Show() const{
    std::cout << m_uiHour << " : " << m_uiMinute << " : " << m_uiSecond << std::endl;
}

//static getters(static member functions)
//IsValid return true when parameters are all in range
bool Time::IsValid(unsigned int Hour, unsigned int Minute, unsigned int Second){
    return (Hour <= MaxHour) & (Minute <= MaxMinute) & (Second <= MaxSecond);
}
//To Be Removed
//IsValid return true when parameters are all in range
bool Time::IsValid(const Time& ATime){
    return IsValid(ATime.Hour, ATime.Minute, ATime.Second);
}

//ToString return std::string with format "h:m:s"
std::string Time::ToString() const{
    std::ostringstream Stream;
    Stream << m_uiHour << " : " << m_uiMinute << " : " << m_uiSecond;
    return Stream.str();
}


