# Effective Java
<div style="text-align: center;">

![Effective-Java-Cover](https://image.aladin.co.kr/product/17119/64/cover500/8966262287_1.jpg)

</div>

> 이 글은 Effective Java를 읽고 정리한 글입니다.

# 목차
- [Item 9. try-finally 보다 try-with-resources를 사용하라.](#Item-9.-try\-finally-보다-try\-with\-resources를-사용하라.)


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

그리고, 코드의 복잡성 이외에도 ```finally``` 문에서 예외가 나면 다른 예외를 덮어써버린다는 것이다. 그래서 ```finally``` 이전에 예외가 있었고, finally에서 예외가 난다면 상당히 찾기 힘들어질 수 있다.

이런 문제점들을 해결하고자 Java 7부터 ```try-with-resources```가 나왔으며 이는 ```AutoCloseable``` 인터페이스를 구현하고있다. (이 책의 저자-Josh Bloch 가 작성함..)
![josh-bloch](https://user-images.githubusercontent.com/19489949/59926556-8251e380-9475-11e9-9257-6e88edd147c1.png)

```try-with-resources```는 try 문에 AutoClosable을 구현하고 있는 클래스라면 아래와 같이 포함해서 작성할 수 있으며 자동으로 try문이 끝나게되면 close를 해주게 된다.

```java
try (InputStream in = new FileInputStream(src); 
        OutputStream out = new FileOutputStream(dst)) {
     ... 
} catch (..) { }
```
두개 이상의 자원을 한번에 try문에 작성할 수 있으며, 두개의 자원 모두 close가 호출되게된다.
