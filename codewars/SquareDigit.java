public class SquareDigit{
  public int squareDigit(int n){
    String res="";

    while(n!=0){
      int digit = n %10; //10으로 나누어서 
      res = digit*digit + res;
      n /= 10;
    }
    return Integer.parseInt(res);
  }
}
