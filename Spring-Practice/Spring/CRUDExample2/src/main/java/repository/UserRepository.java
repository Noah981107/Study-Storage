package repository;

import domain.Users;
import java.util.List;

public interface UserRepository {

    public List<Users> getUsers();
    public void deleteUser(String id);
    public void insertUser(Users user);
    public void updateUser(Users user);
}
