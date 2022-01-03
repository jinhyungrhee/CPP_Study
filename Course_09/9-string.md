# 문자열

## C문자열

- \<cstring> 헤더 파일에 정의
  |역할|코드 및 방법|
  |--|--|
  |생성자|생성자는 없으며 문자 배열을 생성|
  |소멸자|소멸자는 없으며 힙에 문자 배열을 만들 경우 직접 해제함|
  |복사 생성자|char* strcpy(char* str1, const char* str2), char* strncpy(char* str1, const char* str2, size_t n)|
  |길이 구하기|size_t strlen(const char* str)|
  |입출력|라이브러리에 별도의 입출력 연산자 정의X, 하지만 `>>`와 `<<` 연산자를 사용해서 입출력 가능. 한 줄 전체를 입력받는 경우 istream 클래스의 getline()함수 사용|
  |문자에 접근|별도의 함수X, 첨자 연산자(`[]`) 사용|
  |문자 찾기|char* strchr(const char* str, int c) : 정방향 탐색, char* strrchr(const char* str, int c) : 역방향 탐색|
  |서브 문자열 찾기|char* strstr(const char* str, const char* substr) : 정방향 탐색만 지원|
  |문자들 중에 문자 하나 찾기|char* strpbrk(const char* str, const char* set) : 정방향 탐색만 지원, 구분자 찾기 위한 용도|
  |두 문자열 비교하기|int strcmp(char* str1, const char* str2), int strncmp(char* str1, const char* str2, size_t n) : 완전히 동일하면 0 출력|
  |결합하기|char* strcat(char* str1, const char* str2), char* strncat(char* str1, const char* str2, size_t n)|
  |토큰화|char* strtok(char* str, const char* delimit)|

