## while 반복문
기존에 알던 while문과 큰 차이는 없다. 다만 `continue`문을 만나게되면 `while`문의 조건으로 돌아가게하는 구문이 하나있다.

```python
>>> a = 0
>>> while a < 10:
	a = a+1
	if a % 2 == 0: continue
	print(a)

1
3
5
7
9
```
이 코드는 10 이전의 값에서 홀수만 출력하는 코드로 `while`문안에 있는 if 문의 **`continue`**를 만나면 `while` 조건으로 곧바로 다시 되돌아간다.

---

## for 반복문
여태까지 봐왔던 `for`문과는 약간 다르다. `for ~ in` 이런식으로 사용하는데 `for~in`은 리스트,튜플,문자열만을 다룬다.
```python
>>> test_list = ['one','two','three']
>>> for i in test_list:
		print(i)
one
two
three
```
이런형태가 기본적인 for문이다.

```python
>>> a = [(1,2), (3,4), (5,6)]
>>> for (first, last) in a:
...     print(first + last)
...
3
7
11
```
위처럼 `i`대신 튜플로 설정해서 반복문을 처리할 수 도있다. 여태까지 썼던 `for`문에서 발전된 느낌이다.(개인적)

원래 알던 for문은 아래의 코드처럼 표현가능하다
```python
sum=0
for i in range(1,11):
	sum = sum+i

```
`range`라는 함수로 1이상 11미만의 객체를 만들어내어 반복문이 실행된다.

## 리스트 내포(List comprehension)
리스트 내포가 뭘까하고 쳐다보고있었는데 이게 바로 codewars를 하면서 봤던 이해못한 코드였음을 깨닫게되었다. 
[codewars Link](https://ggomi.github.io/Codewars/Codewars-6kyu-Array-diff/)

리스트에 연산이나 별도의 처리를 하고난 다음 결과를 얻고자할 때 유용할 것이라고 생각한다.

```python
>>> a = [1,2,3,4]
>>> result = []
>>> for num in a:
...     result.append(num*3)
...
>>> print(result)
[3, 6, 9, 12]
```


```python
>>> result = [num * 3 for num in a]
>>> print(result)
[3, 6, 9, 12]
```

이런형태로 변형할 수 있게된다.
일반식은 `[표현식 for 항목 in 반복가능객체 if 조건]`