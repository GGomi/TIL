# npm app Tips

## body-parser
- middleware중 하나로서 POST방식으로 정보요청할때 사용.

- 설치방법

```language
npm install body-parser --save
```

```javascript
var bodyParser = require('body-parser');

//URL을 요청하기전 bodyParser를 한번 거쳐야한다는 구문 그래서 middleware임.
app.use(bodyParser.urlencoded({extended: false}));
```
---

## Supervisor
- js파일을 재실행 시키지않아도 Supervisor의 watch기능을 통해 소스의 변경을 감지하고, 자동으로 재실행시켜줌
* 설치: ```sudo npm install supervisor -g```
* 실행: ```supervisor app.js```

---
## Jade
- jade template을 사용하기위한 npm, html코드를 template화 시킴.
- 설치: ```npm install jade --save```

```
//jade 예시
doctype html
html
  head
    meta(charset='utf-8')
  body
    form(action='/topic' method='post')
      p
        input(type='text' name='title' placeholder='title')
      p
        textarea(name='description')
      p
        input(type='submit')

```
- 하지만, jade template을 가져올때 코드가 들여쓰기없이 그냥 한줄로 나오게된다. 이것을 해결하기위해 js파일에 아래의 구 문을 써주면된다. 그럼 이쁘게 나온다요

```javascript
app.locals.pretty = true;
```
---
