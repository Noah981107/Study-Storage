package util;

import io.jsonwebtoken.Claims;
import io.jsonwebtoken.ExpiredJwtException;
import io.jsonwebtoken.Jwts;
import io.jsonwebtoken.SignatureAlgorithm;
import org.junit.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;
import repository.TestMapper;

import java.nio.charset.StandardCharsets;
import java.util.Calendar;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

@Component //개발자가 직접 작성한 Class를 Bean으로 등록하기 위한 어노테이션
public class JwtUtil {

    @Value("${json.web.token.secret.key}") //PropertySource를 사용하여 다양한 프로퍼티 파일을 쉽게 불러들여서 값을 지정
    String secret;

    //@Autowired
    //private TestMapper testMapper;


    public String getJsonWebToken(Long id){
        Map<String, Object> headers = new HashMap<String, Object>();
        headers.put("type", "JWT");
        headers.put("alg", "HS256");
        Map<String, Object> payloads = new HashMap<String, Object>();
        payloads.put("id", id);
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(new Date());
        calendar.add(Calendar.HOUR_OF_DAY, 24);
        Date exp = calendar.getTime();

        return Jwts.builder().setHeader(headers).setClaims(payloads).setExpiration(exp).signWith(SignatureAlgorithm.HS256, secret.getBytes()).compact();
    }

    public String getJsonWebToken2(String id){
        Map<String, Object> headers = new HashMap<String, Object>();
        headers.put("type", "JWT");
        headers.put("alg", "HS256");
        Map<String, Object> payloads = new HashMap<String, Object>();
        payloads.put("id", id);
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(new Date());
        calendar.add(Calendar.HOUR_OF_DAY, 24);
        Date exp = calendar.getTime();

        return Jwts.builder().setHeader(headers).setClaims(payloads).setExpiration(exp).signWith(SignatureAlgorithm.HS256, secret.getBytes()).compact();
    }

    /*public String getJsonWebToken3(){
        return testMapper.test();
    }*/

    public boolean isValid(String token) throws Exception{
        if(token == null){
            throw new Exception("null임");
        }
        else if(!token.startsWith("Bearer ")) {
            throw new Exception("Bearer 로 시작안함");
        }
        token = token.substring(7);
        try{
            Claims claims = Jwts.parser().setSigningKey(secret.getBytes()).parseClaimsJws(token).getBody();
        }
        catch(ExpiredJwtException e1){
            throw new Exception("만료됨");
        }
        catch(Throwable e2){
            throw new Exception("잘못됨");
        }
        return true;
    }


}
