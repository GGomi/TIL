# Component Mapping
- arr.map(callback, [thisArg])
- callback 새로운 배열의 요소를 생성하는 함수로서, 다음 세가지 인수를 가짐.
- currentValue 현재 처리되고 있는 요소
  - index 현재 처리되고있는 요소의 index 값
  - array 메소드가 불려진 배열
- thisArg(*선택항목임*) callback 함수 내부에서 사용 할 this 값을 설정

---

### ES6 문법(Arrow 문법)
```javascript
let one = a => console.log(a);
```
아래와 같은 코드이다.
```javascript
var one = function one(a) {
  return console.log(a);
};

```
### ES6 문법(Arrow 문법) #2
```javascript
var num = [1,2,3,4,5];
var processed = num.map(function(num){
  return num*num;
  });

결과는 [1,4,9,16,25]가 될 것이다.

```
```javascript
let num = [1,2,3,4,5];
let result = num.map((num) => {
  return num*num;
});

결과는 위와 같다.
```

### Mapping 예제
```javascript
class ContactInfo extends React.Component {
    render() {
        return (
            <div>{this.props.contact.name} {this.props.contact.phone}</div>
        )
    }
};

class Contact extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            contactData: [{
                name: 'Abet',
                phone: '010-0000-0001'
            }, {
                name: 'Betty',
                phone: '010-0000-0002'
            }, {
                name: 'Charlie',
                phone: '010-0000-0003'
            }, {
                name: 'David',
                phone: '010-0000-0004'
            }]
        };
    };

    render() {
        const mapToComponents = (data) => {
            return data.map((contact, i) => {
                return (<ContactInfo contact={contact} key={i}/>);
            });
        };

        return (
            <div>
                <h1>Contacts</h1>
                <div>{mapToComponents(this.state.contactData)}</div>       
                </div>
            );
        }
    };

class App extends React.Component {
    render() {
        return (
            <Contact/>
        );
    }
};

ReactDOM.render(
    <App></App>,
        document.getElementById("root")
    );
```
