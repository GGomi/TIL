# 정렬 알고리즘 정리

# 개요
- 기본적인 정렬 알고리즘에 대한 정리입니다. 면접 준비를 하면서 하나하나 다시 되짚어보는 좋은 계기가 되었고, 새롭게 알게 된 부분도 있어서 따로 정리를 해보았습니다.

# 목차
- [정렬 알고리즘](#%EC%A0%95%EB%A0%AC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)
  - [Selection Sort](#selection-sort)
  - [Insertion Sort](#insertion-sort)
  - [Bubble Sort](#bubble-sort)
  - [Quick Sort](#quick-sort)
  - [Merge Sort](#merge-sort)
  - [Heap Sort](#heap-sort)

# 정렬 알고리즘
## Selection Sort
- 정렬을 시도할 배열에 루프를 돌면서 자신보다 작은 값 중에서 제일 작은 값과 스왑하면서 정렬을 한다.

```java
public static void sort(int[] arr) {
        int index;
        int temp;

        for(int i = 0; i < arr.length-1; i++) {
            index = i;

            for(int j = i+1; j < arr.length; j++) {
                if(arr[index] > arr[j]) {
                    index = j;
                }
            }

            if(i != index) {
                temp = arr[i];
                arr[i] = arr[index];
                arr[index] = temp;
            }
        }
    }
```

## Insertion Sort
- 두번째 요소부터 루프를 시작해서 자신의 이전 값들과의 비교를 통해서 자신의 위치를 찾아들어간다.
- 이미 정렬되어있는 경우(```O(n)```)를 제외하고 ```O(n^2)```이다.
```java
public void insertion_sort(int[] list, int n){
  int key;

  for(int i=1; i<n; i++){
    key = list[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

    for(int j=i-1; j>=0 && list[j]>key; j--){
      list[j+1] = list[j]; // 레코드의 오른쪽으로 이동
    }

    list[j+1] = key;
  }
}
```
## Bubble Sort
- 간단한 정렬 방법 중 하나이다. 두개씩 쌍으로 끝까지 루프
- 모든 경우에 대해서 ```O(n^2)```이다. (상당히 비효율적)

```java
public static int[] sort(int[] arr) {
    int temp;

    for(int i = 0; i < arr.length; i++) {
        for(int j = 0; j < arr.length-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    return arr;
}
```
## Quick Sort
- Quick Sort는 평균적으로 ```O(nlogn)``` 시간복잡도를 가진다. 최상의 경우일 때도 ```O(nlogn)```이다.
- 하지만, 최악의 경우(피벗을 잡고, 계속 어느한쪽으로 치우치게될 때) n^2의 시간복잡도를 가진다.
- 해당 배열 안에서 해결하므로 따로 추가 배열은 생성하지않는다.
```java
public static void sort(int[] data, int l, int r){
        int left = l;
        int right = r;
        int pivot = data[(l+r)/2];

        while(left <= right){
            while(data[left] < pivot) left++;
            while(data[right] > pivot) right--;
            if(left <= right) {
                int temp = data[left];
                data[left] = data[right];
                data[right] = temp;
                left++;
                right--;
            }
        }

        if(l < right) sort(data, l, right);
        if(r > left) sort(data, left, r);
    }
```
## Merge Sort
- 정렬 중에서 제일 효율적인 정렬로 최악의 경우 O(n^2)인 Quick Sort에 비해 Merge Sort는 항상 ```O(nlogn)```이다.
- ```분할, 정복, 합병``` 순으로 정렬을 진행한다.

```java
public static int[] sort;

public static int[] sort(int[] arr) {
    sort = new int[arr.length];
    mergeSort(0, arr.length-1,arr);
    return sort;
}

public static void mergeSort(int left, int right,int[] arr){
    int mid;
    if(left<right){
        mid = (left+right)/2;
        mergeSort(left, mid, arr);
        mergeSort(mid+1, right, arr);
        merge(left, mid, right, arr);
    }
}

public static void merge(int left, int mid, int right, int[] arr){
    int l = left;
    int m = mid+1;
    int k = left;

    while(l<=mid || m<=right){
        if(l<=mid && m<=right){
            if(arr[l]<=arr[m]){
                sort[k] = arr[l++];
            }else{
                sort[k] = arr[m++];
            }
        }else if(l<=mid && m>right){
            sort[k] = arr[l++];
        }else{
            sort[k] = arr[m++];
        }

        k++;
    }

    for(int i=left; i<right+1; i++){
        arr[i] = sort[i];
    }
}
```

## Heap Sort
- 모든 경우에 대해서 O(nlogn)의 성능을 보인다.
- 전체를 정렬할 때 사용하는 것보다 전체에서 가장 큰 값이 몇개 필요할 때 사용하면 좋다.