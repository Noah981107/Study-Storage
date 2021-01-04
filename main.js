var http = require('http');
var fs = require('fs');
var url = require('url');

var app = http.createServer(function(request,response){
    var _url = request.url;
    var queryData = url.parse(_url,true).query;
    var title = queryData.id;
    if(_url == '/'){
      title = 'Welcome';
    }
    if(_url == '/favicon.ico'){
      response.writeHead(404);
      response.end();
      return;
    }
    response.writeHead(200);
    fs.readFile(`data/${queryData.id}`, 'utf8', function(err,description){
      var template =`
      <!DOCTYPE html>
      <html>
        <head>
          <meta charset = "utf-8">
          <title> 광주 풋살 매칭 시스템 </title>
          <link rel = "stylesheet" href = "style.css">
        </head>

        <body>
          <h1> <a href = "/">광주 풋살 매칭 시스템 </a> </h1>
          <div id = "grid">
            <ul>
              <li><a href = "/?id=북구">광주광역시 북구</a> </li>
              <li><a href = "/?id=남구">광주광역시 남구</a> </li>
              <li><a href = "/?id=동구">광주광역시 동구</a> </li>
              <li><a href = "/?id=광산구">광주광역시 광산구</a> </li>
              <li><a href = "/?id=서구">광주광역시 서구</a> </li>
            <ul>
            <div id = "location">
              ${description}
            </div>
          </div>
        </body>
      </html>
      `;
      response.end(template);
    });
});
app.listen(3000);
