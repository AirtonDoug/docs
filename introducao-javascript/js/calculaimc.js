var titulo = document.querySelector(".titulo");
titulo.textContent = "Aparecida Nutricionista";

var pacientes = document.querySelectorAll(".paciente");

for(var i =0 ; i < pacientes.length ; i++){
	var paciente = pacientes[i];
	var tdPeso = paciente.querySelector(".info-peso");
	var Peso = tdPeso.textContent;

	var tdAltura = paciente.querySelector(".info-altura");
	var Altura = tdAltura.textContent;

	var tdIMC = paciente.querySelector(".info-imc");

	var Pesovalido = validaPeso(Peso);
	var Alturavalida = validaAltura(Altura);

	if(!Pesovalido){
		console.log("Peso inválido");
		Pesovalido = false;
		tdPeso.textContent = "Peso inválido";
		paciente.classList.add("paciente-invalido");
	}

	if(!validaAltura){
		console.log("Altura inválida");
		Pesovalido = false;
		tdAltura.textContent = "Altura inválida";
		paciente.classList.add("paciente-invalido");
	}

	if(Pesovalido && Alturavalida){
		var imc = calculaImc(Peso,Altura);
		tdIMC.textContent = imc;
	}else{
		tdIMC.textContent = "Altura e/ou Peso inválidos";
	}

}

function validaPeso(peso){
	if(peso >= 0 && peso < 1000)
		return true;
	else
		return false;
}
function validaAltura(altura){
	if(altura >=0 && altura < 3)
		return true;
	else
		return false;	
}

function calculaImc(peso,altura){
	return (peso/(altura*altura)).toFixed(2);
}





		
		


			
			
			 
			 