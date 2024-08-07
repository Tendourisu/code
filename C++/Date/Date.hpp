#ifndef Date_hpp
#define Date_hpp

class Date{
public:
    //constructors
    Date(unsigned int year=1900u,unsigned int month=1u,unsigned int day=1u);
    Date(const Date& Source);
    Date& operator=(const Date& Source);
    virtual ~Date();
    //operators overload
    int  operator- (const Date& ADate) const;
    bool operator==(const Date& ADate) const;
    bool operator!=(const Date& ADate) const;
    bool operator> (const Date& ADate) const;
    bool operator< (const Date& ADate) const;
    bool operator>=(const Date& ADate) const;
    bool operator<=(const Date& ADate) const;
    //non-static setters
    void Set(unsigned int Year, unsigned int Month, unsigned int Day);
    //non-static getters
    bool IsLeapYear( )const;
    unsigned int DaysFrom19000101()const;
    int     DayBetween(const Date& ADate)const;
    bool IsEarlierThan(const Date& ADate)const;
    bool    IsSame    (const Date& ADate)const;
    bool IsLaterThan  (const Date& ADate)const;
    bool IsValid()const;
    //ststic getters
    static bool IsLeapYear(const Date& ADate);
    static bool IsLeapYear(unsigned int Year);
    static unsigned int DaysFrom19000101(unsigned int Year, unsigned int Month, unsigned int Day);
    static unsigned int DaysFrom19000101(const Date& ADaate);
    static int DayBetween(unsigned int year1,unsigned int month1,unsigned int day1,unsigned int year2,unsigned int month2,unsigned int day2);
    static int DayBetween(const Date& ADate1, const Date& ADate2);
    static bool IsEarlierThan(unsigned int year1,unsigned int month1,unsigned int day1,unsigned int year2,unsigned int month2,unsigned int day2);
    static bool IsEarlierThan(const Date& ADate1 ,const Date& ADate2 );
    static bool IsSame(unsigned int year1,unsigned int month1,unsigned int day1,unsigned int year2,unsigned int month2,unsigned int day2);
    static bool IsSame(const Date& ADate1, const Date& ADate2);
    static bool IsLaterThan(unsigned int year1,unsigned int month1,unsigned int day1,unsigned int year2,unsigned int month2,unsigned int day2);
    static bool IsLaterThan(const Date& ADate1, const Date& ADate2);
    static bool IsValid(unsigned int Year, unsigned int Month, unsigned int Day);
    static bool IsValid(const Date& ADate);
    //non-static constant referecing getters
    const unsigned int& year  {m_uiYear};
    const unsigned int& month {m_uiMonth};
    const unsigned int& day   {m_uiDay};
    const bool& isLeapYear    {m_bIsLeapYear};
    //static data members
    static const unsigned int MinYear;
    static const unsigned int MinMonth;
    static const unsigned int MaxYear;
    static const unsigned int MaxMonth;
    static const unsigned int DaysInMonth[2][13];
private:
    unsigned int m_uiYear  {1990};
    unsigned int m_uiMonth {1};
    unsigned int m_uiDay   {1};
    bool m_bIsLeapYear     {false}; ;



};










#endif /* Date_hpp */