// Escreva uma função que verifique se uma determinada string é um palíndromo (ou seja, pode ser lida da mesma forma tanto da esquerda para a direita quanto da direita
//     para a esquerda).
//     Exemplo: arara

function verificaPalindromo(str) {
  const stringLimpa = str.replace(/\s+/g, "").toLowerCase();
  return stringLimpa === stringLimpa.split("").reverse().join("");
}

console.log(verificaPalindromo("arara"));
console.log(verificaPalindromo("javascript"));
