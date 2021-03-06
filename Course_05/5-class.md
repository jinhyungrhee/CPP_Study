# 클래스와 생성자

## 객체지향 패러다임
- C++는 절차 지향과 객체 지향 패러다임이 결합된 언어
- 타입과 인스턴스
  - 타입(type)을 이용햇 인스턴스(instance)를 생성할 수 있음
  - 타입은 추상화된 것이고 인스턴스는 타입을 실체화한 구체적인 실체
  - 타입과 인스턴스의 관계는 **일대다(one-to-many)**관계
  - 하나의 타입을 기반으로 많은 인스턴스 생성 가능
- 속성과 행위
  - 속성(attribute)
    - 인스턴스가 가지는 특징을 의미
    - 컴퓨터 과학에서 속성 : 우리가 관심있어 하는 특성
  - 행위(behavior)
    - 인스턴스는 어떤 행위를 가짐
    - 어떤 인스턴스가 스스로 할 수 있는 작업 또는 연산
- 클래스와 객체
  - C++은 클래스(class)라는 구문을 사용하여 타입(사용자 정의 자료형)을 생성
  - 클래스를 기반으로 만든 인스턴스를 객체(또는 인스턴스)라고 함
  - 객체 지향 프로그래밍에서 객체의 '속성'과 '행위'는 `데이터 멤버`와 `멤버 함수`로 생성
  - **데이터 멤버**
    - 속성을 표현하기 위한 변수를 의미
  - **멤버 함수**
    - 어떤 행위를 할 수 있는 기능들의 모임
    - 객체의 행위는 멤버 함수를 사용해서 구현
  - 실제 세계와 객체 지향 프로그래밍의 용어 비교
    ```
    <실제 세계>           <객체지향 프로그래밍>
      타입        <->        타입 또는 클래스
      인스턴스    <->        인스턴스 또는 객체
      속성        <->        데이터 멤버
      행위        <->        멤버 함수
    ```

## 클래스 

- 객체 지향과 클래스
  - 새로운 자료형(타입)을 만들 때 클래스(class) 사용
  - 객체 지향 프로그래밍을 할 때는 `클래스 정의`, `멤버 함수 정의`, `어플리케이션`(클래스를 기반으로 객체를 만들어서 사용하는 부분)이 필요
  - 객체지향 패러다임 C++ 프로그램의 세 부분
    - 클래스 정의 : 속성과 행위 선언
    - 멤버 함수 정의 : 행위 정의
    - 어플리케이션 : 객체를 인스턴스화하고 사용

- 클래스 정의
  - 새로운 타입을 만들려면 클래스 정의(class definition)를 작성
  - 클래스 정의는 `헤더`, `본문`, `세미콜론` 세 부분으로 구성
    - `클래스 헤더(class header)`는 class 키워드 뒤에 클래스의 이름을 붙여서 생성
    - `클래스 본문(class body)`는 데이터 멤버와 멤버 함수의 선언을 가진 블록(중괄호로 열고 닫히는 영역) 부분
    - `세미콜론`은 클래스 정의를 종료하겠다고 나타내는 부분
  - 데이터 멤버 선언
    - 클래스 정의의 첫 번째 부분
    - 내장 자료형으로 만들 수도 있고, 이전에 정의한 다른 클래스로도 만들 수 있음
    - 클래스의 속성은 데이터 멤버로 생성
  - 멤버 함수 선언
    - 클래스 정의의 두 번째 부분
    - 클래스의 행위를 구현하는데 사용할 함수를 생성
    - 함수 선언(프로토타입) 부분과 비슷
  - 접근 제한자
    - 접근 권한을 나타낼 때 사용
    - 클래스에서 데이터 멤버와 멤버 함수를 선언하면 기본적으로 private 접근 제한자가 붙음
    - private 접근 제한자가 붙으면 class 외부에서 해당 요소로부터 값을 추출할 수도 없고, 값을 변경할 수도 없음
    - 접근 제한자의 멤버 접근 범위
      |접근 제한자|같은 클래스에서의 접근|서브 클래스에서의 접근(상속)|모든 곳으로부터의 접근|
      |--|--|--|--|
      |private|가능|불가능|불가능|
      |protected|가능|가능|불가능|
      |public|가능|가능|가능|
    - 데이터 멤버와 접근 제한자
      - 데이터 멤버에는 일반적으로 **private** 적용
      - 기본적으로 private이 붙지만, 강조하기 위해서 private을 붙여서 사용!
      - private이 적용된 멤버는 멤버함수를 통해서만 접근 가능
    - 멤버 함수와 접근 제한자
      - 어플리케이션에서 멤버 함수를 사용할 수 있어야 하므로 일반적으로 **public** 적용
    - 그룹 접근 제한자
      - 각각 붙이는 대신 그룹 단위로 한꺼번에 한 번만 붙이는 것

