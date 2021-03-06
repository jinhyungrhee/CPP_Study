# 예외 처리

## 예외
- 프로그램 실행 중에 오류가 발생해서 프로그램이 중단되는 경우
- 이를 해결하는 것을 '예외 처리(excepiton handling)'라고 함
- 4가지 고전적인 오류 처리 방법
  - **런타임 때 프로그램을 중단**
    - 아무 것도 하지 않아서, 예외가 있는 경우 프로그램이 중단되게 만드는 것
    - `문제점` : 어떠한 경고도 없이 프로그램이 중단되게 만듦(가장 나쁨)
  - **런타임 때 프로그램 중단 요청**
    - 예상할 수 있는 오류를 조건문 등으로 처리한 후, 프로그램의 중단을 요청하는 것
    - 프로그램이 중단되는 원인을 설명할 수 있음
    - `문제점` : 프로그램이 중단되는 것은 똑같지만 사용자에게 경고를 줌
  - **오류 확인 사용**
    - 반복 때 두 번째 숫자의 값을 확인하고, 0일 때에 나누지 않고 넘어가는 것
    - 프로그램이 중단되지 않고 계속되므로, 일반적으로 이렇게 처리하는 것이 위의 방법보다는 좋음
    - `문제점` : 오류 처리하는 코드와 기본적인 코드가 결합되어 있어서 코드의 가독성이 떨어짐
  - **오류 확인에 함수 리턴 사용**
    - 함수를 사용하는 방법
    - 런타임 오류는 함수 내부의 문장을 실행할 때 발생
    - 함수 외부에 있는 전역 영역에서도 변수를 초기화하는 등의 문장이 있을 수 있지만, 이러한 전역 영역에 위치한 문장에 오류가 있는 경우는 모두 컴파일 시점에 걸러짐
    - 그래서 과거에는 함수에서 어떤 값을 계산하고, 리턴 값을 활용해서 오류를 확인하는 방법을 많이 사용함
      - 예시) main 함수에 문제가 없으면 0을 리턴하고, 문제가 있으면 다른 값을 리턴
    - `문제점` : 모든 상황에 사용할 수 있는 형태가 아님. 구조적 프로그래밍에 따르면 함수의 리턴 값은 하나의 목적만 가져야 함  
  ➡ 이러한 문제들 때문에 '예외 처리'라는 새로운 방법이 필요함!

## 예외 처리 방법

- 런타임 예외가 발생해도 프로그램이 이를 처리하여 중단되지 않게 만들 수 있음!

### try-catch 블록
- try와 catch라는 절(clause)로 구성
- try절에는 프로그램을 중단시킬 가능성이 있는 코드를 넣음
- 런타임 환경은 try절의 코드를 하나하나 실행하다가 예외가 발생하면 프로그램이 중단되는 것이 아니라, catch 절로 이동해서 코드를 계속해서 진행
- try-catch 블록에는 여러 개의 catch 절을 배치할 수 있음
  ```c++
  try
  {
    // 예외를 발생시킬 수 있는 코드
  }
  catch (자료형 변수)
  {
    // 예외를 처리하는 코드
  }
  ```
  - try절에서 오류가 발생하면 예외를 발생(throw)시킴
  - catch절에서는 예외가 발생했을 경우, 프로그램이 중단되는 것을 막는 처리를 함
- throw 연산자(2가지 형태)
  - 1) 특정한 예외 객체를 발생시킬 때 사용
    - 피연산자로 전달된 객체로 예외를 발생(=> 특정 자료형희 예외 발생)
  - 2) catch절 내부에서 예외를 다시 발생시킬 때 사용
    - 현재 발생된 예외를 다른 곳으로 전달(=> 단순 예외 전달)
  - throw 연산자는 어떤 결과를 내지 않음!
  - throw 연산자는 예외를 발생시키는 부가 작용으로만 사용

