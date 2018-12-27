# KWPATTERN

### 문제

서기 2222년, cdinside 알고스팟 갤러리에서 WonhaJin은 무패 전설의 키보드 워리어로 유명하다. WonhaJin은 항상 만년떡밥을 던짐으로써 낚여든 상대방을 무참히 공격하여 굴복시키곤 했다. 이러한 패턴으로 그는 한 번도 키보드 배틀에서 패배한 적이 없다.

한편, 그동안 그와 대등하게 승부했지만 한 번도 이겨 본 적이 없는 숙명의 라이벌 WookMan은 WonhaJin에게 패배를 안겨주고자 22개월간 WonhaJin의 키보드 배틀 패턴을 파악하고자 노력하였다.

그러던 도중 2222년 2월 22일 22시 22분 22초에 그가 뻘글을 쓰는 것을 확인하였다. 이는 키보드 워리어에게 있어 치명적인 약점이다. WookMan은 이로부터 그가 성시마다 약점을 보인다는 가설을 세웠다. 성시란 다음과 같다:

어떤 시각이 24시간제 기준으로 X 년 Y 월 Z 일 A시 B분 C 초이면, 이를 XY ZABC 의 형태로 이어 붙인 것과 그것을 뒤집은 문자열이 서로 같을 때 그 시각은 성시이다.
시각은 그레고리력(양력) 을 따라 4의 배수 해는 2월이 29일까지 있는 윤년이다. 단, 100의 배수 해는 윤년이 아니지만 400의 배수 해는 윤년이다.
X는 네 자리에 맞추어 표기하며, 나머지는 두 자리에 맞추어 표기한다. 모자라는 자리는 “0”으로 채운다.
예를 들어 2011년 9월 20일 23시 57분 11초의 경우, 20110920235711인데 이는 이를 뒤집은 11753202901102와 다르기 때문에 성시가 아니다. 한편 2011년 12월 11일 21시 11분 2초의 경우 20111211211102이므로 성시이다.

이러한 패턴을 이용하여 WonhaJin을 공격하고자 WookMan은 1970년 1월 1일 0시 0분 0초 (이는 프로그래머들에게 있어 현존하는 모든 역사가 시작된 시간이다) 부터 N 번째로 등장하는 성시를 찾는 프로그램을 작성하려고 하였는데, 최근 취업과 육아를 동시에 시작하여 너무 바쁜 나머지 추종자들에게 도움을 요청하였
다.

WookMan의 꼼꼼함에 반한 추종자인 당신은 이 프로그램을 작성해주어야 한다.

입력
> 입력은 여러 개의 테스트 케이스로 구성된다. 입력의 첫 행에는 테스트 케이스의 수 T 가 주어진다.

각 테스트 케이스는 하나의 행으로 이루어져 있는데, 그 행에는 양의 정수 N (1 ≤ N ≤ 10000)이 주어진다.

출력
> 각 테스트 케이스에 대해 N 번째 성시를 한 행에 하나씩 “XXXX-YY-ZZ AA:BB:CC” 의 형식으로 출력한다.

Input
```
4
7
2
20
99
```

Output
```
2000-11-11 11:00:02
2000-01-22 10:00:02
2001-12-22 21:10:02
2013-12-11 21:31:02
```

Solved
```java

import java.util.Scanner;

public class KWPATTERN {
    static int[] YEARS;
    static int START = 2000;
    static int START2 = 2000;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String year;
        String month;
        String day;
        initYears();
        int caseSize = sc.nextInt();

        String[] array = {"01","02","10","11","12"};
        for(int i = 0; i < caseSize; i++) {
            int select = sc.nextInt();
            int temp = select / 10;
            
            // 나누고, 뺐더니 오답, 빼고 나눠야 정답처리..
            int yearIndex = (select - 1) / 10;

            if(select > 10) {
                select = select - ( 10 * temp );

                if(select == 0) {
                    select = 10;
                }
            }

            if(select % 2 == 0) {
                day = "22";
                int target = select / 2;
                month = array[target-1];
            } else {
                day = "11";
                month = array[select/2];
            }
            year = String.valueOf(YEARS[yearIndex]);
            StringBuffer sMonth = new StringBuffer(month);
            StringBuffer sYear = new StringBuffer(year);
            sYear = sYear.reverse();

            System.out.println(year+"-"+month+ "-" + day + " " + sMonth.reverse().toString() + ":"+sYear.substring(0,2)+":"+sYear.substring(2,4));

        }
    }
    public static void initYears() {
        YEARS = new int[1000];
        YEARS[0]=START;
        for(int i=1;i<1000;i++) {
            String s = String.valueOf(YEARS[i-1]);
            if(Integer.parseInt(s.split("")[s.length()-1])>5) {
                YEARS[i-1] = START+10;
                START =YEARS[i-1];
            }
            String z= String.valueOf(START);
            if(Integer.parseInt(z.split("")[1])>5) {
                YEARS[i-1] = START2+1000;
                START2 =YEARS[i-1];
                START = START2;
            }
            YEARS[i]=YEARS[i-1]+1;
        }

    }
}
```