- C 문자열
  - 클래스 자료형이 아님
    - C는 절차지향 언어임
    - 라이브러리에 생성자가 정의되어 있지 않음
  - C 문자열을 구성하려면 문자 배열을 만ㄷ르고, 마지막 요소를 널 문자('\0')로 설정
  - 구분
    - 상수가 아닌 문자열(nonconstant string)
      - 처음에 초기화했던 문자열을 변경할 수 있음
    - 상수 문자열(constant string)
      - 처음에 초기화될 때 정해준 문자열을 변경할 수 없음
      ```c
      // 초기화
      char str[] = {'A', 'B', 'C', 'D', '\0'};        // non-constant (문자 배열을 만들어서 c 문자열을 정의, null문자 추가 필요! )
      char str[] = "ABCD";                            // non-constant compact (문자열을 큰 따옴표로 감싸는 형태로 정의, 자동으로 null문자 추가됨!)
      const char str[] = {'A', 'B', 'C', 'D', '\0'};  // constant
      const char  str[] = "ABCD";                     // constant compact
      ```
  - 생성된 `문자열의 이름`은 변수가 아니라 `rvalue 포인터`임!
  - `큰 따옴표로 감싸진 글자`를 생성하는 것이 바로 `문자열 리터럴`임!
    - 이렇게 만들어진 문자열은 C++에서 `C문자열 리터럴`과 `C++문자열 리터럴` 모두를 나타냄!
    - 문자열 리터럴은 `상수 엔티티`이므로 **한 번 생성된 이후에는 변경할 수 없음!**
    - 문자열 리터럴을 만들고 이를 `상수 포인터`에 할당해서 간단하게 C 문자열을 만들 수 있음!
      - 상수 포인터가 아닌 포인터에 할당하면 컴파일 오류 발생
      - C++는 문자열 리터럴을 상수가 아닌 포인터에 할당하는 것을 금지하고 있음
        ```c++
        char* str = "Hello";       // Error
        const char* str = "Hello"; // OK
        ```
  - **간단한 형태의 초기화**와 **문자열 리터럴**
    - 둘을 구분해서 사용해야 함
    - `간단한 형태의 문자열 초기화`
      - char 자료형의 배열을 간단하게 만드는 것
      - 컴파일러가 배열의 요소를 하나하나 복사해서 문자 배열에 옮기게 됨
    - `문자열 리터럴`
      - 문자열을 사용할 수 있는 모든 곳에 사용할 수 있는 상수 문자열
      - 메모리에 올라간 문자열에 대한 포인터
    ```c++
    char str1[] = "Hello";        // 간단한 형태의 문자열 초기화
    const char str2[] = "Hello";  // 간단한 형태의 문자열 초기화
    const char* str3 = "Hello";   // 문자열 리터럴
    ```
  - 힙 메모리에 생성
    - C문자열은 배열이므로 힙 메모리 위에도 생성할 수 있음
    - 문자열의 이름은 char 자료형에 대한 포인터이므로, 간단한 형태의 초기화 구문을 사용할 수 없음!
      - 문자열이 상수 문자열이 아니라면, 문자 하나하나 초기화해주어야 함
      - 문자열이 상수 문자열이라면, 문자열 리터럴을 사용해서 초기화 가능
      ```c++
      char* str = new char[3];       // 상수가 아닌 두 개의 문자 생성
      const char* str = new char[3]; // 상수인 두 개의 문자 생성
      ```
    - 삭제
      - C 문자열이 힙 메모리에 올라갔다면, delete 구문을 사용하여 삭제
      ```c++
      const char* str = new char[3]; // 생성
      delete[] str;                  // 삭제(포인터 넘겨줌)
      ```
  - 문자열의 길이
    - null문자를 제외한 문자열의 문자 수
    - strlen() 함수 사용
      - C문자열을 매개변수로 받고, size_t 자료형을 리턴
      - size_t는 라이브러리 내부에서 부호없는 정수를 나타냄
      ```c++
      size_t n = strlen(str);
      ```
  - 문자열의 입출력
    - 문자 배열로 선언도니 C문자열로 문자를 읽어들일 수 있음
    - 컴파일러가 문자를 읽어들이기 전에 메모리를 할당해야 하므로 크기를 미리 알고 있어야 함
    - **오버로드한 추출연산자와 삽입연산자**
      - \<cstring> 라이브러리에는 추출연산자(>>)와 삽입연산자(<<)가 오버로드되어 있어서 문자열을 입력/출력 가능(정수, 실수, 문자, 문자열 모두 처리 가능)
        - 추출연산자(>>)
          - 입력 객체(키보드 또는 파일)에서 문자를 하나씩 추출해서 **공백이 나타날 때까지** 배열에 저장. 그리고 뒤에 널 문자 추가
        - 삽입연산자(<<)
          - **널 문자 전까지의 문자**를 출력 객체(모니터 또는 파일)에 출력
        ```c++
        cin >> str; // input
        cout << str; // output
        ```
    - 공백을 포함한 한 줄을 모두 읽어들이고 싶은 경우 : `getline()` 사용
      - getline()은 istream 클래스의 멤버 함수
      - cin 객체 내부에 있음
      - delimeter 매개변수를 입력하지 않으면 자동적으로 '\n' 문자까지만 읽어들여서 한 줄만 읽어 들이게 됨
      ```c++
      cin.getline(str, n);              // '\n'을 delimiter로 사용
      cin.getline(str, n, 'delimiter')  // delimter를 직접 지정하여 사용
      ```
  - 문자열 내부에서 **문자** 탐색 : `strchr()`, `strrchr()` 사용
    - 문자가 처음 등장하는 위치를 포인터로 리턴
    - 탐색하지 못한 경우 널 포인터를 리턴
    ```c++
    char* ptr = strchr(str, 'c');  // 정방향 탐색
    char* ptr = strrchr(str, 'c'); // 뒤에서부터 탐색
    ```
  - 문자열 내부에서 **문자열** 탐색 : `strstr()` 사용
    - 시작 위치에 대한 포인터를 리턴
    - 탐색하지 못한 경우 널 포인터를 리턴
    ```c++
    char* ptr = strstr(str, substr);
    ```
  - 문자들 중 특정 문자의 위치를 탐색 : `strpbrk()` 사용
    - 위치에 대한 포인터를 리턴
    - 탐색하지 못한 경우 널 포인터를 리턴
    - 문자열 토큰화에 사용됨
    ```c++
    char* p = strpbrk(str, "abcd"); // 문자열에서 a나 b나 c나 d가 있으면 해당 위치 리턴(가장 먼저 찾은 것)
    ```
  - 문자열의 비교 : `strcmp()`와 `strncmp()` 사용
    - strcmp는 문자열 전체를 비교
    - strncmp는 두 문자열의 앞의 n개 문자만 비교
    - 동일하지 않은 문자에 도달할 때까지 문자 단위로 하나하나 비교
    - 널 문자까지도 비교
    - 두 문자열이 같은 경우
      - 0 리턴
    - 두 문자열이 다른 경우
      - 첫 번째 문자열의 문자가 크면, 양의 정수 리턴
      - 두 번째 문자열의 문자가 크면, 음의 정수 리턴
    ```c++
    int value = strcmp(str1, str2);
    int value = strncmp(str1, str2, n);
    ```
  - 문자열의 결합 : `strcat()`과 `strncat()` 사용
    ```c++
    strcat(str1, str2)
    strncat(str1, str2, n)
    ```
    - str1뒤에 str2가 연결됨(str1만 변경됨)
    - str1에 결합을 위한 충분한 메모리 공간이 있어야 함
  - **문자열의 토큰화** : `strtok()` 사용
    - '문자열 토큰'은 문자열을 구분 기호(공백 등)로 잘라 만들어진 작은 문자열을 의미
    - 문자열을 구분 기호로 모두 잘라서 문자열 토큰을 만드려면 strtok()함수를 여러 번 반복해서 사용해야 함!(null을 만나기 전까지!)
    - strtok함수
      - ① 구분 기호가 아닌 문자 중에서 처음 등장하는 문자를 찾아서 포인터를 리턴. 찾을 수 없는 경우에는 아무 것도 하지 않음!
      - ② 이어서 구분 기호를 찾음. 구분 기호를 찾으면, 해당 문자를 널 문자로 변경 
      - ③ 이 과정을 끝나는 조건인 null 문자를 만날 때까지 반복처리
      - 첫 번째 호출
        - **str**을 매개변수로 넣어줌
        ```c++
        p = strtok(str, delimit);
        ```
      - 이후의 호출
        - str대신 **0**을 매개변수로 넣어줌(현재 위치에서부터 새롭게 다시 찾으라는 의미!)
        ```c++
        p = strtok(0, delimit);
        ```

