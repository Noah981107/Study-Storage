package controller;

import domain.Users;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

import service.TestService;

import java.util.List;

@Controller
public class TestController {

    @Autowired
    private TestService testService;

    @ResponseBody
    @RequestMapping(value ="/test", method = RequestMethod.GET)
    public ResponseEntity test(){
        return new ResponseEntity(testService.test(), HttpStatus.OK);
    }

    @ResponseBody
    @RequestMapping(value = "/user", method = RequestMethod.POST)
    public String insert(@RequestBody Users user){
        testService.insertUser(user);
        return "User insert Complete";
    }

    @ResponseBody
    @RequestMapping(value = "/user", method = RequestMethod.GET)
    public List<Users> read(){
        return testService.readUser();
    }

    @ResponseBody
    @RequestMapping(value = "/user", method = RequestMethod.PUT)
    public String update(@RequestBody Users user){
        testService.updateUser(user);
        return "User update Complete";
    }

    @ResponseBody
    @RequestMapping(value ="/user", method = RequestMethod.DELETE)
    public String delete(@RequestParam(value = "id", defaultValue = "false") String id){
        testService.deleteUser(id);
        return "User delete Complete";
    }
}
