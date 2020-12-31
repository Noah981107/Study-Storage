var http = require('http');
var fs = require('fs');
var url = require('url');

var app = http.createServer(function(request,response){
    var _url = request.url;
    var queryData = url.parse(_url,true).query;
    var title = queryData.id;
    console.log(queryData.id);
    if(_url == '/'){
      title = 'Welcome';
    }
    if(_url == '/favicon.ico'){
      response.writeHead(404);
      response.end();
      return;
    }
    response.writeHead(200);
    fs.readFile('data/${queryData.id}', 'utf8', function(err,data){
      var discription = data;
      var template = `<!DOCTYPE html>
      <html>

        <head>
          <meta charset = "utf-8">
          <title> 광주 풋살 매칭 시스템 </title>
          <p>
            <!-- Global site tag (gtag.js) - Google Analytics -->
            <script async src="https://www.googletagmanager.com/gtag/js?id=G-HHFBQ5M3SM"></script>
            <script>
            window.dataLayer = window.dataLayer || [];
            function gtag(){dataLayer.push(arguments);}
            gtag('js', new Date());
            gtag('config', 'G-HHFBQ5M3SM');
            </script>
          </p>
          <link rel = "stylesheet" href = "style.css">
        </head>

        <body>
          <h1> <a href = "/">광주 풋살 매칭 시스템 </a> </h1>
          <div id = "grid">
            <ul>
              <li><a href = "/?id=북구" class = "saw">광주광역시 북구</a> </li>
              <li><a href = "/?id=남구" class = "saw">광주광역시 남구</a> </li>
              <li><a href = "/?id=동구" class = "saw">광주광역시 동구</a> </li>
              <li><a href = "/?id=광산구">광주광역시 광산구</a> </li>
              <li><a href = "/?id=서구">광주광역시 서구</a> </li>
            <ul>
            <!--
            <h1> <a href = "index.html"><font color = "red"> 광주 풋살 매칭 시스템</font> </a> </h1>
            <ol>
              <li><a href = "North.html"><font color = "blue"> 광주광역시 북구</font></a> </li>
              <li><a href = "South.html"><font color = "yellow"> 광주광역시 남구</font></a> </li>
              <li><a href = "East.html"> <font color = "black">광주광역시 동구</font></a> </li>
              <li><a href = "Mine.html"> <font color = "green">광주광역시 광산구</font></a> </li>
              <li><a href = "West.html"> <font color = "red">광주광역시 서구</font></a> </li>
            </ol>
            -->
            <div id = "location">
              ${discription}
            </div>
          </div>
          <p>
            <!--Start of disqus.to Script-->
            <div id="disqus_thread"></div>
            <script>
            /**
            *  RECOMMENDED CONFIGURATION VARIABLES: EDIT AND UNCOMMENT THE SECTION BELOW TO INSERT DYNAMIC VALUES FROM YOUR PLATFORM OR CMS.
            *  LEARN WHY DEFINING THESE VARIABLES IS IMPORTANT: https://disqus.com/admin/universalcode/#configuration-variables    */
            /*
            var disqus_config = function () {
            this.page.url = PAGE_URL;  // Replace PAGE_URL with your page's canonical URL variable
            this.page.identifier = PAGE_IDENTIFIER; // Replace PAGE_IDENTIFIER with your page's unique identifier variable
            };
            */
            (function() { // DON'T EDIT BELOW THIS LINE
            var d = document, s = d.createElement('script');
            s.src = 'https://web1-f1podpie6v.disqus.com/embed.js';
            s.setAttribute('data-timestamp', +new Date());
            (d.head || d.body).appendChild(s);
            })();
            </script>
            <noscript>Please enable JavaScript to view the <a href="https://disqus.com/?ref_noscript">comments powered by Disqus.</a></noscript>
            <!--End of disqus.to Script-->
          </p>
          <p>
            <!--Start of Tawk.to Script-->
            <script type="text/javascript">
            var Tawk_API=Tawk_API||{}, Tawk_LoadStart=new Date();
            (function(){
            var s1=document.createElement("script"),s0=document.getElementsByTagName("script")[0];
            s1.async=true;
            s1.src='https://embed.tawk.to/5fe2d139df060f156a8f8179/1eq70358m';
            s1.charset='UTF-8';
            s1.setAttribute('crossorigin','*');
            s0.parentNode.insertBefore(s1,s0);
            })();
            </script>
            <!--End of Tawk.to Script-->
          </p>
        </body>
      </html>
      `;
      response.end(template);
    });
});
app.listen(3000);