## C++ 문자열
- C++ 라이브러리는 string 클래스 제공
- string 클래스는 C문자열과 구분하기 위해 `C++ 문자열 객체`라고 부름
  - C++문자열은 `string 클래스를 객체화`하여 사용
  - C++문자열은 클래스 자료형이며, \<string>라이브러리에 있는 멤버함수를 활용함
  - C문자열은 문자의 배열이며, \<cstring>라이브러리에 정의된 함수를 활용함
- 기본적인 설계
  - string 클래스에는 private 데이터 멤버와 public 멤버 함수가 있음
  - 사용자는 public 멤버 함수를 호출해서 문자열 객체를 조작
  - '데이터 멤버'로는 `문자 배열에 대한 포인터`와 `문자 배열과 관련된 정보`가 있음
  - 데이터 멤버는 일반적으로 스택 메모리에 할당되지만, 문자열은 런타임 이전에 크기를 알 수 없으므로 문자 배열을 힙 메모리에 할당함
    - 문자열의 시작 주소는 스택 메모리에 저장됨
  - C++ 문자열은 null 문자로 끝나지 않음
- 메타 자료형과 상수
  - 두 식별자는 std::string 이름 공간 안에 정의되어 있음(::-클래스 스코프 연산자)
  - 프로그램에서 사용할 때는, 이름 공간을 앞에 붙여줘야 함
    ```c++
    string::size_type length;
    string::npos; // non position - 찾는 것이 없을 때 사용
    ``` 
    - **size_type**은 'unsigned int' 자료형
      - 문자열의 크기는 항상 양수여야하므로 음의 정수가 되는 것을 막기 위해 부호 없는 정수로 정의
      - size_type은 2가지 목적으로 사용됨
        - ① 문자열의 인덱스
        - ② 문자의 수
    - 상수 **npos**는 size_type 자료형이며 -1로 설정
      - npos는 존재하지 않는 인덱스를 나타낼 때 사용
      - `static const size_type npos = -1;`
        - 예시) '안녕하세요'에서 '안'을 찾으면 0번째 인덱스에 '안'이 있고, '가'를 찾으면 존재하지 않음
          - 이를 "`npos번째` 인덱스에 있다(= 존재하지 않는다)"라고 표현!
