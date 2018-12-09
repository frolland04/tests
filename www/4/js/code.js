// *** code.js ***
// Ici c'est la place du code Javascript!

function p(s)
{
    var xmlHttp = new XMLHttpRequest();

    xmlHttp.onreadystatechange = function() {
        if (xmlHttp.readyState == 4 && xmlHttp.status == 200)
        {
            view_div.innerHTML = xmlHttp.responseText;
        }
        else
        {
            view_div.innerHTML = "..."
        }
    };

    xmlHttp.open("GET", s, true);
    xmlHttp.send(null);
}