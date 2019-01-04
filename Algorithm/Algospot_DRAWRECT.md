# DRAWRECT

문제

AdbyMe, Inc. 의 인턴인 A.I.는 웹 브라우저에 직사각형을 그리는 코드를 작성해야 한다. 웹 브라우저는 직사각형 모양의 뷰포트를 가지고 있고, 그려지는 직사각형의 네 변은 반드시 그 뷰포트의 두 축에 평행해야 한다.

한편, A.I.는 코드를 작성하던 중 그릴 직사각형의 네 꼭지점 중 어느 것이든 세 개의 좌표를 알고 있다면 나머지 점의 위치는 유일하게 결정됨을 알아내었다 (네 점 중 어떤 두 개의 좌표를 알아낸 경우는 때에 따라 직사각형을 결정하지 못할 수도 있다.)

A.I.는 LIBe에게 이를 이번 대회 문제로 출제할 것을 제안하였다.

직사각형을 이루는 네 점 중 임의의 세 점의 좌표가 주어졌을 때, 나머지 한 개의 점의 좌표를 찾는 프로그램을 작성하라.

---

입력

입력은 T 개의 테스트 케이스로 구성된다. 입력의 첫 행에는 T 가 주어진다.

각 테스트 케이스는 공백 하나로 구분되는 두 개씩의 정수로 구성된 세 행으로 이뤄지며, 각각 임의의 세 점의 x와 y 좌표이다. 브라우저 뷰포트의 맨 왼쪽 위 픽셀의 좌표는 (1, 1)이고, 맨 오른쪽 아래 픽셀의 좌표는 (1000, 1000)이다. 모든 좌표는 뷰포트 안에 위치하며, 각 점의 위치는 모두 다르다.

예제 입력
```language
2
5 5
5 7
7 5
30 20
10 10
10 20
```

---

예제 출력

```language
7 7
30 10
```

---

- 처음에는 차례대로 받아서 비교하면서 마지막 네번째 좌표를 찾으려고 했는데 규칙을 찾다보니 x1, x2, x3가 있을 때 항상 이 중에서 항상 두개는 같은 좌표이고, 하나는 다른 좌표라는걸 알 수 있었다. (y좌표도 마찬가지)

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class DRAWRECT {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    
    public static void main(String[] args) throws IOException {
        int C = Integer.parseInt(br.readLine());

        while(C > 0) {
            int x = 0;
            int y = 0;
            for(int i = 0; i < 3; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine(), " ");
                x = x^Integer.parseInt(st.nextToken());
                y = y^Integer.parseInt(st.nextToken());
            }

            System.out.printf("%d %d",x,y);
            System.out.println();
            C--;
        }
    }
}
```
- 그래서 위와 같이 XOR연산을 이용해서 입력 중에서 다른 하나를 찾아내었다. XOR연산을 생각하지 못했으면 약간 힘들었을 것 같다. 