- 멤버 함수 정의
  - 멤버 함수 선언은 단순하게 함수의 프로토타입을 적는 것
  - 따라서 별도의 함수 정의가 필요
  - 기본 함수 정의와의 **차이점**(2가지)
    - 멤버 함수에는 `한정자 const`가 있음
      - 안에서 값을 변경하지 못하도록 보호하는 장치
    - 멤버 함수에는 `앞에 클래스 이름`이 붙음
  - 멤버 함수 이름 앞에 클래스 이름과 `클래스 스코프 기호(::)`를 붙여야 함
    |그룹|이름|연산자|표현식|우선 순위|결합방향|
    |--|--|--|--|--|--|
    |기본|클래스 스코프|::|클래스::이름|19|→|

- 인라인 함수
  - 프로그램의 성능을 위해서 컴파일러가 함수 호출 부분을 실제 코드로 대체해버리게 만들고 싶을 때, 함수를 인라인 함수로 선언
  - **암묵적 인라인 함수**
    - 클래스 정의 내부에 함수를 정의하면, 해당 함수는 인라인 함수가 됨!
      ```c++
      class Circle
      {
        // Data Members
        private:
          double radius;
        // Member functions
        public:
          double getRadius()const {return radius}; // 인라인 함수
      }
      ```
      - 이는 바람직하지 않은 방법
        - 함수 정의 부분을 읽기 어려움!
        - 캡슐화 원칙을 위반!
  
  - **명시적 인라인 함수**
    - 함수 정의 앞에 inline 키워드를 추가하면 `명시적 인라인 함수`로 만들 수 있음
      ```c++
      inline double Circle::getRadius() const
      {
        return radius;
      }
      ```

### 어플리케이션

- 객체 인스턴스화
  - 멤버 함수를 사용하려면, 반드시 객체를 인스턴스화해야함!
    - `Circle circle1;`

- 객체에 연산 적용
  - 인스턴스화했다면 멤버 함수로 정의했던 연산을 사용할 수 있음!
    - `circle1.setRadius(10.0);`

- 멤버 선택
  - 멤버 선택 연산자(member selection operator) : `.`
    - 어떤 객체가 가지고 있는 어떤 함수를 실행시킬 때 사용

### 구조체

- 구조체의 모든 멤버는 기본적으로 **public**
- 클래스의 모든 멤버는 기본적으로 **private**
- 구조체를 클래스로 변경 가능!
  ```c++
  //구조체
  struct
  {
    string first;
    char middle;
    string last;
  };
  
  ↓↓↓

  //클래스
  class
  {
    public:
      string first;
      char middle;
      string last;
  };
  ```

## 생성자와 소멸자

- 생성자(constructor)
  - 객체가 데이터 멤버를 갖고 어떤 작업을 하려면, 객체를 만든 뒤 **데이터 멤버를 초기화**하는 작업 필요
    - 특정 메모리 위치에 데이터 멤버 값을 초기화시켜주는 작업
  - 객체는 `생성자(constructor)`라고 부르는 특별한 멤버 함수가 호출될 때 생성됨.
    - 따라서 생성자 내부에서 초기화를 하면 편리!
    - 생성자는 **클래스와 동일한 이름**으로 만들어지는 특별한 멤버 함수
- 소멸자(destructor)
  - 객체가 더 이상 필요 없어지는 경우, 객체가 차지하고 있는 메모리를 비워줘야 함(→ 메모리 재활용)
  - `소멸자(destructor)`라는 특별한 멤버 함수가 호출되어 내부에서 객체를 정리하는 작업 수행
- 객체의 라이프 사이클
  - `생성`:생성자 → `초기화`:생성자 → `연산` → `정리`:소멸자 → `재활용`:소멸자 

### 생성자

- 생성자는 객체를 생성하는 특별한 멤버 함수
- 생성자 내부에서 객체의 데이터 멤버를 초기화
- 생성자의 2가지 특징
  - ① 리턴값이 없음
  - ② 생성자의 이름은 클래스의 이름과 동일함
