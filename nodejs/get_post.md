# GET & POST
---
## GET
> form태그에서 method방식을 정의하지않으면 기본적으로 GET방식을 사용하게된다.

## POST
> URL에 데이터가 포함되어있지않다. 눈에 보이지않음.

---
```Javascript
//app.js
app.get('/form',function (req, res) {
  res.render('form');
});
app.get('/form_receiver',function (req, res) {
  var title = req.query.title;
  var description = req.query.description;
  res.send(title + ',' + description);
});
app.post('/form_receiver',function (req, res) {
  var title = req.body.title;
  var description = req.body.description;
  res.send(title + ',' + description);
});
```

---

```
//form.jade
doctype html
html
  head
    meta(charset='utf-8')
  body
    form(action='form_receiver' method='get')
      p
        input(type='text' name='title')
      p
        textarea(name='description')
      p
        input(type='submit')
```
---
> * GET방식으로 submit하게되면 URL에 자동으로 Querystring이 붙게된다.

> * POST방식은 method방식을 post로 바꾸어주고, js에서도 post방식으로 요청하면 된다. 하지만 req.body.?를 사용하려면 middleware가 필요함.(일종의 확장기능)(ex. body-parser)

> * 그래서 언제 POST를 쓰고, GET을 쓰냐?
정보를 넘길때 숨겨서 전송해야한다싶으면 POST
데이터가 너무 크면 POST, 왜냐하면 GET으로는 URL길이 한계가 있으므로
