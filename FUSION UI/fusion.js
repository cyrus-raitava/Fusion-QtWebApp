function changeName()
{

  document.getElementById('setDeviceName').value = document.getElementById('name').innerHTML;

  document.getElementById('name').style.visibility = 'hidden';
  document.getElementById('setDeviceName').style.visibility = 'visible';

  document.getElementById('changeButton').innerHTML = 'DONE';
  document.getElementById('changeButton').onclick = doneName;

  document.getElementById('setDeviceName').focus();
  document.getElementById('setDeviceName').select();

}

function doneName()
{
  var name = document.getElementById('setDeviceName').value;

  if (name.length > 10) {


      document.getElementById('warningLabel').style.visibility = 'visible';


  } else {

  document.getElementById('warningLabel').style.visibility = 'hidden';

  document.getElementById('name').innerHTML = name;

  document.getElementById('setDeviceName').value = '';

  document.getElementById('name').style.visibility = 'visible';
  document.getElementById('setDeviceName').style.visibility = 'hidden';

  document.getElementById('changeButton').innerHTML = 'CHANGE';
  document.getElementById('changeButton').onclick = changeName;


}

}

function playPause()
{
  if (document.getElementById('playPauseButton').innerHTML == 'Play')
  {
    document.getElementById('playPauseButton').innerHTML = 'Pause';
  } else {
    document.getElementById('playPauseButton').innerHTML = 'Play';
  }
}

function powerState(checkbox)
{

  if (checkbox.checked) {
    document.getElementById('').innerHTML = 'OFF';
  } else {
    document.getElementById('').innerHTML = 'ON';
  }



}

function powerState()
{
  if (document.getElementById('switch').checked)
  {
      document.getElementById('onLabel').innerHTML = 'ON';
      document.getElementById('onLabel').style.color = '#03c46a';
  } else {
      document.getElementById('onLabel').innerHTML = 'OFF';
      document.getElementById('onLabel').style.color = '#ba3728';
  }
}
