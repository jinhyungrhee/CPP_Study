# 연산자 오버로드

## 객체의 역할

- 사용자 정의 자료형의 객체는 함수 내에서 호스트 객체, 매개변수 객체, 리턴 객체로 사용될 수 있음
- 함수를 잘 설계하고 연사자 오버로드하는 방법을 이해하려면, 이러한 역할을 잘 파악해야 함

### 호스트 객체

- 클래스 멤버함수를 정의했다면, 인스턴스 앞에 점을 찍고 멤버함수를 호출
- 호스트 객체는 함수 호출의 주체라고 할 수 있음
- 인스턴스 멤버 함수를 만들 때는 함수 내부에서 fun1, fun2, fun3 등을 지정하지 않음
- 어떤 인스턴스를 호스트 객체로 사용할지는 계속해서 변하기 때문
- 인스턴스 멤버 함수 내부에서 호스트 객체(자기 자신)를 가리키려면 `this 포인터`를 사용해야 함
  - 멤버 함수 내부에서 `*this`는 곧 **호스트 객체**임
  ```c++
  // 프로그래머 작성
  void Fun::multipleByTwo()
  {
    cout << num * 2;
  }

  // 컴파일러 변환
  void Fun::multipleByTwo()
  {
    cout << (this->num) * 2;
  }
  ```
  - 호스트 객체는 this 포인터가 가리키는 객체임
  - \* 연산자 또는 -> 연산자를 사용해 호스트 객체 또는 호스트 객체의 멤버에 접근할 수 있음
- 객체 보호
  - 명시적으로 멤버함수가 호스트 객체를 변경하지 못하게 하려면, 멤버 함수 뒤에 const 한정자를 붙여서 해당 멤버 함수는 호스트 객체를 변경하지 못하는 함수라고 컴파일러에게 알려줘야 함
  - 함수 선언과 정의 모두에 const 한정자를 붙여야 함
  - 다만 const를 붙인다고 호출하는 형태가 바뀌는 것은 아님

### 매개변수 객체

- 매개변수 객체(parameter object)
  - 매개변수로 전달된 객체를 의미
  - 호스트 객체는 멤버 함수 내부에서 숨겨지지만(굳이 this 키워드 사용하지 않아도 됨), 매개변수 객체는 명시적으로 활용해야 함!

- 전달 방법(3가지)
  - 값으로 전달
    - 매개변수가 객체라면, 복사 생성자를 호출해서 객체의 복사본을 만들고, 이를 함수로 전달하므로 **복사 비용이 큼**
    - 따라서 일반적으로 매개변수가 객체일 때는 사용하지 않음!
  - 참조로 전달
    - 사용자 정의 객체를 함수로 전달할 때 사용하는 **가장 일반적인 방법**
    - 값을 복사하지 않고, 단순하게 객체에 별칭을 붙여서 함수 내부에서 사용할 수 있게 하는 것
    - 복사 비용이 없음!
  - 포인터로 전달
    - 객체를 힙에 만들어서 객체를 가리키는 포인터가 있을 때 사용하며, 이외의 일반적인 경우에는 거의 사용하지 않음

- 객체 보호
  - 일반적으로 '참조로 전달'을 사용해서 사용자 정의 자료형의 객체를 함수로 전달할 경우, 원본 객체를 변경할 수 있음
  - '참조로 전달'에서 원본 객체를 변경하지 못하게 할 때는, 매개변수 앞에 const 한정자를 붙임
    - 컴파일러가 원본 객체를 변경할 수 없게 됨!
    ```c++
    // 원본 객체 변경될 수 있음
    void one(Type& para);

    void Fun::one(Type& para)
    {
      ...;
    }

    fun1.one(para);

    // 원본 객체 변경될 수 없음
    void two(const Type& para);

    void Fun::two(const Type& para)
    {
      ...;
    }
    fun1.two(para);
    ```

### 리턴 객체

