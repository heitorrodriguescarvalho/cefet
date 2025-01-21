const input = document.querySelector('#input-1');
const result = document.querySelector('#result-text');
const submitButton = document.querySelector('#submit-button');

function handleClick() {
  const values = input.value.split(',').map(value => parseInt(value.trim()));

  if (values.some(value => isNaN(value))) {
    result.textContent = 'Por favor, insira apenas números.';
    return;
  }

  updateResult(values);
}

function countEven(arr) {
  return arr.filter(value => value % 2 === 0).length;
}

function countEventThreeMultiples(arr) {
  return arr.filter(value => value % 3 === 0 && value % 2 === 0).length;
}

function updateResult(arr) {
  result.innerHTML = `Quantidade de números pares: ${countEven(arr)}<br>Quantidade de números pares múltiplos de 3: ${countEventThreeMultiples(arr)}<br>Total: ${arr.length}`;
}

(() => {
  const initialValues = []

  for (let i = 0; i < 10; i++) {
    initialValues.push(Math.round(Math.random() * 100));
  }

  input.value = initialValues.join(", ")

  handleClick()
})()