- 생성자는 크게 `매개변수가 있는 생성자`, `기본 생성자`, `복사 생성자`로 구분
- **생성자 선언**
  - 생성자는 클래스 멤버 함수이므로 클래스 정의에서 선언
  - 데이터 멤버를 초기화하는 변경 작업을 하므로 const 한정자를 붙일 수 없음!
    ```c++
    class Circle
    {
      ...
      public:                         // * 클래스 내부에 생성자 선언 *
        Circle(double radius);        // 매개변수가 있는 생성자
        Circle();                     // 기본 생성자
        Circle(const Circle& circle); // 복사 생성자(다른 쪽에서 이미 객체화하여 사용하고 있는 것을 가져옴,  &-생성자에 대한 '참조', const-원본을 훼손하지 않기 위해 지정)
      ...
    }
    ```
- **매개변수가 있는 생성자(parameter constructor)**
  - 일반적으로 데이터 멤버를 지정된 값으로 초기화하기 위해서 매개변수가 있는 생성자 사용
- **기본 생성자(default constructor)**
  - 매개변수가 없는 생성자를 의미
  - 생성자를 따로 설정하지 않으면, 컴파일러가 기본 생성자를 만들어 줌!
- **복사 생성자(copy constructor)**
  - 복사 생성자로 객체를 복사하면, 원본과 복사된 사본이 같은 값을 갖는 다른 객체로 생성됨

- **생성자 정의**
  - 생성자는 특별한 멤버 함수
  - 리턴값을 가질 수 없으며, 이름은 클래스의 이름과 같음
    ```c++
    // 클래스 바깥에서 생성자 정의

    // 1. parameter constructor
    Circle::Circle(double rds)
    : radius(rds) // 초기화 리스트
    {
      // 매개변수 유효성 검사, 파일 열기 등
    }

    // 2. default constructor
    Circle::Circle()
    : radius(0.0) // 초기화 리스트
    {
      // 기본 생성자의 경우, 별다른 코드가 없는 경우 多
    }

    // 3. copy constructor
    Circle::Circle(const Circle& cr)
    : radius(cr.radius) // 초기화 리스트
    {
      // 매개변수 유효성 검사, 파일 열기 등
    }
    ```
  - 초기화 리스트(initialization list)
    - 생성자는 함수 헤더 뒤에 `초기화 리스트`를 사용하여 데이터 멤버를 초기화함
    - 초기화 리스트는 헤더 뒤와 본문 사이에 위치하며 콜론(:)으로 시작
      ```
      : 데이터_멤버1(매개변수1), 데이터_멤버2(매개변수2), ...,m 데이터_멤버n(매개변수n)
      ```

### 소멸자

- 소멸자의 2가지 특징
  - 소멸자의 이름은 클래스 이름 앞에 `물결 기호(~)`가 붙은 형태임
  - 소멸자는 리턴값을 가질 수 없음
- 소멸자는 객체가 스코프를 벗어나면 자동적으로 호출됨
- 소멸자 선언
  - 클래스 정의 내부에서 소멸자를 선언하는 예시
    ```c++
    class Circle
    {
      ...
      public:
        ...
        ~Circle(); // 소멸자 선언
    }
    ```
- 소멸자 정의
  - 소멸자도 다른 멤버 함수처럼 정의
  - 이름 앞에 물결 기호(~)가 있다는 점 주의!
    ```c++
    // 소멸자 정의
    Circle::~Circle()
    {
      // 필요한 문장 추가
    }
    ```
- 생성자와 소멸자
  - 변수 생성과 클래스 객체 생성 비교
    |멤버|클래스 자료형|내장 자료형|
    |--|--|--|
    |매개변수가 있는 생성자|Circle circle1(10.0);|double x1 = 10.0;|
    |기본 생성자|Circle circle2;|double x2;|
    |복사 생성자|Circle circle3(circle1);|없음|
    |소멸자|사용자가 호출하지 않음|사용자가 호출하지 않음|

### 필수 멤버 함수

- 그룹1
  - 구성: `매개변수가 있는 생성자`, `기본 생성자`
  - 이러한 생성자가 하나 이상 있어야 하며, 2개를 모두 만들어도 상관 없음
  - 만약 둘 다 만들지 않으면, 시스템은 `합성 기본 생성자(synthetic default constructor)`라는 것을 생성
    - 합성 기본 생성자는 데이터 멤버를 쓰레기 값으로 초기화

