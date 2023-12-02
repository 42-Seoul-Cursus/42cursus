## ex04

- cpp의 파일 입출력은 [fstream](https://cplusplus.com/reference/fstream/fstream/)를 사용한다.
  - [참고 블로그](https://blockdmask.tistory.com/322)
	```cpp
	// 원래 짰던 코드
	// while (!readFile.eof())
	// {
	// 	std::string s;

	// 	std::getline(readFile, s);
	// 	// s.append("\n");
	// 	writeFile.write(s.c_str(), s.length());
	// }

	char c;
  while (readFile.get(c))  // get 함수로 문자 하나씩 읽어오기
  {
      writeFile.put(c);  // 파일에 문자 하나씩 쓰기
  }
	```
