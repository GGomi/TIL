# Algospot Coin Change

## 문제
---
우리 나라에는 10원, 50원, 100원, 500원의 네 가지 동전이 있다. (1원짜리와 5원짜리는 거의 안 쓰니까 없는 걸로 하지요) 이 동전들을 이용해 110원을 거슬러 주는 방법은 몇 가지나 될까? 다음의 네 가지가 있다:

- 10원 짜리 11개
- 10원짜리 6개, 50원짜리 1개
- 10원짜리 1개, 50원짜리 2개
- 10원짜리 1개, 100원짜리 1개
- 
금액이 커지거나 동전의 종류가 많아질 수록 이 경우의 수는 많아진다. 동전의 종류와 금액이 주어질 때, 해당 동전들을 이용해 해당 금액을 환전하는 방법의 수를 구하는 프로그램을 작성하라.

## 입력
입력의 첫 줄에는 테스트 케이스의 수 T (1 <= T <= 100) 가 주어진다. 각 테스트 케이스의 첫 줄에는 환전할 금액 M (1 <= M <= 5000) 과 동전 종류의 개수 C (1 <= C <= 100) 가 주어진다. 그 다음 줄에, C 개의 정수로 각 동전 종류별 금액이 주어진다. 동전의 금액은 5000 이하의 자연수이다.

## 출력
각 테스트 케이스마다, 해당 금액을 환전할 수 있는 경우의 수를 출력한다. 경우의 수가 1000000007 보다 큰 경우, 1000000007 으로 나눈 나머지를 출력한다.

---

## 입력예제

```
4
110 4
10 50 100 500
850 4
10 50 100 500
3600 5
100 300 500 900 2000
1278 8
1 2 4 8 16 32 64 128
```

## 출력예제

```
4
110
130
873794561
```

---

## Solve

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Coins {
    public static void main(String[] args) throws IOException {
        int T;
        int[] coinList;
        long[] count;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));;

        T = Integer.parseInt(br.readLine());

        while (T > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            
            int exchange = Integer.parseInt(st.nextToken());
            int coinCount = Integer.parseInt(st.nextToken());
            count = new long[exchange + 1];

            String[] temp = br.readLine().split(" ");
            coinList = Arrays.stream(temp).mapToInt(Integer::parseInt).toArray();

            count[0] = 1;

            for(int i = 0; i < coinCount; i++) {
                for(int value = coinList[i]; value <= exchange; value+=coinList[0]) {
                    count[value] += count[value - coinList[i]];
                }
            }
            
            if(count[exchange] > 1000000007) {
                count[exchange] %= 1000000007;
            }

            System.out.println(count[exchange]);
            
            T--;
        }
    }
}
```

- 이문제는 DP유형의 문제로 시작했지만 결과적으로 전체탐색 느낌으로 풀이했다. 