- 그룹2
  - 구성: `복사 생성자`
  - 클래스에는 하나의 복사 생성자가 있어야 함
  - 만약 만들지 않으면, 시스템이 `합성 복사 생성자(synthetic copy constructor)`를 생성
  - 일반적으로 복사 생성자는 직접 구현해서 원하는 형태로 만드는 것이 좋음
  - 시스템이 복사 생성자를 만들어주는 것 방지 가능
    - 복사 생성자 선언 후 delete (c++ 11표준부터 가능)
      ```c++
      RandomInteger(const RandomInteger& random) = delete;
      ```

- 그룹3
  - 구성: `소멸자`
  - 클래스에는 하나의 소멸자가 있어야 함
  - 만약 만들지 않으면, 시스템이 `합성 소멸자(synthetic destructor)`를 생성
  - 일반적으로 합성 소멸자는 우리가 원하는 동작을 하지 않으므로 직접 구현하는 것이 좋음


### 클래스와 생성자, 소멸자 예시

- 세 개의 Circle 객체 생성 예제
  ```c++
  #include <iostream>
  using namespace std;

  /* 1. 클래스 정의 */
  class Circle
  {
  // 데이터 멤버 -> '속성' 표현
  private: // 외부에서 접근하지 못하도록 private 설정
    double radius;
  public: // 외부에서 누구나 사용할 수 있도록 public 설정
    // 생성자 선언
    Circle(double radius);		  // parameter constructor
    Circle();					  // default constructor
    ~Circle();					  // Destructor
    Circle(const Circle& circle); // copy constructor
    // 멤버 함수 -> '동작' 표현
    double getRadius() const; // private으로 관리되고 있는 데이터 멤버의 값을 외부에서 읽어낼 수 있도록 하는 함수
    double getArea() const;	  // 안의 내용을 바꾸지 못하도록 'const' 지정!
    double getPerimeter() const;
    void setRadius(double value); // private으로 관리되고 있는 데이터 멤버의 값을 외부에서 설정 가능하도록 하는 함수 - 변경이 필요하므로 const 지정X
  };

  /* 생성자 정의 */
  // 파라미터가 있는 생성자
  Circle::Circle(double rds)
  :radius(rds) // 초기화 리스트 : 데이터 멤버에 대한 값을 매개변수로 받은 값으로 초기화
  {
    cout << "파라미터가 있는 생성자가 호출되었습니다." << endl;
  }

  // 기본 생성자
  Circle::Circle()
  :radius(0.0) // 초기화 리스트 : 데이터 멤버에 대한 값을 매개변수로 받은 값으로 초기화
  {
    cout << "기본 생성자가 호출되었습니다." << endl;
  }

  // 복사 생성자
  Circle::Circle(const Circle& circle)
  :radius(circle.radius) // 초기화 리스트 : 데이터 멤버에 대한 값을 매개변수로 받은 값으로 초기화
  {
    cout << "복사 생성자가 호출되었습니다." << endl;
  }

  /* 소멸자 정의 */
  Circle::~Circle()
  {
    cout << "소멸자가 호출되었습니다.";
    cout << endl;
  }

  /* 2. 멤버함수 정의 */
  /* 클래스 바깥에서 각각의 멤버함수들이 정의되어야 함 */
  double Circle::getRadius() const
  {
    return radius; // 반지름 값 반환
  }

  double Circle::getArea() const
  {
    const double PI = 3.14;
    return (PI * radius * radius); // 면적 계산 후 반환
  }

  double Circle::getPerimeter() const
  {
    const double PI = 3.14;
    return (2 * PI * radius); // 둘레값 계산 후 반환
  }

  void Circle::setRadius(double value)
  {
    radius = value; // 반지름 값 설정
  }

  /* 3. 어플리케이션 부분 */
  int main()
  {
    // 첫번째 circle 객체 생성 후 멤버 함수 적용

    cout << "Circle 1 : " << endl;
    //Circle circle1;
    //circle1.setRadius(10.0);
    Circle circle1(5.2); // 매개변수가 있는 생성자 호출하여 객체 생성
    cout << "Radius: " << circle1.getRadius() << endl;
    cout << "Area: " << circle1.getArea() << endl;
    cout << "Perimeter: " << circle1.getPerimeter() << endl << endl;

    // 두번째 circle 객체 생성 후 멤버 함수 적용

    cout << "Circle 2 : " << endl;
    //Circle circle2;
    //circle2.setRadius(20.0);
    Circle circle2(circle1); // 복사 생성자를 호출하여 객체 생성
    cout << "Radius: " << circle2.getRadius() << endl;
    cout << "Area: " << circle2.getArea() << endl;
    cout << "Perimeter: " << circle2.getPerimeter() << endl << endl;

    // 세번째 circle 객체 생성 후 멤버 함수 적용

    cout << "Circle 3 : " << endl;
    Circle circle3; // 기본 생성자를 호출하여 객체 생성
    cout << "Radius: " << circle3.getRadius() << endl;
    cout << "Area: " << circle3.getArea() << endl;
    cout << "Perimeter: " << circle3.getPerimeter() << endl << endl;

    // 소멸자가 여기에서 자동적으로 호출됨(stack 구조이기 때문에 가장 나중에 생성된 객체가 가장 먼저 소멸됨!)
    return 0;
  }
  ```