- 생성자와 소멸자는 객체를 리턴하지 않고, 객체를 생성하거나 소멸시키는 역할
- 이외의 멤버 함수는 객체를 리턴할 수 있음
- 리턴 방법
  - 값으로 리턴
    - 복사 생성자를 호출해서 객체의 복사본을 만들고, 이를 리턴
    - 복사 비용이 큼
    - 다만 **리턴하는 객체를 함수 내부에서 만드는 경우**, 참조로 리턴과 포인터로 리턴을 사용할 수 없으므로 **값으로 리턴**만 사용 가능
      - 함수가 종료될 때 본문 내에서 생성된 객체도 같이 소멸되기 때문에 참조로 리턴X, 포인터로 리턴X
  - 참조로 리턴
    - 복사 비용이 없지만, 함수 본문 내부에서 객체를 생성하는 경우에는 사용할 수 없음
      - 함수가 종료될 때, 본문 내부에서 생성된 객체가 소멸되기 때문
    - 하지만 매개변수로 전달받은 객체(또는 포인터)와 호스트 객체(또는 포인터)를 리턴해야 하는 경우에는 활용할 수 있음
  - 포인터로 리턴
    - 객체를 힙에 만들어서 객체를 가리키는 포인터가 있을 때 사용
      - 이외의 경우에는 거의 사용하지 않음
    - 장전과 단점은 '참조로 리턴'과 동일
- 객체 보호
  - `리턴된 객체를 보호해야 하는 경우(rvalue로만 사용하는 경우)`에는 const 한정자를 붙여서 객체를 변경하지 않게 보호
  - `리턴된 객체를 보호할 필요가 없는 경우(rvalue와 lvalue로 모두 사용하는 경우)`에는 const 한정자를 붙이지 않아서 객체를 변경할 수 있게 함
  - 두 가지 상황이 모두 필요한 경우에는 const 한정자를 붙인 함수와 붙이지 않은 함수를 모두 만들어서 활용함
    ```c++
    //리턴 객체 변경 가능
    Fun one(int value);

    Fun Fun::one(int value)
    {
      ...;
    }
    fun1.one(value) = ...;

    //리턴 객체 변경 불가
    const Fun two(int value);

    const Fun Fun::two(int value)
    {
      ...;
    }
    fun1.two(value);
    ```

## 연산자 오버로드

- 어떤 연산자를 사용해서 어떤 처리를 할 수 있게 해주는 문법
  - 예시1) 덧셈(+) 연산자
    - 'x + y'의 형태로 사용할 수 있는 '덧셈 연산자'는 int, long, long long, double, long double 등의 자료형에 사용 가능
      ```
      14 + 20
      14.21 + 20.45
      ```
    - 정수의 덧셈과 부동 소수점의 덧셈은 내부적으로 일어나는 처리가 다르지만 같은 연산자를 활용하고 있음(= 연산자 오버로드)
  - 예시2) << 연산자
    - 정수 자료형에 사용하면 정수의 비트를 왼쪽으로 이동
    - cout 객체에 사용하면 기본 자료형을 출력
      ```
      x << 5;     // 비트 이동
      cout << 5;  // 출력
      ```
- 연산자 오버로드를 통해 사용자 정의 자료형도 연산자 활용 가능
  - 예시) Fraction 클래스
    ```
    // 함수 사용
    add(fr1, fr2)
    // 연산자 사용 - *연산자 오버로드 필요*
    fr1 + fr2
    ```
  - 연산자의 범주
    |연산자|피연산자의 위치|이름|오버로드 가능 여부|
    |--|--|--|--|
    |::|primary|클래스 스코프|불가능|
    |[]|postfix|array subscript|가능|
    |()|postfix|function call|가능|
    |.|postfix|member function|불가능|
    |->|postfix|member function|가능|
    |++|postfix|postfix increment|가능|
    |--|postfix|postfix decrement|가능|
    |++|prefix|prefix increment|가능|
    |--|prefix|prefix decrement|가능|
    |~|unary|bitwise not|가능|
    |!|unary|logical not|가능|
    |+|unary|plus|가능|
    |-|unary|minus|가능|
    |*|unary|dereference|가능|
    
    - 오버로드할 수 없는 연산자
    - 오버로드하지 않는 것이 좋은 연산자
      - 6개 존재
      - 연산자의 의미, 평가 순서, 단락 평가(short-circuit)를 사용자가 제대로 구현할 보장이 없으므로 추천되지 않음
    - 오버로드할 수 있는 연산자

