# 다형성

- 다형성은 같은 이름을 갖는 여러 형태의 함수를 클래스별로 만들 수 있게 해주는 기능
  - 오버로딩, 오버라이딩과 연관
- 이렇게 만들어진 함수들은 호출했을 때 함수에 맞는 적합한 형태가 호출
- 예시
  - '열다'라는 단어는 객체에 따라서 다양한 형태로 사용됨
    - 문을 열다, 뚜껑을 열다, 가게를 열다, 모임을 열다 등
  - printArea() : 넓이를 출력하는 함수
    - 삼각형 객체에서는 printArea()가 삼각형의 넓이를 구하는데 사용됨
    - 사각형 객체에서는 printArea()가 사각형의 넓이를 구하는데 사용됨
- 플러그 호환 객체(plug-compatible-object) 개념
  - 소켓과 플러그 호환 장치(객체)
    - 램프와 텔레비전이라는 2개의 전기 장치가 있음
    - 하지만 전원을 공급할 수 있는 소켓은 하나
    - 각각의 장치에는 소켓에 꼽을 수 있는 플러그가 하나 있음
    - t1 시점에는 램프를 소켓에 꼽음
    - t2 시점에는 램프 플러그를 빼고 텔레비전 플러그를 꼽음
    - 이러한 일이 가능한 이유는 두 장치의 플러그와 소켓이 호환되기 때문임
    - `주목해야 할 점` : **램프와 텔레비전(=객체, 플러그 호환 객체)은 소켓(=포인터)으로부터 전원(=함수)이라는 동일한 것을 받지만, 하는 일이 다름!**
      - 하는 일은 객체가 좌우함

## 다형성의 요소
- 3가지 요소
  - 포인터(또는 레퍼런스)
  - 플러그 호환 객체
  - 가상 함수

- ① 포인터와 레퍼런스
  - 소켓 역할을 할 수 있는 것이 필요
    - 포인터와 레퍼런스
  - 베이스 클래스를 가리키는 포인터(또는 레퍼런스)를 사용하면, 포인터가 베이스 클래스와 파생 클래스 모두를 가리키게 만들 수 있음
  - 이러한 이유로 포인터(또는 레퍼런스)를 `다형성 변수`라고 부름!

- ② 플러그 호환 객체
  - 램프와 텔레비전 등의 장치 역할을 하는 플러그 호환 객체 필요
  - `상속을 하는 객체`들이 이러한 역할 수행

- ③ 가상 함수
  - 장치들이 자신의 역할을 하기 위해서 전달해야 하는 전원의 역할을 하는 것
  - `virtual` 한정자를 붙인 함수
  - 예) 모든 플러그 호환 객체에 print() 함수를 만들고 `virtual` 한정자를 붙이면, **객체 별로 다른 것을 출력할 수 있음!** 

## 불완전한 다형성 프로그램

- 코드
  ```c++
  #include <iostream>
  #include <string>
  using namespace std;

  // base 클래스 정의 + inline 함수
  class Base
  {
  public:
    void print() const { cout << "In the Base" << endl; }
  };

  // Derived 클래스 정의 + inline 함수
  class Derived : public Base
  {
  public:
    void print() const { cout << "In the Derived" << endl; }
  };

  int main()
  {
    // Base 클래스에 대한 포인터 생성(소켓 역할 수행)
    Base* ptr;
    // 생성자를 통해서 base객체를 객체화한 후 포인터로 연결 - 힙에 생성
    ptr = new Base();
    // 포인터를 통해 객체 내부의 멤버 함수 실행 -> Base::print() 실행됨!
    ptr->print();
    // 힙 메모리에 있는 객체 삭제
    delete ptr;
    
    // Derived 객체도 동일한 과정 수행
    ptr = new Derived();					// ptr 포인터의 자료형이 Base이므로 계속 Base 클래스를 가리키게 됨!(Base 클래스의 객체에 대한 포인터임)
    ptr->print();							// Base::print() 실행됨! -> 가상함수를 사용하지 않았기 때문에 다형성이 제대로 작동하지 않은 것!
    delete ptr;

    return 0;
  }
  ```
