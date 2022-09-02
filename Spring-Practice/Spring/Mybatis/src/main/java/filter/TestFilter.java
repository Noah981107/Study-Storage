package filter;

import javax.servlet.*;
import java.io.IOException;

public class TestFilter implements Filter {

    @Override
    public void init(FilterConfig filterConfig) throws ServletException {

    }

    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
        System.out.println("filter start !");
        filterChain.doFilter(servletRequest, servletResponse);
        System.out.println("filter end !");
    }

    @Override
    public void destroy() {

    }
}