- 연산자 오버로드 규칙
  - 사용자 정의 자료형에 연산자 오버로드를 할 때는 오버로드와 관련된 규칙과 제한 사항을 잘 알고 있어야 함
    - `우선순위` : 변경 불가
    - `결합방향` : 변경 불가
    - `교환법칙` : 변경 불가
    - `에러티(피연산자 개수)` : 변경 불가
    - `다른 연산자 사용 불가능` : 오버로드 가능한 연산자만 오버로드 가능, 사용자가 연산자 추가할 수 없음
    - `연산자 결합` : 새로운 연산자를 만들겠다고 2개의 연산자를 결합하는 것도 불가능

### 연산자 함수

- 사용자 정의 자료형에 연산자 오버로드를 하려면 `연산자 함수(operator function)`를 만들어야 함
- 형태
  - 함수의 이름이 '`operator` 키워드 뒤에 연산자를 붙인 형태'를 갖는 함수
    ```c++
    리턴_자료형 operator기호(매개변수 목록)

    const Fraction operator+() const; 
    ```
- 연산자 함수는 `멤버 함수`로 정의할 수도 있고, 멤버 함수가 아닌 일반 함수(`비멤버 함수`)로도 정의할 수 있음
- 일부 연산자는 멤버 함수로만 오버로드해야 함
- 멤버 함수로 정의할 때와 비멤버 함수로 정의할 때의 문법 구문이 다르므로, 각각을 나누어서 살펴봐야 함
  - 비멤버 함수로 연산자 오버로드
    - 연산자 오버로드를 하면 연산자 또는 함수 이름으로 호출할 수 있음
    - 예시) Fraction 클래스에 단항 음수 연산자(-) 오버로드
      ```c++
      // 연산자로 바로 사용 (훨씬 간단)
      -fr
      // 연산자 함수로 사용
      fr.operator-()
      ```
      - 연산자 오버로드의 목적 : 사용자 정의 객체를 기본 자료형처럼 모방해서 사용!
  - 멤버 함수로 오버로드
    - 삽입 연산자(<<)와 추출 연산자(>>)를 제외하면 모든 오버로드 가능한 연산자는 멤버 함수로 오버로드 가능!
    - 어떤 연산자는 멤버 함수로 오버로드 하는 것이 적합하고, 어떤 연산자는 비멤버 함수로 오버로드 하는 것이 적합함

### 단항 연산자

- 단항 연산자는 호스트 객체가 곧 피연산자
- 매개변수 객체가 추가로 필요하지 않음
- 호스트 객체와 리턴 객체만 신경쓰면 됨
  - `확인1` : 호스트 객체를 변경해도 되는지/안되는지
  - `확인2` : 리턴 객체는 연산 결과를 의미. 참조로 리턴할 수 있는가? const 한정자를 붙여야 하는가?
  - 프로토타입
    ```c++
    const 자료형& operator 연산자() const
    ```

- 양수와 음수 연산자
  - `확인1` : 호스트 객체는 변경되지 않음(const 한정자 붙임)
  - `확인2` : 리턴객체
    - a. 새로운 객체로 생성(참조로 리턴 아님)
    - b. rvalue로만 사용(const 한정자 붙임)
  - 프로토타입
    ```c++
    const 자료형 operator +() const
    const 자료형 operator -() const
    ```
  - 코드
    ```c++
    // + 연산자
    const Fraction operator+() const;

    const Fraction Fraction::operator+() const
    {
      Fraction temp(+numer, denum); // 새로운 객체 생성
      return temp;                  // 새로운 객체를 리턴 -> 본인은 변화가 없음!
    }

    // - 연산자
    const Fraction operator-() const;

    const Fraction Fraction::operator-() const
    {
      Fraction temp(-numer, denum); // 새로운 객체 생성
      return temp;                  // 새로운 객체를 리턴 -> 본인은 변화가 없음!
    }
    ```

