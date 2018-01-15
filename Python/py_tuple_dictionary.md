## 튜플 자료형

몇가지 제외하고 리스트와 비슷함!

- 리스트는 대괄호로 둘러싸지만 튜플은 소괄호로 둘러싼다.
- 튜플은 리스트와 달리 한번 만들어진 값을 바꿀 수 없다.
- 나머지는 비슷함.

## 딕셔너리 자료형

Hash와 같은의미로 파이썬에서는 딕셔너리라고 함.

```python
>>> dic = {'name':'jeongmin','phone':'01012341234'}
```

이런식으로 'key':'value' 값이 정해진다.

주의할 사항으로 key는 유일한 값이므로 중복되게 key값을 넣으면 안된다.


### key 리스트
```python
# 딕셔너리a의 모든 키값을 가져와서 리스트를 생성한다.(2.7버전 까지)
# 3.0이후버전 부터는 dict_keys라는 객체를 리턴한다.

>>> a.keys()
dict_keys(['name','phone'])
```

### value 리스트
```python
# 딕셔너리 a의 모든 value값을 모아서 리스트를 리턴한다.(2.7버전 까지)
# 3.0이후 버전부터는 dict_values라는 객체를 리턴

>>>a.values()
dict_values(['jeongmin','01012341234'])
```

### 이외의 함수들
```python
# key,value 쌍 얻기
>>> a.times()
dict_items(['name':'jeongmin'],['phone':'01012341234'])

# 해당 key가 딕셔너리 안에 있는지 조사하기(in)
# 키가 있으면 True 반환
>>> 'name' in a
True
```
