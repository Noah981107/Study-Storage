var http = require('http');
var fs = require('fs');
var url = require('url');

var app = http.createServer(function(request,response){
    var _url = request.url;
    var queryData = url.parse(_url,true).query;
    var pathname = url.parse(_url,true).pathname;

    if(pathname === '/') {
      if(queryData.id === undefined) {
        fs.readFile(`data/${queryData.id}`, 'utf8', function(err,description){
          var title = '광주 풋살 매칭 시스템';
          var description = '광주 풋살 매칭 시스템'
          var template = `
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
          </html>
          `;
          response.writeHead(200);
          response.end(template);
        });
      }
      else {

        fs.readFile(`data/${queryData.id}`, 'utf8', function(err,description){
          var title = queryData.id;;
          var template = `
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
          </html>
          `;
          response.writeHead(200);
          response.end(template);
        });
      }
    }
    else {
      response.writeHead(404);
      response.end('Not Found');
    }
});
app.listen(3000);
