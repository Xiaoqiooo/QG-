package com.qg.utils;

import com.qg.pojo.Student;

import java.lang.reflect.Field;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

/**
 * @Description 通用增删改查操作的工具类
 */
public class CRUDUtils {
    /**
     * @Description 通用增删改操作(考虑事务)
     * @param conn
     * @param sql
     * @param args
     * @return
     */
    public static int update(Connection conn,String sql,Object...args){
        //1.进行sql语句的预编译处理，返回PreparedStatement的实例
        PreparedStatement ps = null;
        try {
            ps = conn.prepareStatement(sql);
            //2.填充占位符
            for (int i = 0; i < args.length; i++) {
                ps.setObject(i+1,args[i]);
            }
            //3.执行
            return ps.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }finally {
            //4.关闭资源
            JDBCUtils.closeResource(null,ps);
        }
        return 0;
    }

    /**
     * @Description 通用增删改操作(不考虑事务)
     * @param sql
     * @param args
     */
    public static void update(String sql,Object...args){
        PreparedStatement ps = null;
        Connection conn = null;
        try {
            //1.获取数据库的连接
            conn = JDBCUtils.getConnection();
            //2.进行sql语句的预编译处理，返回prepareStatement的实例
            ps = conn.prepareStatement(sql);
            //3.填充占位符
            for (int i = 0; i < args.length; i++) {
                ps.setObject(i+1,args[i]);
            }
            //4.执行
            ps.executeUpdate();
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            //5.关闭资源
            JDBCUtils.closeResource(conn,ps);
        }
    }

    /**
     * @Description 通用查询操作(不考虑事务)
     * @param sql
     * @param args
     * @return
     */
    public static Student queryForStudents(String sql, Object...args){
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        try {
            conn = JDBCUtils.getConnection();
            ps = conn.prepareStatement(sql);
            for (int i = 0; i < args.length; i++) {
                ps.setObject(i+1,args[i]);
            }
            rs = ps.executeQuery();
            //获取结果集的元数据：ResultSetMetaData
            ResultSetMetaData rsmd = rs.getMetaData();
            //通过getColumnCount获取结果集中的列数
            int columnCount = rsmd.getColumnCount();
            if(rs.next()) {
                Student stu = new Student();
                //处理结果集一行数据中的每一个列
                for (int i = 0; i < columnCount; i++) {
                    //获取列值
                    Object columValue = rs.getObject(i + 1);
                    //获取每个列的列名（别名）
                    String columnLabel = rsmd.getColumnLabel(i + 1);
                    //给stu对象指定的columnName属性赋值为columValue：通过反射
                    Field field = Student.class.getDeclaredField(columnLabel);
                    field.setAccessible(true);
                    field.set(stu, columValue);
                }
                return stu;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JDBCUtils.closeResource(conn,ps,rs);
        }
        return null;
    }

    /**
     * @Description 获取一个记录
     * @param clazz
     * @param sql
     * @param args
     * @param <T>
     * @return
     */
    public static <T> T getInstance(Class<T> clazz,String sql,Object...args){
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        try{
            conn = JDBCUtils.getConnection();
            ps = conn.prepareStatement(sql);
            for (int i = 0; i < args.length; i++) {
                ps.setObject(i+1,args[i]);
            }
            rs = ps.executeQuery();
            //获取结果集的元数据：ResultSetMetaData
            ResultSetMetaData rsmd = rs.getMetaData();
            //通过getColumnCount获取结果集中的列数
            int columnCount = rsmd.getColumnCount();
            if(rs.next()) {
                //提供一个空参的构造器
                T t = clazz.newInstance();
                //处理结果集一行数据中的每一个列
                for (int i = 0; i < columnCount; i++) {
                    //获取列值
                    Object columValue = rs.getObject(i + 1);
                    //获取每个列的列名（别名）
                    String columnLabel = rsmd.getColumnLabel(i + 1);
                    //给stu对象指定的columnName属性赋值为columValue：通过反射
                    Field field = Student.class.getDeclaredField(columnLabel);
                    field.setAccessible(true);
                    field.set(t, columValue);
                }
                return t;
            }
        }catch(Exception e){
            e.printStackTrace();
        }finally {
            JDBCUtils.closeResource(conn, ps, rs);
        }
        return null;
    }
    /**
     * @Description 获取多个记录
     * @param clazz
     * @param sql
     * @param args
     * @param <T>
     * @return
     */
    public static <T> List<T> getForList(Class<T> clazz, String sql, Object...args){
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        try{
            conn = JDBCUtils.getConnection();
            ps = conn.prepareStatement(sql);
            for (int i = 0; i < args.length; i++) {
                ps.setObject(i+1,args[i]);
            }
            rs = ps.executeQuery();
            //获取结果集的元数据：ResultSetMetaData
            ResultSetMetaData rsmd = rs.getMetaData();
            //通过getColumnCount获取结果集中的列数
            int columnCount = rsmd.getColumnCount();
            //创建一个集合对象
            ArrayList<T> list = new ArrayList<T>();
            while(rs.next()) {
                //提供一个空参的构造器
                T t = clazz.newInstance();
                //处理结果集一行数据中的每一个列
                for (int i = 0; i < columnCount; i++) {
                    //获取列值
                    Object columValue = rs.getObject(i + 1);
                    //获取每个列的列名（别名）
                    String columnLabel = rsmd.getColumnLabel(i + 1);
                    //给stu对象指定的columnName属性赋值为columValue：通过反射
                    Field field = Student.class.getDeclaredField(columnLabel);
                    field.setAccessible(true);
                    field.set(t, columValue);
                }
                list.add(t);
            }
            return list;
        }catch(Exception e){
            e.printStackTrace();
        }finally {
            JDBCUtils.closeResource(conn, ps, rs);
        }
        return null;
    }
    /**
     * @Description 获取一个记录(考虑事务)
     * @param clazz
     * @param sql
     * @param args
     * @param <T>
     * @return
     */
    public static <T> T getInstance(Connection conn,Class<T> clazz,String sql,Object...args){
        PreparedStatement ps = null;
        ResultSet rs = null;
        try{
            conn = JDBCUtils.getConnection();
            ps = conn.prepareStatement(sql);
            for (int i = 0; i < args.length; i++) {
                ps.setObject(i+1,args[i]);
            }
            rs = ps.executeQuery();
            //获取结果集的元数据：ResultSetMetaData
            ResultSetMetaData rsmd = rs.getMetaData();
            //通过getColumnCount获取结果集中的列数
            int columnCount = rsmd.getColumnCount();
            if(rs.next()) {
                //提供一个空参的构造器
                T t = clazz.newInstance();
                //处理结果集一行数据中的每一个列
                for (int i = 0; i < columnCount; i++) {
                    //获取列值
                    Object columValue = rs.getObject(i + 1);
                    //获取每个列的列名（别名）
                    String columnLabel = rsmd.getColumnLabel(i + 1);
                    //给stu对象指定的columnName属性赋值为columValue：通过反射
                    Field field = Student.class.getDeclaredField(columnLabel);
                    field.setAccessible(true);
                    field.set(t, columValue);
                }
                return t;
            }
        }catch(Exception e){
            e.printStackTrace();
        }finally {
            JDBCUtils.closeResource(null, ps, rs);
        }
        return null;
    }
}
