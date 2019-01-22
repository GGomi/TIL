# 네이버 인기검색 주식 파싱

## 사용 라이브러리

- BeautifulSoup4

---

## 설명
[파싱 페이지 링크](https://finance.naver.com/sise/lastsearch2.nhn)
- 페이지에서 table 태그 부분 전체를 파싱해서 필요한 부분만 html 파일로 추출


```python
from bs4 import BeautifulSoup
import requests

# 웹페이지를 크롤링해오는 함수
# param web_url - 웹페이지 URL 
# return _html - 웹페이지 html 데이터
def get_html(web_url):
    resp = requests.get(web_url)
    if resp.status_code == 200:
        _html = resp.text
    return _html
####################################

web_url = "https://finance.naver.com/sise/lastsearch2.nhn"

html = get_html(web_url)
soup = BeautifulSoup(html, 'html.parser')
table = soup.find('table', {'class':'type_5'})
f = open("test.html","w", encoding="utf-8")
f.write("<table>")
for i in table:
    f.write(str(i))

f.write("</table>")

# Jquery로 상승주 줄은 빨간색으로, 하락주는 파란색으로 글씨색 바꿔줌
f.write("<script src=\"https://code.jquery.com/jquery-3.3.1.js\"></script>")
f.write("<script type=\"text/javascript\">$(\"[alt=\'상승\']\").closest('td').closest('td').closest('tr').css(\'color\',\'RED\');$(\"[alt=\'하락\']\").closest('td').closest('td').closest('tr').css(\'color\',\'BLUE\');</script>")
f.close()

```