package controller;

import annotation.Auth;
import domain.Users;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import service.TestService;
import springfox.documentation.annotations.ApiIgnore;

@Controller
public class TestController {

    @Autowired
    private TestService testService;

    // 토큰이 없어도 사용가능한 api ( 비로그인 )
    @ResponseBody
    @RequestMapping(value = "/test1", method = RequestMethod.GET)
    public ResponseEntity none_token(){
        return new ResponseEntity("non login api", HttpStatus.OK);
    }

    // 토큰이 있어야만 사용가능한 api ( 로그인 )
    @Auth
    @ResponseBody
    @RequestMapping(value = "/test2", method = RequestMethod.GET)
    public ResponseEntity token_login(){
        return new ResponseEntity("login api", HttpStatus.OK);
    }

    //사용자의 id에 따라 토큰을 발급하는 api
    @ResponseBody
    @RequestMapping(value = "/token", method = RequestMethod.POST)
        public ResponseEntity token_issued(@RequestBody String id){
            return new ResponseEntity(testService.token_issued(id), HttpStatus.OK);
    }

    // 로그인이 필요한 (토큰의 id 값에 따른) 사용자 정보 조회 API
    @Auth
    @ResponseBody
    @RequestMapping(value = "/user", method = RequestMethod.GET)
    public ResponseEntity get_user_inf(@RequestHeader(value ="Authorization") String token){
        return new ResponseEntity(testService.get_user_inf(token), HttpStatus.OK);
    }

    // 회원가입 API
    @ResponseBody
    @RequestMapping(value = "/user", method = RequestMethod.POST)
    public ResponseEntity sign_up(@RequestBody Users user){
        return new ResponseEntity(testService.sign_up(user), HttpStatus.OK);
    }

    // 로그인이 필요한 (토큰의 id 값에 따른) 주문내역 조회 API
    @Auth
    @ResponseBody
    @RequestMapping(value = "/user/order", method = RequestMethod.GET)
    public ResponseEntity get_user_order(@ApiIgnore @RequestHeader(value ="Authorization") String token){
        return new ResponseEntity(testService.get_user_order(token), HttpStatus.OK);
    }
}
