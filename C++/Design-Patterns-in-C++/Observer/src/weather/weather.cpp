#include "weather.h"

WeatherData::WeatherData ()
{

}

void WeatherData::registerObserver (Observer *o)
{
    observers.push_back(o);
}

void WeatherData::removeObserver (const uint32_t id)
{
    observers.erase(observers.begin()+id);
}

void WeatherData::notifyObservers ()
{
    for (uint32_t i = 0; i < observers.size(); i++)
        observers[i]->update(temperature,humidity,pressure);
}

void WeatherData::measurementsChanged ()
{
    notifyObservers();
}

void WeatherData::setMeasurements (const double temperature, const double humidity, const double pressure)
{
    this->temperature = temperature;
    this->pressure = pressure;
    this->humidity = humidity;
    measurementsChanged();
}

CurrentConditionDisplay::CurrentConditionDisplay (Subject *data)
{
    weather_data = data;
    weather_data->registerObserver(this);
}

void CurrentConditionDisplay::update (const double temp, const double hum, const double press)
{
    this->temperature = temp;
    this->humidity = hum;
    display();
}

void CurrentConditionDisplay::display ()
{
    printf("Current conditions: %g degrees and %g %% humidity\n",temperature,humidity);
}

StatisticsDisplay::StatisticsDisplay (Subject *data)
{
    weather_data = data;
    weather_data->registerObserver(this);
}

void StatisticsDisplay::update (const double temp, const double hum, const double press)
{
    this->arr_temperatures.push_back(temp);
    this->min_temperature = *std::min_element(this->arr_temperatures.begin(),this->arr_temperatures.end());
    this->max_temperature = *std::max_element(this->arr_temperatures.begin(),this->arr_temperatures.end());
    this->avg_temperature = calculate_mean(this->arr_temperatures);

    display();
}

void StatisticsDisplay::display ()
{
    printf("Avg/Max/Min temperature = %g/%g/%g\n",avg_temperature,max_temperature,min_temperature);
}

ForecastDisplay::ForecastDisplay (Subject *data)
{
    weather_data = data;
    weather_data->registerObserver(this);
}

void ForecastDisplay::update (const double temp, const double hum, const double press)
{
    this->temperature = temp;
    this->humidity = hum;
    this->pressure = press;
    display();
}

void ForecastDisplay::display ()
{
    printf("Forecast: Some crazy shit happens here!\n");
}

HeatDisplay::HeatDisplay (Subject *data)
{
    weather_data = data;
    weather_data->registerObserver(this);
}

void HeatDisplay::update (const double temp, const double hum, const double press)
{
    this->temperature = temp;
    this->humidity = hum;
    this->pressure = press;
    this->heat_index = calculate_heat_index(this->temperature,this->humidity);
    display();
}

void HeatDisplay::display ()
{
    printf("Heat index is %g\n",this->heat_index);
}