- try-catch 블록의 3가지 패턴
  - 패턴1 : try-catch 블록이 모두 하나의 함수 내부에 포함된 경우
    - 예외가 발생하면 throw 구문 뒤의 try 절은 모두 무시되고, catch 절로 제어가 이동
    - catch 절에서 예외가 또 발생해서 프로그램이 중단되지 않는 이상 함수의 실행은 계속됨
    - throw 구문이 직접적으로 try 구문 내부에 있는 경우
    - 코드
      ```c++
      int main()
      {
        ...
        try
        {
          ...
          throw 값;
          ...
        }
        catch(자료형 변수)
        {
          ...
        }
        ...
        return 0;
      }
      ```
      - throw 구문은 곧바로 try블록을 벗어나게 함!
  - 패턴2 : try-catch 블록이 main 함수 내부에 있지만, 다른 함수 내부에서 예외가 throw되는 경우
    - 호출되는 함수 쪽에서 throw 하는 경우
    - 함수에서 자신을 호출한 쪽으로 예외를 전달할 수 있게 해줌(= `호출하는 함수 쪽`에서 try-catch 블록 사용)
    - 즉, 예외를 발생시키는 함수와 예외를 처리하는 함수가 공개된 것
    - 어떤 함수의 코드를 공개하지 않고 라이브러리 형태로 제공만 하는 경우, 사용자에게 함수가 무엇을 하는지 알려주고(공용 인터페이스) 어떤 예외가 발생하는지 알려줄 수 있음
    - throw구문이 try 구문 내부에서 호출하는 다른 함수 내부에 있는 경우 (= 간접적으로 잇는 경우)
    - 코드
      ```c++
      type aFunction(...)
      {
        ...
        throw 예외_값; // 예외가 발생할 경우
        ...
        return 리턴_값; // 예외가 발생하지 않을 경우
      }
      int main()
      {
        ...
        try
        {
          ..
          aFuction(...);
          ...
        }
        catch(자료형 변수) // 예외가 발생할 경우
        {
          ...
        }
        ...
        return 0;
      }
      ```
- 패턴3 : 호출되는 함수가 독립적인 함수(클래스 멤버 함수 등)라면 `호출되는 함수 쪽`에 try-catch 블록을 사용해야 하는 경우가 있음 (2가지 형태)
  - 형태1) 호출되는 함수 쪽에서 자체적으로 모든 처리를 하고, 함수가 종료되면 리턴
    - 호출되는 함수 쪽에서 첫 번째 패턴으로 독립적으로 모든 예외를 처리하는 형태
  - 형태2) 호출되는 함수 쪽에서 처리를 중단하고, 호출한 함수 쪽으로 예외를 전달하는 경우 (=> "패턴3")
    - 두 함수 모두에 try-catch 블록이 있어야 함
    - 호출되는 함수 쪽의 catch 절에서 예외를 다시 한 번 발생시키고, 이를 호출하는 함수 쪽에서 추가적으로 처리
    - throw 구문이 두 번 사용된 경우
    - 코드
      ```c++
      type aFunction(...)
      {
        ...
        try
        {
          ...
          if (...)
          {
            throw 값; // 문제 발생 - 순서 1
          }
          ...
        }
        catch(자료형 변수)
        {
          throw;  // 문제 발생 - 순서 2
        }
        ...
        return 리턴_값; // 문제가 없는 경우
      }
      int main()
      {
        ...
        try
        {
          ...
          aFunction(...); 
          ...
        }
        catch(자료형 변수) // 문제 발생 - 순서 3
        {
          ...
        }
      }
      ...
      return 0;
      ```

- 여러 개의 catch절과 범용 catch절
  - 각 자료형에 따라서 처리가 다른 경우, catch 절을 여러 개 사용함
  - catch절은 괄호 내부에 입력한 매개변수의 자료형에 해당하는 예외만 catch할 수 있음
  - 만약 모든 자료형의 예외를 처리하고 싶다면 괄호 내부에 점 3개(...)를 입력 -> `범용 catch 절`
    - 일반적으로 특정 자료형의 예외를 먼저 처리하고, 마지막에 이러한 범용 catch 절을 입력
  - 코드
    ```c++
    try
    {
      throw type1 값;
      ...
      throw type2 값;
      ...
    }
    catch(type1 객체1) // 특정 자료형의 예외 처리
    {
      // 예외 처리
    }
    catch(type2 객체2) // 특정 자료형의 예외 처리
    {
      // 예외 처리
    }
    catch(...) // "범용 catch 절" -> 어떤 예외든 전부 처리
    {
      // 예외 처리
    }
    ```
    - 값1이 throw되면, 첫 번째 catch 절이 실행됨(두 번째 catch 절은 무시)
    - 값2가 throw되면, 두 번째 catch 절이 실행됨(첫 번째 catch 절은 무시)

### 예외 전파와 예외 전달

- 예외 전파(exception propagation)라고
  - 함수 내부에서는 예외가 발생된다고 꼭 같은 함수 내부에서 예외를 처리할 필요는 없음
  - 어떤 함수 내부에서 예외가 발생하고 처리되지 않았다면 함수 호출 계층 구조를 타고 예외가 전파
  - 예외를 처리할 수 있는 마지막 함수는 main 함수
  - 만약 main 함수에서도 예외를 처리하지 않으면 런타임 시스템으로 예외가 전파되고 프로그램 전체가 중단됨