### 전위 증가와 전위 감소 연산자

- 전위 증가/감소 연산자는 피연산자를 변경하는 부가 작용(side effect)이 있음
- 리턴 객체는 호스트 객체 자체
- 전위연산자는 `++++x`와 `----x`처럼 사용할 수도 있음
  - 이는 결과를 lvalue로도 사용할 수 있기 때문! 
- `확인1` : 호스트 객체를 변경해야 함(const 한정자 X)
- `확인2` : 리턴 객체
  - a. 부가 작용이 일어난 호스트 객체를 리턴(참조로 리턴)
  - b. lvalue로도 사용해야 함(const 한정자 X)
- 프로토타입
  ```c++
  자료형& operator++()
  자료형& operator--()
  ```
- 코드
  ```c++
  // pre-increment operator
  Fraction& operator++();

  Fraction& Fraction::operator++()
  {
    numer = numer + denom;
    this->normalize();
    return *this;
  }

  // pre-decrement operator
  Fraction& operator--();

  Fraction& Fraction::operator--()
  {
    numer = numer - denom;
    this->normalize();
    return *this;
  }
  ```

### 후위 증가와 후위 감소 연산자

- 리턴 객체는 부가 작용이 일어나기 전에 만들어짐
- `확인1` : 호스트 객체는 부가 작용을 가짐(const 한정자 X)
- `확인`2 : 리턴 객체
  - a. 임시 객체로서 생성해야 함(참조 X)
  - b. rvalue로만 사용됨(const 객체)
- 프로토타입
  ```c++
  const 자료형 operator++(int)
  const 자료형 operator--(int)
  ```
- 후위 증가/감소 연산자는 변경 전에 값을 리턴함
  - 임시적으로 temp라는 객체에 값을 복사하고, 호스트 객체를 변경한 뒤 temp 객체를 리턴함
  - **int 매개변수**는 전위 연산자와 후위 연산자를 구분하기 위한 용도로 사용될 뿐, 내부적으로는 사용되지 않음!
- 코드
  ```c++
  // post-increment operator
  const Fraction& operator++(int); // 참조?

  const Fraction Fraction::operator++(int dummy)
  {
    Fraction temp(numer, denom);
    ++(*this);
    return temp;
  }

  // post-decrement operator
  const Fraction& operator--(int); // 참조?

  const Fraction Fraction::operator--(int dummy)
  {
    Fraction temp(numer, denom);
    --(*this);
    return temp;
  }
  ```

### 이항 연산자

- 피연산자를 2개 가짐
- 오버로드할 때, 피연산자 하나를 호스트 객체로, 다른 피연산자를 매개변수 객체로 사용
- 일반적으로 왼쪽 피연산자를 호스트 객체로, 오른쪽 피연산자를 매개변수 객체로 사용
- 일반적으로 왼쪽 피연산자의 역할과 오른쪽 피연산자의 역할이 다른 연산자만 멤버 함수로 오버로드할 수 있음
  - 역할이 달라야 하나를 호스트 객체로, 다른 하나를 매개변수 객체로 사용할 수 있음
  - 예시) 할당 연산자가 포함된 연산자(+=, -=, *=, /=, %=)는 왼쪽 피연산자와 오른쪽 피연산자의 역할이 다름 

- `확인1` : 오른쪽 피연산자는 매개변수 객체. 참조로 전달해야 하는지? const 한정자를 붙여야 하는지?
- `확인2` : 왼쪽 피연산자는 호스트 객체. const 한정자를 붙여야 하는지?
- `확인3` : 리턴 객체는 연산 결과. 참조로 전달해야 하는지? const 한정자를 붙여야 하는지?
- 프로토타입
  ```c++
  const 자료형& operator 연산자(const 자료형&) const
  -------------               -------------- ------
  리턴 객체 확인               오른쪽 피연산자  왼쪽 피연산자
                                        확인  변경 여부 확인
  ```

