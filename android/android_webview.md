#WebView

##안드로이드 뒤로가기키 웹뷰에서 처리하는 부분
```
@Override
public boolean onKeyDown(int keyCode, KeyEvent event) {
  if ((keyCode == KeyEvent.KEYCODE_BACK) && mWebView.canGoBack()) {

    mWebView.goBack();

    return true;
    }
    return super.onKeyDown(keyCode, event);
  }
```

##SSL 보안인증 문제
*https를 Url에 사용하게되면 SSL 보안인증문제가 생긴다. 이 문제는 다음번에 더 자세히 알아 볼 예정

```
mWebView.loadUrl("http://dormsys.mokpo.ac.kr/system/user/login.php");
```
>이번 MNU_APP개발 중에 사용했던 구문인데  https 보안인증으로 인해 빌딩이 되지않았다.
>우선은 http로 수정하여 진행하였다.
