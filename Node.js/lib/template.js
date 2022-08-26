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
module.exports = template;
