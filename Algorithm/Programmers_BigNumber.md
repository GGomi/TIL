# 큰 수 찾기

## 문제 설명
0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.

예를 들어, 주어진 정수가 [6, 10, 2]라면 [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고, 이중 가장 큰 수는 6210입니다.

0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.

## 제한 사항
- numbers의 길이는 1 이상 100,000 이하입니다.
- numbers의 원소는 0 이상 1,000 이하입니다.
- 정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다.

---

## Solve
```java
public String solution(int[] numbers) {
        String answer = "";
        List<String> list = new ArrayList<>();
        int length = numbers.length;

        for(int i=0; i<length; i++){
            list.add(String.valueOf(numbers[i]));
        }

        // Collections.sort(list, (num1, num2) -> (num2 + num1).compareTo(num1 + num2));
        list.sort((num1, num2) -> (num2 + num1).compareTo(num1 + num2));
        if(list.get(0).equals("0")){
            return "0";
        }

        for(String a:list) {
            answer = answer + a;
        }

        return answer;
    }
```

- 이 코드에서 compareTo라는 함수가 사용되었는데 이 문제를 통해서 알게되었다. 그리고 Java 8부터 List<T> interface에 sort()가 추가되어있기 때문에 Collections를 import하지 않아도 sort가 가능했다.

**A.compareTo(B)**
  - A와 B는 String으로 비교는 사전적 비교를 통해서 대소 비교를 한다. [compareTo 참고](https://m.blog.naver.com/PostView.nhn?blogId=cheesedrive&logNo=220148513502&proxyReferer=https%3A%2F%2Fwww.google.co.kr%2F)
    - A < B일 때 음수를 반환한다.
    - A > B일 때 양수를 반환한다.
    - A = B일 때 0을 반환한다.
  - 이를 통해서 sort를 해주면 사전식 규칙을 따른 정렬이 이루어진다.
