package P75;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Sensor {
    private String type;

    public Sensor(String type) {
        this.type = type;
    }

    public String getType() {
        return type;
    }

    public double readData() {
        return new Random().nextDouble() * 50;
    }
}

class WeatherData {
    private String type;
    private double value;

    public WeatherData(String type, double value) {
        this.type = type;
        this.value = value;
    }

    public String getType() {
        return type;
    }

    public double getValue() {
        return value;
    }
}

class WeatherStation {
    private List<Sensor> sensors;
    private List<WeatherData> weatherData;

    public WeatherStation() {
        this.sensors = new ArrayList<>();
        this.weatherData = new ArrayList<>();
    }

    public void addSensor(Sensor sensor) {
        sensors.add(sensor);
    }

    public void collectData() {
        for (Sensor sensor : sensors) {
            double sensorData = sensor.readData();
            WeatherData dataPoint = new WeatherData(sensor.getType(), sensorData);
            weatherData.add(dataPoint);
        }
    }

    public List<WeatherData> getWeatherData() {
        return weatherData;
    }

    public double analyzeTrend(String type) {
        double sum = 0;
        int count = 0;

        for (WeatherData dataPoint : weatherData) {
            if (dataPoint.getType().equals(type)) {
                sum += dataPoint.getValue();
                count++;
            }
        }

        if (count > 0) {
            return sum / count;
        } else {
            return 0;
        }
    }
}


public class TestWeather {
    public static void main(String[] args) {
        Sensor temperatureSensor = new Sensor("Temperature");
        Sensor humiditySensor = new Sensor("Humidity");

        WeatherStation weatherStation = new WeatherStation();
        weatherStation.addSensor(temperatureSensor);
        weatherStation.addSensor(humiditySensor);

        weatherStation.collectData();

        List<WeatherData> weatherData = weatherStation.getWeatherData();
        System.out.println("Weather Data:");

        for (WeatherData dataPoint : weatherData) {
            System.out.println("- " + dataPoint.getType() + ": " + dataPoint.getValue());
        }

        String trendType = "Temperature";
        double averageTemperature = weatherStation.analyzeTrend(trendType);
        System.out.println("Average " + trendType + ": " + averageTemperature);
    }
}