### 할당 연산자

- 이항 연산자로 일단 할당 연산자를 오버로드해봄. 할당 연산자는 왼쪽 피연산자와 오른쪽 피연산자의 역할이 다름.
  - 왼쪽 피연산자는 lvalue로 사용되며, 부가 작용이 일어남
  - 오른쪽 피연산자는 rvalue로 사용되며, 부가 작용이 일어나지 않음
- 할당 연산자는 왼쪽 객체를 변경해서, 오른쪽 객체의 복사본이 되게 만드는 연산자
- 이러한 연산자는 반드시 왼쪽 피연산자와 오른쪽 피연산자가 이미 존재하는 객체여야 함
  - 바로 복사본을 만들어서 전달해야 하기 때문
- 따라서 할당 연산자는 기존의 객체에서 새로운 복사본을 만들어내는 복사 생성자와는 약간 다름
  - 이미 객체화가 되어 있는 것의 복사본을 만들어서 바로 넘겨줌
- 호스트에는 부가 작용이 일어나야 하므로 const 한정자를 붙일 수 없음
- 리턴 객체는 `x = y = z`처럼 연결해서 사용할 수 있는 것이 일반적이므로 const 한정자를 붙이지 않음
- `확인1` : 호스트 객체는 부가 작용을 가짐(const 한정자를 붙이면 안 됨)
- `확인2` : 리턴 객체
  - a. 오른쪽 객체를 복사해서 호스트 자체를 리턴(참조)
  - b. 연산자를 연결해서 사용(const 한정자 붙이면 안 됨)
- 프로토타입
  ```c++
  자료형& operator=(const 자료형&)
  ```
- 만약 클래스에 할당 연산자를 정의하지 않으면, 시스템이 '합성 할당 연산자'라는 기본 할당 연산자를 제공함
  - 일반적으로 합성 할당 연산자는 거의 사용하지 않음
- 할당 연산자 구현시 주의점
  - 호스트 객체(왼쪽)와 매개변수 객체가 같은 객체는 아닌지 구분해야 함(= 주소가 같지 않아야 함)
    - 같은 주소면(=같은 객체면) 하나가 사라짐!
  - 할당 연산자의 결합방향은 오른쪽에서 왼쪽
    - z = y = x는 z = (y = x) 순서로 연산!
- 코드
  ```c++
  // assignmnet operator
  Fraction& operator=(const Fraction& right)

  Fraction& Fraction::operator=(const Fraction& right) // 참조로 들어오고 참조로 나감
  {
    if (*this != right) // this 포인터가 가리키는 내용(= 주소)과 같지 않으면 처리
    {
      numer = right.numer;
      denom = right.denom;
    }
    // 같으면 처리하지 않음

    return *this; // 리턴되는 내용은 곧 주소 정보(참조에 대한 주소 정보)
  }
  ```

### 복합 할당 연산자

```
fract1 += fract2    →   fract1 = fract1 + fract2
fract1 -= fract2    →   fract1 = fract1 - fract2
fract1 *= fract2    →   fract1 = fract1 * fract2
fract1 /= fract2    →   fract1 = fract1 / fract2
fract1 %= fract2    →   fract1 = fract1 % fract2
```
- fract1이 호스트 객체, fract2가 매개변수 객체임
- 리턴 객체는 변경된 호스트 객체
- 코드
  ```c++
  // += operator
  Fraction& operator+=(const Fraction& right)

  Fraction& Fraction:: operator+=(const Fraction& right)
  {
    numer = numer * right.denom + denom * right.numer;
    denom = denom * right.denom;
    normalize();
    return *this;
  }

  // -= operator
  Fraction& operator-=(const Fraction& right)

  Fraction& Fraction:: operator-=(const Fraction& right)
  {
    numer = numer * right.denom - denom * right.numer;
    denom = denom * right.denom;
    normalize();
    return *this;
  }

  // *= operator
  Fraction& operator*=(const Fraction& right)

  Fraction& Fraction:: operator*=(const Fraction& right)
  {
    numer = numer * right.numer;
    denom = denom * right.denom;
    normalize();
    return *this;
  }

  // /= operator
  Fraction& operator/=(const Fraction& right)

  Fraction& Fraction:: operator/=(const Fraction& right)
  {
    numer = numer * right.denom;
    denom = denom * right.numer;
    normalize();
    return *this;
  }
  ```

