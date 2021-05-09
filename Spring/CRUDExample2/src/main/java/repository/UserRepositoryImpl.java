package repository;

import domain.Users;
import org.springframework.stereotype.Repository;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

@Repository
public class UserRepositoryImpl implements UserRepository {

    private static String className = "com.mysql.cj.jdbc.Driver";
    private static String dbUrl = "jdbc:mysql://localhost:3306/shoppingmall?serverTimezone=UTC";
    private static String dbUser = "root";
    private static String DbPassword = "981772";

    public UserRepositoryImpl() {

    }

    @Override
    public List<Users> getUsers() {
        List<Users> ret = new ArrayList<Users>();
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;

        try{
            Class.forName(className);
            conn = DriverManager.getConnection(dbUrl,dbUser, DbPassword);
            stmt = conn.createStatement();
            rs = stmt.executeQuery("SELECT * FROM shoppingmall.user_info ");

            while(rs.next()){
                Users temp = new Users();
                temp.setId(rs.getString("user_id"));
                temp.setPw(rs.getString("user_pw"));
                temp.setAddress(rs.getString("user_address"));
                temp.setAddress(rs.getString("user_phonenumber"));
                ret.add(temp);
            }

            rs.close();
            stmt.close();
            conn.close();
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
        }
        finally {
            try {
                if (stmt != null) {
                    stmt.close();
                }
            }
            catch(Exception e){
                System.out.println(e.getMessage());
                e.printStackTrace();
            }
            try{
                if(conn != null) {
                    conn.close();
                }
            }
            catch(Exception e){
                System.out.println(e.getMessage());
                e.printStackTrace();
            }
        }
        return ret;
    }
}
