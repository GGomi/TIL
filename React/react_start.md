# React.js 소개
- react.js 는 라이브러리이다. (프레임워크란 모든것이 짜여져있고, 그 틀 안에서 가지고 놀아야함.)
- UI를 구성하기위한 라이브러리.
- 앵귤러를 대체가능한가? -> 비교불가능대상, 앵귤러는 프레임워크
- 배우기 간단하다.
- 장점 : 서버&클라이언트 렌더링
- 단점 : 뷰 Only , IE8 이하 지원 x

# JSX
- XML을 JavaScript로 변경해준다.
- 컴포넌트에서 여러 Element를 렌더링 할 때 꼭 container element 안에 포함시켜야함.
- if Else 문은 사용불가, 삼항연산자를 사용해야함.
- 데이터타입 let을 사용할 것(더알아봐야함.)
-

# props
- 컴포넌트 내부의 Immutable Data
- JSX 내부에 {this.props.propsName}
- 컴포넌트를 사용 할 때, < > 괄호안에 propsName = "value"
- this.props.children 은 기본적으로 갖고있는 props로서,
```
<Cpnt> Here </Cpnt>
```

# state
- 유동적인 데이터
- JSX내부에 {this.state.stateName}
- 초기값 설정이 필수, 생성자에서 this.state={}으로 설정
- 값을 수정할 때에는 this.setState({val: 'new_val'}), 렌더링 된 다음에는 this.state 사용금지

```
class Counter extends React.Component{
  constructor(props){
    super(props);
    this.state = {
      value: 0
    };
    this.handleClick = this.handleClick.bind(this);
  }

  handleClick(){
    this.setState({
      value: this.state.value + 1
    })
  }
  redner() {
    return (
      <div>
        <h2>{this.state.value}</h2>
        <button onClick={this.handleClick}>Press Me</button>
      </div>
    );
  }
}
class App extends React.Component {
  render() {
    return (
      <Counter/>
    );
  }
};

ReactDOM.render(
  <App></App>,
  document.getElementById("root")
);
```

```
class Counter extends React.Component {
  constructor(props) {
    super(props);
    this.state = { value: 0 }
    this.handleClick= this.handleClick.bind(this);
  }

  handleClick() {
    this.setState({value: this.state.value+1})
  }

  render() {
    return(
      <div>
        <h4>Value: {this.state.value}</h4>
        <button onClick={this.handleClick}>TICK</button>
      </div>
      );
  }  
}

class App extends React.Component {
  render() {
    return (
      <Counter/>
    );
  }
};

ReactDOM.render(
  <App></App>,
  document.getElementById("root")
);
```
