// Ici c'est la place du code Javascript
// de la jolie page.
var i = 0;

window.onload = function()
{
    update_i();
}

function update_i()
{
    i ++;

    var si = document.getElementById('si');
    si.innerHTML = i;

    setTimeout(update_i, 400);
}

function reset_i()
{
    i = 0;
}