### 간접 연산자와 멤버 선택 연산자

- 간접 연산자(*)와 멤버 선택 연산자(->)를 활용해서 스택 또는 힙 메모리에 저장된 객체와 객체의 멤버에 접근
- 간접 연산자와 멤버 선택 연산자를 오버로드할 때 주의할 점
- 간접 연산자와 멤버 선택 연산자는 피연산자가 하나인 단항 연산자
- 간접 연산자는 피연산자 포인터가 가리키는 객체를 리턴
  - 연산자가 접두사로 오는 연산자 : `*ptr`
- 멤버 선택 연산자는 피연산자를 포인터로 하고 해당 객체의 멤버를 가리킬 수 있는 포인터로 변환해서 멤버를 리턴
  - 연산자가 접미사로 오는 연산자 : `ptr->`
- 두 연산자의 피연산자는 포인터
- 호스트 객체가 포인터여야 하므로, 포인터 역할을 할 수 있는 클래스 추가 필요!
- **스마트 포인터**
  - '스택'에서 객체에 대한 포인터를 사용하는 경우, 간접 연산자와 멤버 선택 연산자를 오버로드 하지 않아도 괜찮음
    - 포인터를 복합 자료형으로 활용해서 객체를 가리킬 수 있기 때문
    - 객체가 스택에 생성되면, 객체가 스코프를 벗어날 때 소멸되어 스택에서 해제되므로 메모리 누수가 발생하지 않음
  - '힙'에 객체를 생성하는 경우, 메모리 누수를 방지하도록 객체를 제거해야 함
    - 이를 위해 '스마트 포인터' 필요!
  - 스마트 포인터는 원하는 자료형(=사용자 정의 자료형)을 가리킬 수 있는 포인터를 데이터 멤버로 갖는 객체
    - 이 객체의 생성자는 매개변수로 해당 객체에 대한 포인터를 받음!
  - 스마트 포인터를 사용하지 않는 경우
    ```c++
    Fraction* ptr = new Fraction(2, 5);
    *(ptr).print();
    ptr->print();
    ```
    - 이렇게 만든 Fraction 객체는 힙 메모리에서 자동으로 소멸하지 않으므로, 메모리 누수를 피하려면 별도로 소멸작업을 해줘야 함!
    - 이와 달리 스마트 포인터는 자동으로 소멸!(= 소멸자에서 내부적으로 처리)

### 첨자 연산자

- 첨자 연산자(`[]`)는 연산자의 의미를 변경하지 않는 것이 좋음
- 왼쪽 피연산자가 배열의 이름이고, 오른쪽 피연산자는 배열 내부에 있는 요소의 인덱스를 나타내는 정수
- 클래스가 배열처럼 동작하는 경우(=문자열 또는 리스트)에만 첨자 연산자를 오버로드
  - 첨자 연산자가 제대로 동작하려면, '접근자 함수'와 '설정자 함수'를 모두 오버로드!
- 프로토타입
  ```c++
  // 접근자로 사용되는 경우 (부가 작용 없음)
  자료형& operator[](int index) const

  // 설정자로 사용되는 경우 (부가 작용 있음)
  자료형& operator[](int index)
  ```

### 함수 호출 연산자

- 함수 호출 연산자(`()`)를 오버로드하면, 함수처럼 호출할 수 있는 객체를 만들 수 있음
  `name(list of arguments)`
