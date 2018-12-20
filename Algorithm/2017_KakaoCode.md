## 카카오코드 예선
--- 

1. 카카오 프렌즈 컬러링북

- 출판사의 편집자인 어피치는 네오에게 컬러링북에 들어갈 원화를 그려달라고 부탁하여 여러 장의 그림을 받았다. 여러 장의 그림을 난이도 순으로 컬러링북에 넣고 싶었던 어피치는 영역이 많으면 색칠하기가 까다로워 어려워진다는 사실을 발견하고 그림의 난이도를 영역의 수로 정의하였다. (영역이란 상하좌우로 연결된 같은 색상의 공간을 의미한다.)
- 그림에 몇 개의 영역이 있는지와 가장 큰 영역의 넓이는 얼마인지 계산하는 프로그램을 작성해보자.

---

```java
class Solution {
  int[][] pic;
  boolean[][] map;
  int count;
  public int[] solution(int m, int n, int[][] picture) {
      pic = picture;
      map = new boolean[m][n];
      int numberOfArea = 0;
      int maxSizeOfOneArea = 0;
      
      for(int i = 0; i < m; i++) {
          for(int j = 0; j < n; j++) {
              if(pic[i][j] != 0 && map[i][j] != true) {
                  numberOfArea += 1;
                  searching(i,j);
                  count = 0;
                  if(maxSizeOfOneArea < count) {
                      maxSizeOfOneArea = count;
                  }
              }
          }
      }
      int[] answer = new int[2];
      answer[0] = numberOfArea;
      answer[1] = maxSizeOfOneArea;
      return answer;
  }
    
  public void searching(int i, int j) {
      map[i][j] = true;
      
      if(i > 0 && map[i-1][j] == false && pic[i][j] == pic[i-1][j]) {
          searching(i-1, j);
      } 
      if(i+1 < map.length-1 && map[i+1][j] == false && pic[i][j] == pic[i+1][j]) {
          searching(i+1, j);
      } 
      if(j+1 < map[i].length-1&& map[i][j+1] == false && pic[i][j] == pic[i][j+1]) {
          searching(i, j+1);
      } 
      if(j > 0 && map[i][j-1] == false && pic[i][j] == pic[i][j-1]) {
          searching(i, j-1);
      }
      count += 1;
      
  }
}
```
- Flood Fill 알고리즘을 활용하여 구현함. 처음에 재귀함수에 if문을 else if로 처리했더니 통과를 못했었다. **if문 여러개와 if ~ else if...문은 다르다**