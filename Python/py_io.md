## 파이썬 기본 입출력
기본적으로 `input()`으로 키보드의 입력 값을 받는다.
```python
>>> number = input("숫자를 입력")
숫자를 입력
```

`input()` 안에 질문이나 특정 문장을 넣어주면 입력하기 전에 프롬프트에 입력한 문장이 출력되게된다.

```python
>>> for i in range(10):
		print(i, end=' ')

0 1 2 3 4 5 6 7 8 9
```

`end=' '`처럼 끝문자를 지정해주면 한줄에 쭉 이어서 출력하게된다.

---

## 파일 입출력

역시 파이썬답게 파일입출력코드도 간단하다.
```python
f = open("new.txt","w")
f.close
```
이게 기본형태이며 `w` 옵션은 파일쓰기모드인데 파일이 존재하지않으면 생성하고, 존재하면 내용을 모두 지운 후 쓰기모드를 시작한다.
```python
f = open("new.txt","w")
for i in range(1,11):
	data = "%d번째 줄입니다.\n" % i
	f.write(data)
f.close
```
파일을 읽을때는 `read`, `readline`, `readlines` 를 사용한다.
`readline`은 한 줄씩 읽어 들이며, 
`readlines`는 처음부터끝까지 읽고 한줄단위로 끊어서 리스트를 생성하게된다.
`read`는 파일의 내용전체를 문자열로 리턴한다.

---
파일입출력을 할 때 파일을 열었다면 닫아주어야한다 꼭! 이를 자동으로 해주는 것이 있는데 그거슨 **`with`**
```python
with open("new.txt","w") as f:
	f.write("Hello")
```
`with`블록을 벗어나게되면 자동으로 `close`된다. 어떻게 보면 두줄짜리 코드를 한줄로 바꿔준 셈이다.