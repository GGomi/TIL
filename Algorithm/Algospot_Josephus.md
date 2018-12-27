# Josephus

## 문제

1세기에 살던 역사학자 조세푸스는 로마와의 전쟁에서 패해 N - 1명의 동료 병사들과 함께 출구가 없는 동굴에 포위당했다고 합니다. 동료 병사들은 로마에 항복하느니 차라리 자살하자고 결의했고, 포위당한 N명의 사람들이 모두 원형으로 둘러선 뒤 순서대로 자살하기로 했습니다. 한 사람이 자살하면, 다음에는 그 사람으로부터 시계 방향으로 K번째 살아 있는 사람이 자살하는 것입니다.

조세푸스의 책에 따르면 조세푸스와 다른 병사 하나만이 살아남았을 때 이들은 마음을 바꿔 로마에 항복해서 살아남았다고 합니다. 마지막 두 명 중 하나가 되기 위해서는 조세푸스는 첫 번째 병사로부터 몇 자리 떨어진 곳에 있어야 했을까요?

## 입력

입력의 첫 번째 줄에는 테스트 케이스의 개수 C (C≤50)가 주어집니다. 각 테스트 케이스는 두 개의 정수 N, K로 주어집니다(3≤N≤1000, 1≤K≤1000).

## 출력

각 테스트 케이스에 두 개의 정수로, 마지막 살아남는 두 사람의 번호를 오름차순으로 출력합니다. 첫 번째로 자살하는 병사의 번호가 1이며, 다른 사람들의 번호는 첫 번째 병사에서부터 시계 방향으로 정해집니다.

---

Input

```
2
6 3
40 3
```

output

```
3 5
11 26
```

---

Solved

```java

import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class Josephus {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int caseSize = sc.nextInt();

        for(int len = 0; len < caseSize; len++){
            LinkedList <Integer> list = new LinkedList<Integer>();
            int size;
            int targetIndex = 1000;
            int index = 0;
            int targetValue;
            int queueSize = sc.nextInt();
            int K = sc.nextInt() - 1;

            for(int i = 0; i < queueSize; i++) {
                list.add(i+1);
            }

            while(list.size() > 2) {
                list.remove(index);
                size = list.size();

                if(index + K >= size) {
                    targetIndex = (index + K) % size;
                } else {
                    targetIndex = index + K;
                }

                targetValue = list.get(targetIndex);
                index = list.indexOf(targetValue);
            }

            Collections.sort(list);

            System.out.printf("%d %d\n",list.get(0), list.get(1));
        }
    }
}
```

- LinkdeList를 이용하였고, 전체적인 흐름은 현재의 인덱스를 삭제하고, 그 뒤에 남은 요소들에서 어떤 인덱스의 요소를 삭제할 것 인지 결정하게 되는데 **K** 변수를 보면 입력받자마자 -1을 해준다.
- LinkedList에서 remove를 진행한 후에 그 다음 지울 인덱스를 찾기 때문에 K를 -1을 해주어야한다.(자기자신은 이미 지워졌기 때문)