# Semi-Active-Suspension
Semi Active suspension Controller simulation in half car model

1. half car model(해당 모델을 선정한 이유)

차량 동역학에서 서스펜션 컨트롤러의 성능을 검증하기 위해 자주 사용되는 기존의 2자유도 모델(quater car model)은 하나의 서스펜션을 검증하기위해 사용된다. 4자유도 모델(half car model)은 기존의 2자유도 모델을 확장하여 4자유도(two wheels)를 구성하며 그에 따라 4개의 미분 방정식을 필요로 한다. 확장 됨에 따라 검증할 수 있는 요소도 추가되었다. 2자유도 모델의 경우 wheel의 변위와 sprung mass의 변위만을 해석할 수 있었지만 4자유도에서는 기존의 항목에서 sprung mass(body)의 pitch angle과 추가된 wheel의 변위에 대한 해석이 가능하다. 기존의 2자유도 모델에 비해 다양하게 해석 할 수 있다고 생각하여 half car model을 선정하여 controller의 성능을 검증하기로 했다.

![half_model](https://user-images.githubusercontent.com/79674592/110109504-e73ba180-7df0-11eb-8527-68f398297bbd.jpg)

2. equilibrium of force(방정식)

방정식의 스프링상수(k)와 댐퍼 상수(c)는 다음과 같이 정의할 수 있다.

![상수](https://user-images.githubusercontent.com/79674592/110110283-ee16e400-7df1-11eb-91d1-d36bea8d730a.PNG)

시스템의 4개의 미분 방정식은 두개의 자유도(sprung mass,wheels)에서 도출 할 수 있다. sprung mass에 해당하는 미분방정식은 전륜과 후륜의 서스펜션과 sprung mass의 영향을 받는다. sprung mass의 자유물체도는 아래와 같다.
![chassis_accels](https://user-images.githubusercontent.com/79674592/110110689-8f059f00-7df2-11eb-9b65-bda2947112a2.jpg)
![캡처](https://user-images.githubusercontent.com/79674592/110780347-f2d31080-82a7-11eb-870f-555dbfe8fea6.PNG)

sprung mass에서 2개의 방정식을 도출 할 수 있는데 하나는 수직방향 힘의 해석이고 다른 하나는 모멘트의 해석이다. 먼저 힘의 해석을 보면 위에서 구한 상수값의 분모를 소거시켜주기위해 스프링상수의 경우 수직변위의 차를 곱해주고 뎀퍼상수의 경우 상대속도의 차이를 곱해준다. 이 때 질량 중심점과 휠간의 거리에 의해 발생하는 변위는 전륜의 경우(+), 후륜의 경우(-)를 띄는데(좌변 이항시) 이는 요철을 만났을 때 전륜의 경우 힘이 z방향으로 가해질 것이고 힘의 평형의 법칙에 따라 후륜의 경우 z반대 방향으로 작용하기 때문에 lf(theta)와 lr(theta)의 방향은 반대가 된다. 
두번 째는 모멘트(토크)에 관한 해석이다. 모멘트의 경우 힘과 거리의 곱으로 표현 할 수 있기 때문에 위와 같이 나타낼 수 있다. theta의 경우 아주 작은 크기이므로 sin(theta)를 theta로 근사화 한다.
![wheel_accels](https://user-images.githubusercontent.com/79674592/110113373-5f589600-7df6-11eb-898c-89bc3fbe1df2.jpg)
각각의 휠은 위와 같은 자유물체도에 의해 2개의 미분방정식을 도출할 수 있다. kfs와 cfs가 음수인 이유(좌변 이항시)는 sprung mass가 고정되어 있다고 가정한 경우(강체) 전륜이 요철을 만나면 힘이 반대로 작용(-)하게 된다. 반대로 후륜의 경우 평형의 법칙에 의해(+)로 작용하게 된다.

최종적으로 아래와 같은 4개의 미분방정식을 얻게 된다.
![방정식_최종](https://user-images.githubusercontent.com/79674592/110116172-76998280-7dfa-11eb-9fd6-7338664585c8.png)

3. Controller 

- Skyhook Controll logic

![skyhook](https://user-images.githubusercontent.com/79674592/110231701-a5c80500-7f5c-11eb-99d8-5ba103fa9d3c.PNG)

스카이 훅은 sprung mass와 unsprung mass사이의 semi active damper를 설치하여 제어 할 수 있다. 스카이 훅의 전략은 댐핑 계수(damping coefficient)를 높게 또는 낮게 스위칭하여 sprung mass의 진동을 제어하는 것이다. 

![skyhook_eq](https://user-images.githubusercontent.com/79674592/110232002-3ce18c80-7f5e-11eb-8cc6-28898d28722c.PNG)

이 컨트롤 전략은 sprung mass의 속도(수직),그리고 unsprung mass와의 상대속도에 따라 댐핑계수를 변화시키는 것이다. Cmax와 Cmin은 각각 댐핑계수의 최대,최소이다. unsprung mass에 대한 sprung mass의 속도가 양수라면 Cmax에 비례하는 감쇠력을 요구하는 것을 의미한다. 그러므로 최대 댐핑계수가 적용되야하고, 그렇지 않은 상황(unsprung mass에 대한 sprung mass의 속도가 음수)에서는 비활성화된다.

- Ground hook Controll logic

![gh](https://user-images.githubusercontent.com/79674592/110232497-533d1780-7f61-11eb-9e56-80bb1816d5a6.PNG)

그라운드 훅의 컨트롤 전략은 스카이 훅과 매우 유사한데 시스템 구성도에서 볼 수 있듯이 기존의 skyhook의 sprung mass에 달려 있던 댐핑을 제거하고 unsprung mass에 추가한 것이다. 로직은 아래와 아래와 같다.

![gh_logic](https://user-images.githubusercontent.com/79674592/110232548-a1521b00-7f61-11eb-8f6d-ac5682974472.PNG)

- Hybrid hook Controll logic

![hy](https://user-images.githubusercontent.com/79674592/110232592-f68e2c80-7f61-11eb-8afb-e185b809fe65.PNG)

하이브리드 훅은 이름에서도 알 수 있듯이 스카이 훅과 그라운드 훅의 전략을 모두 이용한 것이다. 

![hy_eq](https://user-images.githubusercontent.com/79674592/110232739-f8a4bb00-7f62-11eb-92e3-0bf7b895f33e.PNG)
![hy_2](https://user-images.githubusercontent.com/79674592/110233361-d1e88380-7f66-11eb-8fe2-87e1eb905e32.PNG)

하이브리드 훅의 제어방식은 0~1사이의 값을 갖는 알파의 비율을 변경함으로써 제어할 수 있다. 알파 값이 0인경우 ground hook방식으로 작동하며,1인경우 skyhook의 방식으로 제어된다. 또한 하이브리드의 댐핑 계수는 skyhook의 경우 기존의 skyhook의 gain(damping coefficient)에 alpha를 곱하여 계산되고, groundhook의 경우 (1-alpha)를 groundhook gain에 곱하여 구한다.

4. Result

각각의 제어기는 두 가지 도로환경에서 모두 10초간 시뮬레이션을 진행했다. 시뮬레이션을 통해 각각의 컨트롤러에 따른 Body displacement, Front/Rear displacemet, pitch angle을 비교하였다.

- Body displacement

![Body_dis](https://user-images.githubusercontent.com/79674592/110232827-75d03000-7f63-11eb-8dc3-993f368992a8.PNG)

Body displacement를 비교한 결과 가장 성능이 우수한 controller는 skyhook임을 알 수 있다. sky hook은 모든 도로환경에서 가장 강력한 성능을 나타내는 것을 확인 할 수 있다. 추가로 주목해야 할것은 gruound hook의 경우 기존의 서스펜션 damper와 큰 차이를 보이지 않았다는 점이다. 이는 앞서 소개 했듯이 ground hook의 경우 damper의 위치가 unsprung mass에 위치하기 때문에 sprung mass에 전달되는 진동을 잘 감쇠하지 못한 것을 확인할 수 있었다.

- Front / Rear displacement

![front_Rear](https://user-images.githubusercontent.com/79674592/110233099-183ce300-7f65-11eb-8dc1-3213f0e43673.PNG)

Front와 Rear의 unsprung mass는 3가지 컨트롤러 모두 큰 차이를 보이지 않았다.

- Pitch angle

![pitch](https://user-images.githubusercontent.com/79674592/110233170-926d6780-7f65-11eb-8066-3d7b5d5ef094.PNG)

각 컨트롤러에서 pitch를 분석한 결과도 앞서 Body displacement를 분석한 결과와 매우 유사함을 알 수 있다. 

5. 결론

실험결과 skyhook 방식이 가장 빠르게 정상상태에 수렴하며 초기 진동을 감쇠하는 능력도 가장 우수한 것을 확인 할 수 있었다.
Hybrid hook의 경우 skyhook 다음으로 우수한 성능을 보이는 것을 확인했다. 노면의 상황에 따라 alpha값을 튜닝한다면 skyhook보다 더 나은 결과를 기대할 수 있을 것이다.


6. Reference

https://nrsyed.com/2018/01/07/numerical-approach-to-studying-vehicle-dynamics-with-a-half-car-suspension-model/

Design and Analysis of Semi-active Suspension Using Skyhook, Ground Hook and Hybrid Control Models for a Four Wheeler
