# Dialect
어떤 데이터베이스냐에 따라서 서로 SQL이 조금씩 다르기때문에(데이터베이스 방언)때문에 미리 Persistence.xml에서 사용할 데이터베이스의 종류를 정해서 JPA가 제대로 쿼리를 작성할 수 있게끔 한다.

---

Entity Manager는 쓰레드간에 공유하면 안된다
Entity Manager Factory는 하나만 생성해서 애플리케이션 전체에서 공유한다.
모든 데이터변경은 트랜잭션 안에서 실행

데이터베이스 스키마 자동 생성하기
- DDL을 애플리케이션 실행 시점에 자동생성
- 테이블 중심 -> 객체 중심
- 데이터 베이스 방언을 활용해서 데이터베이스에 맞는 적잘한 DDL 생성
- 이렇게 생성된 DDL은 개발자장비에서만 사용
- 생성된 DDL은 운영서버에서는 사용하지 않거나 적절히 다듬은 후 사용
- 운영장비에는 절대 create, create-drop, update사용 X
- 개발 초기는 create, update
- 테스트서버는 update, validate
- 스테이징과 운영서버는 validate or None

option

```hibernate.hbm2ddl.auto```


enum Class (우아한 형제들 기술블로그 참조)
- 꼭 String 타입으로

@Column

@Lob

@GeneratedValue(strategy = GenerationType.AUTO)

권장하는 식별자 전략
- 기본키 제약조건 : not null , 유일, 불변
- 미래까지 이 조건을 만족하는 자연키는 찾기 어렵다. 대리키를 사용
- 주민등록번호도 기본키로 적절하지 않다
- 권장: Long + 대체키 + 키 생성전략 사용