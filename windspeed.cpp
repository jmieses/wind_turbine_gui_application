#include "windspeed.h"

#include <qdebug.h>
WindSpeed::WindSpeed()
{
    density = 0;
    average_wind_speed = 0;
    read = new Read();
}

WindSpeed::WindSpeed(double new_density, double new_average_wind_speed){
    density = new_density;
    average_wind_speed = new_average_wind_speed;
}

WindSpeed::WindSpeed(const double& new_density, Read& new_read){
    density = new_density;
    read = new Read();

   // read = &new_read;  // shallow copy
    this->read->setData1(new_read.getData1());
    this->read->setData2(new_read.getData2());
    this->read->setDateTime(new_read.getDateTime());
}

void WindSpeed::setDensity(double new_density){
    density = new_density;
}

void WindSpeed::setWindSpeed(double new_average_wind_speed){
    average_wind_speed = new_average_wind_speed;
}

double WindSpeed::getDensity() const{
    return density;
}

double WindSpeed::getWindSpeed() const{
    return average_wind_speed;
}

void WindSpeed::averageWind(QString first_date_time, QString last_date_time){

    int first = this->read->getDateTime().indexOf(first_date_time);
    int last = this->read->getDateTime().indexOf(last_date_time);

    // indexOf() return -1 if element is not found
    // check if element has been found
    if(first == -1){
        qDebug() << "Element not found in averageWind()" << endl;
        return;
    }

    double sum = 0;
    for (int i = first; i <= last; i++){
        sum += this->read->getData1().at(i);
        windX.push_back(this->read->getData1().at(i));
    }
    average_wind_speed = sum / abs((double)last - (double)first);
}

/* Definition of the rule of three. Copy constructor, overloaded assignment operator, destructor.
Check comment at WindSpeed.h file for reference. */

// copy constructor

WindSpeed::WindSpeed(const WindSpeed& w){
    this->density = w.density;
    this->average_wind_speed = w.average_wind_speed;
    read = new Read();


    // check if the members are empty.
    // if not clear the objects and pass the new data
    if (!this->data1.empty()){
        this->data1.clear();
        this->data1.resize(w.data1.size());
    }
    else if (!this->data2.empty()){
        this->data2.clear();
        this->data2.resize(w.data2.size());
    }
    else if (!this->date_time.empty()){
        this->date_time.clear();
        this->date_time.resize(w.date_time.size());
    }

    // Deep copy of the object being passed.
    for (auto it : w.data1){
        this->data1.push_back(it);
    }

    for (auto it : w.data2){
        this->data2.push_back(it);
    }

    for (auto it : w.date_time)
    {
        this->date_time.push_back(it);
    }
    /*std::copy(w.read->getData1().begin(), w.read->getData1().end(), this->read->getData1().begin());
    std::copy(w.read->getData2().begin(), w.read->getData2().end(), this->read->getData2().begin());
    std::copy(w.read->getDateTime().begin(), w.read->getDateTime().end(), this->read->getDateTime().begin());*/
}

// overloaded operator assignment

WindSpeed& WindSpeed:: operator=(const WindSpeed w){

    // check if the two objects are the same
    // if they are the same return this object
    if (this == &w){
        return *this;
    }

    this->density = w.density;
    this->average_wind_speed = w.average_wind_speed;

    // check if the members are empty.
    // if not clear the objects and pass the new data
    if (!this->data1.empty()){
        this->data1.clear();
        this->data1.resize(w.data1.size());
    }
    else if (!this->data2.empty()){
        this->data2.clear();
        this->data2.resize(w.data2.size());
    }
    else if (!this->date_time.empty()){
        this->date_time.clear();
        this->date_time.resize(w.date_time.size());
    }

    // Deep copy of the object being passed.
    for (auto it : w.data1){
        this->data1.push_back(it);
    }

    for (auto it : w.data2){
        this->data2.push_back(it);
    }

    for (auto it : w.date_time)
    {
        this->date_time.push_back(it);
    }

    /*std::copy(w.read->getData1().begin(), w.read->getData1().end(), this->data1.begin());
    std::copy(w.read->getData2().begin(), w.read->getData2().end(), this->data2.begin());
    std::copy(w.read->getDateTime().begin(), w.read->getDateTime().end(), this->date_time.begin());*/
    return *this;
}
WindSpeed::~WindSpeed()
{
    delete read;
}
