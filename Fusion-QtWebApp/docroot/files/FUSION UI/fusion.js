function changeName()
{

  document.getElementById('setDeviceName').value = document.getElementById('name').innerHTML;

  document.getElementById('name').style.visibility = 'hidden';
  document.getElementById('setDeviceName').style.visibility = 'visible';

  // Change text on button, as well as function called when button is clicked

  document.getElementById('changeButton').innerHTML = 'DONE';
  document.getElementById('changeButton').onclick = doneName;

  document.getElementById('setDeviceName').focus();
  document.getElementById('setDeviceName').select();

}

// Function for POSTing data to the webserver, regarding change in device name, as well as updating HTML to reflect change

function doneName()
{
  var name = document.getElementById('setDeviceName').value;

  if (name.length > 10) {

      document.getElementById('warningLabel').innerHTML =  'Warning! Name cannot be longer than 10 characters.';
      document.getElementById('warningLabel').style.visibility = 'visible';


  } else if (name.length == 0) {

    document.getElementById('warningLabel').innerHTML =  'Warning! Name must be at least one character long.';
    document.getElementById('warningLabel').style.visibility = 'visible';

  } else {

  document.getElementById('warningLabel').style.visibility = 'hidden';

  document.getElementById('name').innerHTML = name;

  document.getElementById('setDeviceName').value = '';

  document.getElementById('name').style.visibility = 'visible';
  document.getElementById('setDeviceName').style.visibility = 'hidden';

  document.getElementById('changeButton').innerHTML = 'CHANGE';
  document.getElementById('changeButton').onclick = changeName;

  // SEND FORM DATA TO WEBSERVER WITHOUT REFRESHING PAGE

  sendFormData('deviceName', name);

  }

}



// Function for POSTing data to the webserver, regarding change in play/pause state of current song

function playPause()
{

  var songState;

  if (document.getElementById('playPauseButton').innerHTML == 'Play')
  {
    songState = 'PLAYING';

    document.getElementById('playPauseButton').innerHTML = 'Pause';
  } else {
    songState = 'PAUSED';

    document.getElementById('playPauseButton').innerHTML = 'Play';
  }


  // SEND FORM DATA TO WEBSERVER WITHOUT REFRESHING PAGE

  sendFormData('songState', songState);

}

// Function for POSTing data to the webserver, regarding change in power state of server/webserver

function powerChange()
{

  var powerState;

  if (document.getElementById('switch').checked)
  {
      document.getElementById('onLabel').innerHTML = 'ON';
      document.getElementById('onLabel').style.color = '#03c46a';

      powerState = 'ON';

      // Enable all pressable elements on web interface, when application is 'on'

      document.getElementById('moreInfoButton').disabled = false;
      document.getElementById('changeButton').disabled = false;
      document.getElementById('playPauseButton').disabled = false;
      document.getElementById('choiceBox').disabled = false;


      // TESTING PURPOSES console.log('SWITCH IS NOW ON');
  } else {

      document.getElementById('onLabel').innerHTML = 'OFF';
      document.getElementById('onLabel').style.color = '#ba3728';


      // Disable all pressable elements on web interface, when application is 'off'

      document.getElementById('moreInfoButton').disabled = true;
      document.getElementById('changeButton').disabled = true;
      document.getElementById('warningLabel').hidden = true;
      document.getElementById('playPauseButton').disabled = true;
      document.getElementById('choiceBox').disabled = true;






      // TESTING PURPOSES console.log('SWITCH IS NOW OFF');

      powerState = 'OFF';
  }


  sendFormData('powerState', powerState);



}


// Function for POSTing data to the webserver, regarding change in Source Type


function sourceChange()
{

  var sourceType = document.getElementById('choiceBox').value;


  sendFormData('sourceType', sourceType);

}

// Function to POST data, with input parameters 'attribute' and 'information'

function sendFormData(attribute, information)
{
  // SEND FORM DATA TO WEBSERVER WITHOUT REFRESHING PAGE

  var formData = new FormData();

  formData.append(attribute, information);

  var request = new XMLHttpRequest();

  request.open('POST', '/fusionMusic');

  request.send(formData);
}
