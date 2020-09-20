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
    <p id="error" style="display: none;">Error taking photo</p>
    <p>It might take more than 5 seconds to capture a photo.</p>
    <p>
      <button onclick="rotatePhoto();">ROTATE</button>
      <button onclick="capturePhoto()">CAPTURE PHOTO</button>
      <button onclick="location.reload();">REFRESH PAGE</button>
    </p>
  </div>
  <div><img src="/saved-photo" id="photo" width="70%"></div>
</body>
<script>
  var deg = 0;
  function capturePhoto() {
    fetch("/capture")
      .then((res) => {
        if (res.status === 200) {
          window.photo.src = "/saved-photo"
          window.error.style = "display: none;"
        } else {
          window.error.style = "display: block;"
        }
      })
  }
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

