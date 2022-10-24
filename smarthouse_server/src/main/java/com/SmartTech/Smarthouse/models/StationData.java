package com.SmartTech.Smarthouse.models;

import lombok.Data;

import javax.persistence.*;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.Size;

@Entity                               // Вместо геттеров и сеттеров
public class StationData {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Integer id;
    @Column(nullable = false)
    private Integer stationID;
    @NotEmpty(message = "Name should not be empty")
    @Size(min = 2, max = 50, message = "Name should be between 2 and 50 characters")
    @Column(nullable = false)
    private String stationName;
    @Column
    private float temperature;
    @Column
    private int brightness;
    @Column
    private int humidity;
    @Column
    private boolean error;

    public StationData() {
    }

    public StationData(int stationID, String stationName, float temperature, int brightness, int humidity, boolean error) {
        this.stationID = stationID;
        this.stationName = stationName;
        this.temperature = temperature;
        this.brightness = brightness;
        this.humidity = humidity;
        this.error = error;
    }

    public Integer getId() {
        return id;
    }

    public Integer getStationID() {
        return stationID;
    }

    public void setStationID(Integer stationID) {
        this.stationID = stationID;
    }

    public String getStationName() {
        return stationName;
    }

    public void setStationName(String stationName) {
        this.stationName = stationName;
    }

    public float getTemperature() {
        return temperature;
    }

    public void setTemperature(float temperature) {
        this.temperature = temperature;
    }

    public int getBrightness() {
        return brightness;
    }

    public void setBrightness(int brightness) {
        this.brightness = brightness;
    }

    public int getHumidity() {
        return humidity;
    }

    public void setHumidity(int humidity) {
        this.humidity = humidity;
    }

    public boolean isError() {
        return error;
    }

    public void setError(boolean error) {
        this.error = error;
    }
}
