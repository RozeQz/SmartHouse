DROP TABLE IF EXISTS Stations;
CREATE TABLE Stations (
    id SERIAL PRIMARY KEY,
    stationID INTEGER,
    stationName VARCHAR(50),
    temperature FLOAT,
    brightness INTEGER,
    humidity INTEGER,
    datetime TIMESTAMP,
    error BOOLEAN
);