- ptr 포인터는 베이스 클래스의 객체에 대한 포인터임
- 상속은 is-a 관계이므로 파생 클래스도 베이스 클래스라서 ptr 포인터로 파생 클래스의 객체를 가리킬 수 있음
- 하지만 print 함수를 호출해도 ptr포인터가 베이스 클래스에 대한 포인터이므로 베이스 클래스에 정의된 print함수를 호출함
- 완전한 다형성 프로그램으로 변경
  - virtual 키워드 추가하여 가상함수로 만듦!
  ```c++
  #include <iostream>
  #include <string>
  using namespace std;

  class Base
  {
  public:
    virtual void print() const { cout << "In the Base" << endl; }
  };

  class Derived : public Base
  {
  public:
    virtual void print() const { cout << "In the Derived" << endl; } // 상속받은 클래스에서는 virtual 쓰지 않아도 가능
  };
  ```

## 가상 테이블(virtual table)

- 컴퓨터 시스템은 다형성을 목적으로 클래스 계층(=상속)이 구성될 때 `가상 테이블`이라는 것을 생성
- 가상 테이블에 있는 항목들은 가상 함수에 대한 포인터를 가짐!
- ptr 포인터가 베이스 클래스의 객체를 가리키면, 객체에 있는 가상 테이블 포인터(vptr)가 베이스 클래스의 가상 테이블을 가리킴
- 가상 테이블 내부에는 가상 함수들에 대한 포인터가 들어 있음
- 따라서 print 함수를 호출하면 베이스 클래스의 print 함수가 호출됨
- 파생 클래스도 동일!
  - base 객체 안에 base 가상 테이블에 대한 주소정보를 가지고 있고, 가상 테이블 안에는 base 가상 함수에 대한 포인터를 가지고 있음
  - derived 객체 안에 derived 가상 테이블에 대한 주소정보를 가지고 있고, 가상 테이블 안에는 derived 가상 함수에 대한 포인터를 가지고 있음

## 생성자와 소멸자

  - 생성자와 소멸자를 가상 함수로 선언 가능?
  - 가상 생성자 불가
    - 생성자 이름은 베이스 클래스와 파생 클래스가 무조건 다르므로, 생성자는 가상 클래스 함수가 될 수 없음!
  - 가상 소멸자 가능
    - 소멸자의 이름도 베이스 클래스와 파생 클래스가 무조건 다름
    - 하지만 소멸자는 이름으로 호출하지 않으므로, 가상 소멸자라는 것이 존재
    - 클래스 설계에 가상 함수가 있다면, **메모리 누수를 피할 수 있게** 가상 소멸자를 만들어야 함 (힙에 올라가기 때문)
    - (다형성을 사용하지 않는 경우와 다형성을 사용하는 경우로 구분)
      - 다형성을 사용하지 않는 경우
        - 프로그램이 종료될 때 Person 클래스와 Student 클래스의 소멸자가 호출되어서, 메모리를 해제하므로 메모리 누수가 발생하지 않음
      - 다형성을 사용하는 경우(=가상 함수로 만들고, 가상 소멸자를 만들지 않은 경우(?))
        - ptr 포인터에 delete 연산자를 적용했을 때 두 객체가 모두 정상적으로 삭제될까?
          ```c++
          ptr = new Person(...);
          ...
          delete ptr; // 정상적으로 삭제됨

          ptr = new Student(...);
          ...
          delete ptr; // 정상적으로 삭제되지 않음 - ptr객체가 Person을 가리키고 있기 때문에 student 객체의 메모리 정리가 되지 않음
          ```
          - 이런 문제를 해결하려면 베이스 클래스의 소멸자를 가상 함수로 만들어야 함!
          - 베이스 클래스의 멤버 함수를 가상 함수로 만들면, 파생 클래스에서도 가상 함수가 됨!

