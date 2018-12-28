# Insertion
---

A | 비고
-|-
5 1 4 3 2 |	초기 상태
1 5 4 3 2|1을 왼쪽으로 1칸 옮김
1 4 5 3 2|	4를 왼쪽으로 1칸 옮김
1 3 4 5 2|	3을 왼쪽으로 2칸 옮김
1 2 3 4 5|	2를 왼쪽으로 3칸 옮김

1부터 N까지의 자연수가 한 번씩 포함된 길이 N 인 수열 A[] 를 삽입 정렬했습니다. 원래 수열은 알 수 없지만, 그 과정에서 각 원소가 왼쪽으로 몇 칸이나 이동했는지를 알고 있습니다. 예를 들어, 위 예제에서 각 위치에 있는 값들이 움직인 칸수를 표현하면 {0,1,1,2,3} 이 됩니다. 이 때 원래 수열을 찾아내는 프로그램을 작성하세요.

---

## 입력

입력의 첫 줄에는 테스트 케이스의 수 C (1 <= C <= 50) 가 주어집니다. 각 테스트 케이스의 첫 줄에는 원 배열의 길이 N (1 <= N <= 50000) 이 주어집니다. 그 다음 줄에 N 개의 정수로 A의 각 위치에 있던 값들이 움직인 칸수가 주어집니다. A 는 1부터 N 까지의 정수를 한 번씩 포함합니다.

입력의 양이 많으므로 가능한 빠른 입력 함수를 사용하는 것이 좋습니다.

## 출력
각 테스트 케이스마다 재구성한 A[] 를 한 줄에 출력합니다.

예제입력
```
2
5
0 1 1 2 3
4
0 1 2 3
```

예제 출력
```
5 1 4 3 2
4 3 2 1
```

---

## Solved

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Insertion {
    static int N;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int C = Integer.parseInt(br.readLine());

        while(C > 0) {
            List<Integer> list = new ArrayList<Integer>();
            N = Integer.parseInt(br.readLine());
            arr = stringToint(br.readLine().split(" "));

            for(int i = 1; i <= N; i++) {
                list.add(i);
            }

            solve(list);

            C--;
        }
    }

    public static void solve(List<Integer> list) {
        int[] result = new int[list.size()];

        while(list.size() > 0) {
            int pivot = list.size()-1;
            int temp = list.get(pivot-arr[pivot]);
            result[pivot] = temp;
            list.remove(pivot-arr[pivot]);
        }

        for(int i = 0; i < result.length; i++) {
            if(i != result.length-1) {
                System.out.print(result[i]+" ");
            } else {
                System.out.println(result[i]);
            }
        }
    }

    public static int[] stringToint(String[] arr) {
        int[] iArr = new int[arr.length];
        for(int i = 0; i < arr.length; i++) {
            iArr[i] = Integer.parseInt(arr[i]);
        }

        return iArr;
    }
}
```
- 삽입정렬을 거꾸로 돌린다는 느낌으로 진행하였다. 삽입정렬에 대해서 제대로 이해하고 있어야 풀 수 있는 문제라고 생각한다. ~~머리가 좋으면 노상관~~ 
- 두번째 고민은 어떤 타입에 담아서 답을 구해낼 것인지 였는데 중간의 엘리먼트를 지워야하기 때문에 ArrayList를 사용하였다.