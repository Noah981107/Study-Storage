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
            <a href = "https://www.google.com/search?tbs=lf:1,lf_ui:2&tbm=lcl&sxsrf=ALeKk01Yyv80JghB_CKyIOpXjYGIxO88vA:1609132016078&q=%EA%B4%91%EC%A3%BC%EA%B4%91%EC%97%AD%EC%8B%9C+%EB%B6%81%EA%B5%AC+%ED%92%8B%EC%82%B4&rflfq=1&num=10&sa=X&ved=2ahUKEwiF5Nvx8-_tAhUbPXAKHVg3AM0QjGp6BAgEEEY&biw=959&bih=968#rlfi=hd:;si:;mv:[[35.259445899999996,126.9493543],[35.113428299999995,126.78527559999998]];tbs:lrf:!1m4!1u3!2m2!3m1!1e1!1m4!1u2!2m2!2m1!1e1!2m1!1e2!2m1!1e3!3sIAE,lf:1,lf_ui:2"
            >광주 ${title} 풋살장 위치</a>
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
app.listen(3000);
