//Escreva uma função que receba uma string como argumento e retorne a string invertida.

function inverterString(str) {
  return str.split("").reverse().join("");
}

console.log(inverterString("javascript"));
