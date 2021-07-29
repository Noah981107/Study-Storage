<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %> 
<%
request.setAttribute("n", 10);
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
	<c:if test="${n == 0}">
	n은 과 0과 같습니다.
	</c:if>
	
	<c:if test="${n == 10}">
	n은 과 10과 같습니다.
	</c:if>
</body>
</html>