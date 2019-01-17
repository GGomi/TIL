# RESTAPI

> [추천영상] 그런 RESTAPI로 괜찮은가? [Youtube](https://www.youtube.com/watch?v=RP_f5dMoHFc&t=1415s)

REST
- 분산 하이퍼미디어 시스템을 위한 아키텍쳐 스타일

아키텍쳐스타일? 
- 제약조건의 집합이다.

Uniform interface
- HTTP 메세지에 표현이 담아져야한다.

문제는 
- **self-descriptive message**
- **hypermedia as the engine of application state(HATEOAS)**

## Self-descriptive message
- **메시지는 스스로를 설명해야한다.**
- 서버가 변해서 메시지가 변해도 클라이언트는 그 메시지를 보고 해석이 가능하다.
- 확장가능한 커뮤니케이션
- API응답만으로 이 API가 무슨 API인지 알 수 있어야한다.

## Self-descriptive message 방법
- 미디어 타입을 정의하고 IANA에 등록하고 그미디어 타입을 리소스 리턴할 때 Content-Type을 사용
- profile 링크 헤더를 추가한다.

## HATEOAS
- 애플리케이션의 상태는 하이퍼링크를 통해 전달되어야한다.
- 링크정보를 동적으로 바꿀 수 있다.(**버져닝 할 필요없이**)

## HATEOAS 방법
- 데이터에 링크제공(HAL 스펙따라서)
- 링크헤더나 Location 사용

## Uniform interface는 왜필요한가?

**독립적 진화**
- 서버와 클라이언트가 독립적으로 진화한다.
- 서버의 기능이 변경되어도 클라이언트를 업데이트할 필요가 없다.

 
 Entity에 lombok @Data 어노테이션을 사용했을 때 무한상호참조 발생우려가 있기 때문에 사용하지말 것