# JPA 기초

## Dialect
- 어떤 데이터베이스냐에 따라서 서로 SQL이 조금씩 다르기때문에(데이터베이스 방언)때문에 미리 Persistence.xml에서 사용할 데이터베이스의 종류를 정해서 JPA가 제대로 쿼리를 작성할 수 있게끔 한다.
---
## Entity
- Entity Manager는 쓰레드간에 공유하면 안된다
- Entity Manager Factory는 하나만 생성해서 애플리케이션 전체에서 공유한다.
- 모든 데이터변경은 트랜잭션 안에서 실행
---
## 데이터베이스 스키마 자동 생성하기
- DDL을 애플리케이션 실행 시점에 자동생성
- 테이블 중심 -> 객체 중심
- 데이터 베이스 방언을 활용해서 데이터베이스에 맞는 적잘한 DDL 생성
- 이렇게 생성된 DDL은 개발자장비에서만 사용
- 생성된 DDL은 운영서버에서는 사용하지 않거나 적절히 다듬은 후 사용
- 운영장비에는 절대 create, create-drop, update사용 X
- 개발 초기는 create, update
- 테스트서버는 update, validate
- 스테이징과 운영서버는 validate or None
---
## option
```xml
<property name="hibernate.hbm2ddl.auto" value="create"/>
```
- create는 기존 테이블을 drop 시키고, 다시 생성함.(운영사용금지)
- create-drop은 drop->create->drop 의 순서로 짆애
- create옵션은 테스트할 때만.
---
## Enum Class 
- **꼭 String 타입으로 할 것**
- int로 하면 Enum의 인덱스가 테이블에 Insert된다. 그래서 Enum클래스에 새로운 것이 추가가 된다면 기존 테이블이 꼬이게 된다.
- String으로 하면 Enum이름이 그대로 테이블에 Insert된다.
- default는 ORDINAL(순서를 저장)
```java
@Enumerated(EnumType.STRING)
private RoleType roleType;
```
---

## 매핑관련 Annotation

### @Column

```java
@Column(name="username") // username을 컬럼이름으로 사용함
private String name;
```

### @Temporal
- 날짜 타입 매핑 관련 Annotation
```java
@Temporal(TemporalType.DATE)
private Date date;

@Temporal(TemporalType.TIME)
private Date time;

@Temporal(TemporalType.TIMESTAMP)
private Date timestamp;
```


### @Lob
- 컨텐츠의 길이가 너무길 때, 바이너리 파일로 입력하기위한 Annotation
- CLOB : String, char[], java.sql.CLOB
- BLOB : byte[], java.sql.BLOB
- 선언한 타입대로 변함.
```java
@Lob
private String lobString;

@Lob
private byte[] lobByte;
```

### @Transient
- 이 변수는 매핑하기 싫을 때 쓰는 Annotation인데 안쓰는 것이 좋음.
- 어쨌든 매핑에서 제외시킬 때 사용

---

## 식별자 매핑 어노테이션
@GeneratedValue(strategy = GenerationType.AUTO)
- AUTO를 사용하면 방언에 맞게 매핑해줌.


## 권장하는 식별자 전략
- 기본키 제약조건 : not null , 유일, 불변
- 미래까지 이 조건을 만족하는 자연키는 찾기 어렵다. **대리키**를 사용
- 주민등록번호도 기본키로 적절하지 않다
- 권장: Long + 대체키 + 키 생성전략 사용