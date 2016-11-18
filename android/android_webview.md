#WebView

##안드로이드 뒤로가기키 웹뷰에서 처리하는 부분

>    @Override
>    public boolean onKeyDown(int keyCode, KeyEvent event) {
>        if ((keyCode == KeyEvent.KEYCODE_BACK) && mWebView.canGoBack()) {
>            mWebView.goBack();
>            return true;
>        }
>        return super.onKeyDown(keyCode, event);
>    }
