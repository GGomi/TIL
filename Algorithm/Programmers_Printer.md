# 프린터

## 문제 설명
일반적인 프린터는 인쇄 요청이 들어온 순서대로 인쇄합니다. 그렇기 때문에 중요한 문서가 나중에 인쇄될 수 있습니다. 이런 문제를 보완하기 위해 중요도가 높은 문서를 먼저 인쇄하는 프린터를 개발했습니다. 이 새롭게 개발한 프린터는 아래와 같은 방식으로 인쇄 작업을 수행합니다.

1. 인쇄 대기목록의 가장 앞에 있는 문서(J)를 대기목록에서 꺼냅니다.
2. 나머지 인쇄 대기목록에서 J보다 중요도가 높은 문서가 한 개라도 존재하면 J를 대기목록의 가장 마지막에 넣습니다.
3. 그렇지 않으면 J를 인쇄합니다.

예를 들어, 4개의 문서(A, B, C, D)가 순서대로 인쇄 대기목록에 있고 중요도가 2 1 3 2 라면 C D A B 순으로 인쇄하게 됩니다.

내가 인쇄를 요청한 문서가 몇 번째로 인쇄되는지 알고 싶습니다. 위의 예에서 C는 1번째로, A는 3번째로 인쇄됩니다.

현재 대기목록에 있는 문서의 중요도가 순서대로 담긴 배열 priorities와 내가 인쇄를 요청한 문서가 현재 대기목록의 어떤 위치에 있는지를 알려주는 location이 매개변수로 주어질 때, 내가 인쇄를 요청한 문서가 몇 번째로 인쇄되는지 return 하도록 solution 함수를 작성해주세요.
---
## 입출력예제

|priorities|location|return
-|-|-
[2, 1, 3, 2]|	2|	1
[1, 1, 9, 1, 1, 1]|	0|	5

---

## Solve Code
```java
public int solution(int[] priorities, int location) {
    int answer = 0;
    int startValue;
    int indexValue;
    int max;

    Stack<Integer> stack = new Stack<>();
    Queue<Integer> valueQueue = new LinkedList<>();
    Queue<Integer> indexQueue = new LinkedList<>();

    for(int i = 0; i < priorities.length; i++) {
        stack.add(priorities[i]);
        valueQueue.offer(priorities[i]);
        indexQueue.offer(i);
    }

    Collections.sort(stack);

    while(true) {
        startValue = valueQueue.remove();
        indexValue = indexQueue.remove();
        max = stack.peek();
        if(startValue == max) {
            stack.pop();
            answer++;
            if(location == indexValue) {
                break;
            }
        } else if(startValue < max) {
            valueQueue.offer(startValue);
            indexQueue.offer(indexValue);
        }
    }

    return answer;
}
```
- 첫번째로 푼 코드이다. 큐의 인덱스가 변화하기전의 인덱스정보를 가지고 있어야했는데 이 부분에 대해 어떤 식으로 구현해야할지 몰라서 큐 두개와 스택 한개를 만들어서 풀어버렸다.
- 하나의 큐에는 인덱스를 관리하는 큐이고, 하나는 priorities값의 큐이다. 그리고 스택은 priorities를 정렬해놓은 스택이다. 
- 이 스택을 만든 이유는 항상 가장 큰 값부터 큐에서 나가게 되므로 그걸 체크하려고 만들었는데 효율적이라고 생각하지 않았다.(~~규칙을 못찾았음..~~)

## Others Solve Code
```java
class File {
    int id;
    int pri;
    File (int id, int pri){
        this.id = id;
        this.pri = pri;
    }
}
public class PrinterVersion {

    static int[] priority = new int[10];

    public boolean check(File temp) {
        int pri = temp.pri;

        for(int i = pri+1; i < 10; i++) {
            if(priority[i] != 0) {
                return false;
            }
        }
        return true;
    }
    public int solution(int[] priorities, int location) {
        int answer = 0;
        Queue<File> queue = new LinkedList<>();

        for(int i = 0; i < priorities.length; i++) {
            priority[priorities[i]]++;
            queue.add(new File(i,priorities[i]));
        }

        while(!queue.isEmpty()) {
            File t = queue.remove();
            boolean checked = check(t);

            if(checked) {
                answer++;
                if(t.id == location) {
                    return answer;
                }
                priority[t.pri]--;
            } else {
                queue.add(t);
            }
        }
        return answer;
    }
}
```
- 이 코드는 클래스를 하나 더 만들어서 초기 index를 관리할 수 있어서 괜찮아보이는 코드였지만 while문 안에서 for문(~~최대 10번이긴 하지만..~~)이 들어있는 checked()를 계속 호출하는 것이 좋아보이지는 않았다.
---
## I think this code is Best
```java
public int solution(int[] priorities, int location) {
        int answer = 0;
        int l = location;

        Queue<Integer> que = new LinkedList<Integer>();
        for(int i : priorities){
            que.add(i);
        }

        Arrays.sort(priorities);
        int size = priorities.length-1;

        while(!que.isEmpty()){
            Integer i = que.poll();
            if(i == priorities[size - answer]){
                answer++;
                l--;
                if(l <0)
                    break;
            }else{
                que.add(i);
                l--;
                if(l<0)
                    l=que.size()-1;
            }
        }

        return answer;
    }
```
- 가장 이상적인 코드라고 생각한다. 문제에서 규칙을 찾아내서 큐 하나와 정렬한번, 단순 while문 하나 비교적 깔끔하게 풀어낸 코드라고 생각한다.
- ```Integer i``` 는 왜 ```Integer```로 했는지 모르겠다.(Queue를 Integer로 했다고 Integer로 했나..?)
- 그에 비해서 내 코드는 특징이 없는 것 같다. 두번째 코드는 다른 클래스를 하나 더 활용해서 인덱스관리를 잘할 수 있었고, 세번째 코드는 규칙을 찾아서 최대한 효율적으로 코딩한 것으로 보인다. 
- 더 열심히 해보자!..
