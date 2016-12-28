# [7kyu] Mumbling
-------------------------------------
> ## Example

>> Accumul.accum("abcd");    // "A-Bb-Ccc-Dddd"\
>> Accumul.accum("RqaEzty"); // "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"\
>> Accumul.accum("cwAt");    // "C-Ww-Aaa-Tttt"\
>> 위와 같은 결과를 나타내는 알고리즘 구현
------------------

> ## 내가 짠 코드
```
public static String accum(String s) {
    // your code     
    String temp;
    String res="";
    for (int i = 0; i < s.length(); i++) {
      temp = s.substring(i, i + 1);
      for (int j = 0; j <= i; j++) {
        if (j == 0) {
          res += temp.toUpperCase();
        } else {
          res += temp.toLowerCase();
        }
      }
      res += "-";
    }
    res=res.substring(0,res.length()-1);
    return res;
    }
}
```


> ## Solution
``` 
public static String accum(String s) {
      String[] a = s.toLowerCase().split("");
      String res = "";
      for (int i = 0; i < a.length; i++) {
         res += a[i].toUpperCase();
         for (int j = 1; j < i + 1; j++)
            res += a[i];
         res += "-";
      }
      return res.substring(0, res.length() - 1));
   }
```

> * String[] a = s.split("")으로 쪼개서 array에 담을 수 있다는 것을 알았다면 정답과 똑같이 코딩했을듭..
> * 전부 다 소문자로 바꾸어 준 다음 필요한 부분만 대문자로 바꾸어주는 방식으로 코딩됨.