- C++문자열 관련 라이브러리
  |역할|코드 및 방법|
  |--|--|
  |생성자|string::string()|
  ||string::string(size_type count, char c)|
  ||string::string(const char* cstr)|
  ||string::string(const char* cstr, size_type count)|
  |소멸자|string::~string()|
  |복사생성자|string::string(const string& strg)|
  ||string::string(const string& strg, size_type index, size_type length=npos)|
  |크기와 용적|size_type string::size() const|
  ||size_type string::max_size() const|
  ||void string::resize(size_type n, char c)|
  ||size_type string::capacity() const|
  ||void string::reserve(size_type n = 0)|
  ||bool string::empty() const|
  |입출력|istream& operator>>(istream& in, string& strg)|
  ||ostream& operator<<(ostream& out, const string& strg)|
  ||istream& getline(istream& in, string& strg)|
  ||istream& getline(istream& in, string& strg, char delimit)|
  |특정 위치의 문자에 접근|const char& string::operator[](size_type pos)const|
  ||char& string::operator[](size_type pos)|
  ||const char& string::at(size_type pos)const|
  ||char& string::at(size_type pos)|
  |첫 번째 문자의 위치와 길이를 지정하여 서브 문자열을 추출|string string::substr(size_type pos = 0, size_type length = npos)const|
  |문자의 위치 탐색(정방향 탐색과 역방향 탐색)|size_type string::find(char c, size_type index = 0)const|
  ||size_type string::rfind(char c, size_type index = npos)const|
  |문자 집합에 있는 문자 하나의 위치 탐색(정방향과 역방향 탐색)|size_type string::find_first_of(const string& temp, size_type pos = 0)|
  ||size_type string::find_last_of(const string& temp, size_type pos = npos)|
  |문자 집합에 없는 문자 하나의 위치 탐색(정방향 탐색과 역방향 탐색)|size_type string::find_first_not_of(const string& temp, size_type pos = 0)|
  ||size_type string::find_last_not_of(const string& temp, size_type pos = npos)|
  |두 문자열 비교|int string::compare(size_type pos1, size_type n1, const string strg2, size_type pos2, size_type n2)const|
  ||int string::compare(size_type pos1, size_type n1, const char* cstr, size_type n2)const|
  |두 문자열을 비교하는 연산자(<,<=,>,>=,==,!=)|bool string::operatorOper(const string strg1, const string strg2)|
  ||bool string::operatorOper(const string strg1, const char* cstr)|
  ||bool string::operatorOper(const char* cstr, const string strg1)|
  |문자열 뒤에 문자 추가|void string::push_back(char c)|
  |문자열을 조작(뒤에 추가, 삽입, 대체, 할당)|string& string::append(const string& temp)|
  ||string& string::insert(size_type pos, const string& temp)|
  ||string& string::replace(size_type pos, const string& temp)|
  ||string& string::assign(size_type pos, size_type n, const string& temp)|
  |문자열 삭제|void string::clear()|
  ||string& string::erase(size_type pos = 0, size_type n = npos)|
  |할당 연산자|string& string::operator=(const string& strg)|
  ||string& string::operator=(const char* cstr)|
  ||string& string::operator=(char c)|
  |복합 할당 연산자(결합)|string& string::operator+=(const string& strg)|
  ||string& string::operator+=(const char* cstr)|
  ||string& string::operator+=(char c)|
  |결합 연산자|string& string::operator+(const string& strg1, const string& strg2)|
  ||string& string::operator+(const string& strg1, const char* cstr2)|
  ||string& string::operator+(constr char* cstr1, const string& strg2)|
  ||string& string::operator+(const string& strg1, char c)|
  |문자 배열로 변환|const char* string::data()const|
  |C문자열로 변환|const char* string::c_str()const|

- C++ 문자열의 생성자와 소멸자
  - 기본 생성자
    - 포인터 데이터 멤버를 0(널 포인터)으로 초기화해서 빈 문자열로 생성
    ```c++
    string strg;
    ```
  - 매개변수가 있는 생성자
    - 3가지 존재
    ```c++
    string strg1(5, 'a') // "aaaaa"
    string strg2("hello") // "hello"
    string strg3("hello", 2) // "he"
    ```
  - 복사 생성자
    - 전체 복사 / 일부분 복사
    ```c++
    string strg(oldStrg); // 전체 복사
    string strg(oldStrg, index, length); // 일부분 복사
    ```
  - 소멸자
    - 힙에 생성된 문자 배열을 모두 제거하고, 스택에 할당된 모든 데이터 멤버도 제거
    - delete 연산자를 호출하는 것만으로도 메모리 누수를 막을 수 있음

