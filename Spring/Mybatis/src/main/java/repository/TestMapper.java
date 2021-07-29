package repository;

import domain.Users;

import org.springframework.stereotype.Repository;
import java.util.List;

@Repository
public interface TestMapper {
    String test();
    String insertUser(Users user);
    List<Users> readUser();
    String updateUser(Users user);
    String deleteUser(String user_id);
}
