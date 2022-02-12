const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { text-align:center; }
    .vertical { margin-bottom: 10%; }
    .horizontal { margin-bottom: 0%; }
  </style>
</head>
<body>
  <div id="container">
    <h2>ESP32-CAM Photo</h2>
    <p>
      <button onclick="rotatePhoto();">ROTATE</button>
      <button onclick="location.reload();">REFRESH PAGE</button>
    </p>
  </div>
  <div><img src="/image" id="photo" width="70%"></div>
</body>
<script>
  var deg = 0;
  function rotatePhoto() {
    var img = document.getElementById("photo");
    deg += 90;
    if (isOdd(deg/90)) {
      document.getElementById("container").className = "vertical";
    } else {
      document.getElementById("container").className = "horizontal";
    }
    img.style.transform = "rotate(" + deg + "deg)";
  }
  function isOdd(n) { return Math.abs(n % 2) == 1; }
</script>
</html>)rawliteral";

