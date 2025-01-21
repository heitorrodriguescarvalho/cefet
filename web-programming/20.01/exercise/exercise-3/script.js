const result = document.querySelector('#result-text');
const submitButton = document.querySelector('#submit-button');

function handleClick() {
  const values = []

  for (let i = 0; i < 6; i++) {
    values.push(Math.round(Math.random() * 60));
  }

  result.textContent = values.join(', ');
}

handleClick();