package com.qg.utils;

import com.alibaba.druid.pool.DruidDataSourceFactory;
import com.mysql.cj.protocol.Resultset;

import javax.sql.DataSource;
import java.io.IOException;
import java.io.InputStream;
import java.sql.*;
import java.util.Properties;

/**
 * @Description 操作数据库的工具类
 */

public class JDBCUtils {
    /**
     * @Description 获取数据库的连接
     * @return
     */
    public static Connection getConnection () throws Exception {
        //1.读取配置文件的4个基本信息
        InputStream is = ClassLoader.getSystemClassLoader().getResourceAsStream("jdbc.properties");
        Properties pros = new Properties();
        pros.load(is);

        String user = pros.getProperty("user");
        String password = pros.getProperty("password");
        String url = pros.getProperty("url");
        String driverClass = pros.getProperty("driverClass");

        //2.加载驱动
        Class.forName(driverClass);

        //3.获取连接
        Connection conn = DriverManager.getConnection(url, user, password);
        return conn;
    }

    /**
     * @Description 关闭连接和Statement
     * @param conn
     * @param ps
     */
    public static void closeResource(Connection conn, Statement ps){
        if(ps!=null){
            try {
                ps.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        if(conn!=null){
            try {
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
    /**
     * @Description 关闭连接、Statement和 ResultSet
     * @param conn
     * @param ps
     */
    public static void closeResource(Connection conn, Statement ps, ResultSet rs){
        if(ps!=null){
            try {
                ps.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        if(conn!=null){
            try {
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        if(rs!=null){
            try {
                rs.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    /**
     * @Description 使用德鲁伊数据库连接池技术
     */
    private static DataSource source;
    static{
        try {
            Properties pros = new Properties();
            InputStream is = ClassLoader.getSystemClassLoader().getResourceAsStream("druid.properties");
            pros.load(is);
            source = DruidDataSourceFactory.createDataSource(pros);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static Connection getConnectionDruid() throws SQLException {
        Connection conn = source.getConnection();
        return conn;
    }
}
