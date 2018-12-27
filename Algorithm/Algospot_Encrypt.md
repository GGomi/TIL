# Algospot 문제
---

## Encrypt
---
- 문제

특정 메시지를 암호화 하는 방법은 오랫 동안 다양하게 연구되었다.
그러한 방법들 중에서 가장 간단한 방법을 생각해보자.
특정 문자열을 입력받는다. 편의상 문자열에 공백은 없으며, 영문 대소문자가 입력으로 들어온다. 그러한 다음 문자열의 각 문자에 맨 왼쪽부터 하나씩 0, 1, 2, 3, ... 과 같이 번호를 매긴다.
만약 암호화 하려고 하는 문자열이 `HelloWorld' 가 들어왔을 경우, 다음과 같이 번호가 붙게 된다.

0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 
---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ----
H | e | l | l | o | W | o | r | l | d

---
## 결과
> HloolelWrd

---

```java
import java.util.Scanner;

public class Encrypt {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int caseSize = sc.nextInt();

        for(int i = 0; i< caseSize; i++) {
            String word = sc.next();
            System.out.println("\ninputWord: " + word);
            String even = "";
            String odd = "";
            for(int j = 0; j< word.length(); j++) {
                if(j % 2 == 0) {
                    even += word.substring(j,j+1);
                } else {
                    odd += word.substring(j,j+1);
                }
            }
            word = even+odd;
            System.out.println("word: " + word);
        }
    }
}
```
- 쉬운 문제였다. 처음엔 String대신 Queue를 사용해서 even과 odd를 담으려고 했는데 마지막에 결국 String끼리 더하는 연산이 있어서 일관성있게 String 타입으로 선택하였다.

---