### 인스턴스 멤버

- 클래스를 설계할 때 `인스턴스 멤버`와 `클래스 멤버(=static 멤버)` 두 가지 멤버 그룹 사용
  - 인스턴스 멤버 : 클래스를 객체화 한 경우 인스턴스 멤버라고 함(ex, 개인)
  - 클래스 멤버(static 멤버) : 클래스를 객체화하지 않고도 누구나 바로 사용할 수 있는 멤버(ex, 국적)

- **인스턴스 데이터 멤버(instance data member)**
  - 인스턴스의 속성을 정의
  - 각각의 객체는 클래스에 정의된 데이터 멤버들을 **캡슐화**함
    - 이러한 데이터 멤버는 해당 인스턴스에만 속하므로, 인스턴스끼리 서로 접근할 수 없음
    - 캡슐화 : 객체별로 메모리 영역을 할당하므로, 각 영역에서 객체마다 서로다른 데이터를 갖는 속성을 의미함
  - 접근 제한자
    - 인스턴스 데이터 멤버에는 private과 public 접근 제한자를 적용할 수 있음
    - 일반적으로 **private** 설정
      - public으로 만들면 멤버 함수를 호출하지 않고도 어플리케이션에서 데이터 멤버에 접근할 수 있기 때문!
      - 이는 객체 지향 프로그래밍 기본 개념에 어긋남!
    - 객체 지향 프로그래밍은 객체가 행위(멤버 함수)를 통해서 속성을 조작하는 것이 기본
      - 인스턴스 멤버 함수를 통해서만 데이터 멤버에 접근할 수 있도록 인스턴스 데이터 멤버를 private으로 만들어야 함!

- **인스턴스 멤버 함수(instance member function)**
  - 인스턴스의 행위를 의미. 객체의 인스턴스 데이터 멤버를 조작하기 위해 사용
  - 인스턴스 데이터 멤버는 모든 객체가 개별적으로 갖지만, `멤버 함수`는 메모리 위에 하나만 올라가며 모든 인스턴스가 공유함!
  - 인스턴스 멤버 함수는 일반적으로 **public** 접근 제한자 적용
    - 특별한 경우(= 클래스 내부의 멤버 함수에서만 접근해야 하는 경우)에는 private 접근 제한자 붙임

