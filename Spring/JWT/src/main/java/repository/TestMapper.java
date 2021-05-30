package repository;

import domain.Orders;
import domain.Users;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface TestMapper {
    String token_issued(String id);
    Users get_user_inf(String user_id);
    String sign_up(Users user);
    String check_id(String user_id);
    List<Orders> get_user_order(String user_id);
}
