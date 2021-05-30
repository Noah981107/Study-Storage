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

    @Override
    public String token_issued(String id) {
        return jwtUtil.token_issued(id);
    }
    @Override
    public Users get_user_inf(String token) {
        return jwtUtil.get_user_inf(token);
    }

    @Override
    public String sign_up(Users user) {
        return jwtUtil.sign_up(user);
    }

    @Override
    public List<Orders> get_user_order(String token) {
        return jwtUtil.get_user_order(token);
    }

}
