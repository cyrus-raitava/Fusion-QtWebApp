function loadElements()
{
  var subTitle = document.createElement('h2');
  subTitle.id = 'subTitle';

  subTitle.innerHTML = 'It works!';
  document.body.appendChild(subTitle);

  var currentSourceID = document.createElement('h3');
  currentSourceID.id = 'currentSourceID';
  currentSourceID.innerHTML = 'The current source ID is: ';
  document.body.appendChild(currentSourceID);

  var flags = document.createElement('h3');
  flags.id = 'flags';
  flags.innerHTML = 'The current flag(s) are: ';
  document.body.appendChild(flags);

  var model = document.createElement('h3');
  model.id = 'model';
  model.innerHTML = 'The model is: ';
  document.body.appendChild(model);

  var name = document.createElement('h3');
  name.id = 'name';
  name.innerHTML = 'The current name is: ';
  document.body.appendChild(name);

  var nameSize = document.createElement('h3');
  nameSize.id = 'nameSize';
  nameSize.innerHTML = 'The name size is: ';
  document.body.appendChild(nameSize);

  var sourceID = document.createElement('h3');
  sourceID.id = 'sourceID';
  sourceID.innerHTML = 'The source ID is: ';
  document.body.appendChild(sourceID);

  var sourceType = document.createElement('h3');
  sourceType.id = 'sourceType';
  sourceType.innerHTML = 'The current source type is: ';
  document.body.appendChild(sourceType);

}

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
