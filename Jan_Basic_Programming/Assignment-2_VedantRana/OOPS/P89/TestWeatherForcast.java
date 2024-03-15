package P89;

import java.util.ArrayList;
import java.util.List;

class WeatherData {
    private double temperature;
    private double humidity;
    private double pressure;

    public WeatherData(double temperature, double humidity, double pressure) {
        this.temperature = temperature;
        this.humidity = humidity;
        this.pressure = pressure;
    }

    public double getTemperature() {
        return temperature;
    }

    public double getHumidity() {
        return humidity;
    }

    public double getPressure() {
        return pressure;
    }
}

class Forecast {
    private double predictedTemperature;
    private double predictedHumidity;
    private double predictedPressure;

    public Forecast(double predictedTemperature, double predictedHumidity, double predictedPressure) {
        this.predictedTemperature = predictedTemperature;
        this.predictedHumidity = predictedHumidity;
        this.predictedPressure = predictedPressure;
    }

    public double getPredictedTemperature() {
        return predictedTemperature;
    }

    public double getPredictedHumidity() {
        return predictedHumidity;
    }

    public double getPredictedPressure() {
        return predictedPressure;
    }
}

class WeatherStation {
    private List<WeatherData> weatherDataList;
    private List<Forecast> forecasts;

    public WeatherStation() {
        this.weatherDataList = new ArrayList<>();
        this.forecasts = new ArrayList<>();
    }

    public void addWeatherData(WeatherData weatherData) {
        weatherDataList.add(weatherData);
    }

    public void generateForecast() {
        if (!weatherDataList.isEmpty()) {
            double avgTemperature = weatherDataList.stream().mapToDouble(WeatherData::getTemperature).average().orElse(0);
            double avgHumidity = weatherDataList.stream().mapToDouble(WeatherData::getHumidity).average().orElse(0);
            double avgPressure = weatherDataList.stream().mapToDouble(WeatherData::getPressure).average().orElse(0);

            forecasts.add(new Forecast(avgTemperature, avgHumidity, avgPressure));
        }
    }

    public List<Forecast> getForecasts() {
        return forecasts;
    }
}


public class TestWeatherForcast {

    public static void main(String[] args) {
        WeatherStation station1 = new WeatherStation();
        WeatherStation station2 = new WeatherStation();

        station1.addWeatherData(new WeatherData(25.0, 60.0, 1015.0));
        station1.addWeatherData(new WeatherData(28.0, 55.0, 1010.0));

        station2.addWeatherData(new WeatherData(20.0, 70.0, 1020.0));
        station2.addWeatherData(new WeatherData(22.0, 65.0, 1012.0));

        station1.generateForecast();
        station2.generateForecast();

        List<Forecast> forecasts1 = station1.getForecasts();
        List<Forecast> forecasts2 = station2.getForecasts();

        System.out.println("Forecast from Station 1: " + forecasts1.get(0).getPredictedTemperature() +
                "C, " + forecasts1.get(0).getPredictedHumidity() + "% humidity, " +
                forecasts1.get(0).getPredictedPressure() + " hPa");

        System.out.println("Forecast from Station 2: " + forecasts2.get(0).getPredictedTemperature() +
                "C, " + forecasts2.get(0).getPredictedHumidity() + "% humidity, " +
                forecasts2.get(0).getPredictedPressure() + " hPa");
    }
}

