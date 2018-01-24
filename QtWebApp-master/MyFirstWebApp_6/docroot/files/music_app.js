
function doClick(callback) {

  var xhttp = new XMLHttpRequest();

  xhttp.overrideMimeType("application/json");

  xhttp.open("GET", "/files/name.json", true);

  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      callback(rawFile.responseText);
    }
  };

  xhttp.send(null);
}

function getData() {

}
