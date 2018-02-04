
function fillHTML() {

  var xhttp = new XMLHttpRequest();

  xhttp.overrideMimeType('application/json');

  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {

      console.log(this.responseText);

      // Create variable for converting incoming response for JSON data, to usable JSON object

      var obj = JSON.parse(this.responseText);

      // Loop through data in JSON object, to assign to HTML elements (id = key names in JSON file)

      for (var p in obj) {

        var keyName = '';
        var keyPair = '';

        // Filter out keys that aren't relevant for usage

        if (obj.hasOwnProperty(p)) {
          var keyName = '' + p;
          var keyPair = '' + obj[p];
        }

        // Ensure that if requested element isn't present in HTML, program continues running

        if (!!document.getElementById(keyName)) {
            document.getElementById(keyName).innerHTML += keyPair;
        }
      }

      // Line for testing
      //document.getElementById('header_thing').innerHTML = obj.name;


    }
  };
  xhttp.open('GET', '/jsonData', true);
  xhttp.send();
}
