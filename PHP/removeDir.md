- PHP 게시판 구현중에 게시글 삭제부분에서 첨부파일이 있다면 생성되어있던 첨부파일 디렉토리도 일괄적으로 삭제하는기능이 필요했다.
- 하지만 기존 php함수들로는 선택한경로의 하위파일까지 삭제하고 선택한 폴더까지 지워주는 함수는 없어서 찾게되었다.

```
function rmdir_all($dir) {
  //선택한경로가 존재하지않으면 리턴
  if (!file_exists($dir)) {
    return;
  }
  //선택한 경로의 폴더를 열어 하위파일을 지워주는 구문
  $dhandle = opendir($dir);
  if ($dhandle) {
    while (false !== ($fname = readdir($dhandle))) {
       if (is_dir( "{$dir}/{$fname}" )) {
          if (($fname != '.') && ($fname != '..')) {
             $this->rmdir_all("$dir/$fname");
          }
       } else {
          unlink("{$dir}/{$fname}");
       }
    }
    closedir($dhandle);
  }
  //선택한경로의 폴더지워주는 구문
  rmdir($dir);
}
```
