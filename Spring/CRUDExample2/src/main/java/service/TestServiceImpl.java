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

    public List<Users> getUsers(){
        return userRepository.getUsers();
    }
}
