# Effective Java
<div style="text-align: center;">

![Effective-Java-Cover](https://image.aladin.co.kr/product/17119/64/cover500/8966262287_1.jpg)

</div>

> 이 글은 Effective Java를 읽고 정리한 글입니다.

# 목차
- [Item 1. 생성자 대신 정적팩토리 메서드를 고려하라](#Item-1.-생성자-대신-정적팩토리-메서드를-고려하라)
- [Item 9. try-finally 보다 try-with-resources를 사용하라.](#Item-9.-try\-finally-보다-try\-with\-resources를-사용하라.)

# Item 1. 생성자 대신 정적팩토리 메서드를 고려하라

```java
// 기본타입 boolean을 받아서 Boolean(박싱 클래스) 객체 참조로 변환해준다.
public static Boolean valueOf(boolean b) {
    return b ? Boolean.TRUE : Boolean.FALSE;
}
```
클라이언트가 클래스의 인스턴스를 얻는 전통적인 수단은 public 생성자이다. 하지만 생성자와 별도로 정적 팩토리 메소드를 제공할 수 있다. 정적 팩토리 메소드는 아래와 같은 장점과 단점을 갖는다
## 장점
**1. 이름을 가질 수 있다.**
- 생성자에 넘기는 매개변수와 생성자 자체만으로는 반환될 객체의 특성을 제대로 설명하지 못한다.
- 하지만 정적팩토리메소드는 이름만 잘 지으면 반환될 객체의 특성을 쉽게 묘사할 수 있다.

**2. 호출될 때마다 인스턴스를 새로 생성하지 않아도 된다.**
- 이 장점 때문에 불변클래스는 인스턴스를 미리 만들어 놓거나 새로 생성한 인스턴스를 캐싱하여 재활용하는 식으로 불필요한 객체생성을 피할 수 있다.
- 객체가 자주 요청되는 상황에서 성능을 상당히 끌어올려준다.
- 반복되는 요청에 같은 객체를 반환하는 식으로 언제 어느 인스턴스를 살아 있게 할지를 철저하게 통제할 수 있다.
- 인스턴스를 통제하는 이유는 싱글턴으로 만들 수 있고, 인스턴스화 불가로 만들 수도 있기 때문

**3. 반환타입의 하위 타입객체를 반환할 수 있는 능력이 있다.**
- 반환할 객체의 클래스를 자유롭게 선택할 수 있는 엄청난 유연성
- API를 만들 때 이 유연성을 응용하면 구현 클래스를 공개하지 않고도 그 객체를 반환할 수 있어 API를 작게 유지할 수 있다.

**4. 입력매개변수에 따라 매번 다른 클래스의 객체를 반환할 수 있다.**
- 반환타입의 하위 타입이기만 하면 어떤 클래스의 객체를 반환하든 상관없다.

**5. 정적팩토리 메소드를 작성하는 시점에는 반환할 객체의 클래스가 존재하지 않아도 된다.**
- 서비스 제공자 프레임워크를 만드는 근간이 된다. 대표적으로 JDBC가 있다.
- 서비스 제공자 프레임워크에서 제공자는 서비스의 구현체이다.
- 이 구현체들을 클라이언트에 제공하는 역할을 프레임워크가 통제하여, 클라이언트를 구현체로부터 분리해준다.

## 단점
**1. 정적팩토리메소드만 제공하는 클래스는 하위 클래스를 만들 수 없다.**

**2. 정적팩토리메소드를 프로그래머가 찾기 어렵다.**
- 생성자처럼 API설명에 명확하게 드러나지 않으니 사용자는 정적팩토리메소드 방식클래스를 인스턴스화할 방법을 알아내야한다. 그래서 흔히 사용하는 명명방식들이 생겨나게 되었다.

- **from**: 매개변수를 하나 받아서 해당 타입의 인스턴스를 반환하는 형변환 메소드
- **of**: 여러 매개변수를 받아 적합한 타입의 인스턴스를 반환하는 집계메소드
- **valueOf**: from과 of의 자세한 버전
- **instance, getInstance**: 매개변수로 명시한 인스턴스를 반환하지만, 같은 인스턴스임을 보장하지는 않는다.
- **create, newInstance**: instance 혹은 getInstance와 같지만 매번 새로운 인스턴스를 생성해 반환함을 보장한다.
- **getType**: getInstance와 같으나, 생성할 클래스가 아닌 다른 클래스에 팩토리메소드를 정의할 때 쓴다. Type은 팩토리 메서드가 반환할 객체의 타입이다.
- **newType**: newInstance와 같으나, getType과 같다.
- **type**: getType과 newType의 간결한 버전이다.

### `public` 생성자와 정적팩토리메서드의 상대적인 장단점을 이해하고, 사용하자!


# Item 9. try-finally 보다 try-with-resources를 사용하라.
DB 연결이나 파일 입출력 같은 close()를 통해 닫아주어야하는 자원들이 있다. 이런 자원들은 Java 7 이전에는 try-finally을 통해서 close를 시켜주었다.

하지만, 자원이 2개 이상이 되어버리면 아래와 같이 코드가 복잡해지고, 가독성이 떨어지게된다.

```java
InputStream in = new FileInputStream(src);
try {
    OutputStream out = new FileOutputStream(dst);
    try { 
        ...
    } finally {
        out.close();
    }
} finally {
    in.close();
}
```

![josh-bloch](https://user-images.githubusercontent.com/19489949/59926556-8251e380-9475-11e9-9257-6e88edd147c1.png)

그리고, 코드의 복잡성 이외에도 `finally` 문에서 예외가 나면 다른 예외를 덮어써버린다는 것이다. 그래서 finally 이전에 예외가 있었고, `finally`에서 예외가 난다면 상당히 찾기 힘들어질 수 있다.

이런 문제점들을 해결하고자 Java 7부터 `try-with-resources`가 나왔으며 이는 `AutoCloseable` 인터페이스를 구현하고있다. (이 책의 저자-Josh Bloch 가 작성함..)

`try-with-resources`는 try 문에 AutoClosable을 구현하고 있는 클래스라면 아래와 같이 포함해서 작성할 수 있으며 자동으로 try문이 끝나게되면 close를 해주게 된다.

```java
try (InputStream in = new FileInputStream(src); 
        OutputStream out = new FileOutputStream(dst)) {
     ... 
} catch (..) { }
```
두개 이상의 자원을 한번에 try문에 작성할 수 있으며, 두개의 자원 모두 close가 호출되게된다.
