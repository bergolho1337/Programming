// ---------------------------------------------------------------------------------------------
// Observer design pattern:
// Example program that demonstrates how to implement the Observer pattern in a WeatherApp
// ---------------------------------------------------------------------------------------------

#include <iostream>
#include "weather/weather.h"

int main (int argc, char *argv[])
{
	WeatherData *weather_data = new WeatherData();
	CurrentConditionDisplay *currentDisplay = new CurrentConditionDisplay(weather_data);
	StatisticsDisplay *statisticsDisplay = new StatisticsDisplay(weather_data);
	ForecastDisplay *forecastDisplay = new ForecastDisplay(weather_data);
	HeatDisplay *heatDisplay = new HeatDisplay(weather_data);

	weather_data->setMeasurements(80, 65, 30.4f);
	weather_data->setMeasurements(82, 70, 29.2f);
	weather_data->setMeasurements(78, 90, 29.2f);

	return 0;
}