### Java와의 차이점

- 자바는 사용자가 포인터와 레퍼런스를 구분해서 사용하지 않음. 객체를 변수에 저장하면 무조건 포인터(또는 레퍼런스)처럼 동작하며, 객체는 무조건 힙에 만들어짐(new사용)
- 자바는 public 상속만 지원. 따라서 상속을 하면 무조건 플러그 호환 객체로 작동함
- 자바의 모든 멤버 함수는 가상 함수로 만들어짐

## 바인딩

- 함수는 `함수 호출`과 `함수 정의`라는 엔티티로 구분할 수 있음
- 바인딩이란 함수 호출(print())과 함수 본문(void print(){})의 연결을 의미함
  - 함수는 어딘가 정의되고, 또 다른 곳에서 호출됨
  - 함수를 호출하면, 함수 정의가 실행됨
- 상속에서는 오버라이드를 하면, 시그니처가 같은 2개 이상의 함수가 만들어질 수 있음
  - 함수 호출은 하나지만, 여러 개의 정의가 생기는 것!
- 정적 바인딩 vs 동적 바인딩
  - 정적 바인딩
    - 컴파일 시점 바인딩, 조기 바인딩
    - 함수에 대한 여러 개의 정의가 있고, 컴파일 시점에 어떤 함수를 호출해야 하는지 명확하게 컴파일러가 이해하는 경우에 발생
    - 예시
      ```c++
      person.print(); // person 객체의 print 함수
      student.print(); // student 객체의 print 함수 -> 컴파일러는 이를 컴파일 시점에 인지함
      ```
    - 애매한 점이 없으므로 다형성도 필요 없음
    - 바인딩도 컴파일 시점에 이루어짐
  - 동적 바인딩
    - 런타임 바인딩, 지연 바인딩
    - 바인딩이 런타임 시점에 일어남
    - 컴파일 시점에 객체가 어떤 객체일지 정확히 모르는 경우
    - 프로그램 실행 중에 어떤 변수에 여러 객체의 포인터가 할당되어, 다형성을 발생시킬 때 동적바인딩이 일어남
- 런타임 타입 정보
  - 클래스가 계층 구조를 가질 때는 객체가 어떤 객체인지 확인하거나, 객체의 자료형을 변경해야 하는 경우
  - 런타임 타입 정보(RTTI) 이용
    - **typeid 연산자**
      - 런타임 때 객체의 자료형을 확인
      - \<typeinfo>헤더의 type_info 클래스 사용
      - type_info 클래스는 생성자, 소멸자, 복사 생성자가 없음
      - type_info 객체는 typeid라는 연산자를 호출해서 생성 : `typeid(5), typeid(object_name), typeid(6+2)`
      - type_info 객체는 멤버 함수와 연산자를 적용할 수 있음
        ```c++
        // t1과 t2는 type_info 객체
        t1 == t2
        t1 != t2
        t1.name()
        t1.before(t2)
        ```

## 동적 자료형 변환
- 업캐스트(upcast)
  - 베이스 클래스에 대한 포인터에 파생 클래스의 객체를 넣는 것
    ```c++
    Person* ptr1 = new Student;
    ```
- 다운캐스트(downcast)
  - 파생 클래스에 대한 포인터에 베이스 클래스의 객체를 넣는 것
  - dynamic_cast 연산자 사용
    ```c++
    Student* ptr2 = dynamic_cast<Student*>(ptr1);
    ```
  - dynamic_cast는 Student 클래스가 Person 클래스의 파생 클래스일 때만 가능
  - 일부 개발자들은 이를 활용해 코드로 상속 관계를 확인함
  - 다만 이러한 코드는 오버헤드가 많이 발생하므로 이를 통해 상속 관계를 확인하는 것은 바람직X
