//Escreva uma função que recebe uma string como argumento e retorna o número de vogais presentes nessa string. Considere apenas vogais minúsculas (a, e, i, o, u).

function contarVogais(str) {
  let vogais = "aeiou";
  let contador = 0;
  for (let char of str) {
    if (vogais.includes(char)) {
      contador++;
    }
  }
  return contador;
}

console.log(contarVogais("javascript"));
