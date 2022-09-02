package serviceImpl;

import domain.Orders;
import domain.Users;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import repository.TestMapper;
import service.TestService;
import util.JwtUtil;

import javax.xml.ws.Response;
import java.util.List;

@Service
public class TestServiceImpl implements TestService {

    @Autowired
    private JwtUtil jwtUtil;

    @Autowired
    private TestMapper testMapper;

    @Override
    public String token_issued(String id) {
        String return_id = testMapper.token_issued(id);

        if(return_id == null || return_id.isEmpty()){
            try {
                throw new Exception("There is no such id");
            } catch (Exception e) {
                e.printStackTrace();
                return "ID is None";
            }
        }
        else{
            return jwtUtil.token_issued(return_id);
        }
    }

    @Override
    public Users get_user_inf(String token) {
        String return_id = jwtUtil.get_user_inf(token);
        return testMapper.get_user_inf(return_id);
    }

    @Override
    public String sign_up(Users user) {
        String user_id = user.getUser_id();
        String result  = testMapper.check_id(user_id);
        if (result == null || result.isEmpty()){
            testMapper.sign_up(user);
            return "Membership success";
        }
        else{
            return "There is a duplicate ID";
        }
    }

    @Override
    public List<Orders> get_user_order(String token) {
        String user_id = jwtUtil.get_user_order(token);
        return testMapper.get_user_order(user_id);
    }

}
