<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %> 
<%@ page import="java.util.*" %>
<%
    request.setAttribute("score", 83);
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>Insert title here</title>
</head>
<body>
	<c:choose>
	    <c:when test="${score >=90 }">
	    A학점입니다.
	    </c:when>
	    <c:when test="${score >=80 }">
	    B학점입니다.
	    </c:when>
	    <c:when test="${score >=70 }">
	    C학점입니다.
	    </c:when>
	    <c:when test="${score >=60 }">
	    D학점입니다.
	    </c:when>
	    <c:otherwise>
	    F학점입니다.
	    </c:otherwise>            
	</c:choose>
</body>
</html>