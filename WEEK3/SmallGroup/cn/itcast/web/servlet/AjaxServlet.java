package cn.itcast.web.servlet;

import java.io.IOException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;

@WebServlet(value = "/ajaxServlet")
public class AjaxServlet extends HttpServlet {
    @Override
    protected void doPost(javax.servlet.http.HttpServletRequest request, javax.servlet.http.HttpServletResponse response) throws IOException {
        //获取请求参数
        String username = request.getParameter("username");
        System.out.println(request.getParameterMap());
        //打印username
        System.out.println(username);
        //响应
        response.getWriter().write("hello:"+username);
    }

    @Override
    protected void doGet(javax.servlet.http.HttpServletRequest request, javax.servlet.http.HttpServletResponse response) throws javax.servlet.ServletException, IOException {
        this.doPost(request,response);
    }
}
