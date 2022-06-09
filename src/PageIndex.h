const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" rel="stylesheet">
    <style>
    * {
       box-sizing: border-box;
      }
     html {
        font-family: Arial;
        display: inline-block;
        margin: 0px auto;
        text-align: center;
      }
      h1 { font-size: 2.0rem; }
      h2 { font-size: 2.0rem; }
      p { font-size: 2.0rem; }
      .units { font-size: 1.2rem; }
     
      /* Create three equal columns that floats next to each other */
      .column {
      float: left;
      width: 50%;
      padding-top: 15px;
      }
     /* Clear floats after the columns */
      .row:after {
      content: "";
      display: table;
      clear: both;
      }
    /* Responsive layout - makes the three columns stack on top of each other instead of next to each other */
     @media screen and (max-width:200px) {
     .column {
    width: 100%;
    }
   }
   </style>
  </head>
  <body>
    <h1>Environmental control</h1>
    <div class="row">
    <div class="column">
    <h2>Supply</h2>
    <p>
      <i class="fas fa-battery-full fa-fw" style="font-size:3.0rem;color:#62a1d3;"></i> 
      <span class="measurements-labels">EC : </span> 
      <span id="EcValue">0</span>
      <sup class="units">V</sup>
    </p>
    <p>
      <i class="fas fa-bolt  fa-fw" style="font-size:3.0rem;color:#75e095;"></i>
      <span class="measurements-labels">PH : </span>
      <span id="PhValue">0</span>
      <sup class="units">A</sup>
    </p>
    <p>
      <i class="fas fa-power-off fa-fw" style="font-size:3.0rem;color:#75e095;"></i>
      <span class="measurements-labels">&nbsp;&thinsp;Water Temp : </span>
      <span id="WaterTempValue">0</span>
      <sup class="units">C</sup>
    </p>
    <p>
      <i class="fas fa-power-off fa-fw" style="font-size:3.0rem;color:#75e095;"></i>
      <span class="measurements-labels">&nbsp;&thinsp;Water Level : </span>
      <span id="WaterLevelValue">0</span>
      <sup class="units">-</sup>
    </p>
    </div>
   <div class="column">
   <h2>output</h2>
    <p>
      <i class="fas fa-battery-full fa-fw" style="font-size:3.0rem;color:#62a1d3;"></i> 
      <span class="measurements-labels-out">Air Temp : </span> 
      <span id="AirTempValue">0</span>
      <sup class="units">C</sup>
    </p>
    <p>
      <i class="fas fa-bolt fa-fw" style="font-size:3.0rem;color:#75e095;"></i>
      <span class="measurements-labels-out">Humidity : </span>
      <span id="AirMoistureValue">0</span>
      <sup class="units">%</sup>
    </p>
    <p>
      <i class="fas fa-power-off fa-fw" style="font-size:3.0rem;color:#75e095;"></i>
      <span class="measurements-labels-out">&nbsp;&thinsp;Light : </span>
      <span id="Light">0</span>
      <sup class="units">W</sup>
    </p>
    </div>
    </div>
    <p>
      <i class="far fa-clock" style="font-size:1.0rem;color:#e3a8c7;"></i>
      <span style="font-size:1.0rem;">Time </span>
      <span id="time" style="font-size:1.0rem;"></span>
      
      <i class="far fa-calendar-alt" style="font-size:1.0rem;color:#f7dc68";></i>
      <span style="font-size:1.0rem;">Date </span>
      <span id="date" style="font-size:1.0rem;"></span>
    </P>
  
    <script>
      setInterval(function() {
        // Call a function on page refresh after 1 Second interval
        getSnapshotData(); // take a snap shot of the current data for the next gets
      }, 2000); 
      
      setInterval(function() {
        // Call a function repetatively with 1 Second interval
        Time_Date();
      }, 10000); 

      var data;
      function getSnapshotData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
           data = this.responseText.split(/,/)
            document.getElementById("EcValue").innerHTML = data[0];
            document.getElementById("PhValue").innerHTML = data[1];
            document.getElementById("WaterTempValue").innerHTML = data[2];
            document.getElementById("WaterLevelValue").innerHTML = data[3];
            document.getElementById("AirTempValue").innerHTML = data[4];
            document.getElementById("AirMoistureValue").innerHTML = data[5];
            document.getElementById("Light").innerHTML = data[6];
           //getVoltageinData();
          }
        };
        xhttp.open("GET","getSnapshotData", true);
        xhttp.send();
      }
      
      function Time_Date() {
        var t = new Date();
        document.getElementById("time").innerHTML = t.toLocaleTimeString();
        var d = new Date();
        const dayNames = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday","Saturday"];
        const monthNames = ["January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"];
        document.getElementById("date").innerHTML = dayNames[d.getDay()] + ", " + d.getDate() + "-" + monthNames[d.getMonth()] + "-" + d.getFullYear();
      }
    </script>
  </body>
</html>
)=====";
