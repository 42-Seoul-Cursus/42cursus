# miniRT with sunko

[raytracing in one weekend](https://80000coding.oopy.io/4988ecf3-4d1f-4b94-9068-7872092b981b)와 [mini_raytracing_in_c](https://github.com/GaepoMorningEagles/mini_raytracing_in_c)를 보고 정리

## Raytracing

1. 그 점으로 빛이 얼마나 떨어지는가
2. 그 점에서 표면상의 물체는 어떻게 빛을 반사하는가
3. 카메라가 어디에 있는가

### Khan Academy

Pixar in a Box 내의 Raytracing 강의

점 I가 삼각형 ABC의 내부에 있는지 판단하는 방법은 [삼각형의 무게중심](https://help.autodesk.com/view/3DSMAX/2024/KOR/?guid=GUID-EF593BFC-B7CA-43F8-A752-165C5682035B)을 활용하여 풀 수 있다.
```
점 I를 무게중심으로 정의
I = aA + bB + cC

가중치가 음수라면 점 I는 삼각형 ABC의 외부에 있다.
```

### Vector

`시작지점 + 크기 * 방향` => `P(t) = A + tB;`

시작점, 종점과 상관없이 길이와 방향만 같다면 같은 벡터이다.

## Study resources

- [이득우의 게임 수학](https://www.yes24.com/Product/Goods/107025224)
- [홍정모 그래픽스](https://honglab.co.kr/courses/graphicspt1)
