package serviceImpl;

import domain.Users;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import repository.TestMapper;
import service.TestService;

import java.util.List;

@Service
public class TestServiceImpl implements TestService {

    @Autowired
    private TestMapper testMapper;

    @Override
    public String test() {
        return testMapper.test();
    }

    @Override
    public String insertUser(Users user) {
        return testMapper.insertUser(user);
    }

    @Override
    public List<Users> readUser() {
        return testMapper.readUser();
    }

    @Override
    public String updateUser(Users user) {
        return testMapper.updateUser(user);
    }

    @Override
    public String deleteUser(String user_id) {
        return testMapper.deleteUser(user_id);
    }
}
