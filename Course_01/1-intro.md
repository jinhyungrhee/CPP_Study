# CPP Course-01

## 변수, 값, 상수

### 값
- cin 객체와 cout 객체
  - **입력**의 경우 데이터가 오른쪽으로 이동, **출력**의 경우 데이터가 왼쪽으로 이동
  - cin(console in)객체는 변수의 이름을 알아야 하며, cout(console out)객체는 값을 알아야 함
    - `cin >> 변수;`
    - `cout << 값;`

### 상수

- 상수는 값을 변경할 수 없는 저장소 엔티티이며 값은 언제나 고정적
- 상수를 선언하려면 const라는 한정자와 이름을 지정한 뒤, 할당 연산자를 입력하고 저장할 값을 지정
  - `const double PI = 3.14159;`

## 토큰과 주석

### 토큰

- 컴파일러가 읽어 들여서 실행 가능한 프로그램을 만들 때 활용하는 코드

- 식별자
  - C++ 프로그래밍 언어는 엔티티의 이름을 식별자 identifier라고 함
  - 식별자는 반드시 기호 또는 글자(숫자가 아닌 것)나 언더스코어(_)로 시작
  - 키워드, 미리 정의된 식별자, 사용자 정의 식별자로 구분

- 키워드
  - 키워드(keyword 또는 예약어)는 C++ 프로그래밍 언어에서 미리 예약된 식별자
    |-|-|-|-|-|
    |--|--|--|--|--|
    |alignas|alignof|and|and_eq|asm|
    |auto|bitand|bitor|bool|break|
    |case|catch|char|char16_t|char32_t|
    |class|compl|const|const_cast|constexpr|
    |continue|decltype|default|delete|do|
    |double|dynamic_cast|else|enum|explicit|
    |export|extern|false|float|for|
    |friend|goto|if|inline|int|
    |long|mutable|namespace|new|noexcept|
    |not|not_eq|nullptr|operator|or|
    |or_eq|private|protected|public|register|
    |reinterpert_cast|return|short|signed|sizeof|
    |static|static_assert|static_cast|struct|switch|
    |template|this|thread_local|throw|true|
    |try|typedef|typeid|typename|union|
    |unsigned|using|virtual|void|volatile|
    |wchar_t|while|xor|xor_eq|

- 리터럴
  - 자료형을 가진 상수 값을 의미

- 심볼
  - C++은 알파벳이 아닌 기호들을 연산자와 문장 부호로 사용

## 자료형

### 정수 자료형

|자료형|부호|범위|
|--|--|--|
|short int|부호 있음|-32,768 ~ + 32,767|
|short int|부호 없음(unsigned)|0 ~ 65,536|
|int|부호 있음|-2,147,483,648 ~ +2,147,483,647|
|int|부호 없음(unsigned)|0 ~ 4,294,967,295|
|long int|부호 있음|-2,147,483,648 ~ +2,147,483,647|
|long int|부호 없음(unsigned)|0 ~ 4,294,967,295|

- 정수 변수
  - 생략하지 않은 형태
    ```
    unsigned short int first;
    signed short int seconde;
    unsigned int third;
    signed int fourth;
    unsigned long int fifth;
    signed long int six;
    ```
  - 생략한 형태
    ```
    unsigned short first;
    short seconde;
    unsigned int third;
    int fourth;
    unsigned long fifth;
    long six;
    ```

- 리터럴
  - 프로그램에서 어떤 자료형의 값을 고정하여 사용할 때 리터럴이라고 함.
  - 정수 리터럴
    - 상수 값을 가짐
    - 변수를 초기화할 때 사용
    - 독립적인 값으로 사용하여 계산에 활용할 때 사용
    - 정수 리터럴의 크기와 부호를 명시적으로 지정하는 접미사
      |크기|접미사|부호|접미사|
      |--|--|--|--|
      |int|없음|signed int 또는 signed long|없음|
      |long|l 또는 L|unsigned long 또는 unsigned long|u 또는 U|

### 문자 자료형

- 문자 자료형의 크기는 1바이트의 부호가 없는 것
- 문자 변수는 문자 자료형을 나타내는 char로 변수를 정의

- 문자 리터럴
  - ASCII 테이블에 정의된 글자를 작은 따옴표 안에 넣어 사용
    - `char first = 'A';`
  - ASCII 테이블에 정의된 정수 값을 사용
    - `char fourth = 66;`

- 이스케이프 문자
  |문자|설명|
  |--|--|
  |`\n`|줄바꿈 문자(라인 피드이며 현재 위치에서 바로 아래로 이동)|
  |`\t`|탭문자|
  |`\b`|백스페이스|
  |`\r`|캐리지 리턴(커서의 위치를 앞으로 이동)|
  |`\f`|폼 피드(다음 페이지로 넘기기)|
  |`\'`|작은 따옴표|
  |`\"`|큰 따옴표|
  |`\\`|역 슬래시|

  - 예시
    ```
    cout << "Buenos dias  \bamigos." << endl;
    cout << "Hello\rBonjour mes amis." << endl;\

    // 출력 결과
    Buenos dias amigos. // '\b'는 이전 글자를 삭제(띄어쓰기 하나 삭제)
    Bonjour mes amis.   // '\r'은 줄의 앞부분으로 커서를 옮기고 다시 입력(따라서 앞의 내용이 삭제됨)
    ```

### 부동 소수점 자료형

- C++에서는 소수점을 갖는 숫자를 부동 소수점(floating point)라고 함
- 계산을 더 효율적으로 할 수 있게 C++은 float, double, long double이라는 3가지 종류의 부동 소수점을 정의
- 부동 소수점은 모두 부호가 있는 숫자
- 정밀도 : `float <= double <= long double`
- 부동 소수점 변수
  - 정수 변수를 선언할 때와 같은 방법으로 정의
  - 선언하면서 어떤 값으로 초기화할 수도 있고, 이후에 다른 값으로 할당도 가능
- 부동 소수점 리터럴
  - 23.738, 141.123, -2472.657처럼 소수점을 가진 숫자로 생성
  - 부동 소수점 리터럴은 `double`로 기본 선언(default)
  - 리터럴의 크기를 정의하는 접미사
    |부동 소수점 자료형|접미사|예|
    |--|--|--|
    |float|f 또는 F| 12.23F, 12345.45F, -1436F|
    |double|없음|1425.36, 1234.34, 123454|
    |long double|l 또는 L|2456.23L, 143679.00004L, -0.02345L|

### void 자료형

- '값이 없음'을 나타내는 특별한 자료형
- 유용한 자료형으로 '함수가 어떠한 값도 결과로 내지 않는다'등을 명시할 때 사용

### 문자열 자료형

- 문자열은 C언어로부터 이어진 자료형으로 Null 문자로 끝나는 문자의 집합
  - "John" → 'J', 'o', 'h', 'n', '\0' ('\0'는 Null문자 = 종료 문자)
- C++ 문자열을 사용하려면 \<string> 헤더파일을 읽어 들어야 함
  - `#include <string>`
- string 자료형 선언
  - `string name;`