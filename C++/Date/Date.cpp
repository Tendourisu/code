#include "Date.hpp"
const unsigned int Date::MinYear {1900u};
const unsigned int Date::MinMonth {1u};
const unsigned int Date::MaxYear {9999u};
const unsigned int Date::MaxMonth {12u};
const unsigned int Date::DaysInMonth[2u][13u] {
    {0u,31u,28u,31u,30u,31u,30u,31u,31u,30u,31u,30u,31u},
    {0u,31u,29u,31u,30u,31u,30u,31u,31u,30u,31u,30u,31u}
};
    Date::Date(unsigned int year,unsigned int month,unsigned int day){
        Set(year,month,day);
    }
    Date::Date(const Date& source){
        m_uiDay=source.day;
        m_uiMonth=source.month;
        m_uiYear=source.year;
    }
    Date& Date::operator=(const Date& source){
        if(this!=&source){
            m_uiDay=source.day;
            m_uiMonth=source.month;
            m_uiYear=source.year;
        }
        return *this;
    }
    Date::~Date(){

    }
     void Date::Set(unsigned int year,unsigned int month,unsigned int day){
        if(IsValid(year,month,day)){
            m_uiYear=year;
            m_uiMonth=month;
            m_uiDay=day;
            m_bIsLeapYear=IsLeapYear();
        }
        else{
            m_uiYear=MinYear;
            m_uiMonth=MinMonth;
            m_uiDay=1u;
        }
     }
    bool Date::IsLeapYear() const{
        return IsLeapYear(m_uiYear);
    }
    unsigned int Date::DaysFrom19000101() const{
        unsigned int res=0;
        for(unsigned int Year=MinYear;Year<m_uiYear;Year++){
            res+=IsLeapYear(Year)?366:365;
        }
        for(unsigned int Month=1;Month<m_uiMonth;Month++){
            res+=DaysInMonth[IsLeapYear(m_uiYear)][Month];
        }
        res+=m_uiDay;
        return res-1;
    }
    int Date::DayBetween(const Date& ADate) const{
     return DaysFrom19000101()-ADate.DaysFrom19000101();
    }
    bool Date::IsSame(const Date& ADate) const{
        return DaysFrom19000101()==ADate.DaysFrom19000101();
    }
    bool Date::IsLaterThan(const Date& ADate) const{
        return DaysFrom19000101()>ADate.DaysFrom19000101();
    }
    bool Date::IsEarlierThan(const Date& ADate) const{
        return DaysFrom19000101()<ADate.DaysFrom19000101();
    }
    bool Date::IsValid(unsigned int year,unsigned int month,unsigned int day){
        if(year<MinYear||year>MaxYear||month<MinMonth||month>MaxMonth||day<1u||day>DaysInMonth[IsLeapYear(year)][month]){
            return false;
        }
        else{
            return true;
        }
        }
    bool Date::IsValid() const{
        return IsValid(m_uiYear,m_uiMonth,m_uiDay);
    }
    bool Date::IsLeapYear (unsigned int year){
        return ((year%4==0)&&(year%100!=0))||(year%400==0);
    }
    bool Date::IsLeapYear (const Date& ADate){
        return IsLeapYear(ADate.m_uiYear);
    }
    unsigned int Date::DaysFrom19000101(unsigned int year,unsigned int month,unsigned int day){
        return Date(year,month,day).DaysFrom19000101();
    }
    unsigned int Date::DaysFrom19000101(const Date& ADate){
        return ADate.DaysFrom19000101();
    }
    int Date::DayBetween(unsigned int year1,unsigned int month1,unsigned int day1,unsigned int year2,unsigned int month2,unsigned int day2){
        return Date(year1,month1,day1).DayBetween(Date(year2,month2,day2));
    }
    int Date::DayBetween(const Date& ADate1,const Date& ADate2){
        return ADate1.DayBetween(ADate2);
    }
    bool Date::IsSame(unsigned int year1,unsigned int month1,unsigned int day1,unsigned int year2,unsigned int month2,unsigned int day2){
        return Date(year1,month1,day1).IsSame(Date(year2,month2,day2));
    }
    bool Date::IsSame(const Date& ADate1,const Date& ADate2){
        return ADate1.IsSame(ADate2);
    }
    bool Date::IsLaterThan(unsigned int year1,unsigned int month1,unsigned int day1,unsigned int year2,unsigned int month2,unsigned int day2){
        return Date(year1,month1,day1).IsLaterThan(Date(year2,month2,day2));
    }
    bool Date::IsLaterThan(const Date& ADate1,const Date& ADate2){
        return ADate1.IsLaterThan(ADate2);
    }
    bool Date::IsEarlierThan(unsigned int year1,unsigned int month1,unsigned int day1,unsigned int year2,unsigned int month2,unsigned int day2){
        return Date(year1,month1,day1).IsEarlierThan(Date(year2,month2,day2));
    }
    bool Date::IsEarlierThan(const Date& ADate1,const Date& ADate2){
        return ADate1.IsEarlierThan(ADate2);
    }
    bool Date::IsValid(const Date& ADate){
        return ADate.IsValid();
    }
    int Date::operator-(const Date& ADate) const{
        return DaysFrom19000101()-ADate.DaysFrom19000101();
    }
    bool Date::operator==(const Date& ADate)const{
        return DaysFrom19000101()==ADate.DaysFrom19000101();
    }
    bool Date::operator>(const Date& ADate) const{
        return DaysFrom19000101()>ADate.DaysFrom19000101();
    }
    bool Date::operator<(const Date& ADate) const{
        return DaysFrom19000101()<ADate.DaysFrom19000101();
    }
    bool Date::operator!=(const Date& ADate) const{
        return DaysFrom19000101()!=ADate.DaysFrom19000101();
    }
    bool Date::operator>=(const Date& ADate) const{
        return DaysFrom19000101()>=ADate.DaysFrom19000101();
    }
    bool Date::operator<=(const Date& ADate) const{
        return DaysFrom19000101()<=ADate.DaysFrom19000101();
    }
