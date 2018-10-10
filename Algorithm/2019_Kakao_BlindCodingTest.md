## 2019 Kakao 블라인드 코딩테스트
---

## 1번
```javascript
/**
 * 
 * @param {*} record  [Enter uid1234 Muzi, Enter uid4567 Prodo,Leave uid1234,Enter uid1234 Prodo,Change uid4567 Ryan]	
 * @returns {*} answer [Prodo님이 들어왔습니다., Ryan님이 들어왔습니다., Prodo님이 나갔습니다., Prodo님이 들어왔습니다.]
 * 
 */
function solution(record) {
    var enter = "님이 들어왔습니다.";
    var leave = "님이 나갔습니다.";
    var answer = [];
    var enteredList = [];
    var myMap = new Map();
    for (var i = 0; i < record.length; i++) {
        var recordItem = record[i].split(" ");
        // console.log(recordItem);
        if (recordItem[0] == "Enter") {
            myMap.set(recordItem[1], recordItem[2]);
            enteredList.push(recordItem[1]);
            answer.push(enter);
        } else if (recordItem[0] == "Leave") {
            answer.push(leave);
            enteredList.push(recordItem[1]);
        } else if (recordItem[0] == "Change") {
            myMap.set(recordItem[1], recordItem[2]);
        }
    }
    for (var j = 0; j < enteredList.length; j++) {
        answer[j] = myMap.get(enteredList[j]).concat(answer[j]);
    }
    return answer;
}
```
---
## 3번
```java
/**
 * @param {*} array [["100","ryan","music","2"},["200","apeach","math","2"},["300","tube","computer","3"},["400","con","computer","4"},["500","muzi","music","3"},["600","apeach","music","2"}}
 * @return int 2
 */

import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int solution(String[][] relation) {
        Map<String, Integer> list;
        List<Integer> ans = new ArrayList<Integer>();
        String temp;
        for (int i = 1; i < (1 << relation[0].length); i++) {
            list = new HashMap<String, Integer>();
            for (int j = 0; j < relation.length; j++) {
                temp = "";
                for(int k = 0; k<relation[0].length; k++) {
                    if ((i & (1 << k)) == (1 << k)) {
                        temp += relation[j][k];
                    }   
                }
                list.put(temp, 0);
            }

            if(list.size() == relation.length && result(ans,i)) {
                ans.add(i);
            }
        }

        return ans.size();
    }

    public boolean result(List<Integer> list, int n) {
        for(int i=0;i<list.size();i++) {
            if((list.get(i)&n) == list.get(i)) {
                return false;
            }
        }

        return true;
    }
}
 ```