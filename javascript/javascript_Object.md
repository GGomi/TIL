# Javascript_Object

## 1. 객체 생성하기

### 객체를 생성하는 방법(1)

```javascript
var grades = {'jeongmin':10, 'puppy':100};
```
- 다른언어에서는 맵, 딕셔너리라는 데이터타입이 객체에 해당됨.
- jeongmin이 key가 되고, 10은 value가 된다.

### 객체를 생성하는 방법 (2)

```javascript
var grades = {};
grades['jeongmin'] = 10;
grades['puppy'] = 100;
```

### 객체를 생성하는 방법 (3)

```javascript
var grades = new Object();
grades['jeongmin'] = 10;
grades['puppy'] = 100;
```

---

## 2. 객체 접근하기
---

### 기본적인 접근방법 

```javascript
var grades = {'jeongmin':10, 'puppy':100};

for(val in grades){
     document.write("key :"+key+"<br />value :"+grades[key]+"<br />");
}
```
- grades[key]는 grades.key로도 사용가능하다.
---
### 객체적인 접근방법

```javascript
var grades = {
	'list' = {'jeongmin':10, 'puppy':100},
	'show' = function(){
			 for(key in this.list){
					document.write(key + ":" + this.list[key] + "<br />");
			 }
};

grades.show();
```
- Javascript를 이용한 객체지향프로그래밍에서 핵심이 되는 성질이다. 