<%@page import="java.util.Date"%>
<%@ page language="java" import="java.util.*, java.sql.*, java.time.*,java.text.*" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%

	String username = request.getParameter("username");
	String mail = request.getParameter("mail");
	String phone = request.getParameter("phone");
	String dob = request.getParameter("date");
	String image = request.getParameter("image");
	
	SimpleDateFormat formatter = new SimpleDateFormat("yyyy-mm-dd");
	Date date = formatter.parse(dob);
	Instant instant = date.toInstant();
	
	ZonedDateTime zone = instant.atZone(ZoneId.systemDefault());
	LocalDate givenDate = zone.toLocalDate();
	Period period = Period.between(givenDate, LocalDate.now());
	if( period.getYears() > 18 ){
		Connection con = null;
		try{
			
			 Class.forName("com.mysql.cj.jdbc.Driver");

		         con = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb", "root", "");

		        PreparedStatement ps = con.prepareStatement("insert into mytable(username,mail,dob,phone,image) values(?,?,?,?,?)");

		        ps.setString(1, username);

		        ps.setString(2, mail);

		        
		        
		        java.sql.Date mysqlDate =  new java.sql.Date(date.getTime());

		        ps.setDate(3, mysqlDate);
		        ps.setString(4, phone);

		        ps.setString(5, image);
		       
		        ps.executeUpdate();

		        out.println("Data saved successfully");
			
		}catch(Exception e){
			e.printStackTrace();
		}
		finally{
			if(con != null) con.close();
		}
	}
	else{
		RequestDispatcher rd = request.getRequestDispatcher("/failed.html");
		rd.include(request, response);
	}
	
%>