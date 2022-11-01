package com.SmartTech.Smarthouse.dao;

import com.SmartTech.Smarthouse.models.StationData;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Component;

import java.util.List;

@Component
public class StationDAO {
    private final JdbcTemplate jdbcTemplate;

    @Autowired
    public StationDAO(JdbcTemplate jdbcTemplate) {
        this.jdbcTemplate = jdbcTemplate;
    }

    public List<StationData> allStations() {
        return jdbcTemplate.query("SELECT stationID, stationName FROM Stations GROUP BY stationID, stationName", new BeanPropertyRowMapper<>(StationData.class));
    }

    public List<StationData> stationById(int id) {
        return jdbcTemplate.query("SELECT * FROM Stations WHERE stationID=?", new Object[]{id}, new BeanPropertyRowMapper<>(StationData.class));
    }

    public StationData dataById(int id) {
        return jdbcTemplate.query("SELECT * FROM Stations WHERE id=?", new Object[]{id}, new BeanPropertyRowMapper<>(StationData.class))
                .stream().findAny().orElse(null);
    }

    public void save(StationData station) {
        jdbcTemplate.update("INSERT INTO Stations(stationName, temperature, brightness, humidity, error, stationID) VALUES(?, ?, ?, ?, ?, ?)", station.getStationName(),
                station.getTemperature(), station.getBrightness(), station.getHumidity(), station.isError(), station.getStationID());
    }

    public void delete(int id) {
        jdbcTemplate.update("DELETE FROM Stations WHERE stationID=?", id);
    }
}
