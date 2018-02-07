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

  var formData = new FormData();

  formData.append('deviceName', name);

  var request = new XMLHttpRequest();

  request.open('POST', '/fusionMusic');

  request.send(formData);


  }

}





function playPause()
{

  var songState;

  if (document.getElementById('playPauseButton').innerHTML == 'Play')
  {
    songState = 'PAUSED';

    document.getElementById('playPauseButton').innerHTML = 'Pause';
  } else {
    songState = 'PLAYING...';

    document.getElementById('playPauseButton').innerHTML = 'Play';
  }



  console.log(songState);

  // SEND FORM DATA TO WEBSERVER WITHOUT REFRESHING PAGE

  var formData = new FormData();

  formData.append('songState', songState);

  var request = new XMLHttpRequest();

  request.open('POST', '/fusionMusic');

  request.send(formData);

}

function powerState()
{
  if (document.getElementById('switch').checked)
  {
      document.getElementById('onLabel').innerHTML = 'ON';
      document.getElementById('onLabel').style.color = '#03c46a';

      console.log("SWITCH IS NOW ON");
  } else {
      document.getElementById('onLabel').innerHTML = 'OFF';
      document.getElementById('onLabel').style.color = '#ba3728';

      console.log("SWITCH IS NOW OFF");
  }
}
