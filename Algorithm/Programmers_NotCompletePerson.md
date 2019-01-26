# 완주하지 못한 선수

## 문제 설명
수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.

마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 
선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 
선수의 이름을 return 하도록 solution 함수를 작성해주세요.

## 제한사항
마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.

completion의 길이는 participant의 길이보다 1 작습니다.

참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.

참가자 중에는 동명이인이 있을 수 있습니다.

---
## 입출력 예제
participant|completion|return
-|-|-
[leo, kiki, eden]|[eden, kiki]|leo
[marina, josipa, nikola, vinko, filipa]|[josipa, filipa, marina, nikola]|vinko
[mislav, stanko, mislav, ana]|[stanko, ana, mislav]	|mislav

---
## Solve Code
```java
public String solution(String[] participant, String[] completion) {
        Map<String, Integer> map1 = new HashMap<>();

        String answer = "";

//        for(String temp:participant) {
//            Integer value = map1.get(temp);
//            if(value == null) {
//                map1.put(temp,1);
//            } else {
//                map1.put(temp,value + 1);
//            }
//        }

        for(String partici:participant) {
            map1.put(partici,map1.getOrDefault(partici,0) + 1);
        }

        for(String complete:completion) {
            map1.put(complete,map1.get(complete) - 1);
        }

        for(String key:map1.keySet()) {
            if(map1.get(key) == 1) {
                answer = key;
            }
        }

        return answer;
    }
```

## Explain
- 처음에는 차집합을 구하면 될 것 같아서 차집합에 대해서 알아봤는데 Set을 이용한 차집합은 이 문제에서 적용불가능했다.(왜냐하면 participant에 **중복** 값이 있을 수 있어서)
- 그래서 HashMap을 통해 중복이면 Value를 증가시켜서 중복체크를 했다.
- 처음에는 주석의 내용처럼 if~else를 작성했는데 Java8부터 ```HashMap```에 ```getOrDefault()```라는 메소드를 제공한다. 메소드명 그대로 HashMap에 Key가 존재하지 않을 때 default value값을 설정할 수 있는 메소드이다. 빨리 Java8에 익숙해져야겠다!