# 참조

- 참조(reference)는 객체의 또 다른 이름(별칭)
- C++에서 추가된 기능으로, 함수 등의 엔티티끼리 커뮤니케이션(매개변수로 전달하고 리턴받는 행위)하는 것을 쉽게 만들어줌
- `참조 변수(reference variable)`는 일반적인 변수와 다르게 메모리 위에 새로운 영역을 잡지 않음
  - 기존에 있던 변수와 연결(바인딩)해서, 기존에 있던 변수에 새로운 이름을 붙여주는 것!
  - 따라서 원본 변수가 있어야만 생성할 수 있음
- 예시
  ```c++
  int score = 92;
  int& rScore = score; // 참조 자료형 변수 rScore에 연결(같은 자료형으로 선언한 뒤 & 붙임!)
  ```
- 참조 자료형
  - `int&`, `double&`, `bool&` 등
  - 변수를 참조 변수와 연결할 때는 반드시 '변수의 자료형'과 '참조 변수가 나타내는 자료형'이 일치해야 함
    ```c++
    int num = 100;
    double& rNum = num; // 오류 발생
    ```
- 참조 관계
  - 참조 관계는 스코프를 벗어나서 변수가 파괴되기 전까지는 계속해서 유지됨
    - 한 번 정의되면 변경할 수 없음
  - 변수와 참조 변수가 연결된 관계를 `constant relation(= 영구적인 관계)`이라고 함
  - 예시1) 참조 관계를 변경하려고 하면 컴파일 오류 발생
    ```c++
    int score = 92;
    int& rScore = score;
    int num = 80;
    int& rScore = num; // 새로운 변수와 참조 관계를 다시 맺는 것 불가. 컴파일 에러
    ```
    - 하나의 원본에 대해 참조 변수를 여러 개 만드는 것은 가능하지만, 참조 변수에 대해 여러 개의 원본이 붙을 수는 없음
  - 예시2) 참조 관계를 깨지 않는 예시
    ```c++
    int score = 92;
    int& rScore = score;
    int num = 80;
    rScore = num; // 해당 메모리 위치(score)에 num값(80)을 넣은 것. 참조 연결 X.
    ```
    - 공유하고 있는 메모리 위치에 num 값을 넣은 것임 (참조 연결을 하는 것 X)
    - rScore은 score의 별칭이므로, `rScore = num`은 `score = num`과 같은 기능을 함
  - **참조 다중성**
    - 하나의 변수를 기반으로 여러 개의 참조 변수를 만들 수 잇지만, 반대는 불가능
    - 참조 변수 하나를 여러 변수에 연결할 수 없음
    - 예시) 하나의 변수를 기반으로 여러 개의 참조 변수 만들기
      ```c++
      int num = 100;
      num& rNum1 = num;
      num& rNum2 = num;
      num& rNum3 = num;
      ```
      - 같은 메모리 위치에 4개의 이름이 붙는 것!
- 값 추출
  - 참조 관계가 만들어지면, 원본 변수와 참조 변수 중 아무거나 사용해도 값에 접근하여 값을 추출할 수 있음
- 값 변경
  - 참조 관계가 만들어지면, 데이터 변수 또를 참조 변수를 사용해서 원본 값을 변경할 수 있지만 원본 변수에 `const`가 붙으면 값 변경 불가
    ```c++
    const int score = 92;
    const int& rScore = score; // 값 읽기만 가능. 변경 불가
    ```
- 참조의 활용
  - 참조로 전달(pass-by-reference)
    - 기본 자료형 등의 크기가 작은 자료형을 복사할 때는 pass-by-value가 큰 문제가 없지만, 클래스 자료형처럼 크기가 큰 자료형을 복사할 때는 pass-by-reference/pointer를 사용하는 것이 좋음
      - 복사 비용이 들지 않음!
      - 복사 생성자에서 '참조로 전달' 방식 사용
    - 주의
      - '참조로 전달'을 사용할 때 매개변수에 직접적인 값을 지정할 수 없음
        - 오류 발생!
        - 변수를 매개변수로 넣어야 함!
  - 참조로 리턴(return-by-reference)
    - 호출된 함수에서 호출한 함수 쪽으로 '객체를 리턴'할 때 사용
      ```c++
      type& function(...);
      ```
    - 복사 비용은 없지만, 일반적인 매개변수와 지역 변수의 값을 리턴할 수 없음
      - 일반 매개변수와 지역 변수의 경우, 해당 함수가 종료되면 메모리에서 사라짐!
      - `참조 매개변수`와 `정적 지역 변수`는 함수가 종료되어도 파괴되지 않으므로 리턴 가능함!