- catch 절에서 예외를 완전하게 처리할 수 없거나, 처리하고 싶지 않은 경우
  - 이 경우, 한 단계 위의 함수로 예외를 전달하면 됨
  - 예외에 대한 처리를 위해서는 예외를 발생시켜야 하는데, '네트워크' 또는 '파일 처리' 등에서 이러한 코드 사용
    ```c++
    try
    {
      ...
    }
    catch(type variable)
    {
      ...    // some work 
      throw; // re-throw the exception to the calling function
    }
    ```

### 예외 사양

- 함수 시그니처만으로 함수 내부에서 어떤 여외가 발생할지 알려줌
- 3가지 예외 사양
  - 모든 예외 발생 가능
  - 특정 예외 발생 가능
  - 예외 없음
- **모든 예외 발생 가능**
  - '예외 사양이 없는 함수'는 모든 예외가 발생(throw)할 수 있다는 의미!
  - 어떤 예외가 발생되는지 알려면 함수 본문을 봐야 함
  - 이러한 함수는 라이브러리 함수처럼 다른 사람들이 사용할 가능성이 있는 함수에 적합하지 않음
    ```c++
    type functionName(parameters); // 예외 사양이 없는 함수의 프로토타입
    ```
- **특정 예외 발생 가능**
  - 함수 설계자와 사용자가 다르다면, 함수 내부에서 어떤 예외가 발생할지 명시적으로 알려주는 것이 좋음
  - 특정 예외가 발생할 가능성이 있다면 다음과 같은 문법을 사용
    ```c++
    type functionName(parameters) throw(type1, type2, ... , typen); // 특정 예외가 발생 가능한 함수의 프로토타입
    
    // quotient 함수 예시
    int quotient(int first, int second) throw(int); // int 자료형의 예외가 발생할 가능성이 있음
    ```
    - 이때 자료형1~n은 발생할 가능성이 있는 모든 예외의 종류를 나타냄
- **예외 없음**
  - 함수에서 예외를 전혀 발생시키지 않는다고 명시적으로 알려주는 경우
  - try-catch 블록을 아예 사용할 필요가 없음
  - 함수의 헤더에 throw 키워드를 사용하고 괄호 내부에 아무 것도 입력하지 않음
    ```c++
    type functionName(parameters) throw(); // 예외를 전혀 발생시키지 않는 함수의 프로토타입

    // print 함수 예시
    int print(int first, int second) throw(); // 예외가 발생하지 않을 것이라고 명시 -> 예외처리 필요X
    ```

### 스택 해제(stack unwinding)
  - 프로그램이 사용하는 메모리와 관련
  - 스택 메모리 : 마지막에 넣은 것이 가장 먼저 꺼내지는 후입선출 특성을 갖는 메모리
    - 함수와 관련된 매개변수, 지역변수, 리턴 주소(코드 메모리에 있는 코드 주소)를 추적하는 역할
  - 스택 메모리의 삽입과 삭제
    - 예외 처리는 스택 메모리의 동작을 기반으로 이루어짐
    - 모든 프로그램은 함수를 호출할 때 매개변수, 지역 변수, 리턴 주소 등의 정보가 스택에 삽입
    - 이때 리턴 주소는 함수가 정상적으로/비정상적으로 종료(예외 발생)되었을 때 사용 -> 호출 시 어디로 돌아와야 하는지를 미리 적어 놓음
    - `스택 해제에서 가장 중요한 작용` : **함수와 관련된 정보가 꺼내지면서 매개변수와 지역변수가 모두 사라짐**
      - 만약 매개변수 또는 지역변수가 클래스의 인스턴스라면, 소멸자를 호출해서 소멸시킴
      - 만약 객체를 지역 변수로 스택에 선언했다면, 함수가 종료될 때 관련 정보가 모두 제거되므로 큰 문제가 없음
      - 하지만 객체를 힙에 선언했다면, 객체가 소멸되지 않아 메모리 누수가 발생할 수 있음!