- C++ 문자열의 크기와 용적
  - 문자열 연산에 따라 배열의 크기를 줄여야 하는 경우와 배열의 크기를 늘려야 하는 경우, 이러한 처리들이 내부적으로 이루어짐
  - 크기와 최대 크기
    - 문자열 크기를 리턴하는 함수 : `size()`, `max_size()`
    ```c++
    size_type n = strg.size();
    size_type n = strg.max_size();

    // 예시
    string str = "안녕하세요";
    cout << "str의 길이: " << str.size(); // str의 길이: 15 ('한글'은 한 글자당 3bytes의 크기를 가짐 - 시스템에 따라 달라질 수 있음)
    ```
  - 크기 변경(리사이징) : `resize()`
    - n < size라면 문자열의 뒷부분이 삭제되어 크기를 맞추고, n > size라면 추가되는 부분이 다음코드에서 'c'로 채워져서 크기를 맞춤
    ```c++
    strg.resize(n, 'c')
    ```
  - 용적과 예약 : `capacity()`와 `reserve()`
    - capacity() : 문자열의 현재 용적을 리턴
      - 추가적인 예약이 없다면, 용적은 크기와 동일
    - reserve() : 용적을 추가로 예약 가능
    ```c++
    size_type n = strg.capacity();
    strg.reserve(n);
    ```
  - 빈 문자열 확인하기 : `empty()`
    - 문자열의 크기가 0이면 true를 리턴하고, 그렇지 않으면 false 리턴
    ```c++
    bool fact = strg.empty();
    ```
- C++ 문자열의 입출력
  - 입출력 연산자
    - 기본자료형을 출력할 때 사용했던 연산자들은 '입력 객체(istream)'와 '출력 객체(ostream)'가 있는 멤버 함수
    - 입력 연산자(>>)는 입력 스트림에서 공백을 만나기 전까지 문자를 하나하나 읽어 들임
      - 즉 띄어쓰기 또는 줄바꿈 등이 있으면 읽기 중단
    - 출력 연산자(<<)는 문자열 전체를 출력 스트림에 출력(write)
      - 별도의 제한이 없음
    ```c++
    cin >> strg;
    cout << strg;
    ```
  - getline 함수
    - 특정 구분 기호를 사용해서 입력을 읽는 것을 멈추게 하는 등 추가적인 제어를 하고 싶은 경우 istream 객체의 getline() 사용
    ```c++
    getline(cin, strg);      // '\n'까지 읽어들임
    getline(cin, strg, 'c'); // 'c(원하는 기호)'까지 읽어들임 (작은 따옴표 사용)
    ```
- C++ 문자열의 접근과 출력
  - `[]`를 통해 인덱스로 접근
  - `.at()`을 통해 매개변수로 접근
  ```c++
  char c = strg[pos];
  char c = strg.at(pos);
  const char c = strg[pos];
  const char c = strg.at(pos);
  ```
- C++ 문자열의 서브 문자열 추출 : `subtr()`
  - 첫 번째 매개변수 : 인덱스(위치)
  - 두 번째 매개변수 : 문자 수(길이)
  - 매개변수를 하나만 지정하면, 해당 위치(인덱스)부터 끝까지 추출해서 리턴
  ```c++
  string result = strg.substr(pos, n);
  ```

- C++ 문자열의 탐색 : `find()`와 `rfind()`
  - 두 번째 인덱스를 지정하지 않으면, 정방향 탐색에서는 디폴트로 0, 역방향 탐색에서는 디폴트로 npos가 들어감
  - 탐색에 성공하면 문자의 인덱스를 리턴, 탐색에 실패하면 npos(-1) 리턴
  - 두 함수 모두 부호 없는 정수(size_type)를 리턴
  - npos의 값은 -1이므로 언더플로우가 발생하여 매우 큰 정수(max_integer-1)값을 리턴함
  ```c++
  //정방향
  size_type pos = strg.find(c, index); // c는 '찾을 문자', index는 '탐색 시작 인덱스'
  //역방향
  size_type pos = strg.rfind(c, index); // c는 '찾을 문자', index는 '탐색 시작 인덱스'
  ```
  - 여러 문자 탐색하기 : `find_firsst_of()`, `find_last_of()`, `find_first_not_of()`, `find_last_not_of()`
    - 여러 문자 중에 하나가 존재하는지 탐색하는 경우
    ```c++
    size_type pos = strg.find_first_of(set, index); // set은 여러 개의 문자의 집합(문자열)
    size_type pos = strg.find_last_of(set, index);  // 역방향
    size_type pos = strg.find_first_not_of(set, index); // set이 없는 것 찾음
    size_type pos = strg.find_last_not_of(set, index); // 역방향
    ```
  - 토큰화
    - 탐색 기능을 사용해서 서브 문자열의 시작 위치(wStart)와 끝 위치(wEnd)를 찾으면 문자열에서 서브 문자열을 추출할 수 있음

