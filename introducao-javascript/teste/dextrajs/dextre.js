var botaoadd = document.querySelector("#adicionar-poke");

botaoadd.addEventListener("click",function(event){
    event.preventDefault();
    var form = document.querySelector("#form-add");
    var poke = obterPokeDoForm(form);

    var pokeTr = montaTr(poke);
    var tabela = document.querySelector("#tabela-poke");
    tabela.appendChild(pokeTr);
});

function obterPokeDoForm(form){
    var poke = {
        nome: form.nome.value,
        lvl: form.lvl.value,
        tipo: form.tipo.value
    }
    return poke;
}


function montaTr(poke) {
    var pokeTr = document.createElement("tr");
    pokeTr.classList.add("poke");
    pokeTr.appendChild(montaTd(poke.nome,"nome-poke"));
    pokeTr.appendChild(montaTd(poke.lvl,"lvl-poke"));
    pokeTr.appendChild(montaTd(poke.tipo,"tipo-poke"));
    return pokeTr;
}

function montaTd(dado,classe){
    var td = document.createElement("td");
    td.textContent = dado;
    td.classList.add(classe);
    return td;


}