- **인스턴스 멤버 함수 선택자**
  - 객체 지향 프로그래밍의 어플리케이션 부분(main 함수)에서는 인스턴스를 생성하고, 그 인스턴스가 인스턴스 멤버를 호출하도록 해야 함
  - 이처럼 **인스턴스가 스스로 동작하는 것처럼 코드를 작성하는 것**이 `객체 지향 프로그래밍의 기본 원리`
  - 멤버 선택 연산자
    |그룹|이름|연산자|표현식|우선순위|결합방향|
    |--|--|--|--|--|--|
    |후위|멤버선택|.|객체.멤버|18|→|
    |후위|멤버선택|->|포인터->멤버|18|→|
  - **Q**. 멤버 함수 하나만 메모리에 올라간다면 어떻게 여러 객체가 멤버 함수를 공유할 수 있을까?   
          어떤 객체가 멤버함수를 사용하고 있을 때, 다른 객체가 멤버 함수를 사용하지 못하게 막는 것일까?  
          어떻게 특정 객체가 함수를 사용하고 있을 때 잠그고(lock), 모두 사용한 뒤에 다른 객체가 사용할 수 있도록 잠금 해제(unlock)할 수 있을까?
  - **A**. 백그라운드에서 함수를 잠그는 락킹(locking)과 잠금을 해제하는 언락킹(unlocking) 방법 사용
    - 이를 위해 멤버 함수에 `this 포인터`(=객체의 주소를 나타내는 변수)를 지정함!
    - 모든 멤버 함수에는 `this 포인터`가 숨겨져 있음
    - `this 포인터` : **현재 사용하고 있는 객체를 나타내기 위한 포인터**
  - 숨겨진 매개변수
    - 인스턴스 멤버 함수는 어떻게 this 포인터에 객체의 주소를 할당할 수 있을까?
      - 이는 컴파일러가 멤버 함수의 매개변수에 this 키워드를 자동으로 추가하기 때문!
        ```c++
        // 사용자가 작성한 코드
        double getRadius()const
        {
          return radius;
        }

        ↓↓↓

        // 컴파일러에 의해 내부적으로 작동
        double getRadius(Circle* this)const
        {
          return (this->radius);
        }
        ```
  - **-> 연산자**
    - '간접 참조 연산자(indirection operator)'와 '멤버 선택 연산(member operation)'이 조합된 특수 연산자
      - `this->radius` 와 `(*this).radius`는 동일!
      - 'this 포인터를 통해서 radius 데이터 멤버를 가리키는 것'은 '특정 객체(*this)에 대한 멤버를 가리키는 것'과 동일함!
    - 인스턴스 멤버 함수 호출을 위해 '멤버 선택 연산자'를 사용하면, 컴파일러는 호출을 다음과 같은 형태로 변경함
      ```c++
      // 사용자가 작성한 코드
      circle1.getRadius();

      ↓↓↓

      // 컴파일러에 의해 내부적으로 작동
      this = &circle1;
      getRadius(this);
      ```
  - **명시적인 포인터 사용**
    - 프로그램 내부에서 `this 포인터`를 사용해서 데이터 멤버를 명시적으로 가리킬 수도 있음
    - `this 포인터`를 사용하면 데이터 멤버와 매개변수를 같은 이름으로 사용 가능!
      ```c++
      // this 포인터 사용 X
      void Circle::setRadius(double rds)
      {
        radius = rds;
      }

      // this 포인터 사용 O
      void Circle::setRadius(double radius)
      {
        this->radius = radius;
      }
      ```
  - **호스트 객체(host object)**
    - 인스턴스 멤버 함수를 호출하는 객체
    - `this 포인터`가 가리키는 객체가 바로 호스트 객체

  - **접근자 멤버 함수(accessor member function)**
    - 호스트 객체의 정보를 추출(get)할 때 사용하는 함수. 게터(getter)라고 하기도 함
    - 접근자 인스턴스 멤버 함수가 객체의 상태를 변경하지 않는다는 것을 확실하게 할 수 있도록 함수 헤더 끝에 const 한정자를 추가하는 것이 좋음!
      ```c++
      double getRadius() const;    // 호스트 객체는 read-only
      double getPerimeter() const; // 호스트 객체는 read-only
      double getArea() const;      // 호스트 객체는 read-only
      ```
    - 접근자 멤버 함수에서 데이터 멤버의 값을 무조건 리턴할 필요는 없으며, 다음과 같이 *값을 출력하는 기능을 하는 함수*도 *접근자 멤버 함수*라고 할 수 있음!
      ```c++
      void Circle::output() const
      {
        cout << "Radius: " << radius << endl;
        cout << "Perimeter: " << 2 * radius * 3.14 << endl;
        cout << "Area: " << radius * radius * 3.14 << endl;
      }
      ```

  - **설정자 멤버 함수(mutator memeber function)**
    - 데이터 멤버를 변경해야 할 때 사용
    - 호스트 객체의 상태를 변경하는 인스턴스 멤버 함수가 필요하며 이러한 함수를 '설정자 멤버 함수' 또는 '세터(setter)'라고 부름
    - 설정자 멤버 함수는 호스트 객체의 상태를 변경하므로 const 한정자를 붙이면 안됨!
      ```c++
      void setRadius(double rds); // setter에는 const가 없음!
      ```
    - 매개변수가 없어도 데이터 멤버의 값을 변경한다면 설정자 멤버 함수라고 할 수 있음!
      ```c++
      void Circle::input()
      {
        cout << "circle 객체의 반지름 값을 입력하시오: ";
        cin >> radius;
      }
      ```

  - **❗클래스 불변 속성(class invariant)❗**
    - 클래스의 데이터 멤버의 일부 또는 전체에 적용해야 하는 하나 이상의 조건을 의미
    - 인스턴스 멤버 함수를 사용해서 적용
    - '객체를 생성하는 인스턴스 데이터 멤버 함수(매개변수가 있는 생성자)' 또는 '데이터 멤버의 값을 변경하는 설정자 멤버 함수(setter)'를 사용해서 클래스의 불변 속성을 적용
      ```c++
      Circle::circle(double rds)
      :radius(rds)
      {
        if(radius <= 0.0) // 반지름이 양수여야 한다는 조건(불변의 속성)을 생성자 안에서 적용!
        {
          cout << "No circle can be made!" << endl;
          cout << "The program is aborted" << endl;
          assert(false); // 프로그램을 종료시킴
        }
      }
      ```

