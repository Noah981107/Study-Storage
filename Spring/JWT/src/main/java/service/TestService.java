package service;

import domain.Orders;
import domain.Users;
import org.springframework.http.ResponseEntity;

import java.util.List;

public interface TestService {
    String token_issued(String id);
    Users get_user_inf(String token);
    String sign_up(Users user);
    List<Orders> get_user_order(String token);
}
