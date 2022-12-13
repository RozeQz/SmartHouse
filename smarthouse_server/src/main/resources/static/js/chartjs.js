$(document).ready(function () {
    var data_x = data.map(x => x["datetime"]).reverse();
    var data_temp = data.map(x => x["temperature"]);
    var data_br = data.map(x => x["brightness"]);
    var data_hum = data.map(x => x["humidity"]);

    var lineChartTemp = {
        labels: data_x,
        datasets: [
            {
                label: "Температура",
                borderColor: "rgba(227, 153, 87, 1)",
                backgroundColor: "rgba(227, 153, 87, 0.5)",
                data: data_temp
            },
        ]
    };

    var lineChartBr = {
        labels: data_x,
        datasets: [
            {
                label: "Яркость",
                borderColor: "rgba(63, 173, 127, 1)",
                backgroundColor: "rgba(63, 173, 127, 0.5)",
                data: data_br
            },
        ]
    };

    var lineChartHum = {
        labels: data_x,
        datasets: [
            {
                label: "Влажность",
                borderColor: "rgba(123, 105, 150, 1)",
                backgroundColor: "rgba(123, 105, 150, 0.5)",
                data: data_hum
            },
        ]
    };

    new Chart(document.getElementById("tempChart").getContext("2d"), {type: 'line', data: lineChartTemp });
    new Chart(document.getElementById("brChart").getContext("2d"), {type: 'line', data: lineChartBr });
    new Chart(document.getElementById("humChart").getContext("2d"), {type: 'line', data: lineChartHum });
});