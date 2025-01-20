const container = document.querySelector("#container")
const container2 = document.querySelector("#container-2")

const handleClick = () => {
  const text = document.querySelector("#input")

  container.textContent = text.value
}

container.setAttribute("style", "display: none")

const handleHover = () => {
  container.setAttribute("style", "display: block")
}

const handleBlur = () => {
  container.setAttribute("style", "display: none")
}

container2.textContent = Math.random() * 100