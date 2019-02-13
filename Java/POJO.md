# POJO
- 생성된 자바 객체를 사용하기 위해서 상속을 받아야 한다거나, 인터페이스를 구현해야 한다거나, 어노테이션을 적용해야 한다거나 하는 제약조건이 없는 객체

- ex) POJO가 아닌 객체 
```java
public HelloServlet extends HttpServlet {...}
```

- 하지만, 표준스펙은 아니다.

# DTO
- **Data Transfer Object**
- 계층과 계층 간의 데이터 전송을 목적으로 만들어진 객체
- DB에서 데이터를 얻어 Service나 Controller 등으로 보낼 때 사용하는 객체를 말한다.