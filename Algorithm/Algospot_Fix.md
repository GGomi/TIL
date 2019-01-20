# Fix

## 문제
알고리즘 문제를 푸는 프로그래밍 대회에서, 문제 순서는 난이도와 관계가 없다. 이 문제는 앞에서부터 풀다가 뒤쪽에 있는 쉬운 문제를 놓치는 팀을 막기위해 출제되었다.

프로그래밍 대회에서 N개의 문제가 출제되었을 때, 난이도는 1이상 N이하인 자연수로 결정되고, 모든 문제는 서로 다른 난이도를 가진다. 또한, 숫자가 높을수록 어려운 문제를 의미한다. 그러므로 난이도 1이면 가장 쉬운 문제, N이면 가장 어려운 문제가 된다.

k번째로 쉬운 문제가 k번째에 배치되었다면, 이것을 "난이도 순으로 배치되었다."라고 한다. 역대 대회 문제들의 난이도가 입력으로 주어진다. 각 대회에 몇 문제가 난이도 순으로 배치되었는지 세어보자.

## 입력
입력의 첫 줄에는 대회의 횟수를 나타내는 자연수 T가 주어지고, 두 번째 줄부터 1회 대회부터 T회 대회까지 각 대회에 대한 문제 정보가 주어진다.
각 대회에 대한 문제 정보는 두 줄로 구성된다. 첫 번째 줄에는 출제된 문제 개수 N이 주어지고, 두 번째 줄에는 첫 번째 문제부터 N번째 문제까지 각각의 난이도가 주어진다. (10 <= N <= 12)

## 출력
각 대회에 대해 난이도 순으로 배치된 문제의 개수를 출력한다.

---

## 예제입력
```
2
12
9 11 4 2 6 3 10 8 1 12 7 5
12
1 7 9 10 2 11 6 4 3 12 5 8
```

## 예제 출력
```
1
1
```

---
## Solved Problem

```java
public class Fix {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));;
        int T;
        int count = 0;
        T = Integer.parseInt(br.readLine());
        while (T > 0) {
            int set;
            set = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int i = 0; i < set; i++) {
                int tmp = Integer.parseInt(st.nextToken());
                if (tmp == i + 1) {
                    count++;
                }
            }
            System.out.println(count);
            count = 0;
            T--;
        }
    }
}
```
