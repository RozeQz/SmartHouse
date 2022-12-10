$(document).ready(function () {
    var data_x = data.map(x => x["datetime"]);
    var data_temp = data.map(x => x["temperature"]);
    var data_br = data.map(x => x["brightness"]);
    var data_hum = data.map(x => x["humidity"]);

    var lineChartTemp = {
        labels: data_x,
        datasets: [
            {
                label: "Temperature",
                fillColor: "rgba(220, 220, 220, 0.5)",
                strokeColor: "rgba(220, 220, 220, 1)",
                pointColor: "rgba(220, 220, 220, 1)",
                pointStrokeColor: "#fff",
                data: data_temp
            },
        ]
    };

    var lineChartBr = {
        labels: data_x,
        datasets: [
            {
                label: "Brightness",
                fillColor: "rgba(220, 220, 220, 0.5)",
                strokeColor: "rgba(220, 220, 220, 1)",
                pointColor: "rgba(220, 220, 220, 1)",
                pointStrokeColor: "#fff",
                data: data_br
            },
        ]
    };

    var lineChartHum = {
        labels: data_x,
        datasets: [
            {
                label: "Humidity",
                fillColor: "rgba(220, 220, 220, 0.5)",
                strokeColor: "rgba(220, 220, 220, 1)",
                pointColor: "rgba(220, 220, 220, 1)",
                pointStrokeColor: "#fff",
                data: data_hum
            },
        ]
    };

    new Chart(document.getElementById("tempChart").getContext("2d"), {type: 'line', data: lineChartTemp });
    new Chart(document.getElementById("brChart").getContext("2d"), {type: 'line', data: lineChartBr });
    new Chart(document.getElementById("humChart").getContext("2d"), {type: 'line', data: lineChartHum });
});