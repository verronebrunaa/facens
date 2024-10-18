//Escreva uma função que recebe um endereço de e-mail como argumento e retorna true se o e-mail for válido ou false caso contrário. Um e-mail válido deve conter um único símbolo '@' e pelo menos um ponto '' após o '@'.

function validarEmail(email) {
  let posicaoArroba = email.indexOf("@");
  let posicaoPonto = email.lastIndexOf(".");

  return !!(posicaoArroba > 0 && posicaoPonto > posicaoArroba);
}

console.log(validarEmail("teste@exemplo.com"));
console.log(validarEmail("testeexemplo.com"));
