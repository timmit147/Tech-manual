// Click button on alert on
document.getElementById('poweron').onclick = function() {
  document.getElementById('poweron').style.background='#FF0000';
  document.getElementById('poweroff').style.background='#272727';

}

// Click button on alert off
document.getElementById('poweroff').onclick = function() {
  document.getElementById('poweroff').style.background='#FF0000';
  document.getElementById('poweron').style.background='#272727';
}



// https://www.codegrepper.com/code-examples/html/html+onclick+call+function+with+element+id
// https://stackoverflow.com/questions/1819878/changing-button-color-programmatically
