const n1 = document.querySelector("#num1")
const n2 = document.querySelector("#num2")
const result = document.querySelector("#result")
const labels = document.getElementsByTagName('label')

Array.from(labels).map((label) => label.style.color = "blue")

function add() {
  result.textContent = String(parseInt(n1.value) + parseInt(n2.value))
}

function subtract() {
  result.textContent = String(parseInt(n1.value) - parseInt(n2.value))
}

function multiply() {
  result.textContent = String(parseInt(n1.value) * parseInt(n2.value))
}

function divide() {
  result.textContent = String(parseInt(n1.value) / parseInt(n2.value))
}

const addBtn = document.querySelector("#sum")
addBtn.addEventListener("click", add)

const subtractBtn = document.querySelector("#subtract")
subtractBtn.addEventListener("click", subtract)

const multiplyBtn = document.querySelector("#multiply")
multiplyBtn.addEventListener("click", multiply)

const divideBtn = document.querySelector("#divide")
divideBtn.addEventListener("click", divide)