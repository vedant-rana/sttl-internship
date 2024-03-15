package P46_Observer;

import java.util.ArrayList;
import java.util.List;


interface Observer {
    void update(float temperature, float humidity);
}


interface Subject {
    void registerObserver(Observer observer);
    void removeObserver(Observer observer);
    void notifyObservers();
}


class DisplayObserver implements Observer {
    private String name;

    public DisplayObserver(String name) {
        this.name = name;
    }

    @Override
    public void update(float temperature, float humidity) {
        System.out.println(name + " Display - Temperature: " + temperature + "°C, Humidity: " + humidity + "%");
    }
}


class WeatherStation implements Subject {
    private List<Observer> observers = new ArrayList<>();
    private float temperature;
    private float humidity;

    @Override
    public void registerObserver(Observer observer) {
        observers.add(observer);
    }

    @Override
    public void removeObserver(Observer observer) {
        observers.remove(observer);
    }

    @Override
    public void notifyObservers() {
        for (Observer observer : observers) {
            observer.update(temperature, humidity);
        }
    }


    public void setWeatherData(float temperature, float humidity) {
        this.temperature = temperature;
        this.humidity = humidity;
        notifyObservers();
    }
}



public class TestWeather {
    public static void main(String[] args) {
        WeatherStation weatherStation = new WeatherStation();

        Observer display1 = new DisplayObserver("Display 1");
        Observer display2 = new DisplayObserver("Display 2");

        weatherStation.registerObserver(display1);
        weatherStation.registerObserver(display2);

        weatherStation.setWeatherData(25.5f, 65.2f);

        weatherStation.removeObserver(display1);

        weatherStation.setWeatherData(28.0f, 70.8f);
    }
}