### 정적 멤버(static member = 클래스 멤버)

- 인스턴스 멤버와 마찬가지로, 정적 멤버도 `정적 데이터 멤버`와 `정적 멤버 함수`로 구분됨

- **정적 데이터 멤버(static data member)**
  - 클래스 또는 모든 인스턴스에 포함되는 멤버
  - 정적 데이터 멤버 **선언**
    - 클래스 정의에서 선언해야 하고 `static`이라는 키워드를 붙여야 함
    - 예시
      ```c++
      class Rectangle
      {
        private:
          ...
          static int count; // static data member -> 객체화하지 않고도 공통적으로 사요알 수 있는 데이터 멤버
        public:
          ...
      }
      ```
  - 정적 데이터 멤버 **초기화**
    - 정적 데이터 멤버는 인스턴스에 속하는 것이 아니므로, 생성자에서 초기화할 수 없음
    - 클래스 정의 후에 초기화해야 하며, 따라서 프로그램의 `전역 영역`에서 초기화
      - 일반적으로 클래스 정의 바로 뒷부분의 전역 영역에 작성!
    - 값을 초기화할 때 클래스 이름과 클래스 스코프 연산자(::)를 추가해서 클래스에 속한다는 것을 나타내야 하고 **const 한정자를 추가하면 안 됨!**
      - 누구나 변경할 수 있는 데이터 멤버로 사용되어야 하기 때문
      ```c++
      int Rectangle::count = 0; // const 사용 X
      ```

- **정적 멤버 함수**
  - 정적 데이터 멤버는 일반적으로 private이므로 이에 접근할 수 있는 public 멤버 함수 필요
  - 인스턴스 멤버 함수에서도 정적 데이터 멤버에 접근할 수 있지만, 일반적으로 정적 데이터 멤버에 접근할 때는 정적 멤버 함수를 사용!
  - 정적 멤버 함수는 인스턴스와 연결되지 않으므로, 호스트 객체가 없음!
  - 정적 멤버 함수 **선언**
    - 정적 멤버 함수도 클래스에 속함
    - `static` 키워드를 함수 앞에 붙여야 함
      ```c++
      class Rectangle
      {
        private:
          ...
          static int count;
          ...
        public:
          ...
          static int getCount(); // static member function
          ...
      }
      ```
  - 정적 멤버 함수 **정의**
    - 인스턴스 멤버 함수처럼 클래스 외부에서 정의
      ```c++
      int Rectangle::getCount()
      {
        return count;
      }
      ```
  - 정적 멤버 함수 **호출**
    - 인스턴스 또는 클래스를 통해서 호출 가능
    - 정적 멤버 함수에는 호스트 객체가 없기 때문에 **정적 멤버 함수 내부에서 인스턴스 데이터 멤버에 접근할 수는 없음!**
      - 객체화를 하지 않고 사용하기 때문
      ```c++
      rect.getCount()         // 인스턴스를 통한 호출
      Rectangle::getCount()   // 클래스를 통한 호출
      ```
  - 인스턴스 멤버 함수 vs 정적 멤버 함수
    - 인스턴스 멤버 함수에서는 정적 데이터 멤버에 접근할 수 있지만, 일반적으로 인스턴스 멤버 함수에서 정적 데이터 멤버에 접근하지 않음
    - `인스턴스 멤버 함수`는 인스턴스 데이터 멤버에 접근할 때, `정적 멤버 함수`는 정적 데이터 멤버에 접근할 때 사용하는 것이 바람직!