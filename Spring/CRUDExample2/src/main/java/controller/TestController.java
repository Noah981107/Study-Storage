package controller;

import domain.Users;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import service.TestService;

import java.util.List;

@Controller
public class TestController {

    private TestService testService;

    @Autowired
    public TestController(TestService testService){
        this.testService = testService;
    }

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
        return "Member Inquiry Complete";
    }

    /*@ResponseBody
    @RequestMapping(value = "/delete/{id}", method = RequestMethod.DELETE)
    public String delete(@PathVariable String id){
        testService.deleteUser(id);
        return "User delete Complete";
    }*/

    @ResponseBody
    @RequestMapping(value ="/delete", method=RequestMethod.DELETE)
    public String delete(@RequestParam(value="id", defaultValue = "false") String id){
        testService.deleteUser(id);
        return "User delete Complete";
    }

    @ResponseBody
    @RequestMapping(value = "/create", method = RequestMethod.POST)
    public String insert(@RequestBody Users user){
        testService.insertUser(user);
        return "User insert Complete";
    }

    @ResponseBody
    @RequestMapping(value = "/update", method = RequestMethod.PUT)
    public String update(@RequestBody Users user){
        testService.updateUser(user);
        return "User update Complete";
    }
}