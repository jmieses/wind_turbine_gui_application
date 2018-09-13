#ifndef WINDSPEED_H
#define WINDSPEED_H
#include "read.h"

#define AIR_DENSITY 1.225

class WindSpeed : public Read
{
private:
    double density;
    double average_wind_speed;

public:

    Read* read; // avoid error c2280

    WindSpeed();
    WindSpeed(double, double);
    WindSpeed(const double&, Read&);
    void setDensity(double);
    void setWindSpeed(double);
    double getDensity() const;
    double getWindSpeed() const;
    void averageWind(QString, QString);

    /*Used the rule of three to avoid using a deleted dafault function. Implement the following:
    copy constructor, overloaded assignment operator, and destructor. Once these are implemented
    dafault member functions won't be created.*/

    // copy constructor
    WindSpeed(const WindSpeed&);

    // overloaded assignment operator
    WindSpeed& operator=(const WindSpeed);

    // Destructor
    ~WindSpeed();
};

#endif // WINDSPEED_H
