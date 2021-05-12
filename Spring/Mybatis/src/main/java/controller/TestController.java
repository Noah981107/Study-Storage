package controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.portlet.bind.annotation.ResourceMapping;
import service.TestService;

@Controller
public class TestController {

    @Autowired
    private TestService testService;

    @ResponseBody
    @RequestMapping(value = "/test", method = RequestMethod.GET)
    public ResponseEntity test(){
        return new ResponseEntity(testService.test(), HttpStatus.OK);
    }
}
