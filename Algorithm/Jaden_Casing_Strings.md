## 문제 [Codewars_7kyu] Jaden Casing Strings
---
Jaden Smith, the son of Will Smith, is the star of films such as The Karate Kid (2010) and After Earth (2013). Jaden is also known for some of his philosophy that he delivers via Twitter. When writing on Twitter, he is known for almost always capitalizing every word.

Your task is to convert strings to how they would be written by Jaden Smith. The strings are actual quotes from Jaden Smith, but they are not capitalized in the same way he originally typed them.

Example:

```
Not Jaden-Cased: "How can mirrors be real if our eyes aren't real"
Jaden-Cased:     "How Can Mirrors Be Real If Our Eyes Aren't Real"
```

Note that the Java version expects a return value of null for an empty string or null.

---

#### 1. string 문장을 공백을 구분으로 나누고, 그 나눠진 요소들의 맨앞글자를 대문자로 변경해야함.
#### 2. split()을 사용하자.

---
## Code

```python
def toJadenCase(string):
    #string을 split()함수를 통해 나눠서 sub array를 생성
    sub=string.split()
    res = ""
    
    for i in range(len(sub)):
        res += sub[i][:1].upper() + sub[i][1:len(sub[i])]
        if i != len(sub)-1:
            res += " "
            
    return res
```

첫번째로 작성한 코드인데 너무 파이썬스럽지 못하다고 생각했다..

그리고 `for...in` 구문을 제대로 써먹지 못하는 것 같기도하고 코드가독성이 그리 좋지못했다.

수정을 하려고 고민 중에 `join()`을 알게되었다. `join()`은 `list`를 `string`으로 만들어주기때문에 

`res`변수에 더하는 과정을 없앨 수 있었다.

---

## 2차 Code
```python
def toJadenCase(string):
    #string을 split()함수를 통해 나눠서 sub array를 생성
    sub=string.split()
    
    for i in range(len(sub)):
        sub[i] = sub[i][:1].upper() + sub[i][1:len(sub[i])]
            
    # " ".join을 통해 list요소 사이에 빈칸을 넣고, 하나의 문자열로 합쳐준다.
    return " ".join(sub)
```

---

2차 코드로 submit을 완료하고, 다른 Solution들을 봤는데 list의 각 요소들의 첫번째 문자를 대문자로 바꿔주는 함수가 있었다.

나는 직접 for문을 돌려서 대문자로 바꾸어주었는데 레퍼런스함수로 이미 존재했다.. 이럴때 솔직히 조금 허무한 감이 있지만

놀랍기도 하다..

capitalize() [링크](https://docs.python.org/2/library/string.html)

---

## Other Code

```python
def toJadenCase(string):
	return " ".join(w.capitalize for w in string.split())
```

---