package service;

import domain.Users;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import repository.UserRepository;

import java.util.List;

@Service
public class TestServiceImpl implements TestService {

    private final UserRepository userRepository;

    @Autowired
    public TestServiceImpl(UserRepository userRepository) {
        this.userRepository = userRepository;
    }

    @Override
    public List<Users> getUsers(){
        return userRepository.getUsers();
    }

    @Override
    public void deleteUser(String id) {
        userRepository.deleteUser(id);
    }

    @Override
    public void insertUser(Users user) {
        userRepository.insertUser(user);
    }

    @Override
    public void updateUser(Users user) {
        userRepository.updateUser(user);
    }
}
