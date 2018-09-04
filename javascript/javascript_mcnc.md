# [Javascript]

> ## 1. Web SQL
```
executeSql(sqlStatement, arguments, callback, errorCallback)
```
- 에러콜백은 에러코드로 잡을 것

> ## 2. innerHtml
- innerHtml = "<...>" 이런 식으로 js코드에 html태그를 넣는 방법은 좋지않다.

> ## 3. byteCheck 함수
- 기본적인 for문 방식보다 월등히 빠름, 하지만 두번째가 훨씬 더 빠름
- 첫번째는 정규식을 이용한 byteCheck, 두번째는 쉬프트연산과 삼항연산자를 이용한 바이트체크

```javascript
/**
 * 바이트수 반환  
 * 
 * @param str : tag value
 * @returns {Number}
 */
function byteCheck(str){
    return str.replace(/[\0-\x7f]|([0-\u07ff]|(.))/g,"$&$1$2").length;
}

/**
 * 바이트수 반환 2(훨씬 더~~~ 빠름)
 */
function getByteLength(str, b, i, c) {
    for (b = i = 0; c = s.charCodeAt(i++); b += c >> 11 ? 3 : c >> 7 ? 2 : 1);
    return b;
}
```

