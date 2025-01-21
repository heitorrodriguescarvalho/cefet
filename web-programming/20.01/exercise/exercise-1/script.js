const input1 = document.querySelector('#input-1');
const input2 = document.querySelector('#input-2');
const result = document.querySelector('#result-text');
const submitButton = document.querySelector('#submit-button');

function handleClick() {
  const sortedNum = Math.round(Math.random() * 100)

  if (input1.value === '' || input2.value === '') {
    result.textContent = 'Por favor, preencha os dois campos'

    return;
  }

  if (Math.abs(input1.value - sortedNum) < Math.abs(input2.value - sortedNum)) {
    result.textContent = `Jogador 1 venceu! O número sorteado foi ${sortedNum}.`;
  } else if (Math.abs(input1.value - sortedNum) > Math.abs(input2.value - sortedNum)) {
    result.textContent = `Jogador 2 venceu! O número sorteado foi ${sortedNum}.`;
  } else {
    result.textContent = `Empate! O número sorteado foi ${sortedNum}.`;
  }
}