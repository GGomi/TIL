## [Codewars_6kyu] Array.diff
파이썬의 문법과 API를 익힐겸 알고리즘문제 풀이를 해보았다.

----
Your goal in this kata is to implement an difference function, which subtracts one list from another.

It should remove all values from list `a`, which are present in list `b`.

```
array_diff([1,2],[1]) == [2]
```

If a value is present in `b`, all of its occurrences must be removed from the other:

```
array_diff([1,2,2,2,3],[2]) == [1,3]
```



---

**내가 생각하는 포인트**

1. 파라미터로 배열 두 개를 받는다. 
1. **두번째 배열의 요소들을 첫번째 배열에서 모두 지워야한다.**
1. 파라미터로 들어오는 배열이 비어있을 수 있다.

---
아직 파이썬에 익숙하지도 않고, 알고있는 레퍼런스함수들이 많지 않아서 시간이 조금 걸렸다.

알고리즘 풀이를 하면서 항상 느끼지만 어떻게해야 더 좋게 구현할 수 있을지 고민하는 것은 너무 어렵다ㅠㅠ

하지만 이 문제를 처음 봤을 때 상당히 쉽게 느껴져서 바로 코딩을 시작했다.

- 첫번째 코드
```
def array_diff(a, b):
    #your code here
    if len(b) != 0:
        if len(a) != 0:
            for i in range(0,len(b)):
                count = a.count(b[i])
                for j in range(0,count):
                    a.remove(b[i])
    
	return a
```
결과는 잘 나왔지만 뭔가 지저분해 보인다... count변수를 사용해서 해당 요소가 

몇개들어있는지 확인해서 그만큼만 for문을 돌리는 것도 마음에 안들었다.

그리고 파라미터로 들어오는 배열의 길이가 0인지 아닌지 판단할 필요가 없다고 생각해서 코드를 고쳐보았다.

- 두번째 코드
```
def array_diff(a, b):
    #your code here
    for i in range(len(b)):
        while b[i] in a:
            a.remove(b[i])
    return a
```
파라미터를 체크하는 코드를 지우고, `while...in` 구문을 사용해서 

배열 `b`의 요소가 `a`에 존재하면, 루프를 계속 돌면서 요소를 지워나갔다.

더 이상 고칠만한게 없어보여서 `submit`을 하고, 다른코드들을 보았는데 고수등장..

- **고수의 코드**
```
def array_diff(a, b):
    return [x for x in a if x not in b]
```
단 한줄로 끝내버렸다.... 나는 아직 멀었나보다..ㅎㅎ

정확하게 구문이 이해되지않지만 의미는 일맥상통해보인다. 대괄호자체를 리턴한다는건 상상도 못해봤다..