- 함수처럼 호출할 수 있는 객체를 '함수 객체(functor)'라고 함
- **함수와 함수 객체의 차이**
  - 함수 객체 : 상태를 계속해서 유지할 수 있음
  - 함수 : 호출되면 상태가 사라짐
  - 예시) smallest 객체
    - 이 객체는 `smallest(정수형 자료)` 형태로 함수처럼 호출할 수 있는 함수 객체임
      - 호출할 때마다 지금까지 호출에 사용했던 값 중에서 최소값을 리턴하려면 어떻게 구현해야 할까?

## 비멤버 함수 오버로드

- 이항 연산자(=피연산자가 두 개인 연산자)를 멤버함수로 오버로드한다면, 피연산자 중 하나가 반드시 호스트 객체여야 함
- 따라서 피연산자들이 다른 역할을 갖고 있을 때는 쉽게 읽고 이해할 수 있음
- 하지만 `a + b` 또는 `a < b`와 같이 **두 피연산자가 동일한 역할**을 하고, **결과에 영향을 주지 않는다**면 `일반 함수로 오버로드`하는 것이 좋음
  - 이러한 오버로드는 `전역 함수` 또는 `friend 함수`로 구현 가능!
  - 이항 연산자를 전역함수로 구현하는 경우도 많지만(=>캡슐화 훼손), 클래스의 접근자 함수와 설정자 함수를 활용해서 데이터 멤버에 접근해야 하므로 코드가 복잡해짐!
- **friend 함수(friend function)**
  - 호스트 객체를 기반으로 호출하는 멤버 함수는 아니지만, 클래스의 private 멤버에 접근할 수 있는 특별한 함수 문법
  - friend 함수를 사용하여 연산자 오버로드
  - friend 클래스
    - friend로 선언된 다른 클래스의 private 및 protected 멤버에 접근할 수 있도록 함
    - 특정 상황에서 클래스 내에 접근하지 못하도록 private 제한을 두었는데, 필요의 경우 해당 클래스나 함수에서 접근 가능하도록 사용하는 것이 friend 클래스 및 함수

### 이항 수학 연산자

- 피연산자는 모두 존재하는 객체여야 함
- 함수 내부에서 새로운 객체를 만들어서 리턴
- 매개변수는 참조로 전달할 수 있지만, 리턴 객체는 함수 내부에서 만들어져야 하므로 레퍼런스 자료형이 될 수 없음
- 프로토타입
  ```c++
  friend const 자료형 operator 연산자(const 자료형& left, const 자료형& right)
  ```
  - 두 개의 피연산자는 동일한 역할을 수행하기 때문에 호스트 객체로 처리하기 어려움 → 비멤버 함수로 구현
    - 호스트 객체가 없기 때문에 멤버 함수로 처리하지 않음!
  - friend 키워드는 선언 시에만 작성해도 됨!
- 코드
  ```c++
  // 더하기 연산 
  // 선언
  friend const Fraction operator+(const Fraction& left, const Fraction& right);
  // 정의
  const Fraction operator+(const Fraction& left, const Fraction& right)
  {
    int newNumer = left.numer * right.denom + right.numer * left.denom;
    int newDenom = left.denom * right.denom;
    Fraction result(newNumer, newDenom);
    return result;
  }
  ```

### 일치 연산자와 관계 연산자

- friend 함수를 사용해서 일치 연산자(==, !=)와 관계 연산자(<, <=, >, >=)를 오버로드함
- 피연산자는 모두 존재하는 객체여야 함
- 리턴 값은 불 자료형임
- 프로토타입
  ```c++
  friend bool operator 연산자(const 자료형& left, const 자료형& right)
  ```
- 코드
  ```c++
  // 일치 연산자
  // 선언
  friend bool operator==(const Fraction& left, const Fraction& right);
  // 정의
  bool operator==(const Fraction& left, const Fraction& right)
  {
    return (left.numer * right.denom == right.numer * left.denom);
  }
  ```

### 추출 연산자와 삽입 연산자

