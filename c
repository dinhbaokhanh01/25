=====================================================
BÁO CÁO BÀI TẬP: TẠO ỨNG DỤNG WEB JAVA ĐẦU TIÊN
=====================================================

1. CẤU TRÚC THƯ MỤC DỰ ÁN (MAVEN WEBAPP)
-----------------------------------------------------
jsp-servlet-demo/
├── pom.xml
└── src/
    └── main/
        ├── java/
        │   └── com/codegym/HelloServlet.java
        └── webapp/
            ├── index.jsp
            └── WEB-INF/web.xml

2. MÃ NGUỒN CÁC FILE CHÍNH
-----------------------------------------------------
[FILE 1]: pom.xml
<project xmlns="http://maven.apache.org/POM/4.0.0" 
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" 
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/maven-v4_0_0.xsd">
    <modelVersion>4.0.0</modelVersion>
    <groupId>com.codegym</groupId>
    <artifactId>jsp-servlet-demo</artifactId>
    <packaging>war</packaging>
    <version>1.0-SNAPSHOT</version>

    <properties>
        <maven.compiler.source>17</maven.compiler.source>
        <maven.compiler.target>17</maven.compiler.target>
        <project.build.sourceEncoding>UTF-8</project.build.sourceEncoding>
    </properties>

    <dependencies>
        <dependency>
            <groupId>jakarta.servlet</groupId>
            <artifactId>jakarta.servlet-api</artifactId>
            <version>6.0.0</version>
            <scope>provided</scope>
        </dependency>
        <dependency>
            <groupId>jakarta.servlet.jsp</groupId>
            <artifactId>jakarta.servlet.jsp-api</artifactId>
            <version>3.1.1</version>
            <scope>provided</scope>
        </dependency>
    </dependencies>
</project>

[FILE 2]: src/main/java/com/codegym/HelloServlet.java
package com.codegym;

import java.io.IOException;
import java.io.PrintWriter;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

@WebServlet(name = "HelloServlet", urlPatterns = {"/hello"})
public class HelloServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) 
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            out.println("<!DOCTYPE html><html><head><title>Hello Servlet</title></head><body>");
            out.println("<h1>Chào mừng bạn đến với Servlet đầu tiên!</h1>");
            out.println("<a href='index.jsp'>Quay lại trang chủ JSP</a>");
            out.println("</body></html>");
        }
    }
}

[FILE 3]: src/main/webapp/index.jsp
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>CodeGym JSP Demo</title>
    </head>
    <body>
        <h2>Chào mừng tới lớp học Java Web!</h2>
        <% java.util.Date date = new java.util.Date(); %>
        <p>Thời gian hệ thống hiện tại: <strong><%= date %></strong></p>
        <a href="hello">Đi tới HelloServlet</a>
    </body>
</html>

3. LỆNH ĐÓNG GÓI VÀ ĐƯỜNG DẪN TRUY CẬP
-----------------------------------------------------
- Lệnh đóng gói WAR: mvn clean package
- URL Trang chủ JSP: http://localhost:8080/jsp-servlet-demo/
- URL HelloServlet: http://localhost:8080/jsp-servlet-demo/hello
