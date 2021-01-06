var http = require('http');
var fs = require('fs');
var url = require('url');
var qs = require('querystring');

var template = {
  HTML:function(title, list, body, control) {
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
          ${control}
          ${body}
        </div>
      </body>
    </html>
    `;
  }, LIST :function(filelist) {
    var list = `<ul>`;
    var i = 0 ;
    while(i<filelist.length) {
      list = list + `<li><a href="/?id=${filelist[i]}">${filelist[i]}</a></li>`;
      i = i + 1;
    }
    list = list + `</ul>`;
    return list;
  }
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
          var list = template.LIST(filelist);
          var template2 = template.HTML(title, list, description,`<a href="/create">create</a>`);
          response.writeHead(200);
          response.end(template2);
        })
      }
      else {
        fs.readdir('./data', function(error,filelist) {
          var title = '광주 풋살 매칭 시스템';
          var list = template.LIST(filelist);
          fs.readFile(`data/${queryData.id}`, 'utf8', function(err,description){
            var title = queryData.id;
            var template2 = template.HTML(title, list, description,`<a href="/create">create</a> <a href="/update?id=${title}">update</a>`);
            response.writeHead(200);
            response.end(template2);
          });
        });
      }
    }
    else if(pathname === '/create'){
      fs.readdir('./data', function(error,filelist) {
        var title = '풋살 신청서';
        var description = '광주 풋살 매칭 시스템';
        var list = template.LIST(filelist);
        var template2 = template.HTML(title, list, `
          <form action="/create_process" method ="post">
            <p>
              <input type = "text" name = "title" placeholder = "title">
            </p>
            <p>
              <textarea name = "description" placeholder = "description"></textarea>
            </p>
            <p>
              <input type = "submit">
            </p>
          </form>
          `);
        response.writeHead(200);
        response.end(template2);
      })
    }
    else if(pathname == '/create_process'){
      var body = '';
      request.on('data',function(data){
        body += data;
      });
      request.on('end', function(){
        var post = qs.parse(body);
        var title = post.title;
        var description = post.description;
        fs.writeFile(`data/${title}`, description, 'utf8',
        function(err){
          response.writeHead(302, {Location: `/?id=${title}`});
          response.end('success');
        })
      });
    }
    else if(pathname === '/update'){
      fs.readdir('./data', function(error,filelist) {
        var title = '광주 풋살 매칭 시스템';
        var list = template.LIST(filelist);
        fs.readFile(`data/${queryData.id}`, 'utf8', function(err,description){
          var title = queryData.id;
          var template2 = template.HTML(title, list,`
            <form action="/update_process" method ="post">
              <input type = "hidden" name ="id" value="${title}">
              <p>
                <input type = "text" name = "title" placeholder = "title" value = "${title}">
              </p>
              <p>
                <textarea name = "description" placeholder = "description" >${description}</textarea>
              </p>
              <p>
                <input type = "submit">
              </p>
            </form>
            `,
            `<a href="/create">create</a> <a href="/update?id=${title}">update</a>`);
          response.writeHead(200);
          response.end(template2);
        });
      });
    }
    else if(pathname === '/update_process'){
      var body = '';
      request.on('data',function(data){
        body += data;
      });
      request.on('end', function(){
        var post = qs.parse(body);
        var id = post.id;
        var title = post.title;
        var description = post.description;
        fs.writeFile(`data/${title}`, description, 'utf8',
        function(err){
          response.writeHead(302, {Location: `/?id=${title}`});
          response.end('success');
        });
      })
    }
    else {
      response.writeHead(404);
      response.end('Not found');
    }
});
app.listen(3000);
