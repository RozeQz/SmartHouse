package com.SmartTech.Smarthouse.models;

import javax.persistence.*;
import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.Size;

@Entity
@Table(name = "Stations")
public class StationData {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;
    private Integer stationID;
    @NotEmpty(message = "Name should not be empty")
    @Size(min = 2, max = 50, message = "Name should be between 2 and 50 characters")
    private String stationName;
    private float temperature;
    private int brightness;
    private int humidity;
    private boolean error;

    public StationData() {
    }

    public StationData(Long id, int stationID, String stationName, float temperature, int brightness, int humidity, boolean error) {
        this.id = id;
        this.stationID = stationID;
        this.stationName = stationName;
        this.temperature = temperature;
        this.brightness = brightness;
        this.humidity = humidity;
        this.error = error;
    }

    public Long getId() {
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
