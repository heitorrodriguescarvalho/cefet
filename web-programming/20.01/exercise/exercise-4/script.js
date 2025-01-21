const input1 = document.querySelector('#input-1');
const input2 = document.querySelector('#input-2');
const result = document.querySelector('#result-text');
const submitButton = document.querySelector('#submit-button');

let answer = "";

function handleClick() {
  if (!answer) {
    result.textContent = "Escolha uma questão (0 - 9)"

    return;
  }

  if (input2.value.trim().toLowerCase() === answer) {
    result.textContent = "Parabéns! Você acertou!";
  } else {
    result.textContent = "Resposta incorreta. Tente novamente.";
  }
}

function handleChange() {
  const question = parseInt(input1.value);

  switch (question) {
    case 0:
      result.textContent = "O que tem olhos, mas não pode ver?";
      answer = "agulha";
      break;
    case 1:
      result.textContent = "O que começa com 'e', termina com 'e', e contém uma letra?";
      answer = "envelope";
      break;
    case 2:
      result.textContent = "Quanto mais você tira, maior fica. O que é?";
      answer = "buraco";
      break;
    case 3:
      result.textContent = "O que sobe, mas nunca desce?";
      answer = "idade";
      break;
    case 4:
      result.textContent = "O que tem cabeça, mas não pensa?";
      answer = "alfinete";
      break;
    case 5:
      result.textContent = "O que pode encher uma sala sem ocupar espaço?";
      answer = "luz";
      break;
    case 6:
      result.textContent = "Quanto mais você tem, menos você vê. O que é?";
      answer = "escuridão";
      break;
    case 7:
      result.textContent = "O que corre, mas nunca anda, tem cama, mas nunca dorme?";
      answer = "rio";
      break;
    case 8:
      result.textContent = "O que quebra, mas nunca cai? O que cai, mas nunca quebra?";
      answer = "dia e noite";
      break;
    case 9:
      result.textContent = "O que tem raízes que ninguém vê, é maior que as árvores, sobe, mas nunca cresce?";
      answer = "montanha";
      break;
    default:
      result.textContent = "Número inválido. Insira um número entre 0 e 9.";
      answer = "";
  }
}

handleChange()