- 기본 자료형은 추출 연산자(>>)로 입력 스트림의 값을 읽어 들일 수 있고, 삽입 연산자(<<)로 출력 스트림에 값을 넣을 수 있음
- 프로토타입
  ```c++
  friend istream& operator>>(istream& left, 자료형& right)
  friend ostream& operator<<(ostream& left, const 자료형& right)
  ```
  - 연산자는 오른쪽 피연산자를 변경하므로, 오른쪽 피연산자에 const 한정자를 붙이면 안 됨
  - 호스트 객체가 없기 때문에 friend 함수를 통해 비멤버 함수로 구현
  - 추출 연산자와 삽입 연산자 모두 오른쪽 피연산자는 사용자 정의 객체
  - 다만 왼쪽 피연산자는 추출 연산자의 경우 istream 객체이고, 삽입 연산자의 경우 ostream 객체임
- 코드
  ```c++
  // 추출 연산자
  friend istream& operator>>(istream& left, Fraction& right);

  istream& operator>>(istream& left, Fraction& right)
  {
    cout << "Enter the value of numerator: ";
    left >> right.numer;
    istream << "Enter the value of denominator: ";
    left >> rigth.denom;
    right.normalized();
    return left;
  }

  // 삽입 연산자
  friend ostream& operator<<(ostream& left, const Fraction& right);

  ostream& operator<<(ostream& left, const Fraction& right)
  {
    left << right.numer << "/" << right.denom << endl;
    return left;
  }
  ```

# 자료형 변환

- 기본 자료형에 연산자를 적용할 때 자료형이 섞여 있으면, 변환 규칙에 따라서 변환이 일어남
- 예시) : 반지름이 5인 원 둘레를 찾는 표현식
  ```c++
  double perimeter = 2 * 5 * 3.1415;
  ```
  - 정수 5가 부동 소수점 5.0으로, 정수 2가 부동 소수점 2.0으로 변환된 뒤에 둘레를 구함
- 일부 제한 사항은 있지만 연산자 사용 때 기본 자료형을 사용자 정의 자료형으로 변환하거나, 사용자 정의 자료형을 기본 자료형으로 변환하게 만들 수 있음

## 기본 자료형을 클래스 자료형으로 변환

- 변환 생성자(conversion constructor)라는 매개변수가 있는 생성자를 만들어야 함
- 예시) 정수와 부동 소수점을 Fraction 클래스로 변환하는 경우
  - 정수를 Fraction 클래스로 변환
    - 분모를 1로 두고, 정수가 분자로 들어가는 생성자를 생성
      ```c++
      // 선언
      Fraction(int n);
      // 정의
      Fraction::Fraction(int n)
      : number(n), denom(1)
      {
      }
      ```
  - 부동 소수점을 Fraction 클래스로 변환
    - 1.75는 분수 7/4와 동일. 1.75가 주어지면 175/100으로 변환한 뒤 약분하면 7/4를 구할 수 있음
      ```c++
      // 선언
      Fraction(double value);
      // 정의
      Fraction::Fraction(double value)
      {
        denom = 1;
        while((value - static_cast<int> (value)) > 0.0)
        {
          value *= 10.0;
          denom *= 10;
        }
        numer = static_cast<int> (value);
        normalize();
      }
      ```

## 클래스 자료형을 기본 자료형으로 변환

- operator double처럼 operator 키워드 뒤에 자료형을 붙이는 형태로 기본 자료형으로 변환하는 멤버 함수를 구현할 수 있음
- 예시 : 분수(Fraction) 타입을 부동 소수점으로 변환
  ```c++
  // 선언
  operator double();
  // 정의
  Fraction::operator double()
  {
    double num = static_cast<double> (numer);
    return (num / denom);
  }
  ```
  - 리턴 자료형이 없는 형태라서 이상해보일 수 있음
    - 이는 double 자료형을 리턴하는 특수한 문법의 생성자로 이해
  - 함수 본문에서는 호스트 객체 Fraction을 기반으로 double로 자료형을 구현하고 리턴