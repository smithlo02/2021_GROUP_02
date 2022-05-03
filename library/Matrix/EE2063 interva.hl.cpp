#ifndef INTERVAL_H_INCLUDED
#define INTERVAL_H_INCLUDED

using namespace std;

class interval
{

public:

    interval(float, float);

    interval(float);

    interval(const interval& itv);

    ~interval();

    interval&operator =(const interval& inter);
    interval operator +(const interval& inter);
    interval operator -(const interval& inter);
    interval operator *(const interval& inter);
    interval operator /(const interval& inter);
    interval&operator +=(const interval& inter);

    friend istream& operator>>(istream&, interval&);
    friend ostream& operator<<(ostream&, interval&);

    friend interval operator+(float f, const interval &itv);

private:
    float C_minimum, C_maximum;
};