### 클래스와 예외 처리
- 일반 멤버 함수에서의 예외처리는 독립적인 함수의 예외처리와 동일
- 하지만 생성자와 소멸자에서 발생하는 예외를 처리할 때는 주의 필요!
- **생성자에서의 예외처리**
  - C++는 생성자가 생성 작업을 하지 못하는 경우, 소멸자를 호출하지 않음
  - **생성자 내부에서 예외**가 발생
    - 경우1) 객체를 `스택 메모리에 생성`하는 경우
      - 생성자 내부에서 예외가 발생하므로, 프로그램이 중단되며 스택에 할당된 모든 메모리가 해제됨
    - 경우2) 객체를 `힙 메모리에 생성`하는 경우
      - 힙에 메모리 영역을 할당한 후에 생성자 본문에서 예외가 발생한 경우
      - 생성자에서 예외가 발생한 순간 생성자를 벗어남
      - 객체가 완전하게 만들어진 상태가 아니므로 소멸자가 호출되지 않음
      - 스택 해제 중에 객체가 삭제되기는 하지만, **소멸자가 호출되지는 않으므로 힙에 할당된 영역이 해제되지 않음!**
        - 이러한 문제는 메모리를 할당하는 작업과 메모리를 해제하는 작업이 분리되어 있어서 발생
        - 따라서 메모리 할당과 해제를 하나의 작업으로 결합하면 문제를 해결할 수 있음 => `스마트 포인터`
          ```c++
          Integer::Integer(int v)
          {
            sp(new int); // 스마트 포인터 사용
            *sp = v;
          }
          Integer::~Integer()
          {
            delete ptr;
          }
          int main()
          {
            Integer obj(5);
            ...
            return 0;
          }
          ```
      - **function-try 블록**
        - 초기화 리스트에서 예외가 발생할 경우
          - 초기화 리스트와 try-catch 블록을 결합한 형태의 `function-try 블록`을 사용
        - 코드
          ```c++
          // 생성자
          ClassName::ClassName(...)
          {
            try : 초기화 리스트
            {
              // 생성자 본문
            }
            catch(Type)
            {
              // 예외 처리
              throw exception
            }
          }

          // 어플리케이션
          int main()
          {
            ...
            try
            {
              // 생성자 호출
            }
            catch(Type)
            {
              ...
            }
            return 0;
          }
          ```
- **소멸자에서의 예외 처리**
  - 스택에서 어떤 객체가 사라질 때 소멸자 호출
  - 이때 예외가 발생하면 스택에서 메모리가 제거되는데 문제 발생
    - c++은 `teminator`라는 프로그램 전체를 종료하는 '전역 함수'를 호출

## 표준 예외 클래스

- 계층 구조의 가장 위에는 \<exception> 헤더에 정의되어 있는 exception 클래스가 있음
- 사용자 정의 예외 클래스를 만들지 않아도 \<exception> 또는 \<stdexcept> 헤더에 정의되어 있는 표준 예외 클래스를 활용해도 됨
- exception 클래스의 공용 인터페이스
  ```c++
  exception() throw() // 기본 생성자
  exception(const exception&) throw() // 복사 생성자
  exception& operator = (const exception&) throw() // 할당 연산 함수
  virtual ~exception() throw() // 소멸자(가상함수) -> exception을 상속받는 모든 표준 예외 클래스들은 각자 구현(재정의)해야 함!
  virtual const char* what() const throw() // 멤버 함수(가상함수) -> exception을 상속받는 모든 표준 예외 클래스들은 각자 구현(재정의)해야 함!
  ```

### 논리 오류
- logic_error 클래스
- 논리 오류와 관련된 4개의 클래스의 베이스 클래스
- logic_error 클래스의 공용 인터페이스
  ```c++
  explicit logic_error(const string& wahtArg) // 생성자
  virtual const char* what() const throw()    // 멤버 함수 -> 가상함수(logic_error도 추상 클래스)
  ```
- logic_error 클래스에서 domain_error, out_of_range, length_error, invalid_argument라는 클래스가 파생됨
  - 이러한 파생 클래스의 모든 생성자 함수는 logic_error 클래스와 이름만 다르지 같은 매개변수를 받음
  - 모든 파생 클래스에서 what 멤버 함수를 사용할 수 있음(=> 무조건적으로 재정의해서 사용해야 함)
  - 파생 클래스들의 생성자
    |클래스|생성자|
    |--|--|
    |domain_error|explicit domain_error(const string& wahtArg)|
    |length_error|explicit length_error(const string& wahtArg)|
    |out_of_range|explicit out_of_range(const string& wahtArg)|
    |invalid_argument|explicit invalid_argument(const string& wahtArg)|

- **domain_error**
  - 데이터가 도메인(영역)을 벗어난 경우에 발생
  - 예시) 0.0 ~ 4.5 사이의 학점이 필요한 경우, -1.0이나 6.0과 같은 도메인을 벗어나는 값이 전달되면 domain_error 발생

