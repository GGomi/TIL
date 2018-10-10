## 2019 Kakao 블라인드 코딩테스트
---

## 1번 오픈채팅방
```javascript
/**
 * ----------------------------------------------------------------------------------------
 *                                      record
 * ----------------------------------------------------------------------------------------
 * [Enter uid1234 Muzi, Enter uid4567 Prodo,Leave uid1234,Enter uid1234 Prodo,Change uid4567 Ryan]
 * ----------------------------------------------------------------------------------------
 *                                      answer
 * ----------------------------------------------------------------------------------------
 * [Prodo님이 들어왔습니다., Ryan님이 들어왔습니다., Prodo님이 나갔습니다., Prodo님이 들어왔습니다.]
 * ----------------------------------------------------------------------------------------
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
## 2번 실패율

```java
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
/**
 * 
 * @author jminoh
 * @input
 * ------------------------------------------------
 * N              stages                  result
 * ------------------------------------------------
 * 5	[2, 1, 2, 6, 2, 4, 3, 3]	[3,4,2,1,5]
 * ------------------------------------------------
 * 4	[4,4,4,4,4]	                 [4,1,2,3]
 */
public class Solution {
	public static void main(String[] args) {
		
        // input
		int N = 5;
		int[] stages = { 2, 1, 2, 6, 2, 4, 3, 3 };

		int[] reach = new int[N];
		Map<Integer, Double> list = new HashMap<Integer, Double>();
		int personLength = stages.length;
		double temp = personLength;
		double failed;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < personLength; j++) {
				if (i + 1 == stages[j]) {
					reach[i] += 1;
				}
			}

			// 0으로 나누면 NaN 발생함. 따라서 분기필요
			if(temp != 0) {
				failed = reach[i] / temp;	
			} else {
				failed = 0;
			}

			list.put(i + 1, failed);
			temp -= reach[i];
		}
		System.out.println(list);
		Set<Integer> set = sortByValue(list).keySet();
		int i = 0;
		for(int x : set) {
			reach[i++] = x;
		}
		System.out.println(Arrays.toString(reach));

	}

	/**
	 * @description HashMap을 Value 기준으로 sort
	 * @param map
	 * @return value기준으로 내림차순 정렬된 map
	 */
	public static <K, V extends Comparable<? super V>> Map<K, V> sortByValue(Map<K, V> map) {
		List<Entry<K, V>> list = new ArrayList<>(map.entrySet());

		// comparingByValue() 안에 Comparator.reverseOrder()의 유무로 Order 결정
		list.sort(Entry.comparingByValue(Comparator.reverseOrder()));

		Map<K, V> result = new LinkedHashMap<>();
		for (Entry<K, V> entry : list) {
			result.put(entry.getKey(), entry.getValue());
		}

		return result;
	}

}
```
---
## 3번 후보키
```java
/**
 * @param {*} array [["100","ryan","music","2"},["200","apeach","math","2"},["300","tube","computer","3"},["400","con","computer","4"},["500","muzi","music","3"},["600","apeach","music","2"}}
 * @return int 2
 */

import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;
import java.util.Map;
/**
 * ----------------------------------------------------------------------------------------
 *       array
 * ----------------------------------------------------------------------------------------
 * [["100","ryan","music","2"],["200","apeach","math","2"],["300","tube","computer","3"],["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]]
 * ----------------------------------------------------------------------------------------
 *                                      result
 * ----------------------------------------------------------------------------------------
 *                                        2
 * ----------------------------------------------------------------------------------------
 * 
 */
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