- C++ 문자열의 비교
  - ① `함수`를 사용한 비교
    - 호스트 문자열을 다른 C++문자열과 비교
    - 호스트 문자열을 C문자열과 비교
      - C문자열은 단순하게 앞부터 비교하므로 매개변수 pos를 지정하는 부분이 없음
    ```c++
    int result = strg.compare(pos1, n1, strg2, pos2, n2); // strg(원본)과 strg2를 비교
    int result = strg.compare(pos1, n1, str, n2); // strg(원본, C++)과 str(C)를 비교
    ```
    - 같은 경우 0 리턴
    - 첫 번째 문자열의 문자가 크면 양의 정수 리턴
    - 두 번째 문자열의 문자가 크면 음의 정수 리턴
  - ② `연산자`를 사용한 비교
    - 결과 값이 불 자료형(true나 false)로 리턴
    - 연산자를 사용한 비교에서는 서브 문자열 비교를 따로 할 수 없음
      - 함수를 통해 비교하거나, 서브 문자열을 만든 뒤에 비교해야 함
      - oper는 <, <=, >, >=, ==, != 등의 연산자
      - 두 비교 대상이 모두 c 문자열이라면 단순 포인터 비교(내용이 아닌 포인터의 주소값이 비교됨)
        - **둘 중 하나라도 c++ 문자열이어야 정상적인 비교 가능!**
      ```c++
      bool result = strg1 oper strg2;
      bool result = strg oper str; // strg(c++ 객체) vs str(c 문자열) -> 비교 가능
      bool result = str oper strg; // 비교 가능
      ```

- C++ 문자열 추가, 연산 제거
  - 문자열 뒤에 추가
    - C++ 문자열 라이브러리는 push_back() 함수 제공
    ```c++
    strg.push_back(c);
    ```
  - 수정 연산
    - C++ 문자열 라이브러리에서 수정 연산을 위한 함수들 제공
    - 임시 문자열
      ```c++
      temp(strg);           // 완벽한 C++문자열 생성
      temp(strg, pos2, n2); // C++문자열의 일부분 생성
      temp(1, c);           // 문자열에서 하나의 문자로 만듦
      temp(cstr);           // C++문자열을 C문자열로 생성
      temp(cstr, n);        // 처음부터 n까지의 C문자열로 생성
      ```
    - 연산을 하는 멤버함수
      ```c++
      strg.append(temp);            // append
      strg.insert(pos1, temp);      // insert
      strg.replace(pos1, n1, temp); // replace
      strg.assign(temp);            // assign
      ```
    - 전체 제거와 부분 제거
      - 문자열 전체 또는 문자열의 일부를 제거하고 싶은 경우 사용하는 함수(문자열 완전 소멸X, 객체 자체는 유지)
      ```c++
      strg.clear();       // 문자열 전체 제거 -> 빈 문자열(공백)을 갖는 객체
      strg.erase(pos, n); // 문자열 일부 제거
      ```

- C++ 문자열의 연산자 오버로드와 변환
  - 일부 연산은 연산자 오버로드를 사용한 멤버 함수로 사용 가능
  - c++ 문자열은 할당 연산자(=), 복합 할당 연산자(+=), 더하기 연산자(+)가 오버로드되어 있음
  - 예시) temp, temp1, temp2는 모두 문자열 클래스의 객체
    ```c++
    string strg = temp;           // 할당 연산
    string strg += temp;          // 복합 할당 연산
    string strg = temp1 + temp2;  // 더하기 연산
    ```

- C++ 문자열 변환
  ```c++
  const char* arr = strg.data(); // 문자 배열로 변환
  const char* str = strg.c_str(); // C 문자열로 변환
  ```