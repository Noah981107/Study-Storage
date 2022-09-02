package controller;


import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class TestController {


    //    hello.jsp
    @RequestMapping(value = "/hello", method = RequestMethod.GET)
    public String hello(){
        System.out.print("here");
        return "hello";
    }

    @ResponseBody
    @RequestMapping(value = "/responsebody", method = RequestMethod.GET)
    public String printResponseBody(){
        return "test Response Body";
    }

}
