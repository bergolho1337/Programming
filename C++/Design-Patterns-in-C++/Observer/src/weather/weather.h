#ifndef WEATHER_H
#define WEATHER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include "../utils/utils.h"

#include "observer.h"

class WeatherData : public Subject 
{
private:
    std::vector<Observer*> observers;
    double temperature;
    double pressure;
    double humidity;
public:
    WeatherData ();
    void registerObserver (Observer *o);
    void removeObserver (const uint32_t id);
    void notifyObservers ();
    void measurementsChanged ();
    void setMeasurements (const double temperature, const double humidity, const double pressure);
    inline double getTemperature () { return temperature; }
    inline double getHumidity () { return humidity; } 
    inline double getPressure () { return pressure; }
};

// Types of weather displays
class CurrentConditionDisplay : public Observer
{
private:
    double temperature;
    double humidity;
    Subject *weather_data;
public:
    CurrentConditionDisplay (Subject *data);
    void update (const double temp, const double hum, const double press);
    void display ();
};

class StatisticsDisplay : public Observer
{
private:
    std::vector<double> arr_temperatures;
    double max_temperature;
    double min_temperature;
    double avg_temperature;
    Subject *weather_data;
public:
    StatisticsDisplay (Subject *data);
    void update (const double temp, const double hum, const double press);
    void display ();
};

class ForecastDisplay : public Observer
{
private:
    double temperature;
    double pressure;
    double humidity;
    Subject *weather_data;
public:
    ForecastDisplay (Subject *data);
    void update (const double temp, const double hum, const double press);
    void display ();
};

class HeatDisplay : public Observer
{
private:
    double temperature;
    double pressure;
    double humidity;
    double heat_index;
    Subject *weather_data;
public:
    HeatDisplay (Subject *data);
    void update (const double temp, const double hum, const double press);
    void display ();
};

#endif
