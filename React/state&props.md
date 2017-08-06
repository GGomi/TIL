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
