## 함수
원래 알고있던 내용들을 제외한 나머지, 파이썬에서 내가 처음보았던 부분에 대해서만 기술할 것이다.

---

**1. 입력값이 몇개가 될지 모를 때**
- 함수의 입력변수로 `*args `를 주게되면 전부 모아서 튜플로 만들어준다.

```python
def sum(*args)
	sum = 0
	for i in args:
		sum = sum + i
	return sum

```
**2. Return의 마술**
- 원래 리턴 값은 항상 하나였다. **하지만!**

```python
def sum_and_mul(a,b)
	return a+b, a*b

```
- 이런식으로 리턴을 하게되면 튜플로 두가지 값 모두 받을 수 있게된다. 별개의 두가지 값처럼 리턴을 받고싶다면 
**`a,b = sum_and_mul(3,4)`**처럼 함수를 리턴받는 변수를 두개를 써주게되면 따로 따로 값이 들어가게된다.

**3. 입력인수의 초깃값**
- 입력인수에 값이 할당되지않아도 값을 가질 수 있게끔 초기값을 할당할 수 있다.
```python
def self(name,old,man=True)
	print("이름은 %s " % name)
	print("나이는 %d " % old)
	if man:
		print("Man")
	else:
		print("Woman")

```
- 이런식으로 사용가능, 하지만 초깃값이 있는 입력인수는 맨마지막 순서에 있어야한다. 따라서 초기화시키고 싶은 인수는 맨뒤쪽에 위치시켜야한다. 