import com.qg.pojo.Student;
import com.qg.utils.CRUDUtils;
import org.junit.Test;

public class CommonTest {
    @Test
    public void testUpdateAdd(){
        //增加数据
        String sql1 = "insert into student(sid,name,gender,age,address) value(?,?,?,?,?)";
        CRUDUtils.update(sql1,1,"zhangsan","男",18,"Beijing");
        //查看数据
        String sql2 = "select sid,name,gender,age,address from student where sid = ?";
        Student stu = CRUDUtils.queryForStudents(sql2, 1);
        System.out.println(stu);
        //删除数据
        String sql3 = "delete from student where sid = ?";
        CRUDUtils.update(sql3, 1);
        stu = CRUDUtils.queryForStudents(sql2, 1);
        System.out.println(stu);
    }
}
