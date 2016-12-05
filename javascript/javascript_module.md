#[Javascript]
---------------------------------
> ##1.모듈이란?
> * 다양한 방법이 있지만 그 중의 하나는 코드를 여러개의 파일로 분리하는 것이다.
> * 코드를 개선하면 사용하고 있는 모든 애플리케이션의 동작이 개선된다.
> * 코드수정시에 필요한 로직을 빠르게 찾을 수 있다.
> * 한번 다운로드된 모듈은 웹브라우저에 저장되므로 네트워크 트래픽을 절약할 수 있다.
> * 순수한 자바스크립트에서는 모듈이라는 개념은 존재하지않음. 하지만 구동되는 호스트 환경에 따라서 서로 다른 모듈화 방법이 제공됨. 

> index.js
> 
> ```js
> function welcome() {
> 	return 'Hello World';
> 	}
> ```
> 
> main.html
> 
> ```html
> <html>
> <head>
> 		<meta charset = "utf-8" />
> 		<!--src로 js파일을 로드-->
> 		<script src = "index.js"></script>
> </head>
> 
> <body>
> 		<script>
> 			alert(welcome());
> 		</script>
> </body>
> </html>
> ```

---------------------------------------
> ##2.라이브러리 사용
> * 라이브러리는 자주 사용되는 로직을 재사용하기 편하도록 잘 정리한 일련의 코드 집합
> * 적재적소에 잘 사용하게되면 좋은 코드를 짤 수 있다.
> 
> jquery_apply.html
> 
> ```html
> <!--applied_jQuery-->
> <html>
> <head>
> 		<meta charset = "utf-8" />
> 		<script src = "https://code.jquery.com/jquery-3.1.1.min.js">
> </head>
> <body>
> 	<ul id = "list">
> 		<li>temp</li>
> 		<li>temp</li>
>		<li>temp</li>
>		<li>temp</li>
>	</ul>
>	<input id = "execute_btn" type = "button" value = "execute">
>	<script>
>		<!--단 세줄로 li태그의 모든 text 값을 수정함.-->
>		$('execute_btn').click(function(){
>			$('#list li').text('Hello World');
>		})
>	</script>
></body>
></html>
>```
