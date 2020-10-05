
// **** à la mode 'AJAX' => on interroge une API HTTP 'REST' ****
// **************************************************************

function ajax_get_json(url, callback)
{
    log.send("Requesting HTTP GET: " + url + "...");

    var http = new XMLHttpRequest();

    http.onreadystatechange = function ()
    {
        log.send("[XHR]!" + " " + url + " " + http.readyState);

        if (http.readyState > 1) log.send("[XHR].. " + http.status + " " + http.statusText);

        if (http.readyState === http.DONE && http.status === 200)
        {
            var obj = JSON.parse(http.responseText);
            for (var jsn in obj) log.send(jsn + ": " + obj[jsn]);

            callback(obj)
        }
        log.send("[XHR].")
    };

    http.open("GET", url, true);
    http.setRequestHeader("Accept", "application/json");

    http.send();
}

function ajax_post_json(url, params, callback)
{
    log.send("Requesting HTTP POST: " + url + "...");

    var http = new XMLHttpRequest();
    var data = JSON.stringify(params);

    http.onreadystatechange = function () {
        log.send("[XHR]!" + " " + url + " " + http.readyState + " ...")

        if (http.readyState > 1) log.send("[XHR].. " + http.status + " " + http.statusText);

        if (http.readyState === http.DONE && http.status === 200)
        {
            var obj = JSON.parse(http.responseText);
            for (var jsn in obj) log.send(jsn + ": " + obj[jsn]);

            callback(obj)
        }
        log.send("[XHR].")
    };

    http.open("POST", url, true);
    http.setRequestHeader("Content-type", "application/json; charset=UTF-8");
    http.setRequestHeader("Content-length", data.length);
    http.setRequestHeader("Accept", "application/json");
    http.setRequestHeader("Connection", "close");

    http.send(data);
}
