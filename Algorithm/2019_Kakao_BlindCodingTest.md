## 2019 Kakao 블라인드 코딩테스트
---

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