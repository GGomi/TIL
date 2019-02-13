# DTO와 Model Mapper
## DTO
처음에 Spring + JPA 학습을 하면서 컨트롤러에서 JPA Entity를 바로 리턴해주는 방식으로 구현한 적이 있었습니다. 하지만 이 방법은 좋지않다는 것을 알고, DTO를 이용해서 리턴해주는 방식으로 바꾸게 되었습니다.

그럼 왜 컨트롤러에서 바로 `Entity`를 리턴하면 좋지않을까?

## 왜 Entity를 바로 리턴하면 안될까?
이건 DTO를 사용하는 이유와 상응한다고 생각합니다. 우선, DTO를 사용하는 이유는 아래와 같습니다.

- **1.데이터안전성**
    - 단순하게 `GET`을 하는 API에서는 상관없을 수도 있지만 데이터를 수정하는 API의 경우 `Entity`클래스로 `Request`를 받게되면 모든 속성을 `Controller`에서 받을 수 있게되고, 수정을 원치않는 데이터까지 수정이 될 수 있다. 그래서 DTO를 통해 확실하게 1차 마스킹을 하고, 수정이 필요한 속성만 접근할 수 있도록 한다.
    - `Entity`를 `Response`로 보내게되면 `Entity`클래스의 모든 정보가 노출될 위험이 있다. `@JsonIgnore`로 종종 임시방편으로 막는 경우가 있긴한데 이 방법 또한 좋은 방법이 아닙니다.
- **2.요구사항의 명확성**
    - 해당 API가 정확하게 어떤 값을 다루는지 확인할 수 있습니다.

## Model Mapper
Model Mapper는 Repository를 수정하지 않고, Service, Controller에서만 작업을 할 수 있게해준다.

하지만 Model Mapper는 Setter를 이용하기 때문에 Entity에 Setter가 존재해야 매핑이 가능하다.


