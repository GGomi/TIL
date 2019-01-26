# 전화번호 목록

## 문제
전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.

구조대 : 119
박준영 : 97 674 223
지영석 : 11 9552 4421
전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.

## 제한 사항
phone_book의 길이는 1 이상 1,000,000 이하입니다.

각 전화번호의 길이는 1 이상 20 이하입니다.

## 입출력 예제
phonebook|return
-|-
["119", "97674223", "1195524421"]	| false
["123","456","789"] | true
["12","123","1235","567","88"]	| false

---

## Solve Code
```java
public boolean solution(String[] phone_book) {
        boolean answer = true;
        Arrays.sort(phone_book, Comparator.comparingInt(String::length));

        for(int i = 0; i < phone_book.length; i++) {
            String temp = phone_book[i];
            for(int j = i+1; j < phone_book.length; j++) {
                //if(phone_book[j].subString(0,temp.length().equals(temp)))
                if(phone_book[j].startsWith(temp)) {
                    answer = false;
                    break;
                }
            }
        }

        return answer;
    }
```

## Explain
- 해시라는 카테고리로 분류되어있었는데 왜 Hash인지 모르겠다..
- 단순한 방법으로 풀이했는데 다행히도 통과가 되었다. ~~(사실 처음에 시간초과 뜸)~~
- subString을 사용해서 시간초과가 뜬 걸로 생각되서 다른 메소드를 찾아보다가 ```startsWith```라는 메소드를 알게되었다. 바꾼 후 효율성 테스트 통과!