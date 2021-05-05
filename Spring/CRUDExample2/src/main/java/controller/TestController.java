package controller;

import domain.Users;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import service.TestService;

import java.util.List;

@Controller
public class TestController {
    @Autowired
    private TestService testService;

    @ResponseBody
    @RequestMapping(value = "/read", method = RequestMethod.GET)
    public String find(){
        List<Users> temp = testService.getUsers();
        for(Users user: temp){
            System.out.println("id : " + user.getId());
            System.out.println("password : " + user.getPw());
            System.out.println("address : " + user.getAddress());
            System.out.println("phone_number : " +  user.getPhone_number());
            System.out.println("---------------------------");
        }
        return "Complete";
    }
}