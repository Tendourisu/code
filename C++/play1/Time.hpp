//
//  Time.hpp
//  Demo_Day_01_Time
//
//  Created by 范静涛 on 2024/7/15.
//

#ifndef Time_hpp
#define Time_hpp

#include <string>

class Time{
public:
    //Constructor without parameter
    Time();
    //Constructor with parameters
    Time(unsigned int Hour, unsigned int Minute, unsigned int Second);
    //Copy Constructor
    Time(const Time& Source);
    //Assignment Operator
    Time& operator=(const Time& Source);
    //Destructor
    ~Time();
    //Setters(non-static member functions)
    void Set(unsigned int Hour, unsigned int Minute, unsigned int Second);
    void SetHour(unsigned int Hour);
    void SetMinute(unsigned int Minute);
    void SetSecond(unsigned int Second);
    //non-static getters
    unsigned int GetSecondesFromMiddelNight() const;
    //To Be Removed
    void Show() const;
    //static getters(static member functions)
    bool IsValid(unsigned int Hour, unsigned int Minute, unsigned int Second);
    bool IsValid(const Time& ATime);
    std::string ToString() const;
    //non-static constant referecing getters
    const unsigned int& Hour  {m_uiHour};
    const unsigned int& Minute{m_uiMinute};
    const unsigned int& Second{m_uiSecond};
    //static data members
    static const unsigned int MinHour;
    static const unsigned int MinMinute;
    static const unsigned int MinSecond;
    static const unsigned int MaxHour;
    static const unsigned int MaxMinute;
    static const unsigned int MaxSecond;
private:
    //non-static data members
    unsigned int m_uiHour;
    unsigned int m_uiMinute;
    unsigned int m_uiSecond;
};

#endif /* Time_hpp */
