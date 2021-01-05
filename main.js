var http = require('http');
var fs = require('fs');
var url = require('url');

function templataeHTML(title, list, description) {
  return `
  <!DOCTYPE html>
  <html>
    <head>
      <meta charset = "utf-8">
      <title> 광주 풋살 매칭 시스템</title>
      <link rel = "stylesheet" href = "style.css">
    </head>

    <body>
      <h1> <a href = "/">광주 풋살 매칭 시스템</a> </h1>
      <div id = "grid">
        ${list}
        <div id = "location">
          ${description}
        </div>
      </div>
    </body>
  </html>
  `;
}

function templateList(filelist) {
  var list = '<ul>';
  var i = 0 ;
  while(i<filelist.length) {
    list = list + `<li><a href="/?id=${filelist[i]}">${filelist[i]}</a></li>`;
    i = i + 1;
  }
  list = list + `</ul>`;
  return list;
}

var app = http.createServer(function(request,response){
    var _url = request.url;
    var queryData = url.parse(_url,true).query;
    var pathname = url.parse(_url,true).pathname;

    if(pathname == '/') {
      if(queryData.id == undefined) {
        fs.readdir('./data', function(error,filelist) {
          var title = '광주 풋살 매칭 시스템';
          var description = '광주 풋살 매칭 시스템'
          var list = templateList(filelist);
          var template = templataeHTML(title, list, description);
          response.writeHead(200);
          response.end(template);
        })
      }
      else {
        fs.readdir('./data', function(error,filelist) {
          var title = '광주 풋살 매칭 시스템';
          var list = templateList(filelist);
          fs.readFile(`data/${queryData.id}`, 'utf8', function(err,description){
            var title = queryData.id;
            var template = templataeHTML(title, list, description);
            response.writeHead(200);
            response.end(template);
          });
        });
      }
    }
    else {
      response.writeHead(404);
      response.end('Not found');
    }
});
app.listen(3000);
