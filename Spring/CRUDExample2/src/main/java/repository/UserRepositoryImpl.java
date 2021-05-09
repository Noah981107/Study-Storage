package repository;

import domain.Users;
import org.springframework.stereotype.Repository;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

@Repository
public class UserRepositoryImpl implements UserRepository {

    private static String className = "com.mysql.cj.jdbc.Driver";
    private static String dbUrl = "jdbc:mysql://localhost:3306/shoppingmall?serverTimezone=UTC";
    private static String dbUser = "root";
    private static String DbPassword = "981772";

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
            rs = stmt.executeQuery("SELECT * FROM shoppingmall.user_info");

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

    @Override
    public void deleteUser(String id) {
        Connection conn = null;
        PreparedStatement pstmt = null;
        ResultSet rs = null;
        try {
            Class.forName(className);
            conn = DriverManager.getConnection(dbUrl, dbUser, DbPassword);
            pstmt = conn.prepareStatement("DELETE FROM shoppingmall.user_info WHERE user_id = ?");
            pstmt.setString(1, id);
            pstmt.execute();

            rs.close();
            pstmt.close();
            conn.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
        } finally {
            try {
                if (pstmt != null) {
                    pstmt.close();
                }
            } catch (Exception e) {
                System.out.println(e.getMessage());
                e.printStackTrace();
            }
            try {
                if (conn != null) {
                    conn.close();
                }
            } catch (Exception e) {
                System.out.println(e.getMessage());
                e.printStackTrace();
            }
        }
        return;
    }

    @Override
    public void insertUser(Users user) {
        String id = user.getId();
        String pw = user.getPw();
        String address = user.getAddress();
        String phonenumber = user.getPhone_number();

        Connection conn = null;
        PreparedStatement pstmt = null;
        ResultSet rs = null;

        try{
            Class.forName(className);
            conn = DriverManager.getConnection(dbUrl, dbUser, DbPassword);
            pstmt = conn.prepareStatement("INSERT INTO shoppingmall.user_info(user_id,user_pw,user_address,user_phonenumber) VALUES(?, ?, ?, ?)");
            pstmt.setString(1, id);
            pstmt.setString(2, pw);
            pstmt.setString(3, address);
            pstmt.setString(4, phonenumber);
            pstmt.executeUpdate();

            pstmt.close();
            conn.close();
            rs.close();
        }catch (Exception e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
        } finally {
            try {
                if (pstmt != null) pstmt.close();
            } catch (Exception e) {
                System.out.println(e.getMessage());
                e.printStackTrace();
            }
            try {
                if (conn != null) conn.close();
            } catch (Exception e) {
                System.out.println(e.getMessage());
                e.printStackTrace();
            }
        }
        return;
    }

    @Override
    public void updateUser(Users user) {
        String id = user.getId();
        String address = user.getAddress();
        String phonenumber = user.getPhone_number();

        Connection conn = null;
        PreparedStatement pstmt = null;
        ResultSet rs = null;

        try{
            Class.forName(className);
            conn = DriverManager.getConnection(dbUrl, dbUser, DbPassword);
            pstmt = conn.prepareStatement("UPDATE shoppingmall.user_info SET user_address = ?, user_phonenumber = ? WHERE user_id = ?");
            pstmt.setString(1, address);
            pstmt.setString(2, phonenumber);
            pstmt.setString(3, id);
            pstmt.executeUpdate();

            pstmt.close();
            conn.close();
            rs.close();
        }catch (Exception e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
        } finally {
            try {
                if (pstmt != null) pstmt.close();
            } catch (Exception e) {
                System.out.println(e.getMessage());
                e.printStackTrace();
            }
            try {
                if (conn != null) conn.close();
            } catch (Exception e) {
                System.out.println(e.getMessage());
                e.printStackTrace();
            }
        }
        return;
    }
}
