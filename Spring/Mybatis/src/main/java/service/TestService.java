package service;

import domain.Users;

import java.util.List;

public interface TestService {
    String test();
    String insertUser(Users user);
    List<Users> readUser();
    String updateUser(Users user);
    String deleteUser(String user_id);
}
