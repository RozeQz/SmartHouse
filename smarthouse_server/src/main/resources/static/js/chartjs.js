$(document).ready(function () {
    var data_x = data.map(x => x["datetime"]).reverse();
    var data_temp = data.map(x => x["temperature"]);
    var data_br = data.map(x => x["brightness"]);
    var data_hum = data.map(x => x["humidity"]);

    var lineChart = {
        labels: data_x,
        datasets: [
            {
                label: "Temperature",
                borderColor: "rgba(227, 153, 87, 1)",
                backgroundColor: "rgba(227, 153, 87, 0.5)",
                data: data_temp
            },
            {
                label: "Brightness",
                borderColor: "rgba(63, 173, 127, 1)",
                backgroundColor: "rgba(63, 173, 127, 0.5)",
                data: data_br
            },
            {
                label: "Humidity",
                borderColor: "rgba(123, 105, 150, 1)",
                backgroundColor: "rgba(123, 105, 150, 0.5)",
                data: data_hum
            },
        ]
    };

    new Chart(document.getElementById("lineChart").getContext("2d"), {type: 'line', data: lineChart });
});