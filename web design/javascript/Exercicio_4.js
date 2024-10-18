//Faça um programa que recebe o nome de uma variável e mostre o
// «primeiro>>. <<último nome>>@facens.br
// Por exemplo:
// A variável nome possui o conteúdo "Fabio Rodrigo Colombini".
// Deve mostrar fabio.colombini@facens.br

let nomeCompleto = "Fabio Rodrigo Colombini";
let partes = nomeCompleto.split(" ");
let primeiroNome = partes[0];
let ultimoNome = partes[partes.length - 1];

let email = `${primeiroNome.toLowerCase()}.${ultimoNome.toLowerCase()}@facens.br`;
console.log(email);