- **length_error**
  - 객체의 길이가 필요한 길이와 다른 경우에 발생
  - 예시) 문자열 클래스는 max_size 멤버 함수의 리턴값보다 큰 문자열을 할당하면 length_error 발생

- **out_of_range**
  - 라이브러리 클래스에서 인덱스를 넘는 어떤 처리를 할 때 발생
  - 예시) 문자열 클래스에는 문자열 내부의 문자 위치를 추출하는 at 멤버 함수가 있다고 가정
    - 만약 at 멤버함수에 문자열의 범위를 넘는 인덱스를 전달하면, out_of_range 예외 발생
    - 함수를 설계할 때도 인덱스를 넘는 어떤 처리를 하려 한다면 이러한 예외를 throw 할 수 있음

- **invalid_argument**
  - 어떤 논리적 오류가 있지만, 위의 3가지 예외에 속하지 않는 경우에 사용할 수 있는 범용적인 예외
  - 예시) bitset을 만들 때, 0 또는 1이 아닌 값을 전달하면 invalid_argument 예외 발생

### 런타임 오류
- runtime_error 클래스
- 일반적으로 오버플로우, 언더플로우, 결과가 범위를 벗어나는 경우에 활용
- \<stdexcept> 헤더 파일을 읽어 들여야 함
- runtime_error 클래스의 공용 인터페이스
  ```c++
  explicit runtime_error(const string& whatArg) // 생성자
  virtual const char* what() const throw() // 멤버 함수
  ```
- runtime_error 클래스에서 underflow_eror, overflow_error, range_error라는 클래스가 파생됨
  - 모든 생성자 함수는 같은 매개변수를 받음
  - 모든 파생 클래스에서 what 멤버 함수를 사용할 수 있음(=> 무조건적으로 재정의해서 사용해야 함)
  - 파생 클래스들의 생성자
    |클래스|생성자|
    |--|--|
    |underflow_error|explicit underflow_error(const string& wahtArg)|
    |overflow_error|explicit overflow_error(const string& wahtArg)|
    |range_error|explicit range_error(const string& wahtArg)|

- **underflow_error**
  - 산술 연산을 할 때 발생
  - 다만 산술 연산을 할 때 underflow_error 클래스 자료형의 예외를 발생시키지는 않음
  - 이 예외는 사용자 정의 함수에서 사용자가 언더플로우 발생 가능성이 있는 코드에 활용
- **overflow_error**
  - 산술 연산을 할 때 발생
  - 다만 산술 연산을 할 때 overflow_error 클래스 자료형의 예외를 발생시키지는 않음
  - 이 예외는 사용자 정의 함수에서 사용자가 오버플로우 발생 가능성이 있는 코드에 활용
- **range_error**
  - range_error도 마찬가지임

### 이외의 오류

- **bad_exception**
  - 함수 내부에서 예외 사양에서 지정하지 않은 예외가 throw될 때 발생

- **bad_alloc**
  - \<new> 헤더는 동적 메모리 할당과 관련된 함수들을 제공
  - new 연산자가 어떤 이유로 요청된 메모리를 할당할 수 없는 경우에 bad_alloc 예외가 발생

- **bad_typeid**
  - typeid의 피연산자가 NULL 포인터일 때 발생(코드로 `typeid(*p)에서 p가 널 포인터인 경우)

- **bad_cast**
  - dynamic_cast에 실패할 때 발생

- **failure**
  - \<ios> 헤더 내부에서 입출력과 관련된 예외의 베이스 클래스로 사용
  - ios_base 스코프 내부에 있으므로 ios_base::failure 등의 형태로 사용해야 함
  - failure 클래스의 생성자, 소멸자, 멤버 함수
    ```c++
    explicit failure(const string& mesg) // 생성자
    virtual ~failure()  // 소멸자
    virtual const char* what() const throw() // 멤버 함수
    ```
  - c++의 입출력 클래스는 언어가 예외 처리를 지원하기 전에 만들어짐
  - 이후에 예외 클래스가 언어에 추가된 후, failure 클래스가 예외 클래스 계층에 추가
  - 입출력 조작에서의 예외처리를 위해서 c++는 exception 함수를 추가
    ```c++
    void exception(iostate flags) // 어떤 상태일 때 예외를 발생시킬지 설정하는 함수
    iostate exception const // 예외를 발생시키는 상태를 리턴하는 함수
    ```