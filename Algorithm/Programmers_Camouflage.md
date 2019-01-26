# 위장

## 문제
스파이들은 매일 다른 옷을 조합하여 입어 자신을 위장합니다.

예를 들어 스파이가 가진 옷이 아래와 같고 오늘 스파이가 동그란 안경, 긴 코트, 파란색 티셔츠를 입었다면 다음날은 청바지를 추가로 입거나 동그란 안경 대신 검정 선글라스를 착용하거나 해야 합니다.

스파이가 가진 의상들이 담긴 2차원 배열 clothes가 주어질 때 서로 다른 옷의 조합의 수를 return 하도록 solution 함수를 작성해주세요.

## 제한사항
clothes의 각 행은 [의상의 이름, 의상의 종류]로 이루어져 있습니다.
스파이가 가진 의상의 수는 1개 이상 30개 이하입니다.

같은 이름을 가진 의상은 존재하지 않습니다.

clothes의 모든 원소는 문자열로 이루어져 있습니다.

모든 문자열의 길이는 1 이상 20 이하인 자연수이고 알파벳 소문자 또는 '_' 로만 이루어져 있습니다.

스파이는 하루에 최소 한 개의 의상은 입습니다.

## Solve Code
```java
public int solution(String[][] clothes) {
        int answer = 1;

        Map<String, Integer> hm = new HashMap<>();

        for (String[] cloth : clothes) {
            hm.put(cloth[1], hm.getOrDefault(cloth[1], 0) + 1);
        }

        for(String key:hm.keySet()) {
            answer *= hm.get(key) + 1;
        }

        return answer-1;
    }
```

## Explain
- N가지의 옷 종류와 M개의 옷 개수가 있을 때, M끼리 곱하면 해당 종류의 옷을 고르지 않았을 때의 경우의 수를 세지 못한다. 
- 그래서 각 종류에 1씩 더해주고 곱하고, 적어도 한종류의 옷은 입기 때문에 전부다 입지 않았을 경우의 수 1을 빼준다.