//Faça uma função que mostre o dobro do número passado. Caso o número seja menor ou igual a zero deve mostrar a mensagem "Só é aceito números positivos maiores que zero".

function mostrarDobro(num) {
  if (num <= 0) {
    console.log("Só é aceito números positivos maiores que zero");
  } else {
    console.log(`O dobro de ${num} é ${num * 2}`);
  }
}

mostrarDobro(5);
mostrarDobro(-1);
