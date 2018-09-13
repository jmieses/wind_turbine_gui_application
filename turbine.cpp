#include "turbine.h"

Turbine::Turbine()
{
    wind = new WindSpeed();
}

Turbine::Turbine(double new_rotor_radius, double new_power_coefficient){
    rotor_radius = new_rotor_radius;
    power_coefficient = new_power_coefficient;
}


Turbine::Turbine(double new_rotor_radius, double new_power_coefficient, WindSpeed& new_wind_properties){
    rotor_radius = new_rotor_radius;
    power_coefficient = new_power_coefficient;

    wind = new WindSpeed();
    wind->read->setData1(new_wind_properties.read->getData1());
    wind->read->setData2(new_wind_properties.read->getData2());
    wind->read->setDateTime(new_wind_properties.read->getDateTime());
}

void Turbine::setRotorRadius(double new_rotor_radius){
    rotor_radius = new_rotor_radius;
}

const double Turbine::getRotorRadius() const{
    return rotor_radius;
}

const double Turbine::TurbinePower() const {
    // Power = 0.5*density*Cp*pi*R^2*U^3

    return 0.5*AIR_DENSITY*power_coefficient*PI*pow(rotor_radius, 2)*pow(this->wind->getWindSpeed(), 3);
}

Turbine::~Turbine()
{
    delete wind;
}
