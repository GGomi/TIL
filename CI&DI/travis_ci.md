# CI

**CI (지속적 통합)**

- VCS시스템에 PUSH가 되면 자동으로 TEST, BUILD가 수행되고 결과를 운영서버에 배포까지 자동으로 진행되는 과정을 CI 라고한다.
- CI 툴을 도입했다고 해서 CI를 하고 있는 것은 아니다.

**CI 네가지 규칙 (마틴 파울러)**

1. 모든 소스코드가 살아있고(현재 실행되고) 어느 누구든 현재의 소스를 접근할 수 있는 단일 지점을 유지할 것
2. 빌드 프로세스를 자동화시켜서 어느누구든 소스로부터 시스템을 빌드하는 단일 명령어를 사용할 수 있게 할 것
3. 테스팅을 자동화시켜서 단일 명령어를 통해 언제든지 시스템에 대한 건전한 테스트 Suit를 실행할 수 있게 할 것
4. 누구나 현재 실행파일을 얻으면 지금까지 최고의 실행파일을 얻었다는 확신을 하게 만들 것

## 테스팅 자동화가 특히 중요하다.

지속적 통합을 하기위해서 프로젝트가 완전한 상태임을 보장해야하기 때문