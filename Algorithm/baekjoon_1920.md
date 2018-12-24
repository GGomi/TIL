## 백준 1920번 : 수 찾기
---

N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

첫째 줄에 자연수 N(1≤N≤100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 
다음 줄에는 M(1≤M≤100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수들의 범위는 int 로 한다.


## Input
---
```
5
4 1 5 2 3
5
1 3 7 9 5
```

## Output
---
```
1
1
0
0
1
```
---

```java
public void test() throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int firstLength = Integer.parseInt(br.readLine());
        // Split을 사용해서 String으로 리턴됨.
        String[] firstArr = br.readLine().split(" ");
        int[] convertArr = stringToInt(firstArr);

        // 2진탐색을 위한 오름차순정렬
        Arrays.sort(convertArr);

        int secondLength = Integer.parseInt(br.readLine());
        String[] secondArr = br.readLine().split(" ");
        int[] compareArr = stringToInt(secondArr);

        // 이진탐색 ㄱㄱ
        for(int i = 0; i < compareArr.length; i++) {
            int flag = 0;
            int max = firstLength;
            int min = -1;
            int middle;
            while(max - min > 1) {
                middle = (min+max)/2;
                if(compareArr[i] == convertArr[middle]) {
                    flag = 1;
                    break;
                }
                if(compareArr[i] > convertArr[middle]) {
                    min = middle;
                }else if(compareArr[i] < convertArr[middle]) {
                    max = middle;
                }
            }

            System.out.println(flag);
        }

    }
    // Array int형으로 바꿔줌.
public int[] stringToInt(String[] arr) {
    int[] temp = new int[arr.length];
    for(int i=0; i < arr.length; i++) {
        temp[i] = Integer.parseInt(arr[i]);
    }
    return temp;
}
```
